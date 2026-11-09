## Chapter 2: Application Layer

### Review Questions

#### Section 2.1

* **R1.**
* **HTTP:** Web browsing
* **SMTP:** Email transfer
* **DNS:** Domain name resolution
* **SSH:** Remote terminal access
* **FTP:** File transfer


* **R2.** **Network architecture** refers to the overall organization of the communication process into layers (e.g., 5-layer Internet architecture). **Application architecture** refers to how an application is structured across end systems (e.g., Client-Server or Peer-to-Peer).
* **R3.** The process that initiates the communication is the **client**, and the process that waits to be contacted is the **server**.
* **R4.** A **socket** (the Application Programming Interface / API).
* **R5.** The **IP address** of the destination host and the **port number** assigned to the destination process.
* **R6.** **UDP.** UDP requires no connection establishment delay (0-RTT handshake), whereas TCP requires a 3-way handshake prior to data transmission.
* **R7.** **Financial transaction systems** (e.g., high-frequency trading or automated teller machine commands) require zero data loss and low latency/time-sensitivity.
* **R8.**
* **Reliable data transfer:** Provided by TCP (not UDP).
* **Throughput guarantee:** Provided by neither TCP nor UDP.
* **Timing guarantee:** Provided by neither TCP nor UDP.
* **Security (Encryption/Integrity):** Provided by neither natively (enhancements like TLS/DTLS add this on top).


* **R9.** TLS operates at the **application layer**. The application developer must include TLS library code (e.g., OpenSSL) within the application and pass application data through the TLS socket interface built on top of TCP sockets.
* **R10.** A protocol where two communicating entities exchange control messages prior to sending actual data to establish session parameters, state, or encryption keys.
* **R11.** They require **100% reliable data transfer** without packet loss or out-of-order delivery, which TCP guarantees and UDP does not.
* **R12.**
1. Server sends a `Set-Cookie:` header containing a unique user ID to the browser in an HTTP response.
2. Browser stores the cookie locally.
3. Subsequent HTTP requests include the `Cookie:` header with that ID.
4. Server uses the ID to query a backend database and retrieve the user's purchase history.


* **R13.** QUIC implements connection-oriented features (connection state, connection IDs, reliability, and congestion control) **in the application layer** on top of UDP's connectionless transport.
* **R14.** **UDP sockets** are opened and closed by the OS kernel; QUIC multiplexes logical connections over these UDP sockets.
* **R15.** WhatsApp, Signal, Telegram, iMessage. **No**, they use internet application protocols (e.g., WebSockets, custom TLS protocols, XMPP-derived protocols) rather than SMS infrastructure.
* **R16.**
1. Alice’s Gmail client $\rightarrow$ Gmail SMTP Server: **HTTP / HTTPS** (Webmail) or **SMTP**.
2. Gmail SMTP Server $\rightarrow$ Yahoo! Mail SMTP Server: **SMTP**.
3. Yahoo! Mail Server $\rightarrow$ Bob’s email client: **POP3**, **IMAP**, or **HTTP/HTTPS**.


* **R17.** The number of `Received:` header lines indicates how many intermediate Mail Transfer Agents (MTAs) routed the email. Each line contains the sending host, receiving host, protocol used, and timestamp, ordered chronologically from bottom to top.
* **R18.**
* **HTTP/1.1 HOL:** A slow request blocks all subsequent queued responses on a single TCP connection.
* **HTTP/2 Solution:** Multiplexes frames over a single TCP connection.
* **HTTP/2 HOL:** A single dropped TCP packet halts all multiplexed streams in that connection.
* **HTTP/3 Solution:** Runs over QUIC (UDP), isolating stream packet losses so a lost packet only delays its own stream.


* **R19.** **Yes.** The mail server uses an **MX (Mail Exchange)** Resource Record, while the web server uses an **A** or **AAAA** record.
* **R20.** **Yes**, standard headers often expose the sender's client IP in the earliest `Received:` line. For Gmail, Google strips originator client IP addresses for privacy, making only Google’s relay IP visible.
* **R21.**
* **Enter Deep:** Deploys small server clusters deep into thousands of access ISPs worldwide (closer to users, higher maintenance cost).
* **Bring Home:** Deploys larger server clusters at a smaller number of major Internet Exchange Points (IXPs) (farther from users, lower maintenance cost).


* **R22.** Load balancing across clusters, server availability, power/bandwidth costs, geographic/jurisdictional regulations, and ISP peering agreements.

#### Section 2.6

* **R23.**
* **UDP:** Connectionless, so one socket receives datagrams from any client.
* **TCP:** Connection-oriented. Uses one welcoming/listening socket to accept connections, and spawns a new dedicated socket for each client.
* **Sockets needed:** $n + 1$ (1 listening socket + $n$ connected sockets).


* **R24.**
* **TCP:** The client initiates a 3-way handshake to a specific listening socket; if the server isn't running, connection setup fails.
* **UDP:** Connectionless; client sends datagrams without prior handshake, so it can run even if the server is not yet listening.



---

### Problems

