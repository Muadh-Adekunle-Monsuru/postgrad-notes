
## 1. The Domain Name System (DNS)
### 1.1 Overview and Purpose
- **Host Identification:** Humans prefer easy-to-remember alphanumeric hostnames (e.g., `[www.google.com](https://www.google.com)`), whereas routers prefer fixed-length, hierarchical IP addresses (e.g., `121.7.106.83` for IPv4) for routing efficiency.
- **Core Function:** DNS is an application-layer directory service that translates hostnames to IP addresses.
- **Protocol & Architecture:** It is implemented as a distributed, hierarchical database across name servers (often running BIND software) and operates over **UDP using port 53**.
   
### 1.2 DNS Services

- **Hostname-to-IP Translation:** Maps human-readable names to network-addressable IP numbers.
- **Host Aliasing:** Allows a server with a canonical (real) hostname (e.g., `relay1.west-coast.enterprise.com`) to have multiple simpler alias names (e.g., `enterprise.com`, `[www.enterprise.com](https://www.enterprise.com)`).
- **Mail Server Aliasing:** Obtains mnemonic alias names for mail servers.
- **Load Distribution:** Replicated web servers behind a single hostname can map to multiple IP addresses, distributing incoming traffic across a cluster.
### 1.3 Why Centralizing DNS Fails (Scalability Issue)

A centralized DNS server is impractical because it creates:
1. A **single point of failure**.
2. Overwhelming **traffic volume** (e.g., Comcast handles 600 billion queries/day; Akamai handles 2.2 trillion queries/day).
3. High latency due to **distant centralized databases**.
4. Massive **maintenance overhead**.
    
      
    

### 1.4 Distributed, Hierarchical Database Structure

```
              [ Root DNS Servers ]
            /          |          \
   [.com TLD]      [.org TLD]      [.edu TLD]
      /                |               \
[amazon.com]       [pbs.org]       [umass.edu]  <-- Authoritative Servers
```

1. **Root DNS Servers:**
    - Official contact of last resort.
    - Managed by **ICANN**; consists of 13 logical root servers worldwide, each heavily replicated (over 200 physical servers in the US).
    - Uses **DNSSEC** for authentication and message integrity.
2. **Top-Level Domain (TLD) Servers:**
    - Responsible for generic domains (`.com`, `.org`, `.net`, `.edu`, `.jobs`, `.aero`) and country-code domains (`.cn`, `.uk`, `.fr`, `.tr`).
    - Managed by specific registries (e.g., _Network Solutions_ for `.com`/`.net`; _Educause_ for `.edu`).
3. **Authoritative DNS Servers:**
    - Provide authoritative hostname-to-IP mappings for an organization's publicly accessible hosts.
    - Maintained by the organization itself or a service provider.
4. **Local DNS Servers (Default Name Servers):**
    - Do not strictly belong to the official hierarchy.
    - Maintained by ISPs or institutions; hosts send queries to their local DNS server first, which either answers from its cache or forwards the query into the DNS hierarchy.
        
### 1.5 DNS Query Resolution Strategies

When a client (e.g., `engineering.nyu.edu`) wants to resolve a hostname like `gaia.cs.umass.edu`:
- **Iterated Query:**
    - The contacted server responds with the IP of the next name server to contact ("_I don't know, but ask this server_").
    - _Step Sequence:_ Client $\rightarrow$ Local DNS $\rightarrow$ Root DNS (returns TLD IP) $\rightarrow$ Local DNS $\rightarrow$ TLD DNS (returns Authoritative IP) $\rightarrow$ Local DNS $\rightarrow$ Authoritative DNS (returns IP) $\rightarrow$ Client.
- **Recursive Query:**
    - Places the entire burden of resolution on the contacted server, which sequentially queries the next levels on behalf of the requester.
    - Put heavy computational loads on upper-level hierarchy servers.

```
--- Iterated Resolution ---               --- Recursive Resolution ---

Host --> Local DNS --> Root DNS           Host --> Local DNS --> Root DNS
Host <-- Local DNS <-- (Refers TLD)                                  |
                                                                     v
Host --> Local DNS --> TLD DNS            Host <-- Local DNS <-- TLD DNS
Host <-- Local DNS <-- (Refers Auth)                                 |
                                                                     v
Host --> Local DNS --> Auth DNS           Host <-- Local DNS <-- Auth DNS
Host <-- Local DNS <-- (Returns IP)
```

> **Important Note:** DNS returns IP/Resource Records, **not HTML**. Successful name resolution does not guarantee HTTP connectivity if the web server is down.

### 1.6 DNS Caching & Resource Records (RRs)

