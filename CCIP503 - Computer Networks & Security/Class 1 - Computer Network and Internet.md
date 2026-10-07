
==Difference between node and hosts==

## 1. What is the Internet?

- **Computer Network:** A collection of devices (nodes) connected by communication links.
- **The Internet:** A "network of networks" that interconnects billions of computing devices globally. It serves as an infrastructure that provides services (like Web, streaming, and Skype) to distributed applications.
- **End Systems (Hosts):** Devices that connect to the network, such as PCs, servers, mobile devices, and IoT devices like web-enabled toasters or connected cars.
- **Packet-Switched Networks:** End systems segment data and add header bytes to create packages called "packets".
    - _Analogy/Example:_ Think of a factory shipping cargo. The cargo (data) is divided into trucks (packets). The trucks travel on highways (communication links) and pass through intersections (packet switches/routers) to reach a destination warehouse (receiving end system).
- **Protocols:** Standards that control the sending and receiving of information (e.g., TCP, IP, HTTP). They define the format and order of messages exchanged between network entities, as well as actions taken upon transmission or receipt.
    - _Example:_ Just as human protocols govern social interactions (e.g., saying "Hello" and waiting for a response before asking a question), computer protocols dictate that a client must send a "TCP connection request" and wait for a "TCP connection reply" before asking a server for a file.

 Internet standards are developed by the **IETF** and published as **RFCs (Requests for Comments)**.
 
**Distributed applications**: programs on multiple end systems exchanging data—such as email, web browsing, messaging, traffic-aware maps, music and video streaming, social networks, video conferences, multiplayer games and location-based recommendations.

A **socket interface** is how an application asks the host's network software to deliver data to a particular program at a remote host. **Example:** A video-call application sends audio data through its socket; the network moves it to the other participant's application.

**Several ways to classify networks:**

| Classification                              | Categories                          | Example or intuition                                                                                                                         |
| ------------------------------------------- | ----------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| Direction of transmission                   | Simplex; half-duplex; full-duplex   | One way only; both directions in turns (walkie-talkie); both simultaneously (telephone conversation).                                        |
| Timing                                      | Synchronous; asynchronous           | Sending against a shared timing scheme versus communicating without a continuously shared clock.                                             |
| Organization/authentication (lecture label) | Peer-to-peer; server-based          | Peers can serve each other; a central server can provide a service. These describe organization more directly than an authentication method. |
| Geographic reach                            | LAN; MAN; WAN                       | Building network; metropolitan network; wide-area network.                                                                                   |
| Service style/reliability (lecture label)   | Connection-oriented; connectionless | Establish and maintain a logical connection versus sending independently. These terms do not alone guarantee reliability.                    |

## 2. The Network Edge

The "edge" refers to the end systems and the access networks that physically connect them to the first router (edge router).

The **network edge** contains hosts, often described as **clients** requesting services and **servers** providing them. 

An **access network** physically connects a host to the **first/edge router** on its route.

The **network core** is the interconnected mesh of routers beyond the edge. Physical links can be wired or wireless.

Hosts (End Systems): These are the buildings themselves. In technology terms, this is your personal laptop, your smartphone, or the servers running a Node.js backend or a React frontend. They sit at the absolute outer boundaries of the network and are the only places where data is actually generated, processed, or consumed.

Access Network:  It is the specific, localized physical connectionthat carries data away from the host device. This is your driveway and the local street—like a home Wi-Fi setup, a corporate Ethernet cable, or a mobile 5G connection.

Edge Router: This is the highway on-ramp or tollbooth. It is the very first piece of heavy, ISP-controlled infrastructure that catches the data from your local access network and prepares to route it across the country or the world.

The massive, high-speed web of highways connecting cities is the Network Core. The core does not care what your application does; it only cares about moving traffic efficiently from one on-ramp to an off-ramp. The Edge is where all the actual applications live, where data originates, and where end-users experience the internet.

- **Digital Subscriber Line (DSL):** Uses existing telephone lines to carry both data and voice encoded at different frequencies (Frequency Division Multiplexing). It features a dedicated connection to the central office. A home DSL modem and splitter separate Internet data from traditional voice; data goes toward the ISP, voice toward the telephone network.
    
- **Cable Network:** Uses a Hybrid Fiber-Coaxial (HFC) system. Unlike DSL, homes share the distribution network back to the cable headend (CMTS).
    
- **Home & Enterprise Networks:** Home networks typically combine a modem, router, firewall, NAT, wired Ethernet, and a wireless access point. Enterprise networks connect end systems via Ethernet switches and institutional routers, offering speeds up to 10 Gbps.
    
- **Wireless Networks:** Include Wireless LANs (e.g., WiFi within ~100 ft) and Wide-area cellular access (e.g., 4G/5G over tens of kilometers).
    
- **Physical Media:**
    - **Guided Media:** Waves travel along a solid medium like twisted-pair copper wire, coaxial cable, or fiber-optic cable (which carries light pulses and is immune to electromagnetic noise).
        
    - **Unguided Media:** Waves propagate through the atmosphere/space via radio spectrum (e.g., terrestrial microwave, satellite, cellular).

## 3. The Network Core
The core is the mesh of interconnected routers that transport data across the internet.

- **Packet-Switching (Store-and-Forward):** A router must receive an entire packet before it can begin transmitting it to the next link. It takes $L/R$ seconds to push an $L$-bit packet onto a link with an $R$ bps transmission rate.
    - This is the time required to *push all bits onto the link*, distinct from propagation time (the time for the signal to travel down the medium). Under **store-and-forward**, a router first receives the entire packet, then starts transmitting it onto the next link.
        
