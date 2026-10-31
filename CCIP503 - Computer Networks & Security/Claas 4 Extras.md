# Comprehensive Study Notes: Application Layer

CCIP503 – Computer Networks & Security | Week 4

Kadir Has University — Assist. Prof. Dr. İlktan AR

Based on the complete 56-page lecture, W04 – Application Layer.

## Overview of the lecture

This lecture covers three major topics within the Application Layer of computer networks:

1. Domain Name System (DNS): How computers translate human-readable domain names into IP addresses, how DNS servers cooperate, how DNS caching works, and how DNS can be attacked.
2. Peer-to-Peer (P2P) Applications: How computers exchange resources without relying entirely on central servers, why P2P can scale efficiently, and how BitTorrent operates.
3. Video Streaming and Content Distribution Networks (CDNs): How video travels across networks, why buffering happens, how adaptive streaming works, and how CDNs deliver video efficiently to millions of users.

The lecture also briefly introduces the next topic: the Transport Layer and Wireshark.

The central theme connecting these topics is how application-layer systems use distributed infrastructure to provide efficient, scalable, and reliable Internet services.

# Part 1 — Domain Name System (DNS)

Lecture pages 4–23

## 1.1 Introduction: Hostnames and IP addresses

Every device participating in Internet communication needs a way to be identified and located.

The lecture introduces two important forms of identification.

Hostnames are human-readable identifiers such as:

- `www.google.com`
- `www.facebook.com`
- `gaia.cs.umass.edu`

They are called mnemonic identifiers because they are easier for people to recognize and remember than numerical addresses.

IP addresses are numerical identifiers used in Internet communication and routing.

An example from the lecture is:

`121.7.106.83`

This is an IPv4 address consisting of four numbers (octets), each between 0 and 255. Each octet represents 8 bits, giving IPv4 a total of 32 bits.

An IPv4 address is hierarchical: its network-prefix and host portions help identify the network and the particular interface. The exact boundary depends on its prefix length or subnet mask.

### Why are both needed?

Humans prefer names, but network routers use IP addresses to forward packets.

Suppose you want to visit `www.google.com`.

You type the hostname into your browser, but the computer needs an IP address to contact the destination server.

This creates the fundamental problem:

How can we translate a hostname into an IP address and, where necessary, an IP address back into a hostname?

The Domain Name System solves this problem.

## 1.2 What is DNS?

DNS stands for Domain Name System.

It is an Internet directory service whose main purpose is to translate domain names and hostnames into IP addresses.

A useful analogy is a telephone directory:

| Telephone directory  | DNS                 |
| -------------------- | ------------------- |
| Person's name        | Domain or hostname  |
| Phone number         | IP address          |
| Looking up a contact | DNS query           |
| Directory entry      | DNS resource record |

DNS is more than a simple lookup table. The lecture defines it in two ways:

1. A distributed database implemented through a hierarchy of DNS servers.
2. An application-layer protocol through which hosts query this database.

Because DNS is distributed, its information is spread across many independently managed servers rather than being kept in one global machine.

The lecture also mentions BIND (Berkeley Internet Name Domain), widely used DNS server software historically associated with UNIX systems.

## 1.3 DNS as an application-layer protocol

DNS belongs to the Application Layer, alongside protocols such as HTTP, FTP, and SMTP.

The lecture specifies that DNS commonly uses:

Transport protocol

# UDP

Port number

# 53

A useful clarification is that DNS also uses TCP port 53 when appropriate, including certain large responses and zone transfers. Modern encrypted DNS mechanisms exist as well, but the lecture focuses on traditional DNS.

### Example: Loading a website

Suppose a user enters:

`www.someschool.edu/index.html`

The sequence is:

1. The browser identifies `www.someschool.edu` as the hostname.
2. The system looks for the corresponding IP address, using its configured DNS resolver if necessary.
3. DNS returns the relevant address record.
4. The browser establishes a network connection to the address.
5. The browser sends an HTTP request for `/index.html`.
6. The server responds with the webpage content.

Important: DNS does not download the webpage. It returns information needed to locate the server.

A DNS lookup can therefore succeed even when the website itself is inaccessible, for example, if the web server is offline or its HTTPS port is blocked.

## 1.4 Services provided by DNS

The lecture identifies four major DNS services.

### A. Hostname-to-IP-address translation

This is DNS's primary function.

For example, a DNS A record might indicate:

`www.example.com → 192.0.2.10`

The browser uses the resulting address to contact the destination.

### B. Host aliasing

A host can have a canonical name and one or more aliases.

The lecture gives a conceptual example:

- Canonical hostname: `relay1.west-coast.enterprise.com`
- Aliases: `enterprise.com`, `www.enterprise.com`

A canonical hostname is the underlying or official hostname; aliases provide alternative names.

An actual CNAME record maps one name to another name, rather than directly mapping it to an IP address.

### C. Mail server aliasing

DNS helps identify servers responsible for receiving email for a particular domain.

For example, an organization may use:

`company.com`

for its website and email addresses, but receive email through:

`mail.company.com`

MX records identify mail-exchange servers associated with a domain.

### D. Load distribution

A hostname may correspond to multiple IP addresses.

For example:

```
www.example.com
    |
    +-- 192.0.2.10
    +-- 192.0.2.11
    +-- 192.0.2.12
```

These addresses may belong to replicated web servers.

DNS responses can help distribute client requests across servers, potentially improving availability and reducing the load placed on any single machine.

DNS-based distribution does not, by itself, guarantee that a server is healthy or that traffic is evenly balanced.

## 1.5 Why DNS is not centralized

The lecture asks an important question:

Why don't we use one large DNS server containing all domain names?

There are four major reasons.

| Problem                 | Explanation                                                                                 |
| ----------------------- | ------------------------------------------------------------------------------------------- |
| Single point of failure | Failure of the central server could disrupt name resolution globally.                       |
| High traffic volume     | An enormous number of DNS requests would overload the server and its network links.         |
| Geographic distance     | Users far from the server would experience longer lookup delays.                            |
| Maintenance             | Keeping records for all Internet domains current in one place would be extremely difficult. |

The lecture provides historical workload examples from Comcast and Akamai to demonstrate the enormous scale of DNS traffic.

The conclusion is that centralized DNS would not scale well.

Instead, DNS uses a distributed, hierarchical architecture.

## 1.6 DNS hierarchy: Root, TLD and authoritative servers

One of the most important concepts in this lecture is the DNS hierarchy.

Simplified DNS hierarchy

### Level 1: Root DNS servers

Root servers sit at the top of the DNS hierarchy.

They know which name servers are responsible for top-level domains such as `.com`, `.org`, and `.edu`.

The lecture emphasizes that there are 13 logical root server identities, replicated across many physical machines worldwide.

This distinction is important: 13 logical identities do not mean only 13 physical computers.

The lecture's geographic deployment numbers are historical, based on a 2016 illustration.

Root DNS infrastructure is coordinated through the DNS root-zone management system, with ICANN performing an important coordinating role.

Root servers generally provide referrals rather than directly resolving arbitrary website hostnames.

### Level 2: Top-Level Domain (TLD) servers

TLD servers manage delegation information for top-level domains.

Examples include generic TLDs:

- `.com`
- `.org`
- `.net`
- `.edu`
- `.aero`
- `.jobs`
- `.museum`

And country-code TLDs:

- `.cn` — China
- `.uk` — United Kingdom
- `.fr` — France
- `.ca` — Canada
- `.jp` — Japan

For example, the `.com` TLD servers can identify which authoritative servers are responsible for `amazon.com`.

### Level 3: Authoritative DNS servers

Authoritative servers provide DNS records for the zones they serve.

These servers may be operated directly by an organization or by a third-party DNS hosting provider.

For example, authoritative servers for `example.com` may provide:

```
www.example.com  A   192.0.2.10
mail.example.com A   192.0.2.20
```

These are illustrative addresses.

### Understanding delegation

