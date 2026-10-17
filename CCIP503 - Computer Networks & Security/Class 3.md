
## 2. Principles of network applications (slides 6-30)

### 2.1 Applications and end systems

Question: Why do network applications matter to the existence of networking infrastructure?
Answer: Applications provide the useful services that motivate building networks. Without applications that need communication, there would be little reason to build the infrastructure and protocols supporting that communication.

Question: What examples illustrate the historical development of Internet applications?
Answer: In the 1970s and 1980s, important applications included text email, remote computer access, file transfer, and newsgroups. The Web became a major application in the mid-1990s, supporting browsing, search, and electronic commerce. Instant messaging and P2P file sharing became prominent around the end of the millennium. Later examples include VoIP, videoconferencing, YouTube, Netflix, multiplayer games, and social networking. The deck names Skype, FaceTime, and Google Hangouts as historical videoconferencing examples.

Question: What does creating a network application involve?
Answer: Write programs that run on different end systems and exchange messages over the network. For example, a browser program on a user's computer communicates with a Web server program on another machine.

Question: Why can ordinary network applications be developed without changing network-core devices?
Answer: User application logic normally runs on end systems. Routers and switches forward traffic using existing network services, so developers can deploy new endpoint software without installing the application on every intermediate device. This supports rapid development and distribution.

Question: Which protocol layers are shown at the application endpoints in the lecture diagrams?
Answer: Application, transport, network, data link, and physical. An application uses lower-layer services to communicate with a remote application; it does not directly implement every function of those layers.

### 2.2 Application architectures

Question: How does application architecture differ from network architecture?
Answer: Network architecture describes the infrastructure, protocol layers, and services available to applications. Application architecture describes how application functions are distributed among end systems. A developer usually works within the available network architecture but chooses the application's architecture.

Question: What are the two main application architectures discussed in the lecture?
Answer: **Client-server** and **peer-to-peer (P2P)**. Many real applications use a **hybrid** that combines centralized services with direct peer communication.

Question: How does a client-server application work?
Answer: Clients request services from an always-available server or server fleet. The server receives requests and returns results. For example, a browser asks a Web server for an HTML page, and the server sends the page back.

Question: What characteristics define the server in the lecture's client-server model?
Answer: It is always on, has a stable address, and can use data centers to scale. The simplified model describes a permanent IP address; in practice, stable service names can also identify services backed by multiple machines.

Question: What characteristics define clients in the client-server model?
Answer: Clients initiate communication with the server, may connect intermittently, and may have dynamic IP addresses. In the pure model, clients do not exchange application data directly with one another.

Question: Why do large client-server applications use data centers?
Answer: A single host may be unable to handle all requests. A data center or distributed server fleet combines many machines to provide more processing, storage, and availability while presenting a unified service to users.

Question: Which examples of services using data centers appear in the slides?
Answer: Search engines such as Google, Bing, and Baidu; commerce services such as Amazon, eBay, and Alibaba; email services such as Gmail and Yahoo Mail; and social services such as Facebook, Instagram, Twitter, and WeChat. The slide's claim that Google has 30-50 data centers is a historical illustration, not a verified current count to memorize.

Question: How does a P2P architecture work?
Answer: Peers communicate directly and can both request and provide resources. A pure P2P design has no always-on dedicated service server; broader P2P systems can still use central discovery or coordination. Examples in the deck include BitTorrent, Xunlei, and historical Skype designs.

Question: What does P2P self-scalability mean?
Answer: New peers add demand but can also add service capacity. For example, a new file-sharing participant downloads pieces and then uploads those pieces to others, increasing the system's potential distribution capacity.

Question: Why is P2P management more complicated than managing a centralized service?
Answer: Peers join and leave, connect intermittently, and change addresses. The application must locate available peers and cope with changing resource availability. Administration and security are harder when resources belong to many independently managed devices.

Question: How should client-server and P2P architectures be compared?
Answer: Compare availability, scalability, administration, security, and cost. Client-server offers centralized control but requires provisioned server capacity. P2P can distribute resource costs and gain capacity from peers, but service quality depends on peer availability and coordination.

Question: What is a hybrid application architecture?
Answer: A design that uses central servers for some functions and peer communication for others. For example, a messaging service can centrally manage accounts and call signaling while participants exchange audio or video directly.

Question: Is a videoconferencing application necessarily pure client-server?
Answer: No. It may use direct peer media exchange, centrally relayed media, or a hybrid of central coordination and peer connections. Classify its actual communication paths rather than assume one architecture from its purpose.

Question: Which architecture best fits online banking in the lecture exercise, and why?
Answer: **Client-server.** A bank centrally controls authentication, account records, and transactions; customers request operations from the bank's service.

Question: Which architecture best fits public BitTorrent distribution in the lecture exercise?
Answer: **P2P.** Participants exchange file pieces with one another and contribute upload capacity. Coordination mechanisms do not change the peer distribution of the file data.

Question: Which architecture best fits messaging with central account management and direct media paths?
Answer: **Hybrid.** Account management is centralized, while media can travel directly between peers.

Question: Which architecture best fits a university learning-management system?
Answer: **Client-server.** Students and instructors access centrally managed course materials, submissions, and records.

### 2.3 Processes, sockets, and addressing

Question: What actually communicates over a network: programs or processes?
Answer: **Processes**, meaning running instances of programs. A program is stored code; a process is an executing instance that can send and receive messages.

Question: How do processes on the same machine communicate?
Answer: Through interprocess communication mechanisms governed by the operating system, such as pipes or shared memory. They do not necessarily need messages to cross an external network.

Question: How do processes on different end systems communicate?
Answer: By exchanging messages over the network. A sending process creates and sends a message; a receiving process receives it and may send a reply.

Question: What defines a client process and a server process?
Answer: The **client process initiates communication**; the **server process waits to be contacted**. These roles describe an interaction rather than permanently categorizing every machine.

Question: Can a P2P process act as both a client and a server?
Answer: Yes. When Peer A asks Peer B for a file, A is the client and B is the server for that exchange. If B later requests data from A, their roles reverse.

Question: What is a socket?
Answer: A software interface through which an application process sends data to, and receives data from, the transport service. It is the boundary between application logic and the communication service below it.

Question: How does the lecture's house-and-door analogy explain sockets?
Answer: A process is like a house and its socket is like a door. The process passes a message through the door; the transport infrastructure outside carries it to the receiving process's door.

