# Operating Systems: Chapter 1 & 2 Exercises

## Chapter 1: Introduction

**1.1 How are network computers different from traditional personal computers? Describe some usage scenarios in which it is advantageous to use network computers.**
Network computers (or thin clients) rely on a central server for most processing and storage, whereas traditional PCs have their own local processing power and storage. Network computers are advantageous in environments where centralized administration, security, and lower hardware costs are prioritized, such as call centers, computer labs, or hospital terminals.

**1.2 What network configuration would best suit the following environments?**
a. A dormitory floor: Local Area Network (LAN)
b. A university campus: Local Area Network (LAN) or Campus Area Network (CAN)
c. A state: Wide Area Network (WAN)
d. A nation: Wide Area Network (WAN)

**1.3 Give two reasons why caches are useful. What problems do they solve? What problems do they cause? If a cache can be made as large as the device for which it is caching, why not make it that large and eliminate the device?**
Caches are useful to bridge the speed disparity between fast processors and slower memory, and to hold frequently accessed data. They solve the problem of high latency in data retrieval. They cause cache coherency problems (keeping data consistent across multiple caches). We do not make caches as large as the backing device because cache memory (like SRAM) is significantly more expensive and volatile compared to secondary storage.

**1.4 Under what circumstances would a user be better off using a time-sharing system rather than a PC or a single-user workstation?**
A user is better off with a time-sharing system when they need to perform massively parallel tasks, run simulations requiring massive amounts of RAM and CPU power not available on a single PC, or when multiple users need to collaborate on a centralized, shared dataset simultaneously.

**1.5 List the four steps that are necessary to run a program on a completely dedicated machine—a computer that is running only that program.**
1. Load the program from secondary storage into main memory.
2. Set the CPU registers and program counter to the start of the program.
3. Fetch, decode, and execute the instructions.
4. Output the results and halt the system.

**1.6 How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security) system?**
It prevents user programs from executing privileged instructions (like direct hardware I/O or memory management) that could disrupt the system or other users. If a user program tries to execute a privileged instruction, the hardware traps to the OS.

**1.7 In a multiprogramming and time-sharing environment, several users share the system simultaneously. This situation can result in various security problems.**
**a. What are two such problems?** Unauthorized access to another user's data (privacy violation) and denial-of-service (hogging system resources).
**b. Can we ensure the same degree of security in a time-shared machine as in a dedicated machine? Explain your answer.** No. A time-shared machine has shared software and hardware paths, creating vulnerabilities (like side-channel attacks or OS bugs) that do not exist on a machine physically isolated to one user.

**1.8 Describe a mechanism for enforcing memory protection in order to prevent a program from modifying the memory associated with other programs.**
Using base and limit registers. The base register holds the smallest legal physical memory address for a process, and the limit register specifies the size of the range. The CPU hardware compares every generated address against these registers to ensure it falls within the legal bounds.

**1.9 What are the tradeoffs inherent in handheld computers?**
Handheld computers trade physical size and weight for smaller screens, limited battery life, less processing power, and reduced memory capacity compared to desktop systems.

**1.10 Distinguish between the client-server and peer-to-peer models of distributed systems.**
In a client-server model, specific nodes (servers) provide services to other nodes (clients) in a centralized manner. In a peer-to-peer model, there is no strict distinction; all nodes in the network can act as both clients requesting services and servers providing services to others.

**1.11 Some computer systems do not provide a privileged mode of operation in hardware. Is it possible to construct a secure operating system for these computer systems? Give arguments both that it is and that it is not possible.**
*Possible:* You can write the OS using a secure, interpreted language or software virtual machine where the interpreter enforces security checks on every instruction (software isolation).
*Not possible:* Without hardware support, any machine code executed directly on the CPU could potentially manipulate the system state, making it impossible to enforce absolute security if users can run arbitrary native code.

**1.12 What are the main differences between operating systems for mainframe computers and personal computers?**
Mainframe OSs are designed primarily for high throughput, batch processing, and maximizing hardware utilization for hundreds of concurrent users. PC OSs are designed for single-user interactivity, ease of use, responsiveness, and running rich graphical applications.