The distinction between each level is:

- Root: "Here are the name servers for `.com`."
- TLD: "Here are the authoritative name servers for `example.com`."
- Authoritative: "Here is the requested record for `www.example.com`."

This delegation structure makes it possible for different organizations to manage their DNS data independently.

## 1.7 Local DNS servers

The local DNS server, also called a default name server or recursive resolver in typical configurations, is the server a user's device consults for DNS resolution.

The lecture notes that this server is not strictly part of the root–TLD–authoritative hierarchy.

It acts as an intermediary between the requesting host and the DNS system.

Its primary responsibilities are:

- Receiving DNS queries from clients.
- Returning answers from cache, when available.
- Performing or forwarding DNS resolution when necessary.
- Caching DNS responses to speed up subsequent lookups.

Local DNS resolvers may be provided by ISPs, organizations, or public DNS providers.

### How to check your DNS configuration

The lecture provides these commands:

For Windows:

```
ipconfig /all
```

For macOS:

```
scutil --dns
```

The output identifies configured DNS servers, among other network details.

## 1.8 Complete DNS resolution walkthrough

The lecture presents the process from entering a URL to connecting to a server.

Here is a detailed version using `www.amazon.com` as the example.

1. Browser cache

   The browser checks whether it already has a usable DNS result for the hostname.
2. Stub resolver

   If necessary, the device's resolver sends a query to its configured recursive DNS resolver. Local system caches may also be consulted.
3. Recursive resolver cache

   If the resolver has a valid cached answer, it can return it immediately.
4. Root server referral

   On a cache miss, the resolver can query a root server to locate the `.com` TLD name servers.
5. TLD server referral

   The resolver queries a `.com` server, which identifies authoritative servers for `amazon.com`.
6. Authoritative answer

   The resolver requests the appropriate record from an authoritative server and returns the result to the requesting host.
7. Connect to the service

   The browser uses the resolved address to connect to the web service. DNS resolution ends before the actual webpage retrieval.

The full hierarchy traversal is not required for every query because caches can answer much earlier.

## 1.9 Iterative versus recursive DNS queries

This is an especially important examination topic.

The lecture uses a university example: a host at `engineering.nyu.edu` needs the IP address of `gaia.cs.umass.edu`.

### Iterative query

In iterative resolution, each queried server either provides an answer or directs the requester to another server.

A typical exchange is:

1. The local resolver asks a root server.
2. Root replies with a referral to a TLD server.
3. The local resolver asks the TLD server.
4. The TLD replies with an authoritative-server referral.
5. The local resolver asks the authoritative server.
6. The authoritative server returns the requested DNS data.
7. The local resolver returns the answer to the client.

The key feature is that the resolver follows referrals itself.

### Recursive query

In recursive resolution, the contacted resolver is asked to take responsibility for obtaining the final answer or an appropriate error.

The lecture illustrates the recursive style by showing requests forwarded through successive DNS servers and the responses returned back through that chain.

The diagram raises the concern that performing recursive work at upper levels of the DNS hierarchy could create substantial load.

In common real-world DNS operation, the user's device asks a recursive resolver to perform resolution, while that resolver typically uses iterative queries when communicating with root, TLD, and authoritative servers.

| Characteristic          | Iterative query                      | Recursive query                                     |
| ----------------------- | ------------------------------------ | --------------------------------------------------- |
| Server's responsibility | Answer or provide a referral         | Obtain a final result on behalf of the requester    |
| Who follows referrals?  | Requesting resolver                  | Server accepting recursion                          |
| Typical use             | Resolver querying DNS hierarchy      | Client querying configured recursive resolver       |
| Main concern            | Requester performs more lookup steps | Recursive server needs resources to process queries |

Memory aid: Iterative means "ask the next server yourself." Recursive means "resolve this for me."

## 1.10 DNS caching and TTL

DNS caching is essential to Internet performance.

Without caching, an enormous number of lookups would repeatedly traverse the DNS hierarchy.

When a DNS resolver obtains a record, it may store it temporarily.

If another client requests the same information, the resolver can respond from cache.

### Benefits of caching

- Faster DNS resolution.
- Fewer DNS messages.
- Less traffic reaching root and authoritative servers.
- Reduced demand on DNS infrastructure.
- Better overall scalability.

### Time To Live (TTL)

TTL determines how long a cached DNS record may remain valid.

Suppose an A record has:

```
www.example.com
Address: 192.0.2.10
TTL: 3600 seconds
```

A TTL of 3,600 seconds means the record can ordinarily be cached for up to one hour from the time that TTL is assigned, subject to resolver behavior.

If the authoritative record changes to `192.0.2.11`, clients using an unexpired cached answer may still connect to the old address.

This explains why DNS updates can appear inconsistent across different networks.

The lecture describes DNS resolution as best-effort because caches may temporarily contain outdated information.

### Example: Migrating a website

A company moves its web server from `192.0.2.10` to `192.0.2.11`.

Users whose DNS caches have expired may obtain the new address immediately. Other users may continue using the old address until their cached records expire.

This is why administrators often reduce DNS TTLs ahead of planned migrations.

## 1.11 DNS resource records

DNS stores data as resource records (RRs).

The lecture introduces the general record structure:

\\[ RR = (name,\ value,\ type,\ TTL) \\]

Here:

- `name` identifies the domain or hostname associated with the record.
- `value` contains the record's information.
- `type` identifies what the record represents.
- `TTL` determines its caching lifetime.

### Important DNS record types

| Type  | Purpose                                                     | Example                                 |
| ----- | ----------------------------------------------------------- | --------------------------------------- |
| A     | Maps a hostname to an IPv4 address                          | `www.example.com → 192.0.2.10`          |
| AAAA  | Maps a hostname to an IPv6 address                          | `www.example.com → 2001:db8::10`        |
| NS    | Identifies authoritative name servers                       | `example.com → ns1.example.com`         |
| CNAME | Maps an alias to a canonical hostname                       | `shop.example.com → stores.example.net` |
| MX    | Identifies email-exchange servers and their preference      | `example.com → mail.example.com`        |
| TXT   | Holds text such as verification or email-policy information | SPF-related policy text                 |
| PTR   | Maps an address to a hostname in reverse DNS                | `192.0.2.10 → host.example.com`         |
| SRV   | Identifies hostnames and ports providing services           | A service target with port 5060         |

The addresses and domain names in these examples are illustrative.

### Understanding key records in more detail

A and AAAA records: Both specify network addresses. A records use IPv4; AAAA records use IPv6. A hostname can have both types.

CNAME records: Rather than storing an IP address, a CNAME redirects DNS lookup to another hostname. The resolver must then resolve the target name.

NS records: These identify name servers responsible for a DNS zone and are essential for delegation.

MX records: Mail delivery systems use MX records to locate mail servers. MX records also contain preference values; lower numerical preferences are generally attempted first.

TXT records: These are frequently used for domain verification and email authentication policies.

PTR records: These support reverse DNS lookups, where a known IP address is used to discover its associated hostname.

SRV records: These advertise the server and port associated with a particular service. This is useful for protocols that need service discovery.

## 1.12 DNS message structure

The lecture explains that DNS queries and responses share the same general message format.

A DNS message contains:

Header

Identification

Flags

Question count

Answer count

Authority count

Additional count

Question section

Requested name and record type

Answer section

Records answering the query

Authority section

Authority-related records

Additional section

Helpful supplementary records

### Header fields

The identification field is a 16-bit transaction ID used to associate a response with its query.

The flags contain information including:

- Whether the message is a query or response.
- Whether recursion is desired.
- Whether recursion is available.
- Whether the response is authoritative.

The header also includes counts for the question, answer, authority and additional sections.

### Example

A client requests the A record for `www.example.com`.

The question section contains the hostname and record type A.

The answer section may contain the corresponding IPv4 address.

The authority section can contain information about relevant name servers, while the additional section may provide supplementary records that help the resolver.