Question: What does the application developer control, and what does the operating system control in the socket diagram?
Answer: The developer controls the application and its use of sockets, including choosing transport and available socket options. The operating system normally implements the underlying transport, network, and link services. The diagram is a conceptual division, not a claim that every protocol must always run inside the OS.

Question: Why is an IP address alone insufficient to identify a receiving application process?
Answer: Several processes can run on one host. The IP address identifies the network endpoint, while a **destination port number**, interpreted with the transport protocol, identifies the receiving service/socket.

Question: What addressing information is needed to send data to a remote service?
Answer: The destination IP address and destination port, together with the chosen transport protocol. Example: the slide addresses an HTTP server at `128.119.245.12`, TCP port `80`, associated with `gaia.cs.umass.edu`.

Question: What common service ports are introduced in the addressing slides?
Answer: **HTTP: TCP 80** and **SMTP mail-server relay: TCP 25**. These are conventional default ports, not mandatory values for every deployment.

Question: Is every IP address 32 bits long?
Answer: No. The slide's 32-bit statement refers to **IPv4**. **IPv6 addresses are 128 bits**. Addressing should not be reduced to a permanently unique identifier for an entire physical computer, since interfaces and hosts can have multiple addresses.

### 2.4 Protocol definitions and transport requirements

Question: What four things does an application-layer protocol define?
Answer: (1) Message types, such as requests and responses; (2) message syntax, including fields and delimiters; (3) message semantics, meaning what fields represent; and (4) rules governing when and how processes send and respond to messages.

Question: How do message syntax and semantics differ?
Answer: **Syntax** specifies structure; **semantics** specifies meaning. Example: syntax says an HTTP response starts with a version and status code, while semantics says status code `404` means the target resource was not found.

Question: What is the difference between open and proprietary protocols?
Answer: Open protocols have publicly documented specifications, often in RFCs, allowing independent implementations to interoperate. HTTP and SMTP are examples. Proprietary protocols are controlled by an organization and may not have fully public specifications; the slides use Skype as a historical example.

Question: What are the four broad transport-service requirements considered in the lecture?
Answer: Reliable data transfer, throughput, timing, and security. Developers choose transport and additional application mechanisms according to the services their application needs.

Question: Which applications require reliable data transfer, and which may tolerate loss?
Answer: File transfer and Web transactions need complete, correct data. Real-time audio can sometimes tolerate a small amount of loss because missing samples may be concealed and retransmitted samples may arrive too late to be useful.

Question: What is the difference between minimum-throughput and elastic applications?
Answer: Some multimedia applications need enough throughput to sustain acceptable playback. Elastic applications, such as file downloads, can use whatever throughput is available; less throughput mainly makes completion take longer.

Question: Why are timing requirements important for Internet telephony and interactive games?
Answer: These applications depend on prompt responses. Excessive delay makes conversation awkward or gameplay unresponsive, even when every byte eventually arrives correctly.

Question: What does security mean as an application transport requirement?
Answer: It can include confidentiality through encryption, protection against tampering, and authentication. Reliable delivery and cryptographic integrity are different: recovering lost bytes does not by itself prevent malicious modification.

Question: Which two transport protocols are the main introductory choices in the lecture?
Answer: **TCP (Transmission Control Protocol)** and **UDP (User Datagram Protocol)**. Their different service models influence the application's design.

### 2.5 TCP, UDP, and delivery patterns

Question: What services does TCP provide?
Answer: A connection-oriented, reliable, ordered **byte stream**, full-duplex communication, and congestion control. A handshake establishes the connection before normal data exchange.

Question: What does a full-duplex TCP connection mean?
Answer: Both processes can send data to each other over the connection at the same time. It is not restricted to alternating one-way transfers.

Question: What does TCP's reliable, ordered delivery mean in practice?
Answer: TCP detects loss and retransmits as needed, presenting received bytes in order. If the connection cannot continue, the application can encounter a failure; TCP does not guarantee successful delivery despite permanent outages or guarantee that the remote application processed the data.

Question: What does it mean that TCP provides a byte stream rather than messages?
Answer: TCP preserves byte order but does not preserve the application's send-call boundaries. An application must define message framing, such as lengths or delimiters. Two sends can be observed as one receive, or one send can require several receives.

Question: What is TCP congestion control?
Answer: TCP adjusts its sending behavior to reduce overload when the network becomes congested. The lecture describes this as throttling a sending client or server along the path to the receiver.

Question: What services does UDP provide?
Answer: Connectionless delivery of individual datagrams without a transport handshake. It preserves datagram boundaries but has no built-in guarantee of delivery, ordering, or retransmission, and no built-in congestion-control mechanism.

Question: What can happen to messages sent using UDP?
Answer: They may be lost, arrive out of order, or be duplicated. Applications that need protection against these outcomes must provide suitable mechanisms above UDP.

Question: Why might an application choose UDP?
Answer: It can avoid a transport connection setup and give the application control over deadlines, retransmissions, and message handling. For real-time media, a late packet may be less useful than a timely newer packet. The application still needs appropriate rate management and any required security or reliability.

Question: Is TCP always slow and UDP always fast?
Answer: No. The deck later explicitly corrects this simplification. Performance depends on network conditions and application design. UDP has fewer built-in services, but an application may add them; TCP's mechanisms can improve useful throughput and reliability.

Question: Can applications add reliability or congestion control above UDP?
Answer: Yes. UDP's minimal service does not prevent higher layers from adding acknowledgments, retransmissions, sequencing, or congestion control. QUIC, used by HTTP/3, is one example.

Question: What are unicast, multicast, and broadcast?
Answer: **Unicast:** one sender to one destination. **Multicast:** one sender to a selected group. **Broadcast:** one sender to all hosts within a broadcast scope. For example, delivering a file to one host is unicast; distributing packets to a joined receiver group is multicast; sending to all hosts on an IPv4 broadcast LAN is broadcast.

Question: How do TCP and UDP differ in their support for unicast, multicast, and broadcast?
Answer: TCP provides unicast connections between endpoints. UDP can be used with unicast and, where supported by the underlying network, multicast or broadcast. Clarification: IPv6 has multicast but no IP broadcast, so “UDP supports all casts” is a simplified statement with network-specific limits.

Question: Which application protocols and transports appear in the slide's application table?
Answer: These are the lecture's examples, including the image-only table on slide 29.