- **DNS Caching:** Name servers store recently learned mappings temporarily to reduce response time and hierarchy traffic. Cache entries expire after a specified **Time to Live (TTL)**.
    
      
    
- **Resource Record Format:** `(Name, Value, Type, TTL)`
    
      
    

|**Record Type**|**Name**|**Value**|**Example / Description PDF+ 1**|
|---|---|---|---|
|**A**|Hostname|IPv4 Address|`(foo.com, 145.37.93.126, A)`|
|**AAAA**|Hostname|IPv6 Address|Maps a hostname to an 128-bit IPv6 address.|
|**NS**|Domain|Hostname of Authoritative DNS Server|`(foo.com, dns.foo.com, NS)`|
|**CNAME**|Alias Name|Canonical (Real) Name|`([www.ibm.com](https://www.ibm.com), servereast.backup2.ibm.com, CNAME)`|
|**MX**|Domain Name|Hostname of Mail Server|Maps domain to SMTP server; includes preference values.|
|**TXT**|Name|Text Data|Used for domain verification & security policy (e.g., SPF).|
|**PTR**|IP Address|Hostname|Reverse DNS lookups.|
|**SRV**|Service Name|Hostname & Port|Advertises location/port of specific services.|

#### DNS Message Format

Both Query and Reply messages share the same packet layout:

  

- **Header (12 bytes total):** Identification (16-bit ID), Flags (Query/Reply, Authoritative, Recursion Desired, Recursion Available), and 4 fields indicating count of Questions, Answer RRs, Authority RRs, and Additional RRs.
    
      
    
- **Body:** Questions section, Answer RRs, Authority RRs, Additional Info RRs.
    
      
    

### 1.7 Registration & Security Vulnerabilities

- **Registering a Domain:** To register a new company domain (e.g., `networkutopia.com`), the registrant provides authoritative server details to a registrar, which inserts `NS` and `A` records into the corresponding TLD servers.
    
      
    
- **Four Real-World Failure Modes:**
    
      
    1. **Cache Poisoning:** Injecting false records into a recursive resolver's cache (mitigated by DNSSEC and port randomization).
        
          
        
    2. **DNS Hijacking:** Unauthorized modification of resolver settings or registrar entries to redirect users.
        
          
        
    3. **Typosquatting:** Registering misspelled domain names targeting user typing errors.
        
          
        
    4. **Availability Attacks (DDoS):** Flooding DNS infrastructure to prevent name resolution.
        
          
        

## 2. Peer-to-Peer (P2P) Applications

### 2.1 P2P vs. Client-Server Architecture

- **Client-Server:** Always-on server handles requests; server upload bandwidth is a bottleneck that scales **linearly** as user count $N$ increases.
    
      
    
- **P2P:** Minimal/no reliance on dedicated servers. Arbitrary end systems (peers) directly communicate, acting as both clients and servers.
    
      
    
- **Self-Scalability:** As new peers join, they bring new service demands but also **add upload capacity** to the system.
    
      
    

### 2.2 File Distribution Time Analysis

Let:

- $F$ = File size (bits)
- $N$ = Number of downloading peers
- $u_s$ = Server upload rate
- $d_{min}$ = Minimum client download rate
- $u_i$ = Upload rate of peer $i$
#### Client-Server Distribution Time ($D_{c-s}$)
The server must sequentially send $N$ copies of file $F$:
$$D_{c-s} \ge \max \left\{ \frac{N \cdot F}{u_s}, \, \frac{F}{d_{min}} \right\}$$

Distribution time increases linearly without bound as $N$ grows.
#### P2P Distribution Time ($D_{P2P}$)

The server must upload at least one full copy, each peer must receive one copy, and aggregate upload capacity is $u_s + \sum u_i$:

$$D_{P2P} \ge \max \left\{ \frac{F}{u_s}, \, \frac{F}{d_{min}}, \, \frac{N \cdot F}{u_s + \sum_{i=1}^{N} u_i} \right\}$$

Distribution time remains largely flat as $N$ grows because peer upload capability compensates for increased demand.

  

### 2.3 BitTorrent Protocol Mechanics

- **Terminology:**
    
      
    - **Torrent:** Collection of peers exchanging chunks of a specific file.
        
          
        
    - **Chunk:** File split into equal sub-parts, typically **256 KB**.
        
          
        
    - **Tracker:** Centralized infrastructure node tracking connected peers in a swarm.
        
          
        
    - **DHT (Distributed Hash Table):** Decentralized peer discovery over UDP without requiring a tracker.
        
          
        
    - **PEX (Peer Exchange):** Connected peers directly share lists of other known peers.
        
          
        

