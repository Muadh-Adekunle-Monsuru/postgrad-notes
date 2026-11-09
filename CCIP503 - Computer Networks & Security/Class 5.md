# Week 5: Transport Layer

This document is a comprehensive summary of the Week 5 lecture notes on the Transport Layer in computer networks, covering its core services, multiplexing, UDP, and the principles of Reliable Data Transfer (RDT).

---

## 1. Introduction and Transport-Layer Services

The primary role of the transport layer is to provide **logical communication** between application processes running on different hosts. 

*   **Logical Communication:** From the application's perspective, it appears as though the two communicating processes (e.g., your web browser and a YouTube server) are directly connected, even if they are physically separated by thousands of miles and numerous routers.
*   **Relationship with Network Layer:** 
    *   *Network Layer (IP):* Provides logical communication between *hosts* (computers).
    *   *Transport Layer (TCP/UDP):* Provides logical communication between *processes* (applications running on those computers).
    *   **Analogy:** Imagine two houses, each with 12 kids writing letters to each other. The houses are the *hosts*, the kids are the *processes*, the letters are the *application messages*, the postal service is the *network layer protocol (IP)*, and the kids who sort and deliver the mail to their siblings inside the house are the *transport layer protocol*.

### The Two Main Internet Transport Protocols:
1.  **TCP (Transmission Control Protocol):** Reliable, connection-oriented, in-order byte stream. It includes congestion control and retransmission mechanisms.
2.  **UDP (User Datagram Protocol):** Connectionless, unreliable datagram service. No delivery guarantees or ordering.

---

## 2. Multiplexing and Demultiplexing

A single computer can run multiple network applications simultaneously (e.g., a web browser, Spotify, and a multiplayer game). The transport layer ensures that incoming data is handed to the correct application.

*   **Multiplexing (Sender Side):** Gathering data chunks from different sockets, encapsulating them with transport headers (which include port numbers), and passing them to the network layer.
*   **Demultiplexing (Receiver Side):** Reading the transport headers of incoming segments and directing the data to the correct application socket.
    *   **Analogy:** Demultiplexing is like a mailroom clerk (the OS) reading the name on an envelope (the port number) and putting the letter into the correct employee's mailbox (the socket).

### How It Works (Port Numbers)
Sockets are identified using **Port Numbers** (16-bit values from 0 to 65535). Well-known ports (0-1023) are reserved for standard services (e.g., HTTP uses Port 80, HTTPS uses 443).

### Connectionless vs. Connection-Oriented Demultiplexing
*   **Connectionless (UDP):** A UDP socket is identified by a **2-tuple**: `(Destination IP, Destination Port)`. If two different computers send a UDP packet to the same destination IP and port, both packets are pushed through the exact same socket to the application.
*   **Connection-Oriented (TCP):** A TCP socket is identified by a **4-tuple**: `(Source IP, Source Port, Destination IP, Destination Port)`. A web server handles multiple clients by creating a unique socket for every individual connection based on this 4-tuple.

---

## 3. Connectionless Transport: UDP (User Datagram Protocol)

UDP is a "bare-bones" protocol that does almost nothing beyond multiplexing/demultiplexing and basic error checking.

*   **Characteristics:**
    *   **Best-effort service:** Packets may be lost or arrive out of order.
    *   **Connectionless:** No handshaking before sending data (no delay).
    *   **No congestion control:** UDP will send data as fast as the application generates it, regardless of network traffic.