| Application | Application-layer protocol in the deck | Transport in the deck |
| --- | --- | --- |
| File transfer/download | FTP, RFC 959 | TCP |
| Email | SMTP, RFC 5321 | TCP |
| Web documents | HTTP/1.1, RFC 7230 | TCP |
| Internet telephony | SIP, RFC 3261; RTP, RFC 3550; or proprietary protocols | TCP or UDP |
| Streaming audio/video | HTTP, RFC 7320 as printed; DASH | TCP |
| Interactive games | WoW/FPS proprietary protocols | UDP or TCP |

The streaming row's **RFC 7320** reference appears to be a typo: that RFC concerns URI design and ownership, not the HTTP protocol specification. These are illustrative mappings, not universal requirements; for example, HTTP/3 uses QUIC over UDP.

Question: Why should signaling and media be distinguished in Internet telephony?
Answer: Call-control messages and audio/video packets serve different purposes and can use different protocols or transports. SIP is a signaling example; RTP is a media transport protocol commonly carried over UDP. A “TCP or UDP” table entry does not imply every part of a call uses the same transport.

## 3. The Web and HTTP (slides 32-60)

### 3.1 Web objects and basic HTTP operation

Question: How did the Web change the Internet's audience in the early 1990s?
Answer: Before the Web, Internet use largely involved researchers, academics, and students using remote login, file transfer, news, and email. The Web attracted the general public and enabled widespread on-demand access to information.

Question: What does it mean that the Web operates on demand?
Answer: Users request content when they want it, unlike traditional broadcast radio or television, where the provider schedules when content is transmitted.

Question: What is HTTP?
Answer: **Hypertext Transfer Protocol**, the Web's application-layer protocol. It defines how clients request resources and how servers return responses, including message structure and meaning.

Question: What roles do a Web browser and a Web server play?
Answer: The browser is the HTTP client: it requests, receives, and displays Web objects. The Web server receives requests and sends responses. The slides illustrate Firefox and Safari clients communicating with an Apache server.

Question: What is a Web object?
Answer: A resource such as an HTML file, image, audio file, or other content addressable by a URL. The slides also list Java applets as a historical example.

Question: How is a Web page usually composed?
Answer: A base HTML document references additional objects such as images. The browser retrieves the HTML, parses it, discovers the referenced resources, and requests them separately as needed.

Question: What is a URL, and which parts are illustrated in the slides?
Answer: A **Uniform Resource Locator** identifies a resource. In `http://www.someschool.edu/someDept/pic.gif`, `www.someschool.edu` is the host name and `/someDept/pic.gif` is the path. The added `http://` scheme makes the slide's abbreviated example a complete URL.

Question: What is the basic TCP-based HTTP interaction described in the lecture?
Answer: (1) The client creates a socket and initiates a TCP connection, conventionally to port 80 for plain HTTP; (2) the server accepts it; (3) the client and server exchange HTTP requests and responses; and (4) the connection eventually closes. HTTP/1.x and HTTP/2 use TCP; HTTP/3 uses QUIC over UDP.

Question: What does it mean that HTTP is stateless?
Answer: HTTP does not require the server to remember earlier requests to understand a later one. A repeated ordinary request can be handled independently. Applications can still maintain sessions, databases, and caches; statelessness does not mean servers cannot remember anything.

Question: Why does a persistent connection not make HTTP a stateful application protocol?
Answer: Keeping the transport connection open is different from remembering application history. Multiple independent requests can share one connection without requiring the server to remember the user's earlier actions.

### 3.2 Connections, RTT, and response time

Question: What is a non-persistent HTTP connection?
Answer: In the lecture's model, one TCP connection carries at most one requested object and then closes. Retrieving several objects requires several connections.

Question: What is a persistent HTTP connection?
Answer: A connection reused for multiple requests and responses. The server leaves it open after a response, allowing additional objects or pages from that server to use the same connection.

Question: What happens when non-persistent HTTP retrieves the example HTML page containing ten JPEG references?
Answer: The client opens a TCP connection, requests the HTML, receives it, and the connection closes. The browser parses the HTML, finds ten image references, and repeats the exchange for each image. The simplified example uses **11 objects and 11 TCP connections** in total.

Question: What are the individual steps of the non-persistent HTTP exchange diagram?
Answer: (1) Client initiates TCP to the server's port 80; (2) server accepts; (3) client sends a request through its socket naming the desired object; (4) server forms and sends a response through its socket; (5) the connection closes after delivery; (6) client displays/parses the HTML and repeats the process for referenced objects. The diagram presents client and server actions on parallel time lines.

Question: What is round-trip time (RTT)?
Answer: The time for a small packet to travel from client to server and back. It includes propagation, queueing at intermediate routers/switches, and processing delays.

Question: What is the lecture's non-persistent HTTP response-time formula?
Answer: **Response time ≈ 2 × RTT + file transmission time.** One RTT is used to establish TCP; another covers sending the HTTP request and receiving the beginning of the response; transmitting the complete object takes additional time.

Question: What assumptions limit the formula 2 × RTT + file transmission time?
Answer: It is a simplified model that omits DNS lookup, TLS setup, server computation, loss/retransmission, and detailed TCP startup effects. The request is small and connection establishment succeeds normally. Actual page-load time also depends on scheduling multiple resources.

Question: How do you calculate file transmission time?
Answer: Divide object size in bits by the effective transmission rate in bits per second: **T = L/R**. Example: a 1 Mbit object at 10 Mbps takes approximately `1/10 = 0.1 seconds` to transmit, ignoring other delays.

Question: What is a worked example of non-persistent HTTP response time?
Answer: If RTT is 100 ms and file transmission takes 50 ms, response time is approximately `2 × 100 + 50 = 250 ms`. This uses the lecture's simplified model.

Question: What is the simplified sequential cost of fetching a base HTML page plus ten images using non-persistent HTTP?
Answer: Assuming the same RTT for all objects and no parallel connections, **22 × RTT + the sum of the 11 transmission times**. Real browsers can open parallel connections, so this is a teaching calculation, not a universal page-load formula.

Question: Why does persistent HTTP reduce overhead?
Answer: It reuses the established TCP connection, avoiding a new handshake for each object. The example's HTML and ten images can use one connection, and later pages on the same server may reuse it too.

Question: What is HTTP/1.1 pipelining?
Answer: Sending multiple requests back-to-back without waiting for each response before sending the next request. Responses on that connection are returned in request order. Pipelining is distinct from merely keeping a connection open.

Question: What does the slide mean by “as little as one RTT for all referenced objects” with persistent HTTP?
Answer: Once the connection exists and the browser knows the referenced objects, it can pipeline requests and begin receiving responses after roughly one additional RTT. This is a best-case latency illustration; object transmission, congestion, and server work still take time.