- **Queueing Delay and Packet Loss:** If an arriving packet finds the required outgoing link already busy, it waits in an output buffer adding **queueing delay**. If the finite buffer is already full, packet loss occurs (the packet is dropped).
    - _Example:_ Queueing is like cars backing up at a busy toll booth. Packet loss occurs when the line backs up so far that the exit ramp is closed, forcing new cars to be turned away.
        
- **Routing vs. Forwarding:**
    - **Routing:** The network-wide process that determines the entire source-to-destination path taken by packets.
    - **Forwarding:** The localized action of moving a packet from a router's input port to the appropriate output port.
    - _Example:_ Routing is using a GPS to map a cross-country trip from New York to California. Forwarding is the act of reading a highway sign and steering your car onto the specific exit ramp at a single intersection.
        
### Circuit Switching vs. Packet Switching

- **Circuit Switching:** A dedicated path and resources (buffers, bandwidth) are reserved in advance for the entirety of a communication session (like a traditional telephone network). There is no store-and-forward transmission, and performance is guaranteed. However, if the circuit isn't actively being used, the resources sit idle, causing bandwidth wastage.
- **Packet Switching:** Resources are not reserved; packets use resources on demand. It supports store-and-forward transmission, requires no call setup, and wastes no bandwidth, but packets may experience queueing delays.
  
| Question | Circuit switching | Packet switching |
|---|---|---|
| Resource allocation | Dedicated path and reserved share before communication | Links shared on demand; no dedicated end-to-end circuit |
| Setup | Call/circuit setup | No circuit setup |
| Sending | Continuous dedicated circuit; no hop-by-hop packet store-and-forward model | Packets stored and forwarded at switches |
| Path | A call uses its established route | Different packets may use different routes |
| Performance tradeoff | Reserved capacity, more predictable service; capacity unused during idle time | Flexible sharing; queues and loss possible during congestion |

### Multiplexing in Circuit Switching
- **FDM (Frequency Division Multiplexing):** The frequency spectrum is divided into continuous, narrow bands, with each connection getting its own dedicated band.
    - _Example:_ FM radio stations—one station broadcasts continuously on 88 MHz, while another broadcasts continuously on 108 MHz.
- **TDM (Time Division Multiplexing):** Time is divided into fixed frames and slots. A connection gets the entire frequency band, but only during its specific, periodic time slot.
    - _Example:_ A shared comedy club stage where Comedian A gets the microphone for exactly 5 minutes, then Comedian B gets it for 5 minutes, repeating in cycles.




A node is any physical device connected to a network capable of sending, receiving, or forwarding data, whereas a host is a specific type of node that acts as an end system generating or consuming that data.
- **Node:** Encompasses every active connection point within a network infrastructure. This includes intermediary devices in the network core, such as routers, switches, hubs, and modems, whose primary purpose is to direct traffic.
- **Host:** Refers exclusively to devices at the network edge that run applications and possess a unique network address (like an IP address). Examples include personal computers, smartphones, web servers, and smart appliances.
**Key Distinction:**

Every host is a node, but not every node is a host. For example, a network switch is a node because it receives and forwards data packets, but it is not a host because it does not originate the data or run end-user applications. A laptop connected to that switch, however, is both a node and a host.




---

**Network Components & Infrastructure**

  

- **Device Roles:** Link-layer switches are typically deployed in access networks, whereas routers operate within the network core.
    
      
    
- **Internet Structure:** The broader network architecture relies on points of presence (PoPs), multi-homing, peering arrangements, and Internet exchange points (IXPs) to connect networks.
    
      
    

**Protocols & Applications**

  

- **Protocols:** A protocol dictates the format, order, and actions for messages exchanged between communicating entities. The IP protocol specifically defines the format of packets sent among routers and end systems.
    
      
    
- **Applications:** Distributed applications involve multiple end systems exchanging data with one another across the network.
    
      
    

**Broadband Residential Access**

The three primary broadband residential access methods are DSL, Cable, and FTTH.

  

- **DSL (Digital Subscriber Line):** Utilizes a digital subscriber line access multiplexer (DSLAM).
    
      
    
- **Cable:** Utilizes a cable modem termination system (CMTS). It operates as a shared broadcast medium: every downstream packet from the head end travels to every connected home, and all upstream packets travel back to the head end.
    
      
    
- **FTTH (Fiber to the Home):** Relies on optical-distribution architectures.
    
      
    - **AON (Active Optical Network):** Essentially switched Ethernet.
        
          
        
    - **PON (Passive Optical Network):** Uses a home optical network terminator (ONT) connected to a neighborhood splitter (combining fewer than 100 homes). The splitter connects to an optical line terminator (OLT) in the telco’s central office. The OLT converts optical/electrical signals and connects to the internet via a router. Packets sent from the OLT are replicated at the splitter for all connected homes.
        
          
        
- **Wireless:** Fixed wireless Internet (FWI) uses terrestrial radio channels, categorized by range: short (1–2 meters), local (tens to hundreds of meters), and wide area (tens of kilometers).
    
      
    

**Circuit Switching & TDM**

  

- **Mechanism:** Circuit switching reserves a constant transmission rate (a fraction of link capacity) for the entire duration of a connection.
    
- **TDM Rate Calculation:** The transmission rate of a Time Division Multiplexing (TDM) circuit is the frame rate multiplied by the bits per slot. For instance, 8,000 frames/sec $\times$ 8 bits/slot = 64 kbps.
    
      
    
- **Transmission Example:** For a 1.536 Mbps link with 24 slots, each circuit receives 64 kbps. Transmitting a 640,000-bit file takes 10 seconds of transmission time plus any initial setup time (e.g., a 500 msec setup yields a 10.5-second total delay).
    
   