## 1.13 Registering a domain and inserting DNS records

The lecture uses a fictional startup called Network Utopia.

The company wishes to register:

`networkuptopia.com`

The overall process is:

1. Register the domain through a domain registrar.
2. Specify the authoritative name servers.
3. Configure the authoritative DNS zone.
4. Create appropriate DNS records for web and other services.
5. Ensure the domain's delegation points to the correct name servers.

The lecture illustrates the following records:

```
networkuptopia.com      NS  dns1.networkuptopia.com
dns1.networkuptopia.com  A   212.212.212.1
```

The second record is an example of the address information needed to locate an in-domain name server, often supplied as glue information in the parent zone.

The company's authoritative DNS server also needs records for its website, such as an A record for `www.networkuptopia.com`.

This demonstrates how domain registration, TLD delegation, and authoritative DNS configuration work together.

## 1.14 DNS security threats

The lecture discusses four failure modes.

### A. DNS cache poisoning

An attacker attempts to insert fraudulent DNS information into a resolver's cache.

For example:

```
www.bank.example
     ↓
Attacker-controlled IP address
```

A victim might be directed to an impersonating website instead of the legitimate service.

Defenses described in the lecture include stronger DNS transaction matching, randomized source ports, and DNSSEC validation.

### B. DNS hijacking

DNS hijacking occurs when DNS resolution behavior is changed without authorization.

Possible targets include:

- Resolver configuration.
- Registrar accounts.
- Authoritative DNS zones.

For example, an attacker gaining access to a domain's DNS management account could alter its A records and redirect users.

### C. Typosquatting

Typosquatting uses misleading domain names resembling legitimate websites.

For example, a visually similar or misspelled domain might lead users to an attacker-controlled site.

DNS may resolve such a domain correctly from a technical perspective, but that does not make the destination trustworthy.

This is an important distinction between correct name resolution and legitimate website identity.

### D. Availability attacks

Attackers may flood recursive resolvers or authoritative servers with traffic, preventing legitimate DNS queries from being answered.

Possible defenses include redundancy, rate limiting, monitoring and resilient DNS delegation.

### DNSSEC

The lecture also introduces DNSSEC, which provides cryptographic authentication and integrity checking for DNS data.

DNSSEC can help clients validate that certain DNS records have not been altered during resolution. It does not encrypt ordinary DNS queries, and it does not guarantee that the destination website is safe.

### DNS section recap

You should now understand that DNS is a distributed application-layer system that translates names into records, uses hierarchical delegation, relies heavily on caching, and requires safeguards against manipulation and disruption.

# Part 2 — Peer-to-Peer (P2P) Applications

Lecture pages 26–41

## 2.1 Introduction to P2P architecture

The first section focused on DNS, which relies on a distributed hierarchy of servers. This section introduces another important form of distributed system: Peer-to-Peer (P2P) networking.

The lecture begins by contrasting P2P systems with conventional client-server systems.

In client-server applications, clients generally communicate with always-available servers that provide services or resources.

Examples include websites, email systems, and many centralized file-hosting platforms.

In P2P systems, devices called peers can communicate directly with other peers, exchanging resources without necessarily depending on a central server for every operation.

The main idea is:

A peer can be both a consumer and a provider of resources.

For example, a computer downloading a file from another computer may simultaneously upload already-downloaded parts of that file to a third computer.

This differs from traditional client-server networking, in which the server is normally responsible for distributing the requested content.

## 2.2 Client-server versus P2P architecture

Client-server

The server provides resources to clients.

Peer-to-peer

Peers exchange resources with one another.

| Characteristic    | Client-server                  | P2P                                             |
| ----------------- | ------------------------------ | ----------------------------------------------- |
| Central server    | Typically essential            | May be limited or unnecessary for data exchange |
| Communication     | Primarily client to server     | Peer to peer                                    |
| Resource provider | Server                         | Multiple peers                                  |
| Upload capacity   | Primarily supplied by server   | Supplied by server and peers                    |
| Scalability       | Server may become a bottleneck | New peers can increase capacity                 |
| Availability      | Depends heavily on server      | Depends on peer and discovery availability      |
| Management        | More centralized               | Often more complex                              |

## 2.3 Key characteristics of P2P systems

The lecture identifies several important features.

### A. Direct peer communication

Devices can communicate directly to exchange content.

For example, Peer A can download a portion of a file from Peer B, while Peer B downloads another portion from Peer C.

### B. Self-scalability

One of the most important advantages of P2P systems is self-scalability.

When a new peer joins:

- It increases demand because it wants the file.
- It can also increase supply by contributing its upload capacity.

This differs from traditional client-server distribution, where adding clients generally increases demand without increasing the server's capacity.

### C. Intermittent availability

Peers are not necessarily connected continuously.

A peer may:

- Disconnect unexpectedly.
- Change its IP address.
- Have limited upload bandwidth.
- Join or leave at any time.

Therefore, P2P systems need mechanisms for discovering participants and adapting when peers disappear.

### D. Management complexity

Because peers can join and leave unpredictably, the system must coordinate resource discovery and sharing.

P2P networking also encounters connectivity problems caused by NAT devices, firewalls, and inconsistent peer availability.

The lecture identifies BitTorrent file sharing, KanKan streaming and Skype VoIP as examples associated with P2P architectures.

These are examples from the lecture's historical context, not necessarily descriptions of their current architectures.

## 2.4 File distribution: The central performance problem

The lecture asks:

How long does it take to distribute a file of size F from one server to N peers?

This problem is examined using mathematical models of client-server and P2P distribution.

First, we define the symbols.

| Symbol          | Meaning                                         |
| --------------- | ----------------------------------------------- |
| \\(F\\)         | File size, in bits                              |
| \\(N\\)         | Number of peers receiving the file              |
| \\(u_s\\)       | Server upload rate, in bits per second          |
| \\(u_i\\)       | Upload rate of peer \\(i\\)                     |
| \\(d_i\\)       | Download rate of peer \\(i\\)                   |
| \\(d\_{\min}\\) | Minimum download rate among all receiving peers |
| \\(D\_{CS}\\)   | Client-server distribution time                 |
| \\(D\_{P2P}\\)  | P2P distribution time                           |

The model assumes that the underlying network has sufficient capacity so that the specified upload and download rates are the main bottlenecks.

The times calculated are theoretical lower bounds. Real systems can take longer due to overhead, congestion and other limitations.

## 2.5 Client-server file distribution time

In a client-server system, the server must transmit a separate copy of the file to every client.

Suppose:

- The file contains \\(F\\) bits.
- There are \\(N\\) clients.
- The server upload capacity is \\(u_s\\).

The server must upload a total of:

\\[ NF\text{ bits} \\]

The minimum time for that transmission is:

\\[ \frac{NF}{u_s} \\]

There is also a download limitation: every client must receive the whole file.

The slowest client has download rate \\(d\_{\min}\\), so it needs at least:

\\[ \frac{F}{d\_{\min}} \\]

Therefore, the client-server minimum distribution time obeys:

\\[ \boxed{D\_{CS}\geq \max\left(\frac{NF}{u_s},\frac{F}{d\_{\min}}\right)} \\]

### Understanding the maximum function

There are two constraints:

1. The server must transmit enough data for all clients.
2. Even the slowest client must completely receive the file.

The entire distribution cannot finish until both constraints are satisfied.

Therefore, the minimum possible time must be at least the larger of the two values.

### Worked example

Suppose:

- File size \\(F=100\\) MB = 800 Mb.
- Number of clients \\(N=10\\).
- Server upload rate \\(u_s=20\\) Mbps.
- Slowest client download rate \\(d\_{\min}=10\\) Mbps.

Server constraint:

\\[ \frac{NF}{u_s} =\frac{10\times800}{20} =400\text{ seconds} \\]

Slowest-client constraint:

\\[ \frac{F}{d\_{\min}} =\frac{800}{10} =80\text{ seconds} \\]