```
[ New Peer Alice ] 
       │
       ├─► 1. Gets Infohash from Magnet Link[cite: 41]
       ├─► 2. Queries Tracker / DHT / PEX for peer list[cite: 41]
       ├─► 3. Connects to subset of peers ("Neighbors")[cite: 35, 41]
       └─► 4. Exchanges file chunks using Rarest-First & Tit-for-Tat[cite: 35, 36, 41]
```

#### Key Performance Decisions

1. **Chunk Request Strategy — _Rarest First_:**
    
      
    - Alice determines which chunks are least common among her neighbors and requests those first.
        
          
        
    - _Purpose:_ Equalizes chunk availability across the swarm so no single chunk becomes a bottleneck.
        
          
        
2. **Chunk Transmission Strategy — _Tit-for-Tat_:**
    
      
    - Alice measures upload data rates from neighbors and sends chunks to the **top 4 peers** delivering data to her at the highest rates.
        
          
        
    - Re-evaluates top 4 providers every **10 seconds**; all other peers are _choked_.
        
          
        
3. **Optimistic Unchoking:**
    
      
    - Every **30 seconds**, Alice randomly selects one choked peer and sends chunks to it.
        
          
        
    - _Purpose:_ Allows new peers without chunks to join the active exchange and discover better trading partners.
        
          
        

## 3. Video Streaming and Content Distribution Networks (CDNs)

### 3.1 Streaming Challenges & Bandwidth Consumption

- **Bandwidth Footprint:** Video streaming accounts for ~80% of residential ISP traffic (Netflix, YouTube, Prime).
    
      
    
- **Bitrate Heterogeneity:** Low quality (~100 kbps) up to 4K streaming (>10 Mbps).
    
      
    
- **Key Challenges:** Network congestion, variable bandwidth, and packet loss causing playout delay or freezing.
    
      
    

### 3.2 Playout Buffering

- **Continuous Playout Constraint:** Video playout must match the original timing sequence.
    
      
    
- **Client Playout Buffer:** Absorbs variable network delays (**jitter**) and packet retransmissions.
    
      
    - If **Throughput > Playback Rate**: Buffer fills.
        
          
        
    - If **Throughput < Playback Rate**: Buffer drains, causing stalls/rebuffering if depleted.
        
          
        

### 3.3 Dynamic Adaptive Streaming over HTTP (DASH)

DASH places video adaptation intelligence completely on the **client side**:

  

- **Server Role:**
    
      
    - Video file is divided into distinct chunks.
        
          
        
    - Each chunk is encoded into **multiple quality/bitrate versions**.
        
          
        
    - Provides a **Manifest File** containing URLs for each chunk quality level.
        
          
        
- **Client Role:**
    
      
    - Periodically measures available bandwidth and buffer levels.
        
          
        
    - Consults the manifest and dynamically requests the highest supportable bitrate chunk.
        
          
        
    - Decides _when_ to request a chunk (preventing overflow/underflow), _what_ quality to fetch, and _where_ (which CDN server) to fetch it from.
        
          
        

### 3.4 Content Distribution Networks (CDNs)

Serving streaming video from a single centralized "mega-server" fails due to single points of failure, network congestion, and long network paths. CDNs solve this by replicating content across distributed server clusters.

  

#### CDN Deployment Models

1. **Enter Deep:** Deploy thousands of small server clusters **deep inside access networks** close to end users (e.g., Akamai with >240,000 servers in >120 countries).
    
      
    
2. **Bring Home:** Deploy larger server clusters in key **Points of Presence (POPs)** near access networks (e.g., Limelight Networks).
    
      
    

#### Real-World Case Study: Netflix Open Connect

- Combines **Open Connect Appliances (OCAs)** embedded directly into partner ISP networks with peering links.
    
      
    
- Control infrastructure directs client software to fetch chunks from local OCAs, reducing core Internet transit reliance and localizing video traffic.
    
      
    

## Summary Overview & Key Concepts

|**Concept**|**Primary Protocol / Mechanism**|**Primary Goal**|**Key Trade-Off / Bottleneck**|
|---|---|---|---|
|**Name Resolution**|**DNS** (UDP Port 53)|Map human hostnames to IP addresses|Centralization does not scale; solved via distributed hierarchy & caching.|
|**Peer-to-Peer**|**BitTorrent** (Tit-for-Tat, Rarest-First)|Scalable file distribution|Requires peer availability; uses optimistic unchoking for discovery.|
|**Adaptive Streaming**|**DASH** over HTTP|Smooth video playback over variable networks|Playout buffer balances latency/startup delay vs. stall avoidance.|
|**Content Delivery**|**CDN** (Akamai, Open Connect)|Global delivery of heavy media content|Complex routing, cache replication, and server placement overhead.|