* **P1.**
* **a. False** (In HTTP/1.1, the client sends 1 request for HTML, gets 1 response, then sends 3 separate requests for the images $\rightarrow$ 4 request and 4 response messages).
* **b. True**
* **c. False** (Non-persistent connections close after each response; a single TCP segment carries at most 1 request).
* **d. False** (Indicates when the response was generated by the server, not when the object was modified).
* **e. False** (e.g., `304 Not Modified` or `HEAD` responses have empty bodies).


* **P2.**
* **a. URL:** `[http://gaia.cs.umass.edu/cs453/index.html](http://gaia.cs.umass.edu/cs453/index.html)` (from `GET /cs453/index.html` and `Host: gaia.cs.umass.edu`).
* **b. HTTP Version:** `HTTP/1.1` (from status line).
* **c. Connection:** Persistent (`Connection: keep-alive`).
* **d. IP Address:** Cannot be determined from the request text (IP address is contained in the IP packet header, not the HTTP GET payload).
* **e. Browser:** Netscape 7.2 / Mozilla 5.0. Server uses this to send browser-specific formatted content.


* **P3.**
* **a.** The header `Connection: close` signals connection termination. **Both** client and server can signal it.
* **b.** Standard HTTP provides **no** encryption services natively (requires HTTPS / TLS).
* **c. Yes**, modern clients routinely open multiple parallel TCP connections to a single host.
* **d. Yes.** Asymmetric closure can happen if one side issues a `FIN` while the other side has in-flight data.


* **P4.** $\text{Total Elapsed Time} = \sum_{i=1}^{n} \text{RTT}_i + 2 \cdot \text{RTT}_0$
*(Sum of $n$ DNS lookup RTTs + $1\text{ RTT}_0$ for TCP connection setup + $1\text{ RTT}_0$ for HTTP request/response).*
* **P5.**
* **Parallel Non-Persistent HTTP:** Does **not** make sense. Total link bandwidth is fixed at $150\text{ bps}$. Splitting it into $N=10$ parallel connections gives each $15\text{ bps}$, leaving total transfer time identical while adding overhead from 10 separate TCP handshakes.
* **Persistent HTTP:** **Minimal overall gains.** Data size ($100\text{ Kbit}$) dominates control size ($200\text{ bits}$), so saving 9 handshakes saves negligible time relative to data transmission.


* **P6.** `MAIL FROM:` is used in the SMTP envelope protocol to indicate sender identity for routing/bounces. `From:` is a text header line *inside* the email body consumed by the user's MUA.
* **P7.**
* **SMTP:** End of body marked by a single line with a period (`<CR><LF>.<CR><LF>`).
* **HTTP:** Uses `Content-Length` header or chunked transfer encoding (`Transfer-Encoding: chunked`).
* **Can HTTP use SMTP's method?** No, HTTP transmits binary objects where a standalone `.` byte pattern could occur naturally within binary data.


* **P8.** **Mail Transfer Agent**.

---

## Chapter 3: Transport Layer

### Review Questions

* **R1.**
* **a.** Header with a 4-byte **Destination Port Number**.
* **b.** Header with 4-byte **Source Port Number** and 4-byte **Destination Port Number**.
* **c. No.** Port multiplexing is handled entirely at the end systems.


* **R2.**
* **a.** Sender writes the recipient's name on an internal letter inside the envelope. Sending delegate writes sending house address and receiving house address on envelope. Receiving delegate opens envelope and hands letter to recipient.
* **b. No**, the mail service only inspects the outer envelope address.


* **R3.**
* **Source Port:** $y$
* **Destination Port:** $x$


* **R4.** Finer application control over send timing, no connection setup delay, no congestion control restriction, and smaller header overhead.
* **R5.** Firewalls and NATs often block UDP traffic, whereas TCP port 445/80/443 traffic passes through freely.
* **R6.** **Yes.** The application developer can build reliability mechanisms (ACKs, sequence numbers, timers, retransmissions) into the application layer (e.g., QUIC).
* **R7.** **Yes.** Both segments land in the same socket. The process distinguishes them by reading the source IP address and source port number contained in the IP header and UDP header.
* **R8.** **No**, they pass through different socket descriptors. However, **both sockets share destination port 80** on Host C; the kernel demultiplexes incoming TCP segments using the 4-tuple `(Source IP, Source Port, Dest IP, Dest Port)`.
* **R9.** To detect duplicate packets caused by retransmissions or delayed ACKs.
* **R10.** To detect packet loss and trigger retransmission when an ACK is not received within an expected time window.
* **R11.** **Yes.** Timers are still necessary to detect packet loss (if a packet is lost, no ACK will ever arrive).
* **R12.**
* **a.** Packets 1–5 are sent. Packet 1 is lost. Receiver drops packets 2–5 (out-of-order) and re-ACKs packet 0. Sender timer expires for packet 1, triggering retransmission of all packets 1–5.
* **b.** Packet 1 arrives; ACK 1 is lost. When packet 2 arrives, receiver sends ACK 2. ACK 2 cumulatively acknowledges packet 1, preventing sender timeout.
* **c.** Sender window size limits transmission; packets beyond window capacity wait until the window slides forward.