Question: When does a server close an unused persistent connection?
Answer: Typically after a configurable idle timeout, or when the connection must otherwise be terminated. Persistence does not mean a connection stays open forever.

### 3.3 HTTP request structure and methods

Question: What are the two main HTTP message types?
Answer: **Requests**, sent by clients, and **responses**, sent by servers.

Question: What is the general structure of an HTTP/1.x request?
Answer: A request line, zero or more header lines, a blank line, and an optional message body. The request line contains a method, request target, and HTTP version separated by spaces.

Question: What is an example of an HTTP/1.1 GET request?
Answer:

```http
GET /index.html HTTP/1.1
Host: www-net.cs.umass.edu
User-Agent: Firefox/3.6.10
Accept: text/html,application/xhtml+xml
Accept-Language: en-us,en;q=0.5
Accept-Encoding: gzip,deflate
Accept-Charset: ISO-8859-1,utf-8;q=0.7
Keep-Alive: 115
Connection: keep-alive

```

This preserves the lecture's historical header example. On the wire, each displayed line ends in `\r\n`, and the header section ends with an extra `\r\n`. Header choices shown here are illustrative rather than recommendations for a modern browser.

Question: What do CRLF and the blank line mean in HTTP/1.x messages?
Answer: **CRLF** is carriage return followed by line feed, written `\r\n`. It terminates lines. An empty line, producing `\r\n\r\n` after the last header, separates headers from the body.

Question: What do the request headers in the lecture example describe?
Answer: `Host` identifies the target host; `User-Agent` describes the client; `Accept` lists acceptable media types; `Accept-Language` expresses language preferences; `Accept-Encoding` lists supported content encodings; `Accept-Charset` expresses character-set preferences in the historical example. The connection-related headers communicate persistence information in that example.

Question: Is HTTP always transmitted as human-readable ASCII text?
Answer: The lecture's text examples describe **HTTP/1.x start lines and headers**. Bodies can contain binary data, and HTTP/2 and HTTP/3 use binary framing. Do not generalize the ASCII claim to all HTTP content and versions.

Question: Is Connection: keep-alive necessary for HTTP/1.1 persistence?
Answer: HTTP/1.1 connections are persistent by default unless closure is indicated. The deck illustrates explicit keep-alive headers, but an HTTP/1.1 client does not need that header just to request the default behavior.

Question: What does GET do?
Answer: It retrieves a representation of a resource. It is defined as a safe method, so applications should not use it to request state-changing operations such as deleting an account. Example: `GET /courses/503` retrieves course information.

Question: What does HEAD do?
Answer: It requests the response metadata that a GET would provide, without the representation body. It can check resource metadata without downloading the full object.

Question: What does POST do?
Answer: It submits data for processing according to the target resource's behavior. The data is commonly in the request body. Examples include submitting a form, creating an order, or sending search parameters to an application that accepts POST.

Question: What does PUT do?
Answer: It requests creation or replacement of the target resource representation with the supplied content. Example: `PUT /profiles/42` supplies the intended new representation of profile 42. The slide's file-upload wording is one possible use, not the entire meaning.

Question: What does DELETE do?
Answer: It requests removal of the target resource's association/functionality. Example: `DELETE /documents/17`. Whether this physically erases a file or database record is an application implementation decision.

Question: Which method sets are contrasted in the historical HTTP version slide?
Answer: The slide lists GET, POST, and HEAD under HTTP/1.0, and those methods plus PUT and DELETE under HTTP/1.1. This is a teaching comparison of method support, not an exhaustive list of all HTTP methods.

Question: How do GET and POST differ in the form-submission examples?
Answer: GET commonly puts form parameters in the URL query string; POST commonly sends them in a request body. A clearer two-field version of the slide's abbreviated example is `http://www.somesite.com/animalsearch?animal=monkeys&food=bananas`. An ampersand separates parameters, and typical fields use `name=value` pairs.

Question: Does a GET request normally have a message body?
Answer: Ordinary retrieval requests generally do not. HTTP framing can represent content with GET, but GET content has no generally defined semantics and may be rejected. Use query parameters for ordinary retrieval or an appropriate method such as POST for submitted content.

Question: What does idempotent mean for an HTTP method?
Answer: Repeating the same request has the same intended effect on server state as making it once. PUT and DELETE are idempotent. Responses may differ: the first DELETE may succeed and a later identical DELETE may report that the resource is already absent. POST is not defined as idempotent in general.

### 3.4 HTTP responses and status codes

Question: What is the general structure of an HTTP/1.x response?
Answer: A status line containing the HTTP version, numeric status code, and reason phrase; header lines; a blank line; and a body where applicable. Some responses, including HEAD responses and 304 responses, contain no representation body.

Question: What is the meaning of HTTP/1.1 200 OK?
Answer: The server is using HTTP/1.1 and the request succeeded. `200` is the status code; `OK` is the reason phrase. For a normal successful GET, the requested representation follows in the body.

Question: What response headers are illustrated in the lecture, and what do they mean?
Answer: `Date` gives the response timestamp; `Server` identifies server software when disclosed; `Last-Modified` gives the resource modification time; `ETag` is a version validator; `Accept-Ranges: bytes` advertises byte-range support; `Content-Length` gives body length in bytes; `Content-Type` describes the media type and possibly charset. `Keep-Alive` and `Connection` describe connection behavior in the historical example.

Question: What is a short example of an HTTP response?
Answer:

```http
HTTP/1.1 200 OK
Content-Type: text/html; charset=UTF-8
Content-Length: 14

<h1>Hello</h1>
```

The body shown has 14 ASCII/UTF-8 bytes if it has no trailing newline. The actual wire uses CRLF for header lines and an empty line before the body.

Question: What do the main HTTP status-code classes mean?
Answer: **1xx:** informational; **2xx:** successful; **3xx:** redirection or cache-related response; **4xx:** client/request-related problem; **5xx:** server-side failure. This grouping helps interpret the individual codes listed in the deck.

Question: What does 301 Moved Permanently mean, and what should the client do?
Answer: The resource has a permanent new location. The response normally supplies the destination in a `Location` header, and the client can follow it.

Question: What does 400 Bad Request mean?
Answer: The server cannot process the request because of a perceived client error, such as malformed syntax. Inspect and correct the request rather than assume the resource is missing.

Question: What does 404 Not Found mean?
Answer: The server did not find the requested resource, or does not disclose its existence. Check the URL and resource availability.