Therefore:

\\[ D\_{CS}\geq\max(400,80)=400\text{ seconds} \\]

Minimum distribution time: 6 minutes 40 seconds.

The server upload capacity is the dominant bottleneck.

### What happens as N increases?

Holding the server capacity constant:

\\[ \frac{NF}{u_s}\propto N \\]

This means the server's total upload requirement grows linearly with the number of clients.

If the number of clients doubles, the server must upload twice as much data.

This explains why a single centralized server can become inefficient when distributing large files to many users.

## 2.6 P2P file distribution time

P2P distribution changes the situation because peers contribute upload bandwidth.

The server no longer needs to upload a full separate copy to every peer.

Once parts of the file enter the peer community, peers can redistribute them to one another.

The lecture identifies three important constraints.

### Constraint 1: The server must upload at least one full copy

Initially, only the server has the complete file.

For every bit to become available somewhere in the peer community, the server must upload at least \\(F\\) bits.

Therefore:

\\[ D\_{P2P}\geq\frac{F}{u_s} \\]

### Constraint 2: Every peer must download a copy

The slowest peer must still receive the entire file.

Therefore:

\\[ D\_{P2P}\geq\frac{F}{d\_{\min}} \\]

### Constraint 3: Total system upload capacity

All N peers collectively need:

\\[ NF\text{ bits} \\]

Unlike client-server distribution, the available upload capacity includes the server and all participating peers:

\\[ u\_{\text{total}}=u_s+\sum\_{i=1}^{N}u_i \\]

Therefore:

\\[ D\_{P2P}\geq\frac{NF}{u_s+\sum\_{i=1}^{N}u_i} \\]

Combining the three constraints:

\\[ \boxed{ D\_{P2P}\geq \max\left( \frac{F}{u_s}, \frac{F}{d\_{\min}}, \frac{NF}{u_s+\sum\_{i=1}^{N}u_i} \right) } \\]

This is one of the most important formulas in the lecture.

### Worked example using the same file

Suppose:

- \\(F=800\\) Mb.
- \\(N=10\\).
- \\(u_s=20\\) Mbps.
- Every peer uploads at \\(u_i=5\\) Mbps.
- \\(d\_{\min}=10\\) Mbps.

Constraint 1:

\\[ \frac{800}{20}=40\text{ s} \\]

Constraint 2:

\\[ \frac{800}{10}=80\text{ s} \\]

Constraint 3:

Total upload rate:

\\[ u\_{\text{total}}=20+(10\times5)=70\text{ Mbps} \\]

Thus:

\\[ \frac{NF}{u\_{\text{total}}} =\frac{8000}{70} \approx114.3\text{ s} \\]

So:

\\[ D\_{P2P}\geq\max(40,80,114.3) \\]

Minimum distribution-time lower bound: approximately 1 minute 54 seconds.

Compare this with the client-server lower bound of 6 minutes 40 seconds.

P2P offers a much smaller lower bound in this example because the peers contribute to distribution.

Important clarification: This comparison is between theoretical lower bounds, not a guarantee of actual completion times.

## 2.7 Visual comparison of client-server and P2P scaling

The lecture's graph on page 32 uses the following assumptions:

- All peers have the same upload rate \\(u\\).
- \\(F/u=1\\) hour.
- The server upload rate \\(u_s=10u\\).
- The minimum client download rate \\(d\_{\min}\geq u_s\\).

Under these assumptions, the client-server lower bound becomes:

\\[ D\_{CS}=\frac{N}{10}\text{ hours} \\]

And the P2P lower bound becomes:

\\[ D\_{P2P}= \max\left( 0.1,\frac{N}{10+N} \right)\text{ hours} \\]

Minimum distribution time vs. number of peers

Reconstructed from the lecture's page 32 assumptions. Values are theoretical lower bounds.

Client-serverP2P

0 hours0.85 hours1.7 hours2.55 hours3.4 hours151015202530

### Interpretation

For 10 peers:

- Client-server: at least 1 hour.
- P2P: at least 0.5 hour.

For 30 peers:

- Client-server: at least 3 hours.
- P2P: at least 0.75 hour.

The client-server time grows linearly.

The P2P time grows much more slowly because every additional peer also supplies upload capacity.

As \\(N\\) becomes very large, with the lecture's assumptions:

\\[ \frac{N}{10+N}\longrightarrow1 \\]

Therefore, the P2P lower bound approaches approximately one hour rather than increasing without limit.

This illustrates self-scalability mathematically.

### Important limitation

Actual P2P performance still depends on available peers, connection speeds, protocol overhead, chunk availability and whether peers cooperate.

The mathematical model demonstrates potential scalability, not guaranteed real-world speed.

# Part 2B — BitTorrent

## 2.8 What is BitTorrent?

BitTorrent is a P2P file-distribution protocol originally developed by Bram Cohen.

Rather than downloading a complete file from one server, users download pieces from multiple peers.

The lecture describes BitTorrent as an important example of P2P file sharing.

### Key terms

Torrent: The collection of peers participating in the distribution of a particular file or set of files.

Peer: A device participating in the torrent by downloading or uploading data.

Chunk/piece: A portion of the file that can be distributed independently.

Tracker: A coordination service that helps peers discover other peers.

Seeder: A peer that has all the content and makes it available to others.

Leecher: A peer that is still downloading content. The term does not necessarily mean the peer refuses to upload.

The lecture uses a typical piece size of 256 KB as a historical example. Actual BitTorrent piece sizes vary.

## 2.9 Why does BitTorrent divide files into chunks?

Consider a 1 GB file.

Downloading it from one computer would make the transfer depend heavily on that computer's upload performance.

Instead, BitTorrent divides the file into many pieces.

For illustration, a 1,024 MiB file divided into 256 KiB pieces produces:

\\[ \frac{1024\times1024}{256}=4096\text{ pieces} \\]

Different peers can possess different pieces.

For example:

| Peer   | Pieces held |
| ------ | ----------- |
| Alice  | 1, 2, 5     |
| Bob    | 3, 4, 7     |
| Carol  | 1, 6, 8     |
| Daniel | 2, 3, 5, 6  |

Alice can request piece 3 from Bob while requesting piece 6 from Carol.

Once Alice receives piece 6, she can upload it to Daniel or another peer.

Thus, peers can exchange content simultaneously.

This reduces the need for the original source to deliver every piece repeatedly.

## 2.10 How a peer joins a torrent

The lecture describes Alice joining a torrent.

1. Discover the torrent. Alice obtains the torrent identity using a torrent file or magnet link.
2. Find peers. Alice contacts a tracker, uses DHT, or uses other available discovery information.
3. Connect to neighbors. Alice establishes connections with a subset of discovered peers.
4. Identify available pieces. Connected peers exchange information about the pieces they possess.
5. Download and upload. Alice requests missing pieces while uploading available pieces to other peers.
6. Complete the download. After obtaining all pieces, Alice may disconnect or continue seeding.

A peer's neighbors can change over time.

If one peer disconnects, Alice can discover and connect to other participants.

## 2.11 The two important decisions in BitTorrent

The lecture emphasizes that BitTorrent's efficiency depends on two questions:

1. Which chunks should a peer request first?
2. Which other peers should receive upload capacity?

BitTorrent addresses these using rarest-first and tit-for-tat strategies.

## 2.12 Rarest-first chunk selection

The rarest-first strategy prioritizes missing pieces that are least common among a peer's connected neighbors.

### Example

Suppose Alice needs four pieces:

| Missing piece | Number of neighbors possessing it |
| ------------- | --------------------------------- |
| A             | 8                                 |
| B             | 5                                 |
| C             | 2                                 |
| D             | 1                                 |

Alice should prioritize piece D because only one neighbor currently has it.

### Why?

If the only peer possessing piece D disconnects, that piece might become unavailable within Alice's current neighborhood.

By downloading rare pieces earlier, Alice helps reduce the risk that they become bottlenecks later.