* **R13.** In **Selective Repeat**, the receiver individually acknowledges out-of-order packets and buffers them; the sender retransmits *only* unacknowledged packets upon timeout. In **GBN**, the receiver drops out-of-order packets, and the sender retransmits *all* unacknowledged packets from the lost packet onward.
* **R14.**
* **a. False** (Host B sends pure ACK segments without piggybacked data).
* **b. False** (`rwnd` fluctuates dynamically based on receiver buffer availability).
* **c. True**
* **d. False** ($m$ increments by the number of data payload bytes, not by 1).
* **e. True**
* **f. True** ($\text{TimeoutInterval} = \text{EstimatedRTT} + 4 \cdot \text{DevRTT}$).
* **g. False** (ACK number depends on the sequence number expected from Host B in the opposite direction).


* **R15.**
* **a. Data size:** $110 - 90 = 20\text{ bytes}$.
* **b. ACK Number:** $90$ (Host B ACKs the next expected byte).


* **R16.** **3 segments are sent:**
1. Client sends segment with 'R' (Payload: 1 byte).
2. Server sends ACK + echoed 'R' (Payload: 1 byte).
3. Client sends ACK for echoed 'R' (Payload: 0 bytes).


* **R17.** **$R / 2\text{ bps}$** (TCP congestion control enforces equal bandwidth sharing).
* **R18.** **True.** `ssthresh` is set to $\frac{1}{2} \cdot \text{cwnd}$ upon timeout.
* **R19.**
* Client to Front-End setup + request = $2 \cdot \text{RTT}_{\text{FE}}$
* Front-End to Back-End request + response = $\text{RTT}_{\text{BE}} + \text{processing time}$
* Front-End to Client data delivery = $2 \cdot \text{RTT}_{\text{FE}}$
* **Total:** $4 \cdot \text{RTT}_{\text{FE}} + \text{RTT}_{\text{BE}} + \text{processing time}$



---

### Problems

* **P1.**
* **a. Sum:**

$$\begin{aligned} \text{Sum} &= 01010011_2 + 01100110_2 + 01110100_2 \\ &= 100101101_2 \xrightarrow{\text{wrapped carry}} 00101101_2 + 1_2 = 00101110_2 \\ \text{1s Complement Checksum} &= 11010001_2 \end{aligned}$$


* **b.** Taking the 1s complement allows the receiver to sum all data bytes plus the checksum; a sum equal to all 1s (`11111111`) indicates no detected errors.
* **c.** Receiver sums data bytes + checksum. If any bit in the sum is `0`, an error is detected.
* **d. 1-bit error:** Always detected. **2-bit error:** Can go undetected if opposite bit flips cancel out.


* **P2.**
* **a.** $01011100_2 + 01100101_2 = 11000001_2 \rightarrow \text{Checksum} = \mathbf{00111110_2}$
* **b.** $11011010_2 + 01100101_2 = 100111111_2 \rightarrow 00111111_2 + 1 = 01000000_2 \rightarrow \text{Checksum} = \mathbf{10111111_2}$
* **c.** Byte 1 bit 0 flips $0 \to 1$ (`01011101`) and Byte 2 bit 0 flips $1 \to 0$ (`01100100`). Sum remains identical ($11000001_2$), so checksum does not change.


* **P3.** **No.** Bit errors can compensate for one another (e.g., matching bit flips in opposing directions across different words).
* **P4.**
* **State 1 (Wait for 0 from below):**
* If `rdt_rcv(rcvpkt) && corrupt(rcvpkt)` $\rightarrow$ Send ACK1.
* If `rdt_rcv(rcvpkt) && notcorrupt(rcvpkt) && has_seq0(rcvpkt)` $\rightarrow$ Deliver data, Send ACK0, **Transition to State 2**.
* If `rdt_rcv(rcvpkt) && notcorrupt(rcvpkt) && has_seq1(rcvpkt)` $\rightarrow$ Send ACK1.


* **State 2 (Wait for 1 from below):**
* If `rdt_rcv(rcvpkt) && corrupt(rcvpkt)` $\rightarrow$ Send ACK0.
* If `rdt_rcv(rcvpkt) && notcorrupt(rcvpkt) && has_seq1(rcvpkt)` $\rightarrow$ Deliver data, Send ACK1, **Transition to State 1**.
* If `rdt_rcv(rcvpkt) && notcorrupt(rcvpkt) && has_seq0(rcvpkt)` $\rightarrow$ Send ACK0.




* **P5.**
* **a. Sender Window Ranges:** Any 4 consecutive sequence numbers of the form $[k - d, k - d + 3]$ where $d \in \{0, 1, 2, 3, 4\}$.
* **b. ACK Values in Transit:** Any ACK in the range $[k - 4, k - 1]$.


* **P6.**
* **a. True.** Delayed duplicate ACKs from prior window positions can arrive after the window slides.
* **b. True.** Cumulative ACKs delayed in the network can arrive after the sender window has moved past them.
* **c. True.** SR with window size 1 operates as a stop-and-wait protocol.
* **d. True.** GBN with window size 1 operates as a stop-and-wait protocol.