Question: What does 505 HTTP Version Not Supported mean?
Answer: The server does not support the HTTP major version used by the request. Client/server protocol compatibility needs investigation.

Question: What does 304 Not Modified mean, and what should the browser do?
Answer: A conditional retrieval found that the cached representation is still valid. The server does not resend the representation body; the browser reuses its cached copy.

Question: What does 401 Unauthorized mean, and what is the likely next step?
Answer: The request lacks valid authentication credentials. Obtain or supply valid credentials according to the authentication challenge before retrying.

Question: What does 403 Forbidden mean, and how is it different from 401?
Answer: The server refuses the request. In the lecture's diagnosis, the user may lack permission. Supplying the same credentials again may not help; review access rights. A 401 concerns missing or invalid authentication, whereas a 403 need not be fixable merely by authenticating.

Question: What does 429 Too Many Requests mean?
Answer: The client has exceeded a request-rate limit. Delay retries appropriately, taking any `Retry-After` information into account.

Question: What does 503 Service Unavailable mean?
Answer: The server is temporarily unable to handle the request, for example because of overload or maintenance. Retry later as appropriate rather than repeatedly adding load.

### 3.5 Cookies and application state

Question: Why do Web applications use cookies when HTTP is stateless?
Answer: Applications may need to recognize returning users, remember carts, or maintain authenticated sessions. Cookies let the browser return a value that the application can associate with earlier activity.

Question: What four components make up the cookie mechanism described in the slides?
Answer: (1) A `Set-Cookie` response header; (2) a `Cookie` request header; (3) browser-managed cookie storage on the user's device; and (4) a server-side database in the lecture's identifier-based example. RFC 6265 is the cookie reference cited by the deck.

Question: How does the cookie example work on a first visit and later visits?
Answer: On the first visit, the server creates an identifier such as `1678`, stores a corresponding record, and returns a cookie. The browser stores it and includes it on matching later requests. The server uses the identifier to look up the associated state, including on a later visit one week afterward.

Question: What is the difference between Set-Cookie and Cookie?
Answer: `Set-Cookie` is sent by the server to create or update a browser cookie; `Cookie` is sent by the browser to return stored cookie values. A realistic version of the slide's simplified identifier example is `Set-Cookie: session_id=1678`, followed later by `Cookie: session_id=1678`.

Question: What uses of cookies are listed in the lecture?
Answer: Authorization/session identification, shopping carts, recommendations, and session state such as Web email. A cookie can identify a session; actual authorization decisions remain the server's responsibility.

Question: How can cookies support one-click shopping and personalization?
Answer: The server can associate a cookie identifier with an account record containing preferences and stored customer details. Returning requests identify that record, allowing personalization and reducing repeated data entry. The details do not need to be stored directly in the cookie.

Question: What privacy consequence is illustrated by the Susan/Amazon example?
Answer: Once a visitor registers, a site can associate the identifier and previously tracked visits with a named account. This links browsing history and stored customer information in the site's database.

Question: How can state be maintained across otherwise independent HTTP requests?
Answer: Endpoints can store state, and requests can carry an identifier that connects each transaction to that state. In the lecture's example, the browser returns a cookie and the server looks up the session record.

### 3.6 Web caching and worked calculations

Question: What is a Web cache or caching proxy?
Answer: An intermediary that stores copies of resources and can satisfy requests on behalf of an origin server. The origin server is the authoritative source of the resource. The lecture describes a proxy with local disk storage.

Question: What happens on a cache hit and a cache miss?
Answer: On a **hit**, an appropriate stored copy serves the request without retrieving the full object from the origin. On a **miss**, the cache requests the object from the origin, returns it to the client, and may store a copy. Freshness and caching rules determine whether reuse is allowed.

Question: Why is a Web cache both a server and a client?
Answer: It acts as a server when answering the browser's request and as a client when requesting a missing or revalidated resource from the origin server.

Question: Where are institutional caches installed, according to the lecture?
Answer: Within university, company, or residential ISP networks. In the illustrated configuration, the browser directs its Web requests through the cache.

Question: What benefits does Web caching provide?
Answer: Lower client response time for hits, reduced traffic on the institution's access link, and less demand on origin servers. Distributed caches can help content providers with limited resources reach many users.

Question: What numerical assumptions are used in the caching example?
Answer: A **100 Mbps institutional LAN**, a **15 Mbps Internet access link**, **1 Mbit average object size**, **15 requests/second**, and **2 seconds RTT between the institutional router and origin servers**. The later cache solution assumes a 40% hit rate.

Question: How is traffic intensity calculated in the slide example?
Answer: **Traffic intensity = request rate × average object size / link capacity**, or `ρ = λL/R`. The numerator is average offered traffic in bits per second. The result is dimensionless.

Question: What is the offered traffic load in the example?
Answer: `15 requests/s × 1 Mbit/request = 15 Mbit/s`, or **15 Mbps**. Keep bits and bytes distinct: the slide says 1 Mbit, not 1 Mbyte.

Question: What is the LAN traffic intensity in the example?
Answer: `ρ_LAN = (15 × 1)/100 = 0.15`, or **15% utilization** in the simplified model. The lecture treats the corresponding LAN delay as small, on the order of milliseconds or tens of milliseconds.

Question: What is the original Internet access-link traffic intensity?
Answer: `ρ_access = (15 × 1)/15 = 1.0`, or **100% utilization**. The offered load equals capacity, leaving no spare capacity to absorb bursts.

Question: Why does delay become extremely large as traffic intensity approaches 1?
Answer: Bursts create queues, and there is little spare service capacity to drain them. In idealized steady-state queueing models, mean delay grows without bound at saturation. Real finite-buffer networks instead also drop packets; the slide's “minutes” illustrates severe delay, not an exact result derived from the given values.

Question: How does the slide break down total response delay without a cache?
Answer: **Total delay = Internet delay + access-link delay + LAN delay.** Its illustrative result is `2 seconds + minutes + milliseconds`, because the saturated access link dominates.

Question: How does upgrading the access link to 100 Mbps change the example?
Answer: Access-link intensity becomes `(15 × 1)/100 = 0.15`. The lecture treats access and LAN delays as negligible compared with the 2-second Internet delay, so total response time is roughly **2 seconds**. The drawback is the cost of the higher-capacity access link.

Question: What does a cache hit rate of 0.4 mean?
Answer: **40% of requests** are satisfied locally and **60% miss** and need origin access. In this example, equal average object sizes let the request hit ratio also determine the fraction of data avoided on the access link.

