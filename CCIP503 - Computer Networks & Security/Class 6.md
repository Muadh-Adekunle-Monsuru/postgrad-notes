# Week 7: Transport Layer (Part 2) — TCP, Flow Control & Congestion Control

This document acts as **Part 2** to the Class 5 Transport Layer notes. It provides an extensive summary of Transmission Control Protocol (TCP), including segment structures, sequence/ACK mechanics, RTT calculations, retransmission algorithms, connection lifecycle, flow control, and network congestion control.

---

## 1. Connection-Oriented Transport: TCP Basics

TCP is defined as a **connection-oriented**, **full-duplex**, and **point-to-point** transport-layer protocol running exclusively in end systems (hosts).

*   **Connection-Oriented:** Before data transmission begins, the client and server engage in a handshake to exchange control messages and establish state variables.
*   **Point-to-Point:** A single connection is strictly between one sender and one receiver (multicasting or broadcasting is not supported by TCP).
*   **Full-Duplex Service:** Data can flow simultaneously in both directions between Host A and Host B.
*   **Byte-Stream Model:** TCP views data not as discrete packet blocks, but as an unstructured, ordered stream of bytes.

---

## 2. TCP Segment Structure & Sequence Numbers

A standard TCP header is $20 \text{ bytes}$ (without optional fields).

### 2.1 Segment Header Fields
*   **Source & Destination Port Numbers (16 bits each):** For process-to-process demultiplexing.
*   **Sequence Number (32 bits):** The byte-stream number of the **first data byte** in the segment's payload.
*   **Acknowledgment Number (32 bits):** The sequence number of the **next byte expected** from the other side (**Cumulative ACK**).
*   **Header Length (`head len`, 4 bits):** Length of the TCP header in 32-bit words.
*   **Flags (6 bits / C, E, U, A, P, R, S, F):**
    *   `A` (ACK): Indicates the acknowledgment field is valid.
    *   `R` (RST), `S` (SYN), `F` (FIN): Connection management (reset, synchronization, teardown).
    *   `C` (CWR), `E` (ECE): Explicit Congestion Notification bits.
*   **Receive Window (`rwnd`, 16 bits):** Number of bytes the receiver is willing to accept (Flow Control).
*   **Internet Checksum (16 bits):** Used for bit-error detection over header and payload.

---

### 2.2 Sequence Numbers and Cumulative ACKs (With Example)

Because sequence numbers count **bytes**, not segments, sequence numbers step up by the size of the payload.

#### Example Scenario: File Transfer
Suppose a host wants to transfer a $500,000 \text{ byte}$ file.
*   **Initial Byte Index:** $0$
*   **Maximum Segment Size (MSS):** $1,000 \text{ bytes}$

**Segmentation breakdown:**
1.  **Segment 1:** Sequence Number $= 0$ (carries bytes $0 \text{ to } 999$).
2.  **Segment 2:** Sequence Number $= 1,000$ (carries bytes $1,000 \text{ to } 1,999$).
3.  **Segment 3:** Sequence Number $= 2,000$ (carries bytes $2,000 \text{ to } 2,999$).

#### Cumulative Acknowledgment Behavior:
*   When the receiver gets Segment 1 (bytes $0\text{--}999$), it returns $\text{ACK} = 1,000$, declaring: *"I have received everything up to byte 999; I am expecting byte 1,000 next."*
*   **Handling Out-of-Order Segments:** If Segment 1 and Segment 3 arrive, but Segment 2 is missing, the receiver buffers Segment 3. However, its ACK will remain $\text{ACK} = 1,000$ until Segment 2 arrives and fills the gap. Once Segment 2 is processed, the receiver immediately advances to $\text{ACK} = 3,000$.

---

## 3. Round-Trip Time (RTT) Estimation & Timeout Interval

TCP uses a timeout mechanism to retransmit lost segments. Setting an accurate timeout interval requires tracking the dynamically changing network RTT.

