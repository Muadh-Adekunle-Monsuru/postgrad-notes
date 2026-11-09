## Chapter 2: Application Layer

### Review Questions

#### Section 2.1

- **R1.** List five nonproprietary Internet applications and the application-layer protocols that they use.

- **R2.** What is the difference between network architecture and application architecture?
    
- **R3.** For a communication session between a pair of processes, which process is the client and which is the server?
    
- **R4.** What is the software interface that a process sends messages into, and receives messages from?
    
- **R5.** What information is used by a process running on one host to identify a process running on another host?
    
- **R6.** Suppose you wanted to do a transaction from a remote client to a server as fast as possible. Would you use UDP or TCP? Why?
    
- **R7.** Referring to Figure 2.4, we see that none of the applications listed in Figure 2.4 requires both no data loss and timing. Can you conceive of an application that requires no data loss and that is also highly time-sensitive?
    
      
    
- **R8.** List the four broad classes of services that a transport protocol can provide. For each of the service classes, indicate if either UDP or TCP (or both) provides such a service.
    
      
    
- **R9.** Recall that TCP can be enhanced with TLS to provide process-to-process security services, including encryption. Does TLS operate at the transport layer or the application layer? If the application developer wants TCP to be enhanced with TLS, what does the developer have to do?
    
      
    
- **R10.** What is meant by a handshaking protocol?
    
      
    
- **R11.** Why do HTTP, SMTP, and IMAP run on top of TCP rather than on UDP?
    
      
    
- **R12.** Consider an e-commerce site that wants to keep a purchase record for each of its customers. Describe how this can be done with cookies.
    
      
    
- **R13.** How is it that QUIC can be connection-oriented even though it runs over UDP?
    
      
    
- **R14.** In HTTP/3 code, are UDP, TCP, or QUIC sockets opened and closed?
    
      
    
- **R15.** List several popular messaging apps. Do they use the same protocols as SMS?
    
      
    
- **R16.** Alice uses Gmail and Bob uses Yahoo! Mail. Suppose Alice sends an email message to Bob. List the series of application protocols that are used to get the message from Alice to Bob.
    
      
    
- **R17.** Print out the header of an e-mail message you have recently received. How many `Received:` header lines are there? Analyze each of the header lines in the message.
    
      
    
- **R18.** What is the HOL blocking issue in HTTP/1.1? How does HTTP/2 attempt to solve it? What is the HOL issue in HTTP/2? How does HTTP/3 solve it?
    
      
    
- **R19.** Is it possible for an organization’s Web server and mail server to have exactly the same alias for a hostname (for example, `foo.com`)? What would be the type for the RR that contains the hostname of the mail server?
    
      
    
- **R20.** Look over your received e-mails, and examine the header of a message sent from a user. Is it possible to determine from the header the IP address of the host from which the message was sent? Do the same for a message sent from a Gmail account.
    
      
    
- **R21.** CDNs typically adopt one of two different server placement philosophies. Name and briefly describe them.
    
      
    
- **R22.** Besides network-related considerations such as delay, loss, and bandwidth performance, there are other important factors that go into designing a CDN server selection strategy. What are they?
    
      
    

#### Section 2.6

- **R23.** In Section 2.6, the UDP server described needed only one socket, whereas the TCP server needed two sockets. Why? If the TCP server were to support $n$ simultaneous connections, each from a different client host, how many sockets would the TCP server need?
    
      
    
- **R24.** For the client-server application over TCP described in Section 2.6, why must the server program be executed before the client program? For the client-server application over UDP, why may the client program be executed before the server program?
    
      
    

### Problems

- **P1.** True or false?
    
      
    - a. A user requests a Web page that consists of some text and three images. For this page, the client will send one request message and receive four response messages.
        
          
        
    - b. Two distinct Web pages (for example, `www.mit.edu/research.html` and `www.mit.edu/students.html`) can be sent over the same persistent connection.
        
          
        
    - c. With nonpersistent connections between browser and origin server, it is possible for a single TCP segment to carry two distinct HTTP request messages.
        
          
        
    - d. The `Date:` header in the HTTP response message indicates when the object in the response was last modified.
        
          
        
    - e. HTTP response messages never have an empty message body.
        
          
        