**1.13 Which of the following instructions should be privileged?**
Privileged: a (Set value of timer), c (Clear memory), e (Turn off interrupts), f (Modify entries in device-status table), h (Access I/O device).
Non-privileged: b (Read the clock), d (Issue a trap instruction), g (Switch from user to kernel mode - this is done *via* a trap, the instruction to trap is user-level, though the actual mode bit change is hardware-controlled).

**1.14 Discuss, with examples, how the problem of maintaining coherence of cached data manifests itself in the following processing environments:**
**a. Single-processor systems:** Minimal issue; if the CPU caches disk data, the OS just needs to ensure the cache is flushed to disk before another process accesses the raw disk block.
**b. Multiprocessor systems:** If CPU 1 caches a variable and modifies it, CPU 2 must not read the outdated value from main memory or its own local cache. Hardware protocols (like MESI) are required.
**c. Distributed systems:** If Client A caches a file from a server and modifies it, Client B must be informed that its cached copy of the file is now invalid.

**1.15 Identify several advantages and several disadvantages of open-source operating systems. Include the types of people who would find each aspect to be an advantage or a disadvantage.**
*Advantages:* Free to use (advantage for students/startups), source code can be audited for security and modified (advantage for developers/researchers).
*Disadvantages:* Lack of official, guaranteed commercial support (disadvantage for enterprise IT managers), potential lack of drivers for proprietary hardware (disadvantage for end-users).

**1.16 How do clustered systems differ from multiprocessor systems? What is required for two machines belonging to a cluster to cooperate to provide a highly available service?**
Clustered systems consist of multiple autonomous computers connected via a network (loosely coupled), whereas multiprocessor systems share a single physical machine, memory, and clock (tightly coupled). To provide high availability, clustered machines require shared storage (like a SAN) and software to monitor each other's health (heartbeats) to trigger failovers.

**1.17 What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?**
The main difficulty is guaranteeing that the OS can respond to events and complete tasks within strict, fixed-time constraints (deadlines).

**1.18 Direct memory access is used for high-speed I/O devices in order to avoid increasing the CPU’s execution load.**
**a. How does the CPU interface with the device to coordinate the transfer?** The CPU writes control parameters (source, destination, bytes to transfer) into the DMA controller's registers.
**b. How does the CPU know when the memory operations are complete?** The DMA controller sends an interrupt to the CPU when the transfer is finished.
**c. Does this process interfere with the execution of the user programs?** Yes, both the DMA and CPU share the memory bus. When DMA is transferring data, it may steal memory cycles from the CPU (cycle stealing), slightly slowing down user program execution.

**1.19 Identify which of the functionalities listed below need to be supported by the operating system for (a) handheld devices and (b) real-time systems.**
a. Batch programming: Not highly needed for either.
b. Virtual memory: Often limited or not used in real-time systems (to avoid page fault delays); historically limited in handhelds, though modern ones use it.
c. Time sharing: Important for handhelds to run multiple apps; less critical for strict real-time systems which prioritize scheduling based on deadlines rather than fair time-sharing.

**1.20 Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes?**
1. Virtualization: A hypervisor or Virtual Machine Manager (VMM) mode that has higher privileges than the guest OS kernel mode.
2. System services rings: Dividing the OS kernel itself into layers of privileges (e.g., core kernel vs. device drivers) to isolate faults.

**1.21 Define the essential properties of the following types of operating systems:**
a. Batch: Groups similar jobs to maximize CPU utilization; no user interaction during execution.
b. Interactive: Immediate response to user input.
c. Time sharing: CPU switches rapidly among multiple interactive users.
d. Real time: Strict timing constraints and deadlines for processing.
e. Network: Provides features across a network, like file sharing across independent computers.
f. Parallel: Multiple CPUs sharing memory to run tasks faster.
g. Distributed: OS managing a group of distinct computers to appear as a single system.
h. Clustered: Nodes working together closely, usually for high availability and load balancing over a network.
i. Handheld: Optimized for low power, touch interfaces, and limited resources.

**1.22 Describe the differences between symmetric and asymmetric multiprocessing. What are three advantages and one disadvantage of multiprocessor systems?**
In symmetric multiprocessing (SMP), all processors are peers and perform all tasks. In asymmetric multiprocessing, one boss processor assigns tasks to worker processors.
*Advantages:* Increased throughput, economy of scale (shared peripherals), increased reliability/fault tolerance.
*Disadvantage:* Increased OS and hardware complexity.