Question: What request rate and access traffic remain after adding the cache?
Answer: Misses occur at `15 × 0.6 = 9 requests/s`. Their access traffic is `9 × 1 Mbit = 9 Mbps`. Therefore, access-link intensity drops from 1.0 to `9/15 = 0.6`.

Question: What response times does the cache solution assume?
Answer: A hit takes **0.01 seconds** (10 ms) and a miss takes **2.01 seconds**. These are illustrative delay assumptions supplied by the lecture, not uniquely determined by a utilization of 0.6.

Question: How is the mean response time with the cache calculated?
Answer: Weight each outcome by its probability: `T_avg = hT_hit + (1-h)T_miss`. With the slide values, `0.4 × 0.01 + 0.6 × 2.01 = 0.004 + 1.206 = 1.21 seconds`, slightly greater than **1.2 seconds**.

Question: Why can the cache outperform the access-link upgrade in the lecture example?
Answer: The upgrade reduces queueing but every request still incurs the approximately 2-second origin delay. With a cache, 40% of requests avoid that delay entirely, producing the illustrative **1.21-second average**.

Question: Is traffic intensity below 0.8 a universal guarantee of small delay?
Answer: No. The slide uses it as an illustrative rule of thumb. Actual delay depends on burstiness, packet/object sizes, queueing behavior, scheduling, and capacity; utilization alone does not specify a delay in milliseconds.

Question: What is a conditional GET, and why is it useful?
Answer: A GET that includes a validator so the server sends the resource only if the cached copy is no longer current. It reduces unnecessary object transmission, saves bandwidth, and avoids full-body transfer delay when nothing changed.

Question: How does If-Modified-Since work in the lecture's conditional GET example?
Answer: The cache sends the stored modification date in `If-Modified-Since`. If the representation has not changed since that date, the server returns **304 Not Modified** without the object body. If it changed, the server returns **200 OK** with the updated representation.

Question: Does a 304 response eliminate all network delay?
Answer: No. The conditional request and response still travel to and from the server. It avoids transmitting the full representation, not the round trip needed for revalidation.

Question: How can an ETag support conditional retrieval?
Answer: A client can send the stored ETag in `If-None-Match`. If the server's current representation still matches that validator, it can return 304 for a conditional GET. This explains the ETag response header shown earlier in the slides.

### 3.7 HTTP/2, HTTP/3, and head-of-line blocking

Question: What is HTTP head-of-line (HOL) blocking in HTTP/1.1 pipelining?
Answer: Responses must be returned in request order, so a small object can wait behind a large earlier response. In the slide, first-come-first-served response ordering delays smaller objects.

Question: What is HTTP/2's main goal in the lecture?
Answer: Reduce delay for pages with multiple objects by allowing more flexible transmission over a connection. It retains familiar HTTP methods, status codes, and most header semantics while changing the wire framing.

Question: How does HTTP/2 reduce application-level HOL blocking?
Answer: It divides messages into frames associated with different streams and can interleave those frames. A server can make progress on small responses while still transmitting a large response, instead of finishing the entire large object first.

Question: What does the HTTP/2 diagram with O1, O2, O3, and O4 illustrate?
Answer: O1 is a large object and O2-O4 are smaller. By interleaving their frames, O2-O4 can complete quickly, while O1 finishes slightly later. The diagram illustrates scheduling flexibility rather than creating extra link bandwidth.

Question: What HTTP/2 features are listed in the lecture?
Answer: Binary framing and interleaving, more flexible stream scheduling influenced by priority information, and server push of resources not yet requested. These are protocol capabilities in the teaching material; do not assume every client or deployment enables server push or applies the same priority policy. The deck cites RFC 7540 (2015).

Question: Why does TCP loss still stall HTTP/2 streams on one connection?
Answer: TCP exposes one ordered byte stream. If a segment is missing, later bytes cannot be delivered in order until recovery, even if those bytes contain frames for different HTTP/2 streams. HTTP/2 removes HTTP/1.1 response-order blocking but not this transport-level dependency.

Question: Why can browsers use multiple TCP connections in the lecture's explanation?
Answer: Separate connections can limit how widely a stall on one connection affects requests. The slides also mention increased aggregate throughput. Actual connection behavior depends on protocol and implementation; HTTP/2 is designed to multiplex streams on a connection.

Question: Does plain TCP provide encryption?
Answer: No. TCP reliability is not confidentiality or authentication. HTTPS over TCP uses TLS to add security; HTTP/2 does not make TCP intrinsically encrypted.

Question: What transport does HTTP/3 use, and what services does it provide?
Answer: **QUIC over UDP**, rather than ordinary HTTP messages directly over bare UDP. QUIC supplies secure transport and reliable streams, helping avoid TCP's loss-induced blocking between unrelated streams.

Question: Does HTTP/3 give every object independent congestion control?
Answer: No. This corrects the slide's “per object error- and congestion-control” shorthand. QUIC provides reliable delivery at stream level, while congestion control is shared across the connection. Loss can delay the affected stream and reduce overall sending rate without forcing unrelated streams to wait for that stream's missing bytes.

Question: How do HTTP/1.1, HTTP/2, and HTTP/3 compare at a high level?
Answer:

| Version | Framing and concurrency | Transport | Main limitation/improvement discussed |
| --- | --- | --- | --- |
| HTTP/1.1 | Text start lines/headers; pipelined responses remain ordered | TCP | Small responses can wait behind large responses |
| HTTP/2 | Binary frames; multiplexed streams | TCP, with TLS for HTTPS | Reduces response-order blocking; TCP loss still affects all streams |
| HTTP/3 | HTTP carried on multiplexed QUIC streams | QUIC over UDP, with integrated TLS security | Avoids TCP's cross-stream delivery blocking; congestion still affects the connection |

## 4. Electronic mail on the Internet (slides 62-74)

### 4.1 Components and mail flow

Question: What are the three main components of Internet email?
Answer: **User agents**, **mail servers**, and **SMTP (Simple Mail Transfer Protocol)**. Email was important from the Internet's early development and remains a major application.

Question: What is an email user agent?
Answer: An application for composing, editing, sending, and reading messages, also called a mail reader. The deck gives Microsoft Outlook, Apple Mail, and an iPhone mail client as examples.

Question: What are the roles of mail servers?
Answer: They store incoming messages in users' mailboxes, hold outgoing messages in queues, and transfer messages to other mail servers using SMTP. They form the core of the email infrastructure.