### 3.1 RTT Calculations
1.  **SampleRTT:** The measured time from segment transmission until ACK receipt (ignoring retransmissions to avoid ambiguity).
2.  **EstimatedRTT (Exponentially Weighted Moving Average - EWMA):**
    $$ EstimatedRTT = (1 - \alpha) \cdot EstimatedRTT + \alpha \cdot SampleRTT $$
    *(Typical standard value: $\alpha = 0.125$)*

3.  **DevRTT (Safety Margin Calculation):** Estimates the variation/jitter of SampleRTT from EstimatedRTT:
    $$ DevRTT = (1 - \beta) \cdot DevRTT + \beta \cdot |SampleRTT - EstimatedRTT| $$
    *(Typical standard value: $\beta = 0.25$)*

4.  **Timeout Interval Setting:**
    $$ TimeoutInterval = EstimatedRTT + 4 \cdot DevRTT $$

---

### 3.2 EWMA Numerical Example
Assume initial $EstimatedRTT = 100 \text{ ms}$, $\alpha = 0.5$.

*   **Sample 1:** $105 \text{ ms} \implies EstimatedRTT = 0.5(105) + 0.5(100) = 102.5 \text{ ms}$
*   **Sample 2:** $103 \text{ ms} \implies EstimatedRTT = 0.5(103) + 0.5(102.5) = 102.75 \text{ ms}$
*   **Sample 3:** $108 \text{ ms} \implies EstimatedRTT = 0.5(108) + 0.5(102.75) = 105.375 \text{ ms}$

*EWMA ensures single sporadic network spikes do not trigger massive premature timeout retransmissions.*

---

## 4. Retransmission Mechanisms & Fast Retransmit

TCP relies on timer expirations and duplicate acknowledgments to achieve reliability.

### 4.1 Retransmission Scenarios
1.  **Lost ACK:** Host A sends $Seq=92$ ($8 \text{ bytes}$). Host B receives it and sends $ACK=100$, but $ACK=100$ is lost. Host A times out, retransmits $Seq=92$, and Host B re-ACKs $100$.
2.  **Premature Timeout:** Host A sends $Seq=92$ ($8 \text{ bytes}$) and $Seq=100$ ($20 \text{ bytes}$). Timers expire prematurely. Host A retransmits $Seq=92$. Host B receives it, sees it already has bytes $92\text{--}119$, and sends a cumulative $ACK=120$.
3.  **Cumulative ACK Covering Lost ACK:** Host A sends $Seq=92$ and $Seq=100$. $ACK=100$ is lost, but $ACK=120$ arrives safely before the timeout. Host A knows all bytes up to $119$ were delivered successfully.

### 4.2 Fast Retransmit
Timeout periods can be long. If the sender receives **3 duplicate ACKs** for the same data (a total of 4 identical ACKs), it infers that the segment immediately after the ACKed byte was lost.
*   **Action:** Resend the missing segment immediately **without waiting for the timer to expire**.

---

## 5. TCP Flow Control

Flow control is a **speed-matching service** that prevents a fast sender from overflowing a slow receiver's socket buffer (`RcvBuffer`).

```
+------------------------------------------------------+
|                     RcvBuffer                        |
|  +------------------------+-----------------------+  |
|  |     Buffered Data      |   Free Buffer Space   |  |
|  | (Waiting for App Read) |        (rwnd)         |  |
|  +------------------------+-----------------------+  |
+------------------------------------------------------+
```

### 5.1 Mechanics
1.  The receiver calculates available space:
    $$ rwnd = RcvBuffer - [LastByteReceived - LastByteRead] $$
2.  The receiver advertises $rwnd$ in every TCP header.
3.  The sender constrains unacknowledged in-flight data:
    $$ LastByteSent - LastByteAcked \le rwnd $$

#### Numerical Example:
*   $RcvBuffer = 64 \text{ KiB}$
*   Currently buffered unread data $= 48 \text{ KiB}$
*   Advertised $rwnd = 64 - 48 = 16 \text{ KiB}$
*   If $cwnd = 20 \text{ KiB}$, sender's sending limit is $\min(rwnd, cwnd) = \min(16, 20) = 16 \text{ KiB}$.