Once Alice has piece D, she can upload it to other peers, increasing its availability.

The strategy therefore improves the distribution of scarce pieces throughout the swarm.

Key principle: Rarest-first protects availability, not merely download speed.

## 2.13 Tit-for-tat: Deciding whom to upload to

The next problem is deciding which peers deserve upload capacity.

Because upload bandwidth is limited, Alice cannot necessarily serve everyone simultaneously.

The lecture describes a tit-for-tat strategy:

- Alice gives priority to four peers currently uploading data to her at the highest rates.
- Other interested peers may be temporarily choked, meaning Alice does not upload pieces to them.
- Alice reevaluates her preferred peers every 10 seconds.
- Every 30 seconds, she randomly selects another peer to unchoke.

These timings describe the classical algorithm presented in the lecture; implementations may differ.

### Why does this encourage cooperation?

Suppose Bob uploads pieces to Alice at a high rate.

Alice rewards Bob by uploading pieces to him.

Both peers benefit from the exchange.

A peer that contributes little may receive less preferential upload service.

This encourages reciprocal sharing instead of relying entirely on a small number of generous participants.

## 2.14 Optimistic unchoking

A challenge with tit-for-tat is that new peers may have nothing to upload.

If everybody serves only their best existing trading partners, new participants might struggle to join effective exchanges.

BitTorrent addresses this through optimistic unchoking.

### Example from the lecture

1. Alice randomly unchokes Bob.
2. Alice begins uploading pieces to Bob.
3. Bob starts reciprocating and uploads to Alice.
4. Alice becomes one of Bob's preferred providers.
5. Bob becomes one of Alice's preferred providers.

This can establish a productive relationship that neither peer would have discovered through existing preferred connections.

Optimistic unchoking also allows peers to discover better upload partners.

### Rarest-first versus tit-for-tat

| Mechanism            | Main question                                     | Purpose                                                     |
| -------------------- | ------------------------------------------------- | ----------------------------------------------------------- |
| Rarest-first         | Which piece should I download?                    | Improve piece availability and avoid rare-piece bottlenecks |
| Tit-for-tat          | Whom should I upload to?                          | Reward useful contributors                                  |
| Optimistic unchoking | Which additional peer should I temporarily serve? | Help new participants and discover better trading partners  |

These three mechanisms are central to understanding classical BitTorrent performance.

## 2.15 Why BitTorrent is efficient

The lecture emphasizes that BitTorrent's efficiency comes from more than splitting files into pieces.

It also depends on:

- Sharing pieces among participants instead of repeatedly relying on the original source.
- Prioritizing rare pieces.
- Encouraging peers to upload through reciprocal incentives.
- Finding useful trading partners.
- Using the aggregate upload capacity of the swarm.

Simply dividing a file into chunks would not automatically produce these advantages.

The scheduling and peer-selection strategies matter.

## 2.16 Tracker, DHT and Peer Exchange

BitTorrent must enable peers to discover one another.

The lecture introduces three mechanisms.

### A. Tracker

A tracker is a coordination service.

Its primary role is to tell participants about other peers in the same torrent.

A tracker generally does not store the actual file pieces.

For example, Alice contacts a tracker and receives information about Bob, Carol and Daniel, who are participating in the same swarm.

Alice can then attempt to connect to them.

### B. Distributed Hash Table (DHT)

A DHT allows peers to discover other peers without depending on one central tracker.

The lecture specifies that BitTorrent's DHT peer-discovery mechanism uses UDP.

The main benefit is reducing dependence on centralized peer-discovery infrastructure.

### C. Peer Exchange (PEX)

Through PEX, connected peers exchange information about additional participants.

For example:

- Alice knows Bob.
- Bob knows Carol.
- Bob informs Alice about Carol.
- Alice can attempt to connect to Carol.

This expands the peer-discovery process.

### Comparison

| Discovery method | How it works                                           | Main benefit                                   |
| ---------------- | ------------------------------------------------------ | ---------------------------------------------- |
| Tracker          | Central coordination service supplies peer information | Straightforward discovery                      |
| DHT              | Distributed peer lookup                                | Less dependency on a single tracker            |
| PEX              | Connected peers share known peer information           | Expands discovery through existing connections |

The lecture cautions that trackerless discovery does not automatically guarantee availability.

A torrent still depends on usable metadata, reachable peers and actual content availability.

## 2.17 Magnet links and infohashes

The lecture provides a practical example of Alice downloading a Linux distribution through a magnet link.

A magnet link contains information identifying the torrent, notably an infohash.

The infohash is derived from the torrent's metadata and identifies the torrent.

If Alice has only the magnet link, her client may still need to acquire additional torrent metadata before it can determine which files and pieces to download.

### Complete example

Suppose Alice wants to download a Linux ISO.

1. She opens a magnet link in her BitTorrent client.
2. The client reads the infohash.
3. It uses available discovery mechanisms to find peers.
4. It may retrieve the necessary torrent metadata.
5. It discovers which peers possess different pieces.
6. It downloads pieces from several peers.
7. It uploads pieces to other participants while downloading.
8. Once all pieces are present and verified, the download completes.
9. Alice may remain connected as a seeder.

This example connects every major concept in the P2P section: peer discovery, metadata, chunks, uploading, downloading and cooperation.

### P2P section recap

The essential lesson is that P2P systems distribute work across participants. They can scale efficiently because peers contribute capacity as they join, but they require mechanisms to manage changing peers, discover resources and coordinate sharing.

BitTorrent demonstrates this using chunk-based distribution, rarest-first scheduling, tit-for-tat incentives, optimistic unchoking and multiple peer-discovery methods.

# Part 3 — Video Streaming and Content Distribution Networks (CDNs)

Lecture pages 43–54

## 3.1 Introduction: Why video streaming is challenging

Video streaming is one of the most demanding applications on the Internet because video files can be extremely large and must be delivered continuously.

The lecture identifies two main challenges:

Scale: Delivering videos to extremely large numbers of users simultaneously.

Heterogeneity: Different users have different devices, networks, connection speeds and network conditions.

For example, one person might watch a movie using a high-speed fiber connection, while another watches the same movie on a mobile phone with a weak wireless connection.

Both users expect smooth playback.

The system must adapt to these differences.

### Video traffic and bandwidth requirements

The lecture provides the following illustrative bitrate values:

| Video type                   | Approximate bitrate in the lecture |
| ---------------------------- | ---------------------------------- |
| Low-quality compressed video | 100 kbps                           |
| High-definition streaming    | Over 3 Mbps                        |
| 4K video                     | Over 10 Mbps                       |

These are indicative values from the lecture, not fixed requirements for every video. Modern codecs can produce different quality levels at different bitrates.

The lecture also notes that major streaming services historically accounted for a significant proportion of residential Internet traffic, illustrating why video delivery requires scalable infrastructure.

## 3.2 Understanding bitrate

Bitrate is the amount of data needed to represent or transmit media per unit of time.

It is usually measured in bits per second:

- kbps: kilobits per second
- Mbps: megabits per second
- Gbps: gigabits per second

A higher bitrate can support higher visual quality, although codec efficiency, resolution, frame rate and compression settings also matter.

The basic relationship between video bitrate, duration and data size is:

\\[ \text{Data size (bits)} = \text{Bitrate (bits/s)}\times\text{Duration (s)} \\]

To convert bits into bytes:

\\[ \text{Bytes}=\frac{\text{Bits}}{8} \\]

### Worked example from the lecture

The lecture states that a 2 Mbps video lasting 67 minutes consumes approximately 1 GB.

Let's verify it.

Duration:

\\[ 67\times60=4020\text{ seconds} \\]

Total number of bits:

\\[ 2,000,000\times4020 =8,040,000,000\text{ bits} \\]

Convert to bytes:

\\[ \frac{8,040,000,000}{8} =1,005,000,000\text{ bytes} \\]

Therefore:

\\[ \boxed{\text{Data size}\approx1.005\text{ GB}} \\]