- **P2.** Consider the following string of ASCII characters that were captured by Wireshark when the browser sent an HTTP GET message (i.e., this is the actual content of an HTTP GET message). The characters `<CR><LF>` represent carriage-return and line-feed characters.
    
      
    
    HTTP
    
    ```
    GET /cs453/index.html HTTP/1.1
    Host: gaia.cs.umass.edu
    User-Agent: Mozilla/5.0 (Windows;U; Windows NT 5.1; en-US; rv:1.7.2) Gecko/20040804 Netscape/7.2 (ax)
    Accept: text/xml, application/xml, application/xhtml+xml, text/html;q=0.9, text/plain;q=0.8,image/png,*/*;q=0.5
    Accept-Language: en-us,en;q=0.5
    Accept-Encoding: zip,deflate
    Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
    Keep-Alive: 300
    Connection: keep-alive
    ```
    
    Answer the following questions, indicating where in the HTTP GET message above you find the answer:
    
      
    - a. What is the URL of the document requested by the browser?
        
          
        
    - b. What version of HTTP is the browser running?
        
          
        
    - c. Does the browser request a non-persistent or a persistent connection?
        
          
        
    - d. What is the IP address of the host on which the browser is running?
        
          
        
    - e. What type of browser initiates this message? Why is the browser type needed in an HTTP request message?
        
          
        
- **P3.** Obtain the HTTP 1.1 specification (RFC 2616). Answer the following questions:
    
      
    - a. Explain the mechanism used for signaling between the client and server to indicate that a persistent connection is being closed. Can the client, the server, or both signal the close of a connection?
        
          
        
    - b. What encryption services are provided by HTTP?
        
          
        
    - c. Can a client open three or more simultaneous connections with a given server?
        
          
        
    - d. Either a server or a client may close a transport connection between them if either one detects the connection has been idle for some time. Is it possible that one side starts closing a connection while the other side is transmitting data via this connection? Explain.
        
          
        
- **P4.** Suppose within your Web browser you click on a link to obtain a Web page. The IP address for the associated URL is not cached in your local host, so a DNS lookup is necessary to obtain the IP address. Suppose that $n$ DNS servers are visited before your host receives the IP address from DNS; the successive visits incur an RTT of $\text{RTT}_1, \dots, \text{RTT}_n$. Further suppose that the Web page associated with the link contains exactly one object, consisting of a small amount of HTML text. Let $\text{RTT}_0$ denote the RTT between the local host and the server containing the object. Assuming zero transmission time of the object, how much time elapses from when the client clicks on the link until the client receives the object?
    
      
    
- **P5.** Consider a short, 10-meter link, over which a sender can transmit at a rate of $150\text{ bits/sec}$ in both directions. Suppose that packets containing data are $100,000\text{ bits}$ long, and packets containing only control (e.g., ACK or handshaking) are $200\text{ bits}$ long. Assume that $N$ parallel connections each get $1/N$ of the link bandwidth. Now consider the HTTP protocol, and suppose that each downloaded object is $100\text{ Kbits}$ long, and that the initial downloaded object contains 10 referenced objects from the same sender. Would parallel downloads via parallel instances of non-persistent HTTP make sense in this case? Now consider persistent HTTP. Do you expect significant gains over the non-persistent case? Justify and explain your answer.
    
      
    
- **P6.** What is the difference between `MAIL FROM:` in SMTP and `From:` in the mail message itself?
    
      
    
- **P7.** How does SMTP mark the end of a message body? How about HTTP? Can HTTP use the same method as SMTP to mark the end of a message body? Explain.
    
      
    
- **P8.** In SMTP operations, what does **MTA** stand for?
    
      
    

## Chapter 3: Transport Layer

### Review Questions

- **R1.** Suppose the network layer provides the following service: The network layer in the source host accepts a segment of maximum size 1,200 bytes and a destination host address from the transport layer. The network layer then guarantees to deliver the segment to the transport layer at the destination host. Suppose many network application processes can be running at the destination host.
    
      
    - a. Design the simplest possible transport-layer protocol that will get application data to the desired process at the destination host. Assume the operating system in the destination host has assigned a 4-byte port number to each running application process.
        
          
        
    - b. Modify this protocol so that it provides a “return address” to the destination process.
        
          
        
    - c. In your protocols, does the transport layer “have to do anything” in the core of the computer network?
        
          
        