**1.23 The issue of resource utilization shows up in different forms in different types of operating systems. List what resources must be managed carefully in the following settings:**
a. Mainframe: CPU time, memory, I/O bandwidth.
b. Workstations connected to servers: Network bandwidth, server response time.
c. Handheld computers: Battery power, limited memory.

**1.24 What is the purpose of interrupts? What are the differences between a trap and an interrupt? Can traps be generated intentionally by a user program? If so, for what purpose?**
Interrupts alert the CPU to asynchronous events that require immediate attention. An interrupt is hardware-generated, while a trap is a software-generated interrupt caused either by an error (e.g., division by zero) or a specific request. Yes, user programs intentionally generate traps (using instructions like `syscall` or `int`) to request operating system services (system calls).

**1.25 Consider an SMP system. Illustrate with an example how data residing in memory could in fact have two different values in each of the local caches.**
If variable X is 5 in memory. CPU 1 reads X, caching 5. CPU 2 reads X, caching 5. CPU 1 adds 1 to X, making it 6 in its local cache. Before CPU 1 writes the new value back to main memory and before a cache coherency protocol invalidates CPU 2's cache, CPU 2 still has X=5 in its cache, while CPU 1 has X=6.

**1.26 Consider a computing cluster consisting of two nodes running a database. Describe two ways in which the cluster software can manage access to the data on the disk. Discuss the benefits and disadvantages of each.**
1. Asymmetric (Active/Standby): Node A runs the database; Node B just monitors. *Benefit:* Simple to implement, no data conflicts. *Disadvantage:* Node B's hardware is wasted during normal operation.
2. Symmetric (Active/Active): Both nodes run the database and access the disk. *Benefit:* Better performance and utilization. *Disadvantage:* Highly complex, requires a Distributed Lock Manager (DLM) to prevent data corruption.

---

## Chapter 2: Operating-System Structures

**2.1 What are the five major activities of an operating system with regard to file management?**
1. Creating and deleting files.
2. Creating and deleting directories.
3. Supporting primitives for manipulating files and directories.
4. Mapping files onto secondary storage.
5. Backing up files on stable storage media.

**2.2 What are the three major activities of an operating system with regard to memory management?**
1. Keeping track of which parts of memory are currently being used and by whom.
2. Deciding which processes (or parts thereof) and data to move into and out of memory.
3. Allocating and deallocating memory space as needed.

**2.3 Why is a just-in-time compiler useful for executing Java programs?**
A JIT compiler translates Java bytecode into native machine language at runtime, rather than interpreting it line-by-line. This significantly improves execution speed while maintaining the platform-independence of the bytecode.

**2.4 The services and functions provided by an operating system can be divided into two main categories. Briefly describe the two categories and discuss how they differ.**
1. Services for the user: Functions that make the system easier to use (User interface, program execution, I/O operations, file-system manipulation, communications, error detection).
2. Services for system efficiency: Functions that ensure efficient operation of the system itself (Resource allocation, accounting, protection, and security).

**2.5 Why is the separation of mechanism and policy desirable?**
It allows for maximum flexibility. Policy determines *what* will be done, while mechanism determines *how* it will be done. Separating them means you can change the policy (e.g., prioritizing GUI tasks over background tasks) without rewriting the underlying mechanisms (e.g., the context switching code).

**2.6 Would it be possible for the user to develop a new command interpreter using the system-call interface provided by the operating system?**
Yes. A command interpreter (shell) is just a standard user-level program that reads text input and executes appropriate system calls (like `fork` and `exec`) to run other programs.

**2.7 What is the purpose of the command interpreter? Why is it usually separate from the kernel?**
Its purpose is to read commands from the user or a file and execute them. It is separate from the kernel because it is prone to changes (users have different preferences for shells) and separating it keeps the kernel smaller and more secure.

**2.8 What is the main advantage for an operating-system designer of using a virtual-machine architecture? What is the main advantage for a user?**
*Designer:* Easy to test and debug new operating systems without disrupting the host system or needing dedicated hardware.
*User:* The ability to run multiple different operating systems concurrently on the same hardware.