---

## 6. TCP Connection Lifecycle

### 6.1 3-Way Handshake (Establishment)
*   **Step 1 (Client $\rightarrow$ Server):** `SYN` segment sent. `SYN=1`, `seq=client_isn`.
*   **Step 2 (Server $\rightarrow$ Client):** `SYNACK` segment sent. `SYN=1`, `ACK=1`, `seq=server_isn`, `ack=client_isn+1`. Server allocates buffers.
*   **Step 3 (Client $\rightarrow$ Server):** `ACK` segment sent. `SYN=0`, `ACK=1`, `seq=client_isn+1`, `ack=server_isn+1`. (Payload data can be attached).

*Analogy:* Rock Climbing Command: 1. *"On belay?"* $\rightarrow$ 2. *"Belay on."* $\rightarrow$ 3. *"Climbing."*

### 6.2 Connection Teardown (Termination)
1.  Client sends `FIN` segment to server.
2.  Server responds with `ACK`, then sends its own `FIN` segment when ready to close.
3.  Client responds with `ACK` and enters a **timed wait** state to ensure final ACK delivery before deallocating resources.

---

## 7. TCP Congestion Control

While **Flow Control** protects the receiver, **Congestion Control** protects the network routers from buffer overflows and excessive queuing delay.

### 7.1 Costs of Network Congestion
1.  **High Queueing Delays:** Near link capacity $R$, delays approach infinity.
2.  **Wasted Link Capacity (Retransmissions):** Router drops packets, forcing retransmissions of dropped packets.
3.  **Unneeded Duplicate Retransmissions:** Premature timeouts force redundant deliveries.
4.  **Upstream Capacity Waste:** Dropping a packet downstream wastes all hop bandwidth and buffer space consumed upstream.

---

### 7.2 Congestion Control Mechanisms

The sender maintains a **Congestion Window (`cwnd`)** and limits in-flight data:
$$ LastByteSent - LastByteAcked \le \min(cwnd, rwnd) $$
$$ \text{TCP Sending Rate} \approx \frac{cwnd}{RTT} \text{ bytes/sec} $$

#### 1. AIMD (Additive Increase, Multiplicative Decrease)
*   **Additive Increase:** Increase $cwnd$ by $1 \text{ MSS}$ every $RTT$ in the absence of congestion signals.
*   **Multiplicative Decrease:** Cut $cwnd$ in half upon detecting a packet loss event.
*   *Result:* Sawtooth rate profile.

```
  Sending Rate
       ^
  cwnd |      /|    /|    /|
       |     / |   / |   / |
       |    /  |  /  |  /  |
       |   /   | /   | /   |
       +-----------------------> Time
           (Sawtooth Pattern)
```

#### 2. Slow Start
*   At connection startup or after a timeout recovery, $cwnd$ starts at $1 \text{ MSS}$ (or up to $10 \text{ MSS}$ in modern standards per RFC 6928).
*   $cwnd$ **doubles every RTT** (increases by $1 \text{ MSS}$ for every received ACK).
*   Transitions into linear Additive Increase once $cwnd$ reaches `ssthresh` (Slow Start Threshold).

---

## Summary Matrix: Flow Control vs. Congestion Control

| Metric / Feature         | Flow Control                                   | Congestion Control                      |
| :----------------------- | :--------------------------------------------- | :-------------------------------------- |
| **Protected Target**     | Receiving Application / Receiver Socket Buffer | Intermediate Network Routers and Links  |
| **Primary Variable**     | Receive Window (`rwnd`)                        | Congestion Window (`cwnd`)              |
| **Driven By**            | Explicit receiver feedback in header           | Inferred loss, duplicate ACKs, timeouts |
| **Limit Equation**       | $\text{In-Flight} \le rwnd$                    | $\text{In-Flight} \le cwnd$             |
| **Combined Enforcement** | $\text{Max In-Flight Data} = \min(rwnd, cwnd)$ |                                         |