- **R2.** Consider a planet where everyone belongs to a family of six, every family lives in its own house, each house has a unique address, and each person in a given house has a unique name. Suppose this planet has a mail service that delivers letters from source house to destination house. The mail service requires that (1) the letter be in an envelope, and that (2) the address of the destination house (and nothing more) be clearly written on the envelope. Suppose each family has a delegate family member who collects and distributes letters for the other family members. The letters do not necessarily provide any indication of the recipients of the letters.
    
      
    - a. Using the solution to Question R1 above as inspiration, describe a protocol that the delegates can use to deliver letters from a sending family member to a receiving family member.
        
          
        
    - b. In your protocol, does the mail service ever have to open the envelope and examine the letter in order to provide its service?
        
          
        
- **R3.** Consider a TCP connection between Host A and Host B. Suppose that the TCP segments traveling from Host A to Host B have source port number $x$ and destination port number $y$. What are the source and destination port numbers for the segments traveling from Host B to Host A?
    
      
    
- **R4.** Describe why an application developer might choose to run an application over UDP rather than TCP.
    
      
    
- **R5.** Why is it that voice and video traffic is often sent over TCP rather than UDP in today’s Internet? (Hint: The answer has nothing to do with TCP’s congestion-control mechanism.)
    
      
    
- **R6.** Is it possible for an application to enjoy reliable data transfer even when the application runs over UDP? If so, how?
    
      
    
- **R7.** Suppose a process in Host C has a UDP socket with port number 6789. Suppose both Host A and Host B each send a UDP segment to Host C with destination port number 6789. Will both of these segments be directed to the same socket at Host C? If so, how will the process at Host C know that these two segments originated from two different hosts?
    
      
    
- **R8.** Suppose that a Web server runs in Host C on port 80. Suppose this Web server uses persistent connections, and is currently receiving requests from two different Hosts, A and B. Are all of the requests being sent through the same socket at Host C? If they are being passed through different sockets, do both of the sockets have port 80? Discuss and explain.
    
      
    
- **R9.** In our `rdt` protocols, why did we need to introduce sequence numbers?
    
      
    
- **R10.** In our `rdt` protocols, why did we need to introduce timers?
    
      
    
- **R11.** Suppose that the round-trip delay between sender and receiver is constant and known to the sender. Would a timer still be necessary in protocol `rdt3.0`, assuming that packets can be lost? Explain.
    
      
    
- **R12.** Visit the Go-Back-N interactive animation at the companion Web site:
    
      
    - a. Have the source send five packets, and then pause the animation before any of the five packets reach the destination. Then kill the first packet and resume the animation. Describe what happens.
        
          
        
    - b. Repeat the experiment, but now let the first packet reach the destination and kill the first acknowledgment. Describe again what happens.
        
          
        
    - c. Finally, try sending six packets. What happens?
        
          
        
- **R13.** Repeat R12, but now with the Selective Repeat interactive animation. How are Selective Repeat and Go-Back-N different?
    
      
    
- **R14.** True or false?
    
      
    - a. Host A is sending Host B a large file over a TCP connection. Assume Host B has no data to send Host A. Host B will not send acknowledgments to Host A because Host B cannot piggyback the acknowledgments on data.
        
          
        
    - b. The size of the TCP `rwnd` never changes throughout the duration of the connection.
        
          
        
    - c. Suppose Host A is sending Host B a large file over a TCP connection. The number of unacknowledged bytes that A sends cannot exceed the size of the receive buffer.
        
          
        
    - d. Suppose Host A is sending a large file to Host B over a TCP connection. If the sequence number for a segment of this connection is $m$, then the sequence number for the subsequent segment will necessarily be $m + 1$.
        
          
        
    - e. The TCP segment has a field in its header for `rwnd`.
        
          
        
    - f. Suppose that the last `SampleRTT` in a TCP connection is equal to 1 sec. The current value of `TimeoutInterval` for the connection will necessarily be $\ge 1\text{ sec}$.
        
          
        
    - g. Suppose Host A sends one segment with sequence number 38 and 4 bytes of data over a TCP connection to Host B. In this same segment, the acknowledgment number is necessarily 42.
        
          
        