**2.9 It is sometimes difficult to achieve a layered approach if two components of the operating system are dependent on each other. Identify a scenario in which it is unclear how to layer two system components that require tight coupling of their functionalities.**
The virtual memory subsystem and the storage (file) subsystem. Virtual memory needs the storage subsystem to swap pages to disk (backing store), meaning VM should be above storage. However, the storage subsystem often uses virtual memory to buffer and cache files in memory, meaning storage should be above VM.

**2.10 What is the main advantage of the layered approach to system design? What are the disadvantages of using the layered approach?**
*Advantage:* Modularity simplifies debugging and system verification. A layer can be debugged without concern for the layers above it.
*Disadvantages:* It is difficult to accurately define the layers without circular dependencies. It also tends to be less efficient due to the overhead of passing data and system calls through multiple layers.

**2.11 What is the relationship between a guest operating system and a host operating system in a system like VMware? What factors need to be considered in choosing the host operating system?**
The host OS controls the physical hardware and provides the virtualization layer (hypervisor), while the guest OS runs as an isolated application on top of the host. Factors for choosing a host OS include hardware compatibility, performance overhead, security, and virtualization support (e.g., kernel-level hypervisors).

**2.12 Describe three general methods for passing parameters to the operating system.**
1. Pass the parameters in registers.
2. Store the parameters in a block (or table) in memory, and pass the address of the block as a parameter in a register.
3. Push the parameters onto the stack, and have the operating system pop them off.

**2.13 What is the main advantage of the microkernel approach to system design? How do user programs and system services interact in a microkernel architecture? What are the disadvantages of using the microkernel approach?**
*Advantage:* Easy to extend the OS, highly reliable, and secure because most services run in user space. If a service crashes, the kernel doesn't crash.
*Interaction:* Via message passing.
*Disadvantage:* Performance overhead due to frequent context switching and message passing between user space and kernel space.

**2.14 What system calls have to be executed by a command interpreter or shell in order to start a new process?**
In UNIX-like systems, a `fork()` system call is used to create a new process, followed by an `exec()` system call to replace the newly created process's memory space with a new program.

**2.15 What are the two models of interprocess communication? What are the strengths and weaknesses of the two approaches?**
1. Message Passing: *Strength:* Easy to implement in distributed systems, avoids conflicts. *Weakness:* Slower due to system call overhead.
2. Shared Memory: *Strength:* Maximum speed and convenience since memory is read/written directly. *Weakness:* Requires complex synchronization mechanisms (locks) to avoid data corruption.

**2.16 Discuss the pros and cons of the Synthesis approach to kernel design and system-performance optimization (where the kernel assembles routines within kernel space).**
*Pros:* Extremely fast performance due to optimized, shortened execution paths and reduced overhead for system calls.
*Cons:* Extremely difficult to write, debug, and maintain. Assembling code at runtime can introduce severe security vulnerabilities and stability risks.

**2.17 In what ways is the modular kernel approach similar to the layered approach? In what ways does it differ from the layered approach?**
*Similar:* Both break the OS into logical, manageable components (abstraction).
*Different:* The layered approach is strictly hierarchical (Layer N can only use Layer N-1). The modular approach allows any module to call any other module, providing more flexibility and better performance without strict ordering.

**2.18 How could a system be designed to allow a choice of operating systems from which to boot? What would the bootstrap program need to do?**
The system uses a boot manager program. The initial bootstrap program (in firmware/BIOS) loads the boot manager from a fixed location on the disk. The boot manager understands the disk partitions, presents a menu to the user, and then loads the specific kernel of the chosen OS into memory and executes it.

**2.19 What are the advantages and disadvantages of using the same system-call interface for manipulating both files and devices?**
*Advantages:* Simplicity and uniformity. A user program can read from a disk file or a terminal using the exact same `read()` command.
*Disadvantages:* Loss of functionality. Specific devices might have advanced features or controls that cannot be easily accessed through a generic file interface.

**2.20 Describe how you could obtain a statistical profile of the amount of time spent by a program executing different sections of its code. Discuss the importance of obtaining such a statistical profile.**
You can use a profiling tool that issues periodic timer interrupts. At each interrupt, the tool records the current value of the program counter. By analyzing these samples, you can see which code sections are executed most frequently. This is critical for optimization, allowing developers to focus their efforts on the most CPU-intensive parts of the code.