The lecture's approximation is correct using decimal gigabytes.

This calculation assumes a constant 2 Mbps bitrate and excludes additional protocol overhead.

### Why does bitrate matter?

Suppose a video requires 5 Mbps of sustained download throughput.

If the connection can supply only 2 Mbps for a prolonged period, the player cannot receive data as quickly as it consumes the video.

Without enough previously buffered video, playback will eventually stop.

This creates the need for buffering and adaptive streaming.

## 3.3 Streaming stored video

The lecture first examines a simple scenario:

A video file is stored on a server and transmitted across the Internet to a client.

The basic workflow is:

Video server

Internet

Video client

The server delivers video data while the client receives, buffers and plays it.

Unlike a complete file download, streaming allows playback to begin before the entire file has arrived.

For example, a user watching a 90-minute movie does not have to download all 90 minutes of content before watching the first scene.

The client can play the beginning while the server is still sending later parts.

This is the defining feature of streaming stored video.

## 3.4 Recording, transmission and playback

The lecture's timeline diagram on page 45 distinguishes three processes:

1. The video is recorded or encoded.
2. Video data is transmitted over the network.
3. The client receives and plays the video.

The example uses a frame rate of 30 frames per second.

This means the client should display approximately one frame every:

\\[ \frac{1}{30}\approx0.0333\text{ seconds} \\]

Or 33.3 milliseconds.

To provide smooth playback, frames must become available before they are needed for display.

### Why network delay matters

Suppose frames should play every 33.3 milliseconds, but network packets arrive at unpredictable times.

Some frames may arrive quickly, while others are delayed by congestion.

If the client attempts to play a missing frame before it arrives, playback may pause or degrade.

Therefore, playback timing cannot depend directly on the arrival time of every packet.

This leads to the concept of buffering.

## 3.5 Streaming challenges

The lecture identifies three important problems.

### A. Variable network bandwidth

A user's download throughput is not necessarily constant.

It can change because of:

- Congestion on a home or office network.
- Wireless interference.
- Limited access-network capacity.
- Congestion inside the ISP or Internet core.
- Load on the content server.

For example, a connection might deliver 12 Mbps for several seconds, drop to 2 Mbps during congestion and later recover to 8 Mbps.

If the video requires a constant 5 Mbps, this variation can affect playback.

### B. Packet loss and delay

Packets can be delayed or lost as they travel through the network.

In a reliable transport protocol, lost data may be retransmitted, increasing the time before it becomes available.

This may cause stalls or poor playback performance.

### C. Continuous playback constraint

The lecture calls this the continuous playout constraint.

A video should be played at the correct rate.

For a recorded 30 fps video, playback should ordinarily progress at 30 frames per second rather than speeding up or slowing down according to the network's instantaneous delivery speed.

The network therefore needs to deliver data early enough for the client to maintain the intended timing.

## 3.6 Network jitter

Jitter is variation in network delay.

Suppose three video packets experience these delays:

| Packet   | Network delay |
| -------- | ------------- |
| Packet 1 | 40 ms         |
| Packet 2 | 100 ms        |
| Packet 3 | 55 ms         |

The packets do not experience identical delays.

Even if average network delay is acceptable, these variations can disrupt time-sensitive playback.

The lecture explains that a client-side playout buffer can help compensate for this variability.

## 3.7 Playout buffering

A playout buffer is temporary storage used to hold received media before playback.

Instead of displaying each video frame immediately when it arrives, the client accumulates some data and then begins playback.

### Why buffering works

Suppose the player has already downloaded 10 seconds of video.

If the network becomes slow for 3 seconds, the player can continue playing data already stored in the buffer.

This helps prevent interruptions.

Illustrative playback buffer

Buffered video available

10 seconds

The player has a reserve of downloaded media that can absorb a temporary interruption.

Conceptual model: the slider represents playable video already downloaded, assuming no additional data arrives.

### Buffering introduces a trade-off

Buffering improves reliability, but it can also delay playback.

If the client waits to accumulate more data before starting, the user experiences a longer startup time.

Therefore, streaming systems must balance:

- Smooth playback.
- Startup delay.
- Available bandwidth.
- Buffer capacity.

The lecture also points out that buffering can make live interactions less responsive when it adds significant delay.

## 3.8 Throughput versus playback rate

The lecture distinguishes two important quantities.

Playback rate: The rate at which the player consumes encoded media.

Network throughput: The rate at which the network delivers media data to the player.

These quantities determine whether the buffer grows or shrinks.

Let:

- \\(R_n\\) = network delivery throughput.
- \\(R_p\\) = playback consumption rate.
- \\(B\\) = amount of buffered media data.

A simplified buffer relationship is:

\\[ \frac{dB}{dt}=R_n-R_p \\]

This relationship is an explanatory extension of the lecture's throughput-versus-playback concept.

### Case 1: Throughput exceeds playback rate

Suppose:

\\[ R_n=8\text{ Mbps},\quad R_p=4\text{ Mbps} \\]

The network supplies data faster than playback consumes it.

The buffer grows at approximately:

\\[ 8-4=4\text{ Mbps} \\]

This helps the player prepare for future network slowdowns.

### Case 2: Throughput equals playback rate

Suppose:

\\[ R_n=4\text{ Mbps},\quad R_p=4\text{ Mbps} \\]

The network supplies data at the same average rate as playback consumes it.

The buffer remains approximately stable.

### Case 3: Throughput is below playback rate

Suppose:

\\[ R_n=2\text{ Mbps},\quad R_p=4\text{ Mbps} \\]

The client consumes data faster than the network supplies it.

The buffer shrinks at approximately:

\\[ 4-2=2\text{ Mbps} \\]

If this condition persists, the buffer will eventually become empty.

Playback may then stall.

### Worked example: How long until a buffer empties?

Suppose a player has 20 Mb of buffered video.

The network delivers 2 Mbps while the video consumes 4 Mbps.

The deficit is:

\\[ 4-2=2\text{ Mbps} \\]

The approximate time until the buffer empties is:

\\[ t=\frac{20}{2}=10\text{ seconds} \\]

Thus, the player can continue for approximately 10 seconds before stalling, assuming the rates remain constant.

Important: Average throughput alone is not enough to guarantee smooth playback. Short-term drops and jitter also matter.

# Part 3B — Dynamic Adaptive Streaming over HTTP (DASH)

## 3.9 What is DASH?

DASH stands for:

Dynamic Adaptive Streaming over HTTP

It is a technique that allows a video player to adapt the quality of streamed video according to current network conditions.

Rather than supplying the video at one fixed bitrate, the system makes multiple encoded versions available.

The client selects which version to download for each segment.

### Why DASH is needed

Suppose a user is watching a video while traveling.

Their available network throughput changes:

- Strong Wi-Fi: 15 Mbps.
- Weaker Wi-Fi: 5 Mbps.
- Mobile connection: 2 Mbps.
- Better mobile reception: 8 Mbps.

If the video always uses a bitrate of 10 Mbps, playback may repeatedly stall during poor network conditions.

DASH allows the client to request lower-bitrate segments when bandwidth is limited and higher-bitrate segments when conditions improve.

## 3.10 How the DASH server works

The lecture describes several server-side operations.

### Step 1: Divide the video into chunks

The original video is divided into segments.

For example, a 60-second video might be divided into ten 6-second segments.

### Step 2: Encode segments at multiple rates

Each segment is available at multiple quality levels.

For example:

| Quality level | Illustrative bitrate |
| ------------- | -------------------- |
| Low           | 0.5 Mbps             |
| Medium        | 2 Mbps               |
| High          | 5 Mbps               |
| Very high     | 10 Mbps              |

These are example encodings, not mandatory DASH quality levels.

### Step 3: Store the encoded segments

The segments are placed on web servers or CDN nodes.

Different clients can then retrieve different representations of the same video.

### Step 4: Provide a manifest file