*   **Why use UDP?**
    *   It has a tiny header ($8 \text{ bytes}$ vs TCP's $20 \text{ bytes}$).
    *   No connection setup overhead (lower latency).
    *   Ideal for real-time apps (e.g., video calls, gaming) where a slightly dropped frame is better than a delayed retransmission, and for quick single-query services like DNS lookups.
    *   *Note on QUIC:* Modern protocols like HTTP/3 use QUIC, which builds reliable and secure transport *on top* of the fast, connectionless UDP layer.

### UDP Header and Checksum
The UDP header contains four fields (each 16 bits): Source Port, Destination Port, Length, and Checksum.

*   **Checksum:** Used to detect bit errors (e.g., flipped bits) in the transmitted segment.
    *   *How it works:* The sender treats the data as a sequence of 16-bit integers, adds them up (using 1's complement arithmetic), and puts the result in the Checksum field. The receiver performs the same calculation; if the results don't match, the packet is corrupted.
    *   *Important:* Checksum only *detects* errors; it does not repair them.

---

## 4. Principles of Reliable Data Transfer (RDT)

Networks are inherently unreliable (they lose and corrupt packets). The transport layer must implement protocols to create a "reliable channel" abstraction over this unreliable medium.

### The Evolution of RDT
1.  **rdt1.0 (Perfect Channel):** Assumes the network never loses or corrupts packets. The sender just sends, and the receiver just receives.
2.  **rdt2.0 (Channel with Bit Errors):** Packets might get corrupted. 
    *   *Mechanism introduced:* **ACKs** (Acknowledgements - "I got it OK") and **NAKs** (Negative Acknowledgements - "It was corrupted, send again"). 
    *   *Fatal Flaw:* What if the ACK or NAK itself gets corrupted? The sender won't know what to do. If it blindly retransmits, it might create a duplicate packet.
3.  **rdt2.1 / rdt3.0 (Handling Duplicates and Loss):** Packets can be corrupted AND completely lost.
    *   *Mechanisms introduced:* 
        *   **Sequence Numbers:** Attached to each packet. If the receiver sees a sequence number it already acknowledged, it knows it's a duplicate and can safely discard it.
        *   **Countdown Timer (Timeout):** If a packet is lost, the sender will wait a certain amount of time. If no ACK is received before the timer expires, it retransmits the packet.
    *   *This creates a **Stop-and-Wait** protocol:* The sender sends one packet, starts a timer, and does absolutely nothing else until it gets an ACK.

### The Problem with Stop-and-Wait
Stop-and-wait is terribly inefficient. 
*   *Example:* If you have an $80 \text{ ms}$ Round Trip Time (RTT) and send a $1 \text{ KB}$ packet, your throughput is artificially capped at a very low speed (around $100 \text{ kb/s}$) because the sender spends $99\%$ of its time just waiting for the ACK.

---

## 5. Pipelined Protocols: GBN and Selective Repeat

To solve the inefficiency of Stop-and-Wait, we use **Pipelining**. 
*   **Definition:** Allowing the sender to transmit multiple packets "in-flight" before waiting for acknowledgments. This requires sequence numbers to have a larger range and requires the sender/receiver to buffer packets.

There are two main approaches to handling errors in a pipelined protocol:

### 1. Go-Back-N (GBN)
*   **How it works:** The sender can send up to $N$ unacknowledged packets. The receiver only sends **cumulative ACKs** (e.g., "I have correctly received everything up to packet 3").
*   **Error Handling:** The receiver expects packets in strict order. If packet 2 is lost but packets 3, 4, and 5 arrive, the receiver discards 3, 4, and 5. When the sender's timer for packet 2 expires, it "goes back" and retransmits packet 2, 3, 4, and 5.
*   **Pros/Cons:** Very simple receiver logic (no buffering of out-of-order packets), but wastes bandwidth by retransmitting packets that were successfully delivered but out-of-order.

### 2. Selective Repeat (SR)
*   **How it works:** The receiver acknowledges each packet individually. Out-of-order packets are **buffered** by the receiver until the missing packets arrive to fill the gaps.
*   **Error Handling:** If packet 2 is lost but 3, 4, and 5 arrive, the receiver buffers 3, 4, and 5 and sends individual ACKs for them. When the sender's timer for packet 2 expires, it *only* retransmits packet 2.
*   **Pros/Cons:** Highly efficient use of bandwidth, but requires complex logic and memory on the receiver side to buffer out-of-order packets.
*   *The Dilemma:* If the window size is too large compared to the available sequence numbers, the receiver might not be able to tell the difference between a brand-new packet and a delayed retransmission of an old packet. Thus, the window size must be restricted.