**2.21 Why do some systems store the operating system in firmware, while others store it on disk?**
Systems like embedded devices, simple appliances, or older consoles store the OS in firmware (ROM/EEPROM) because it allows for instant booting, the OS is small, and the hardware doesn't have or need a disk drive. General-purpose computers store the OS on disk because it is large, needs frequent updates, and the disk allows for a modular, expandable system.




**Two programming examples where multithreading does not provide better performance:**

  

1. **Strictly Sequential Algorithms:** A program calculating a sequence where each step is entirely dependent on the result of the previous step (e.g., calculating the Fibonacci sequence). Because the tasks cannot be executed in parallel, creating threads only adds context-switching overhead without any speed benefit.
    
      
    
2. **Short-Lived, Simple Computations:** A script that performs a very fast, simple mathematical calculation or searches a small array. The time and CPU resources required for the operating system to create, manage, and destroy the threads will take longer than simply executing the computation sequentially.
    
      
    

**Which components of program state are shared across threads in a multithreaded process?**

  

- **b. Heap memory** (Shared)
    
      
    
- **c. Global variables** (Shared)
    
      
    

_(Note: Register values and Stack memory are strictly private to each individual thread, as they keep track of the thread's independent execution state and function calls)._

  

**Performance implications for the many-to-many model (User threads > Processors):**

  

- **a. Kernel threads < processors:** The program cannot fully utilize the hardware. Even if multiple user threads are ready to run and processors are idle, the OS only schedules kernel threads. The maximum true parallelism is bottlenecked by the number of kernel threads.
    
      
    
- **b. Kernel threads = processors:** The program can achieve maximum hardware parallelism, with all processors theoretically running a thread simultaneously. However, if one kernel thread blocks (e.g., due to a page fault or a blocking I/O call), that processor will sit idle because there are no backup kernel threads allocated to the program to take its place.
    
      
    
- **c. Processors < kernel threads < user threads:** This provides the optimal balance. The program can utilize all processors simultaneously. If one kernel thread blocks for an I/O operation, the OS can swap in one of the extra kernel threads onto that processor, maintaining maximum hardware utilization.
    
      
    

**What are two differences between user-level threads and kernel-level threads? Under what circumstances is one better?**

  

1. **Management and Visibility:** User-level threads are managed entirely by a user-space thread library and are invisible to the operating system kernel. Kernel-level threads are managed directly by the OS.
    
      
    
2. **Blocking Behavior:** If a user-level thread makes a blocking system call (like reading a file), the kernel blocks the entire process, halting all other user threads inside it. If a kernel-level thread blocks, the OS can simply schedule a different kernel thread from the same process.
    
      
    

- **When User-Level is better:** When the application is highly compute-bound, requires massive amounts of threads, and rarely performs blocking I/O. User threads are much faster to create and context-switch because they do not require a system call (mode switch to the kernel).
    
      
    
- **When Kernel-Level is better:** When the application frequently performs blocking I/O or needs to truly run in parallel on a multiprocessor system.
    
      
    

**Can a multithreaded solution using multiple user-level threads achieve better performance on a multiprocessor system than on a single-processor system?** No. Because user-level threads are entirely invisible to the operating system, the OS treats the entire application as a standard single-threaded process. The kernel will only allocate one processor to this process at a time. Therefore, all user-level threads will simply time-share a single processor, regardless of how many physical processors the hardware actually has.

  

**What resources are used when a thread is created? How do they differ from those used when a process is created?**

  

- **Thread Creation:** A thread is lightweight. Creating one only requires allocating a small data structure (a Thread Control Block), which contains a register set, a program counter, and a stack. It shares the code, data, and OS resources (like open files) of its parent process.
    
      
    
- **Process Creation:** A process is heavyweight. Creating one requires allocating a completely new memory address space, building a large Process Control Block (PCB), duplicating and initializing OS resources, and copying the parent's code and data. It is significantly more memory and CPU-intensive.
    
      
    

**Under what circumstances does a multithreaded solution using multiple kernel threads provide better performance than a single-threaded solution on a single-processor system?** When the application frequently performs operations that cause it to wait, such as blocking I/O (reading from a disk or network) or handling page faults. In a single-threaded program, a blocking operation forces the entire application to halt and wait. With multiple kernel threads, if one thread blocks, the OS can immediately context-switch to another thread in the same application, allowing useful computation to overlap with the I/O wait time.