Question: How does a mailbox differ from an outgoing message queue?
Answer: A **mailbox** contains messages received for a user. An **outgoing queue** holds messages awaiting sending or successful relay to their next destination.

Question: Which mail server acts as the SMTP client, and which acts as the SMTP server?
Answer: The sending mail server initiates the connection and acts as the client. The receiving mail server waits for and accepts that connection, acting as the server. The same machine can play either role in different transfers.

Question: What are the six steps in the Alice-to-Bob email example?
Answer: (1) Alice composes a message addressed to Bob using her user agent; (2) the agent submits it to Alice's mail server, which queues it; (3) Alice's server opens a TCP connection to Bob's mail server; (4) SMTP transfers the message; (5) Bob's server places it in Bob's mailbox; and (6) Bob uses his user agent and an access mechanism to read it.

Question: Why does Bob not use SMTP to read his mailbox in the lecture model?
Answer: SMTP handles submission and relay/delivery. Retrieving or synchronizing stored mail is the job of a mail access protocol such as POP3 or IMAP, or of a Web interface accessed over HTTP/HTTPS.

### 4.2 SMTP operation and commands

Question: What transport and conventional server-to-server port does SMTP use?
Answer: **TCP**, conventionally **port 25** for mail-server relay. TCP reliably carries the SMTP exchange. User submission is a separate deployment role and need not use port 25.

Question: What are the three phases of an SMTP transfer?
Answer: **SMTP greeting/handshaking**, **message transfer**, and **connection closure**. The SMTP greeting occurs after TCP connection establishment; the two handshakes are different layers.

Question: What does an SMTP command/response interaction look like?
Answer: The client sends text commands; the server replies with a numeric status code and explanatory text. This resembles the command/status style of the lecture's HTTP/1.x examples.

Question: What is the sample SMTP interaction shown in the lecture?
Answer:

```text
S: 220 hamburger.edu
C: HELO crepes.fr
S: 250 Hello crepes.fr, pleased to meet you
C: MAIL FROM: <alice@crepes.fr>
S: 250 alice@crepes.fr... Sender ok
C: RCPT TO: <bob@hamburger.edu>
S: 250 bob@hamburger.edu ... Recipient ok
C: DATA
S: 354 Enter mail, end with "." on a line by itself
C: Do you like ketchup?
C: How about pickles?
C: .
S: 250 Message accepted for delivery
C: QUIT
S: 221 hamburger.edu closing connection
```

`C` means SMTP client and `S` means SMTP server. The deck's body-only DATA content is simplified; a complete message normally contains message headers, a blank line, and the body.

Question: What do HELO, MAIL FROM, RCPT TO, DATA, and QUIT do?
Answer: `HELO` identifies/greet the client; `MAIL FROM` supplies the envelope sender; `RCPT TO` identifies a recipient; `DATA` begins transfer of the message content after permission; and `QUIT` ends the session. Modern extended SMTP commonly uses `EHLO` to discover supported extensions.

Question: What do the SMTP codes 220, 250, 354, and 221 mean in the sample?
Answer: `220`: service ready; `250`: requested operation succeeded; `354`: send message content and finish with the terminator; `221`: service closing the connection.

Question: How does SMTP mark the end of DATA content?
Answer: With a line containing only a dot, expressed on the wire as **`\r\n.\r\n`**. The terminator ends the message content, not necessarily the TCP connection.

Question: How can SMTP transmit a body line that begins with a dot without ending the message accidentally?
Answer: SMTP uses **dot-stuffing**: the sender adds an extra leading dot to such a line, and the receiver removes the extra dot. This explains how the end-of-DATA delimiter can safely coexist with message text.

Question: Does SMTP use persistent connections?
Answer: Yes. More than one message can be transferred before the connection closes, avoiding a new TCP setup for every message.

Question: What does “accepted for delivery” mean in the SMTP sample?
Answer: The receiving server has accepted responsibility for the message at that stage. It does not mean Bob has opened or read it, and acceptance by an intermediate server does not by itself prove final mailbox delivery.

### 4.3 SMTP versus HTTP and message format

Question: Why is HTTP described as pull and SMTP as push?
Answer: In normal Web retrieval, the HTTP client asks for content and the server returns it (**pull**). In SMTP, the sending client initiates transfer of a message toward the receiver (**push**). This describes the lecture's typical use cases rather than every possible HTTP method.

Question: What similarities and differences between HTTP and SMTP are highlighted in the deck?
Answer: Both use command/response interactions and status codes in their text-based examples. HTTP normally returns an individual representation in a response; one email can bundle several parts in a MIME multipart message. SMTP supports persistent connections and uses an explicit end-of-DATA marker. HTTP/2 and HTTP/3 are not text-framed like the HTTP/1.x examples.

Question: Must every email contain only 7-bit ASCII characters?
Answer: The slides describe the traditional SMTP baseline. Real email can carry non-ASCII text and attachments using MIME encodings such as base64 or quoted-printable. Negotiated extensions such as 8BITMIME and SMTPUTF8 support additional content/address capabilities. “ASCII only” should not be memorized as a rule for all modern email.

Question: What is MIME, and why does it matter to the SMTP discussion?
Answer: **Multipurpose Internet Mail Extensions** provide message structure for content types, attachments, and multipart content, plus transfer encodings where needed. For example, a message can contain text and a photo while using a compatible encoding for the photo's bytes.

Question: How does an email message's format differ from the SMTP transfer protocol?
Answer: SMTP defines how the message is transported; the Internet message format defines the message's headers and body. The slides cite RFC 5321 for SMTP and RFC 2822 for message format; RFC 5322 supersedes RFC 2822. This resembles the distinction between HTTP transport exchanges and HTML document syntax, though email headers are also part of message content.

Question: What is the general format of an email message?
Answer: Header fields such as `From`, `To`, and `Subject`, followed by a blank line and the body. Example:

```text
From: Alice <alice@crepes.fr>
To: Bob <bob@hamburger.edu>
Subject: Lunch

Do you like ketchup?
How about pickles?
```

These message headers are transmitted as part of SMTP DATA content.

Question: How do email From/To headers differ from SMTP MAIL FROM/RCPT TO?
Answer: `From:` and `To:` are fields inside the message that users can see. `MAIL FROM` and `RCPT TO` are SMTP envelope commands used for transfer and delivery. They can differ; for example, a Bcc recipient is an envelope recipient without appearing in the visible To field.