- **R15.** Suppose Host A sends two TCP segments back to back to Host B over a TCP connection. The first segment has sequence number 90; the second has sequence number 110.
    
      
    - a. How much data is in the first segment?
        
          
        
    - b. Suppose that the first segment is lost but the second segment arrives at B. In the acknowledgment that Host B sends to Host A, what will be the acknowledgment number?
        
          
        
- **R16.** Consider the Telnet example discussed in Section 3.5. A few seconds after the user types the letter ‘C,’ the user types the letter ‘R.’ After typing the letter ‘R,’ how many segments are sent, and what is put in the sequence and acknowledgment fields?
    
      
    
- **R17.** Suppose two TCP connections are present over some bottleneck link of rate $R\text{ bps}$. Both connections have a huge file to send (in the same direction over the bottleneck link). The transmissions of the files start at the same time. What transmission rate would TCP like to give to each of the connections?
    
      
    
- **R18.** True or false? Consider congestion control in TCP. When the timer expires at the sender, the value of `ssthresh` is set to one half of its previous value.
    
      
    
- **R19.** In the discussion of TCP splitting in the sidebar in Section 3.7, it was claimed that the response time with TCP splitting is approximately $4 \cdot \text{RTT}_{\text{FE}} + \text{RTT}_{\text{BE}} + \text{processing time}$. Justify this claim.
    
      
    

### Problems

- **P1.** UDP and TCP use 1s complement for their checksums.
    
      
    - a. Suppose you have the following three 8-bit bytes: `01010011`, `01100110`, `01110100`. What is the 1s complement of the sum of these 8-bit bytes? (Note: compute 8-bit sums for this problem.) Show all work.
        
          
        
    - b. Why does UDP take the 1s complement of the sum (i.e., why not just use the sum)?
        
          
        
    - c. With the 1s complement scheme, how does the receiver detect errors?
        
          
        
    - d. Is it possible that a 1-bit error will go undetected? How about a 2-bit error?
        
          
        
- **P2.** 1s Complement Calculations:
    
      
    - a. Suppose you have the following 2 bytes: `01011100` and `01100101`. What is the 1s complement of the sum of these 2 bytes?
        
          
        
    - b. Suppose you have the following 2 bytes: `11011010` and `01100101`. What is the 1s complement of the sum of these 2 bytes?
        
          
        
    - c. For the bytes in part (a), give an example where one bit is flipped in each of the 2 bytes and yet the 1s complement doesn’t change.
        
          
        
- **P3.** Suppose that the UDP receiver computes the Internet checksum for the received UDP segment and finds that it matches the value carried in the checksum field. Can the receiver be absolutely certain that no bit errors have occurred? Explain.
    
      
    
- **P4.** Draw the Finite State Machine (FSM) for the receiver side of protocol `rdt3.0`.
    
      
    
- **P5.** Consider the GBN protocol with a sender window size of 4 and a sequence number range of 1,024. Suppose that at time $t$, the next in-order packet that the receiver is expecting has a sequence number of $k$. Assume that the medium does not reorder messages.
    
      
    - a. What are the possible sets of sequence numbers inside the sender’s window at time $t$? Justify your answer.
        
          
        
    - b. What are all possible values of the ACK field in all possible messages currently propagating back to the sender at time $t$? Justify your answer.
        
          
        
- **P6.** Answer true or false to the following questions and briefly justify your answer:
    
      
    - a. With the SR protocol, it is possible for the sender to receive an ACK for a packet that falls outside of its current window.
        
          
        
    - b. With GBN, it is possible for the sender to receive an ACK for a packet that falls outside of its current window.
        
          
        
    - c. The alternating-bit protocol is the same as the SR protocol with a sender and receiver window size of 1.
        
          
        
    - d. The alternating-bit protocol is the same as the GBN protocol with a sender and receiver window size of 1.