The manifest describes the available representations and how the client can locate their segments.

The lecture refers to this as a manifest file.

In MPEG-DASH, this metadata is commonly called the Media Presentation Description (MPD).

The manifest gives the player enough information to select and request the available video segments.

## 3.11 How the DASH client works

The lecture explains that much of the adaptation logic resides in the client.

The player:

1. Obtains the manifest.
2. Estimates available network throughput.
3. Determines its buffer status.
4. Selects a segment representation.
5. Downloads that segment using HTTP.
6. Monitors changing network conditions.
7. Adjusts later segment requests.

The client can choose different bitrates at different times.

### Example: Adaptive quality selection

Suppose the client is streaming a video with available representations at 1, 3, 5 and 8 Mbps.

Interactive DASH example

Available network throughput

## 6 Mbps

1 Mbps

3 Mbps

5 Mbps

8 Mbps

Selected representation: 3 Mbps. This simplified example selects the highest available bitrate within 80% of estimated throughput to leave a safety margin.

Illustration of DASH adaptation. Real clients also consider buffer occupancy, download history, device capabilities and other factors.

### Why not always choose the highest bitrate?

Higher quality requires more data.

If the player requests segments that are too large for the available bandwidth, the buffer may empty before the download finishes.

Therefore, DASH tries to select a bitrate that balances quality against the risk of interruption.

## 3.12 The three key DASH client decisions

The lecture identifies three central decisions.

### A. When to request a chunk

The client schedules requests so the buffer is not depleted.

Requesting segments too slowly may cause buffering interruptions.

Requesting too aggressively may waste bandwidth or fill the buffer unnecessarily.

### B. What encoding rate to request

The client chooses a bitrate based on network capacity and playback conditions.

Higher available throughput can support higher-quality video.

Lower throughput may require lower-quality video.

### C. Where to request a chunk

The client can select an appropriate server or CDN location.

The lecture highlights two factors:

- Network proximity.
- Available bandwidth.

A nearby server may provide better performance, but the best choice also depends on congestion and server availability.

The lecture summarizes the complete streaming system as:

\\[ \boxed{ \text{Streaming video} = \text{Encoding} + \text{DASH} + \text{Playout buffering} } \\]

Each component has a separate role.

| Component         | Responsibility                                                |
| ----------------- | ------------------------------------------------------------- |
| Encoding          | Compress video into representations suitable for transmission |
| DASH              | Select and retrieve appropriate media segments                |
| Playout buffering | Smooth out variable delivery and maintain continuous playback |

# Part 3C — Content Distribution Networks (CDNs)

## 3.13 Why CDNs are necessary

The lecture asks:

How can a video platform deliver millions of videos to hundreds of thousands of users simultaneously?

One possible approach is to use a single extremely powerful server.

The lecture calls this the mega-server approach.

However, it has major limitations.

### Problem 1: Single point of failure

If the server fails, the service may become unavailable to all users depending on it.

### Problem 2: Network congestion

A huge number of clients downloading from one location can overload the server's network links.

### Problem 3: Geographic distance

Users located far from the server may experience longer network paths and potentially greater delays or congestion.

### Problem 4: Limited scalability

As demand increases, the central server and surrounding infrastructure must provide increasing amounts of processing, bandwidth and storage capacity.

Therefore, the lecture concludes that one mega-server is not a scalable solution for global video distribution.

## 3.14 What is a CDN?

A Content Distribution Network (CDN) is a distributed system of servers that stores or caches copies of content at multiple locations.

Instead of forcing every user to retrieve content from a single original server, users can download content from CDN nodes that are better positioned to serve them.

Simplified CDN model: content is replicated or cached across distributed nodes and served to nearby or otherwise suitable users.

### Example

Suppose a popular movie is hosted by a streaming company.

Without a CDN, every viewer might need to retrieve the movie from a distant central data center.

With a CDN, frequently requested movie segments can be stored at multiple regional or ISP-local servers.

Users retrieve the segments from an appropriate CDN node rather than always contacting the origin.

This can reduce traffic on long network paths and improve delivery performance.

## 3.15 CDN deployment strategies

The lecture identifies two important CDN placement approaches.

### Strategy 1: Enter deep

The CDN deploys servers deep inside many access networks, close to end users.

Akamai is given as the lecture's example.

The advantages include:

- Shorter network paths to users.
- Potentially reduced latency.
- Less dependence on long-distance transit paths.
- Better localization of traffic.

The disadvantage is greater deployment and management complexity because servers are spread across many locations.

The lecture mentions a historical Akamai deployment figure of 240,000 servers in more than 120 countries in 2015. This should be understood as a dated example rather than a current inventory.

### Strategy 2: Bring home

The CDN uses a smaller number of relatively large server clusters placed at strategically chosen locations.

These clusters are commonly located at Points of Presence (POPs) near access networks.

The lecture associates this approach with Limelight.

The advantages include more centralized infrastructure and potentially simpler management, though some clients may be farther from the nearest cluster.

### Comparison

| Characteristic         | Enter deep                   | Bring home                                            |
| ---------------------- | ---------------------------- | ----------------------------------------------------- |
| Number of locations    | Many                         | Fewer                                                 |
| Typical placement      | Deep inside access networks  | Large regional POP clusters                           |
| User proximity         | Often very close             | Generally farther than highly distributed edge caches |
| Operational complexity | Higher geographic complexity | More centralized                                      |
| Historical example     | Akamai                       | Limelight                                             |

Both strategies seek to reduce the cost and difficulty of large-scale content delivery.

They simply distribute infrastructure differently.

## 3.16 How CDN delivery works

The lecture provides a streaming example in which a subscriber requests a television show.

The process is:

1. A user selects a video.
2. The streaming service identifies appropriate content representations and locations.
3. The client receives a manifest.
4. The player uses the manifest to request video segments.
5. CDN nodes deliver the requested content.
6. If network conditions change, the client may request different bitrate representations or use a different content location.

DASH and CDNs therefore complement one another.

DASH decides which representation to retrieve, while the CDN infrastructure provides distributed locations from which content can be delivered.

This separation is useful because a network path can become congested even when a server itself is functioning correctly.

A client may obtain better performance by switching to another available representation or delivery location.

## 3.17 Case study: Netflix Open Connect

The lecture concludes its CDN section with Netflix Open Connect.

Open Connect is Netflix's content-delivery infrastructure and ISP partnership program.

The lecture identifies several important elements.

### A. Deployment model

Netflix uses Open Connect Appliances deployed in or near ISP networks, together with interconnection and peering arrangements.

These appliances store and serve video content.

### B. Why embed appliances in ISP networks?

Placing popular content close to subscribers reduces the need to retrieve every video over long external network paths.

For example, if many customers of the same ISP watch a popular series, the ISP-local Open Connect infrastructure may serve those requests.

This can reduce upstream traffic and improve efficiency.

### C. Control and data responsibilities

The lecture distinguishes two broad responsibilities.

Control: Systems and intelligent clients help determine where content should be retrieved.

Data delivery: The Open Connect appliances actually serve media objects to subscribers.

This is an important architectural distinction: the systems that decide where to fetch content do not necessarily perform the same work as the systems transferring the video data.

### D. Broader lessons

Netflix's CDN design illustrates that large-scale delivery is not simply a matter of buying faster servers.

The lecture identifies several contributing factors:

- Strategic cache placement.
- Predicting popular content.
- Working with ISPs.
- Monitoring infrastructure health.
- Network routing.
- Efficient content delivery.

The main lesson is that large-scale Internet delivery requires coordinated application, infrastructure and network design.

### Video streaming and CDN section recap

Video streaming systems must deliver media continuously despite changing bandwidth, congestion and delays.

Buffering helps absorb short-term variation, DASH adapts the requested media bitrate, and CDNs distribute content geographically to improve scalability and performance.

Together, these techniques make large-scale streaming practical.

# Part 4 — Connecting the Three Main Topics