Question: Are email message headers the same as the message body?
Answer: No. The complete message sent during SMTP DATA contains both a header section and a body separated by a blank line. The slide's wording about headers being “within the body of the email message area” means within SMTP-transmitted content, not within the email's own body section.

### 4.4 Mail access, POP3, IMAP, and Webmail

Question: What is a mail access protocol?
Answer: A protocol through which a user agent accesses messages stored on a mail server. POP3 emphasizes download-oriented retrieval; IMAP provides access and synchronization of server-side mailboxes and folders.

Question: What is POP3?
Answer: **Post Office Protocol version 3**, a simple mail access protocol defined in RFC 1939. It offers relatively limited functionality compared with IMAP.

Question: What transport and default port are used in the lecture's POP3 model?
Answer: A TCP connection to **port 110**. The lecture describes basic unencrypted authentication; a protected deployment must use TLS rather than assume that TCP encrypts credentials.

Question: What are POP3's three phases?
Answer: **Authorization**, **transaction**, and **update**. They authenticate the client, permit mailbox operations, and commit requested deletions on normal session completion.

Question: What happens in the POP3 authorization phase?
Answer: The client authenticates, traditionally by sending a username and password. Without transport protection, the basic exchange exposes those credentials in cleartext.

Question: What happens in the POP3 transaction phase?
Answer: The client can obtain mailbox statistics, retrieve messages, mark messages for deletion, and remove deletion marks. Deletion marking is not the same as immediately deleting a message.

Question: What happens in the POP3 update phase?
Answer: After `QUIT` from the transaction phase, the server enters update and removes messages marked for deletion. The lecture's sequence separates selection for deletion from committing it.

Question: What do POP3 +OK and -ERR responses mean?
Answer: `+OK` indicates that the command succeeded and can be followed by data. `-ERR` indicates a problem with the command or requested operation.

Question: Does downloading with POP3 always delete messages from the server?
Answer: No. Clients may leave messages on the server or mark them for later deletion. POP3 is download-oriented but downloading alone is not the deletion command.

Question: What limitation of POP3 motivates IMAP in the lecture?
Answer: POP3 does not provide IMAP-style server-side folder management and synchronized message flags. Organizing downloaded messages into local folders does not automatically reproduce those folders and states on every device.

Question: What does IMAP stand for, and what does it provide?
Answer: **Internet Message Access Protocol**. It lets clients access and manage mail kept on the server, including folders and message flags, so multiple devices can share a consistent mailbox view. The deck uses inconsistent expansions; this is the standard name.

Question: What IMAP capabilities are listed in the slides?
Answer: Retrieve and delete messages, organize server-side folders, flag messages for urgency or follow-up, save drafts on the server, and synchronize read/unread state between multiple clients.

Question: What ports does the lecture list for IMAP?
Answer: **TCP 143** for IMAP, and **TCP 993** for IMAP with implicit TLS. The slide calls the secure form SSL/TLS; TLS is the relevant modern security terminology. Port 143 can also support a negotiated TLS upgrade rather than always being unencrypted.

Question: What is the typical IMAP operation sequence described in the lecture?
Answer: The user signs into a mail client; the client connects to the mail server; it retrieves headers or other metadata; it fetches message content and attachments as needed; changes such as read status or folder moves are synchronized with the server. Messages generally remain there unless removed by a client or server policy.

Question: Must IMAP download a message only after the user clicks it?
Answer: No. IMAP supports selective retrieval, which explains the slide's example, but clients can prefetch messages, download attachments, or maintain offline copies. “Only on click” and “attachments never automatically download” are client-policy examples, not protocol requirements.

Question: Is IMAP always faster than POP3?
Answer: No. Fetching metadata and selected parts can make initial mailbox access efficient, as the slide explains. Actual speed depends on network conditions, mailbox size, client behavior, and what content is being fetched.

Question: How does Webmail use HTTP/HTTPS and mail protocols?
Answer: The browser communicates with a Webmail service over HTTP/HTTPS. The provider handles message sending and mailbox access behind that interface. SMTP is used for mail relay; internal access may use IMAP, POP3, or provider-specific systems. A browser does not need to speak IMAP directly to display Webmail.

Question: How do SMTP, POP3, and IMAP differ?
Answer:

| Protocol | Main role | Typical behavior | Port(s) explicitly taught in the deck |
| --- | --- | --- | --- |
| SMTP | Submission and relay/delivery | Pushes mail to a receiving service; outgoing queues | TCP 25 for server-to-server relay |
| POP3 | Mail access | Download-oriented retrieval; optional deletion | TCP 110 |
| IMAP | Mail access and synchronization | Server-side folders, flags, drafts, multi-device state | TCP 143; TCP 993 with implicit TLS |

Question: Why is IMAP well suited to reading email on both a phone and a laptop?
Answer: Mailboxes, folders, and message flags are maintained on the server. Reading or moving a message on one device can be reflected on the other after synchronization, rather than requiring independently managed local collections.

## 5. Review problems connecting the lecture topics

Question: A server hosts both a Web service and an email relay at one IP address. How are messages directed to the correct service?
Answer: By the transport protocol and destination port. For example, a connection to TCP 80 targets the conventional plain-HTTP service, while TCP 25 targets the conventional SMTP relay. The shared IP alone cannot select the service.

Question: A call must remain responsive even when occasional audio packets are lost. Which transport characteristics matter most?
Answer: Low delay and sufficient throughput, with an acceptable loss tolerance. A UDP-based media design may handle late/lost packets at the application level rather than wait for retransmission. Reliability, congestion management, and security still need deliberate design.

Question: A shopping website remembers a cart while HTTP requests remain independent. Which mechanism explains this?
Answer: The browser returns a cookie identifying a session, and the application associates that session with cart state. Application state can persist even though HTTP does not require remembering earlier requests.

Question: A cache has a stored object, sends If-Modified-Since, and receives 304. Should it expect a fresh object body?
Answer: No. It should reuse its stored representation. The response validates the cached copy without sending the object again.

Question: A small image waits behind a large response in HTTP/1.1 pipelining. What feature helps in HTTP/2, and what limitation remains?
Answer: HTTP/2 can interleave frames from separate streams so the small response progresses earlier. If a TCP segment is lost, however, the connection's ordered byte-stream delivery can still stall multiple streams.

Question: An email has reached Bob's mailbox, but he has not opened it. Which protocols serve these two stages?
Answer: SMTP serves message transfer toward Bob's mail server. POP3, IMAP, or an HTTP/HTTPS Webmail interface serves Bob's access to the stored message. Delivery and reading are separate events.