Although DNS, P2P applications and video streaming appear to be different subjects, they share several fundamental networking principles.

## 4.1 Distribution reduces dependence on central infrastructure

DNS distributes name-resolution responsibilities across a hierarchy.

P2P systems distribute file-delivery responsibilities among peers.

CDNs distribute content-delivery responsibilities across geographically separated servers.

The common goal is to avoid unnecessary dependence on one central server.

## 4.2 Caching and replication improve efficiency

DNS caching stores recently resolved records so the same lookup does not need to be repeated.

CDN caching stores frequently accessed content closer to users.

BitTorrent makes pieces available across multiple peers, enabling additional participants to obtain them without repeatedly downloading everything from the original source.

All three systems improve efficiency by making useful information or data available from multiple locations.

## 4.3 Distributed systems require coordination

Distributing infrastructure creates new challenges.

DNS uses delegation and resource records to coordinate name resolution.

BitTorrent uses trackers, DHT, PEX and chunk-selection algorithms to coordinate file sharing.

Streaming platforms use manifests, adaptive clients, routing systems and CDN selection mechanisms to coordinate video delivery.

Therefore, distribution improves scalability, but it also requires mechanisms for finding resources and making decisions.

## 4.4 Reliability and availability remain important

A distributed architecture can reduce reliance on a single server, but distribution does not automatically guarantee reliability.

DNS can suffer from attacks or misconfiguration.

P2P swarms can become unusable if required pieces are unavailable.

CDN systems can experience delivery failures when content placement, connectivity or routing is inadequate.

Every architecture needs appropriate monitoring, availability and failure-handling mechanisms.

# Part 5 — Complete Formula Reference

These are the primary quantitative relationships to understand from the lecture, including a few explanatory formulas used in the examples above.

| Formula                                | Meaning                                                     |
| -------------------------------------- | ----------------------------------------------------------- |
| \\(\frac{F}{u_s}\\)                    | Minimum time for the server to upload one complete copy     |
| \\(\frac{NF}{u_s}\\)                   | Minimum server transmission time for N client-server copies |
| \\(\frac{F}{d\_{\min}}\\)              | Minimum time for the slowest client to receive one copy     |
| \\(u\_{\mathrm{total}}=u_s+\sum u_i\\) | Combined upload capacity in a P2P system                    |
| \\(\frac{NF}{u_s+\sum u_i}\\)          | P2P aggregate upload-capacity constraint                    |
| \\(S=R\times t\\)                      | Data size from bitrate and duration                         |
| \\(\frac{dB}{dt}=R_n-R_p\\)            | Simplified change in streaming-buffer contents              |

## The two most important distribution formulas

Client-server lower bound

\\[ \boxed{D\_{CS}\geq\max\left\\{\frac{NF}{u_s},\frac{F}{d\_{\min}}\right\\}} \\]

P2P lower bound

\\[ \boxed{D\_{P2P}\geq\max\left\\{\frac{F}{u_s},\frac{F}{d\_{\min}},\frac{NF}{u_s+\sum\_{i=1}^{N}u_i}\right\\}} \\]

Remember that the P2P formula contains three constraints, while the client-server formula contains two.

# Part 6 — Important Terminology for Revision

| Term                 | Meaning                                                              |
| -------------------- | -------------------------------------------------------------------- |
| DNS                  | Distributed system for resolving domain names and other DNS records  |
| Hostname             | Human-readable identifier for a host or service                      |
| IP address           | Numerical network-layer address                                      |
| Root DNS server      | Server that provides referrals to TLD servers                        |
| TLD server           | Server responsible for top-level domain delegation information       |
| Authoritative server | Server providing authoritative records for a DNS zone                |
| Recursive resolver   | Server that performs DNS resolution for a client                     |
| Iterative query      | Query where the server answers or provides a referral                |
| Recursive query      | Query where the server is asked to obtain the final result           |
| TTL                  | Time To Live; controls DNS caching duration                          |
| DNSSEC               | DNS security extensions providing authenticated DNS data             |
| P2P                  | Peer-to-Peer networking                                              |
| Peer                 | Participant that can request and provide resources                   |
| Swarm/torrent        | Collection of participants distributing the same content             |
| Tracker              | Service that helps peers discover participants                       |
| DHT                  | Distributed Hash Table, used for decentralized peer discovery        |
| PEX                  | Peer Exchange; sharing information about known peers                 |
| Infohash             | Identifier derived from torrent metadata                             |
| Rarest-first         | Strategy prioritizing scarce file pieces                             |
| Tit-for-tat          | Strategy encouraging reciprocal uploading                            |
| Optimistic unchoking | Temporarily serving another peer to discover useful partners         |
| Bitrate              | Number of bits of encoded media per second                           |
| Throughput           | Rate at which data is successfully delivered                         |
| Jitter               | Variation in network delay                                           |
| Buffer               | Temporary storage holding received data before playback              |
| DASH                 | Dynamic Adaptive Streaming over HTTP                                 |
| Manifest             | Metadata describing available media representations and segments     |
| CDN                  | Content Distribution Network                                         |
| POP                  | Point of Presence, a network infrastructure location                 |
| Open Connect         | Netflix's content-delivery infrastructure and ISP partnership system |

# Part 7 — Exam-Focused Revision

These questions cover the most conceptually important material in the lecture. The answers are included so you can test your understanding.

Revision question 1 of 14

Self-test

## Why is DNS designed as a distributed hierarchical system?

Try explaining your answer before revealing the solution.

Reveal answer

&#x20;PreviousNext&#x20;

# Part 8 — Final Lecture Summary

The main ideas can be condensed into this comparison:

| Topic           | Core problem                                                                                      | Main solution                                          | Important mechanisms                                                                 |
| --------------- | ------------------------------------------------------------------------------------------------- | ------------------------------------------------------ | ------------------------------------------------------------------------------------ |
| DNS             | How do hosts discover the network addresses and service information associated with domain names? | Distributed, hierarchical name resolution              | Root/TLD/authoritative servers, resource records, recursion, iteration, TTL, caching |
| P2P             | How can large files be distributed to many users without overwhelming the original source?        | Peers share file pieces and upload capacity            | Self-scalability, chunking, rarest-first, tit-for-tat, DHT, PEX                      |
| Video streaming | How can media play smoothly over networks with changing conditions?                               | Buffering and adaptive delivery                        | Throughput estimation, jitter compensation, DASH                                     |
| CDN             | How can content be delivered efficiently to geographically dispersed users?                       | Distributed content caches and delivery infrastructure | Enter-deep, bring-home, manifests, intelligent server selection                      |

The three most important lessons of Week 4 are:

First, distributing responsibilities improves Internet scalability. DNS distributes name resolution, BitTorrent distributes file-sharing workloads, and CDNs distribute content delivery.

Second, efficient networking depends on intelligent decisions. DNS chooses where to find authoritative information, BitTorrent selects pieces and upload partners, and DASH selects appropriate media representations and sources.

Third, network performance is not determined by bandwidth alone. Availability, caching, congestion, delay, jitter, cooperation, and infrastructure placement all affect application behavior.

## Part 9 — Next Week and Assigned Reading

Lecture page 55

The lecture ends by introducing the next week's topics:

- The Transport Layer, including Chapter 3 of Kurose and Ross's Computer Networking textbook.
- The use of Wireshark to inspect and analyze network traffic.

The assigned preparation is to review the Week 4 lecture notes and read Chapter 3 of the textbook.

In preparation for the Transport Layer, pay particular attention to the distinction between application protocols such as DNS, HTTP and BitTorrent, and the underlying transport services that help carry their messages. This relationship will be important when studying TCP, UDP, ports and transport-layer reliability.

Overall: This lecture explains how major Internet applications locate services, exchange resources and deliver content at scale. Understanding the DNS hierarchy, the client-server/P2P distribution formulas, BitTorrent algorithms, playout buffering, DASH and CDN architectures provides the foundation for the next stage of computer networking studies.