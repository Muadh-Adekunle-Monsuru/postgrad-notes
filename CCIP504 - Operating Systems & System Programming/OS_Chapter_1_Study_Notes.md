**Big picture:** A computer has hardware that can do work, applications that request work, and an OS that safely coordinates the work. Almost every chapter topic comes back to three questions: **Who gets a resource? How is work coordinated? How is the system protected?**

## Important slide-era clarifications

- **System call** means a request for a kernel service, not specifically a request to wait for I/O.
- **Blocking I/O** does not mean the whole CPU must sit idle: the OS can run other processes.
- **DMA** avoids CPU copying of every byte; the CPU still sets up and handles transfers.
- The slide illustrates a **mode bit** with 0/1; actual architectures can expose multiple privilege levels.
- **Linux** refers to the kernel; **Ubuntu** is a distribution. The entire OS is broader than the kernel alone.
- **Timer interrupts** allow preemption; they do not themselves fix infinite loops.

---


## 1. Operating system fundamentals

**Q. What is an operating system (OS)?**

**A.** Software that manages a computer’s hardware and provides services for applications. Think of it as the manager between apps and physical parts. Example: Linux lets a browser use memory, the CPU and network without controlling the hardware directly.

**Q. What are the main goals of an OS?**

**A.** Make a computer easy to use, run applications, share hardware efficiently, and keep the system safe and reliable. Memory cue: **Convenience, Efficiency, Protection**.

**Q. What are the four components of a computer system?**

**A.** **Users → Applications → Operating system → Hardware.** Example: you (user) type in a browser (app); Linux (OS) arranges for the keyboard and screen (hardware) to work.

**Q. What does it mean that the OS is a resource allocator?**

**A.** The OS decides which program gets resources such as CPU time, RAM, disk access and devices. Example: it shares CPU time between a browser and a music player.

**Q. What does it mean that the OS is a control program?**

**A.** The OS supervises program behavior and blocks unsafe or unauthorized operations. Example: a normal app cannot directly overwrite the memory of another app.

**Q. What is a kernel?**

**A.** The **core** of the OS that manages hardware, processes, memory and system calls. It stays available while the computer runs. Think: the engine of the OS, not the entire vehicle.

**Q. What is the difference between a kernel, an OS and an application?**

**A.** **Kernel:** core resource manager. **OS:** kernel plus supporting system software (usage varies). **Application:** software for a user task, e.g. Firefox. Linux is a kernel; Ubuntu is a complete Linux-based OS distribution.

**Q. What is a Linux distribution (distro)?**

**A.** A packaged operating system containing the Linux kernel plus utilities, libraries, package management and often a desktop environment. Examples: Ubuntu, Debian and Fedora.

**Q. How can I identify my Linux kernel and distribution?**

**A.** `uname -s` shows kernel name; `uname -r` shows kernel release; `cat /etc/os-release` shows distribution details. In your existing example: kernel name Linux; distro Ubuntu 24.04.4 LTS.

**Q. What is the difference between a system program and an application program?**

**A.** A **system program** helps provide or manage the computing environment (e.g. shell or service manager). An **application** performs a user task (e.g. browser or document editor). The boundary is not always perfectly sharp.


## 2. Booting and computer hardware

**Q. What happens when a computer boots?**

**A.** Firmware starts, initializes/checks important hardware, selects a boot path, runs a bootloader where applicable, and loads the OS kernel. The kernel then starts system services. Short version: **Firmware → Bootloader → Kernel → Services**.

**Q. What is a bootstrap program or bootloader?**

**A.** Software used to start loading the operating system. The slides use *bootstrap program* broadly; on modern PCs, UEFI firmware often launches a separate bootloader such as GRUB.

**Q. What is firmware?**

**A.** Low-level software stored in nonvolatile memory on a device. It starts or controls hardware before the main OS takes over. Examples: PC UEFI firmware, router firmware.

**Q. What is ROM, and how does it relate to firmware?**

**A.** **Read-only memory** traditionally stores instructions that remain after power-off. Modern firmware is usually held in rewritable nonvolatile flash rather than fixed ROM.

**Q. What is a CPU?**

**A.** The **Central Processing Unit** executes machine instructions: calculations, decisions and control of program execution. It is the computer’s main general-purpose processor.

**Q. What are CPU registers?**

**A.** Tiny, extremely fast storage locations inside a CPU core that hold values, addresses and execution state currently in use. Think: the CPU’s immediate workspace.

**Q. What is a program counter (PC)?**

**A.** A CPU register that identifies the location of the next instruction to execute (with architecture-specific details). It helps the CPU resume a paused task correctly.

**Q. What is a bus in computer architecture?**

**A.** A communication path carrying data and control signals among system components. The slide’s common-bus diagram is a simplified view; modern computers may use several different interconnects.

**Q. What is a device controller?**

**A.** Hardware that manages communication with a device or class of devices, such as a disk or USB controller. It receives commands and reports results to the CPU/OS.

**Q. What is a device driver?**

**A.** OS software that knows how to operate particular hardware through its controller. **Controller = hardware; driver = software.** Example: a Wi-Fi driver tells the Wi-Fi hardware what to do.

**Q. What is a buffer?**

**A.** Temporary storage for data while it is being moved or processed. Example: a disk controller holds incoming data briefly before transfer to RAM.

**Q. What does I/O mean?**

**A.** **Input/Output:** data entering or leaving the computer or a program. Examples: keyboard input, reading a disk, sending network packets, displaying a picture.

**Q. What does concurrent operation of CPU and I/O mean?**

**A.** The CPU can execute instructions while a device independently works on a transfer. Example: while a file is downloading, the CPU can keep your editor responsive.


## 3. Interrupts and I/O

**Q. What is an interrupt?**

**A.** A signal/event that temporarily redirects the CPU to handle something needing attention. Example: a disk controller signals that a read request completed. Memory cue: an **attention bell**.

**Q. Why do operating systems use interrupts?**

**A.** They let the CPU react to important events without continuously checking for them. Example: the CPU can run another process while a disk operation completes.

**Q. What is an interrupt service routine (ISR)?**

**A.** The handler code that runs when an interrupt occurs. It performs urgent interrupt-related work and helps the OS respond to the event.

**Q. What is an interrupt vector/table?**

**A.** A hardware/OS-defined table or mechanism used to find the appropriate interrupt handler. Think of it as a **directory of emergency contacts** for different events.

**Q. What happens when an interrupt is handled?**

**A.** The processor and OS preserve required execution state, identify the event, run the handler, and resume interrupted work or schedule another task. Saved state includes relevant registers and instruction location.

**Q. What is polling?**

**A.** Repeatedly checking a device or condition to see if something has changed. Example: asking “Is the printer done?” again and again instead of waiting for a notification.

**Q. What is the difference between polling and interrupts?**

**A.** **Polling:** CPU/software checks repeatedly. **Interrupt:** hardware signals that attention is needed. Polling can be useful, but unnecessary repeated checks waste work.

**Q. What is busy waiting (spinning)?**

**A.** A thread stays runnable and repeatedly checks a condition instead of sleeping. Example: `while (lock_is_busy) {}`. This can waste CPU time, though very short spins can sometimes be efficient.

**Q. What is a trap or exception?**

**A.** An event arising while executing instructions that transfers control to a handler. Examples: divide-by-zero error or a deliberate instruction used to enter the kernel. Terminology varies by CPU architecture.

**Q. How is a hardware interrupt different from a software exception/trap?**

**A.** A typical **hardware interrupt** comes from a device or timer and is asynchronous to the current instruction; an **exception/trap** arises as a result of executing an instruction. Both can transfer control to kernel code.

**Q. What is a system call?**

**A.** A controlled request by a user program for a service only the OS kernel can provide. Examples: open/read a file, create a process, allocate certain resources. It is **not** simply “waiting for I/O.”

**Q. How does a system call work in simple steps?**

**A.** **App requests service → CPU enters kernel mode → kernel checks/does the work → returns result → CPU resumes user mode.** Example: `read()` asks Linux to get bytes from a file.

**Q. What is synchronous (blocking) I/O?**

**A.** An operation in which the calling thread waits until the relevant I/O operation can complete before that call returns. Another thread/process may still use the CPU during the wait.

**Q. What is asynchronous I/O?**

**A.** An operation that can be started without the caller waiting immediately for its completion; the result is collected later via an event, completion notification or similar mechanism.

**Q. Does synchronous I/O always leave the CPU idle?**

**A.** **No.** A blocked process can sleep while the OS runs another ready process. The slide describes a primitive arrangement in which waiting could idle the CPU.

**Q. What is a device-status table?**

**A.** OS-maintained information about devices, such as device type, state and outstanding work. It helps the OS track which device is ready, busy or has completed a request.

**Q. What is Direct Memory Access (DMA)?**

**A.** A hardware-assisted technique that lets a device/controller transfer data to or from RAM without the CPU copying each byte. The CPU sets up the transfer and handles completion or errors.

**Q. Why does DMA improve performance?**

**A.** It reduces CPU involvement in bulk data transfer and often reduces interrupt overhead. Example: storage hardware can place a block of data into RAM while the CPU runs other instructions.

**Q. What is the difference between I/O with DMA and without DMA?**

**A.** **Without DMA:** CPU must participate more directly in moving data. **With DMA:** controller moves the bulk data; CPU mainly prepares and completes the operation. Modern details vary by device.

**Q. Does DMA mean the CPU does nothing for I/O?**

**A.** **No.** The CPU/OS typically configures the transfer, manages buffers and permissions, and processes completion notifications. DMA avoids byte-by-byte CPU copying.


## 4. Memory, storage and caching

**Q. What is main memory (RAM)?**

**A.** Fast working storage holding instructions and data that currently need to be accessed. **Volatile:** normal RAM contents disappear when power is lost. Analogy: your desk while working.

**Q. What is secondary storage?**

**A.** Long-term, usually nonvolatile storage for files and programs. Examples: SSD and hard disk. Analogy: filing cabinet, compared with RAM as your desk.

**Q. What does volatile memory mean?**

**A.** Memory that normally loses its contents when power is removed. Example: ordinary DRAM.

**Q. What does nonvolatile storage mean?**

**A.** Storage that preserves data without power. Examples: SSD, hard disk and firmware flash.

**Q. What is the basic storage hierarchy?**

**A.** **Registers → CPU cache → RAM → SSD/HDD** (roughly fastest/smallest to slower/larger). Faster storage generally costs more per byte and has less capacity.

**Q. What is a cache?**

**A.** A small, fast storage area keeping copies of data likely to be needed again. Analogy: keeping frequently used books on your desk instead of fetching them from a distant shelf.

**Q. What is a cache hit?**

**A.** The requested data is already in the cache, so it can be accessed quickly.

**Q. What is a cache miss?**

**A.** The requested data is not in the cache; the system must retrieve it from a slower level and may store a copy in the cache.

**Q. What is a cache replacement policy?**

**A.** A rule for deciding which cached item to evict when the cache is full. The goal is to keep the most useful data. Example idea: Least Recently Used (LRU).

**Q. What is locality of reference?**

**A.** Programs tend to reuse the same data or access nearby locations over short periods. This is why caches work well.

**Q. What is temporal locality?**

**A.** If data is used now, it is likely to be used again soon. Example: repeatedly updating the same loop counter. Memory cue: **temporal = time**.

**Q. What is spatial locality?**

**A.** If one memory address is used, nearby addresses may soon be used. Example: reading an array from first element to last. Memory cue: **spatial = space**.

**Q. How are caching and buffering different?**

**A.** **Caching** keeps copies to speed up future access. **Buffering** temporarily holds data to smooth a transfer or speed mismatch. Example: cached webpage versus audio playback buffer.

**Q. What is a magnetic disk track and sector?**

**A.** A **track** is a circular recording path on a traditional hard disk; a **sector** is a subdivision storing a fixed-size block of data. SSDs do not use physical spinning tracks.

**Q. Does 100 GB of free disk space mean 100 GB of RAM?**

**A.** **No.** Free disk space is room for persistent files; RAM is temporary working memory. `df -h` reports filesystem space; `free -h` reports RAM/swap usage.

**Q. Why can Linux use apparently free RAM for caching?**

**A.** Unused RAM can accelerate file access, and many caches are reclaimable when applications need memory. Look at **available** memory, not only **free** memory.

**Q. How do I check RAM pressure and disk capacity on Linux?**

**A.** For memory: `free -h` (and tools such as `vmstat`). For filesystem capacity: `df -h`. For directory sizes: `du -sh <path>`.


## 5. Processors and computer architectures

**Q. What is a multiprocessor system?**

**A.** A computer with multiple processors or processing units able to execute work in parallel, often sharing RAM and an OS. The slide uses “tightly coupled” for shared-memory designs.

**Q. What are the benefits of multiprocessing?**

**A.** **Higher throughput** (more work per time), **economy of scale** (sharing resources rather than duplicating everything), and potential **reliability improvements** when designs tolerate failure.

**Q. What is throughput?**

**A.** The amount of work completed per unit time. Example: number of jobs processed per second. It is different from response time for a single job.

**Q. What is symmetric multiprocessing (SMP)?**

**A.** Multiple processors/cores operate as peers under one OS and can generally run kernel and user work, accessing shared memory. Example: modern multicore desktop OS.

**Q. What is asymmetric multiprocessing (AMP)?**

**A.** Different processors have assigned or specialized roles, sometimes with one controlling others. Example: one processor handles management while another handles dedicated work.

**Q. What is a CPU core?**

**A.** An independent execution engine inside a physical CPU chip/package. A dual-core CPU contains two cores able to do useful work concurrently.

**Q. What is a logical CPU or hardware thread?**

**A.** An execution context the OS can schedule work on. A physical core may expose more than one logical CPU using simultaneous multithreading (SMT).

**Q. How many logical CPUs are there with 1 socket, 2 cores per socket and 2 threads per core?**

**A.** **1 × 2 × 2 = 4 logical CPUs.** A logical CPU is not the same as a complete physical core.

**Q. Why distinguish physical cores from logical CPUs?**

**A.** Logical CPUs sharing one physical core also share some execution resources, so doubling logical CPU count does not necessarily double performance.

**Q. What is a clustered system?**

**A.** Two or more separate computers (**nodes**) cooperate to provide a service or compute a job. Unlike SMP, they are distinct machines connected through a network.

**Q. What is high availability (HA)?**

**A.** Designing a service to keep working despite failures. Example: a backup server takes over if the primary server dies.

**Q. What is the difference between asymmetric and symmetric clustering?**

**A.** **Asymmetric:** one active node with another in standby. **Symmetric:** multiple nodes actively provide services and monitor one another. Real-world cluster designs have many variations.

**Q. What is a storage-area network (SAN)?**

**A.** A dedicated network or storage infrastructure giving servers block-level access to shared storage. Some clusters use SANs, but not every cluster requires one.

**Q. What is high-performance computing (HPC)?**

**A.** Using powerful processors and often many computers together to solve computation-heavy tasks such as scientific simulations. Work must be split so parts can run in parallel.

**Q. What is graceful degradation?**

**A.** A system keeps offering reduced service when a part fails instead of stopping entirely. Example: remaining servers handle fewer requests after one fails.


## 6. Multiprogramming, scheduling and protection

**Q. What is multiprogramming?**

**A.** Keeping multiple jobs available so that when one blocks, such as waiting for I/O, another can run on the CPU. Goal: **better CPU utilization**.

**Q. What is time-sharing or multitasking?**

**A.** The OS rapidly switches CPU time among runnable tasks, creating the experience that many applications run at once and keeping the system responsive.

**Q. What is the key difference between multiprogramming and time-sharing?**

**A.** **Multiprogramming:** minimize idle CPU time. **Time-sharing:** provide quick interactive responses by repeatedly dividing CPU time among tasks.

**Q. What is CPU scheduling?**

**A.** The OS deciding which ready process/thread should run next and for how long. Example: choosing between a browser, editor and background update.

**Q. What is a context switch?**

**A.** Switching CPU execution from one thread/process to another by saving the outgoing execution state and restoring the incoming state. This has some overhead.

**Q. What is concurrency?**

**A.** Making progress on multiple tasks during overlapping time periods. On one core, tasks can alternate; true simultaneous execution requires multiple execution resources.

**Q. What is parallelism?**

**A.** Literally executing multiple tasks at the same instant, such as two threads on different CPU cores. **Concurrency = overlap; parallelism = same time**.

**Q. What is swapping?**

**A.** Moving process memory between RAM and secondary storage to free RAM or resume a process. Modern virtual memory often moves individual pages rather than complete processes.

**Q. What is dual-mode operation?**

**A.** Hardware separates **user mode** (restricted application execution) from **kernel mode** (privileged OS execution) to protect the computer.

**Q. What is user mode?**

**A.** Restricted CPU execution mode for ordinary applications. Programs cannot directly run privileged instructions or freely access protected memory.

**Q. What is kernel mode?**

**A.** Privileged CPU execution mode where OS code can manage hardware, memory maps, interrupts and other protected operations.

**Q. What are privileged instructions?**

**A.** Operations allowed only in a privileged mode because misuse could compromise the computer. Example: controlling memory-management hardware or interrupt configuration.

**Q. What is a mode bit?**

**A.** A hardware representation of the current privilege level. The slide uses **0 = kernel, 1 = user** as an illustration; real CPUs may have more than two privilege levels.

**Q. Why do system calls require a switch into kernel mode?**

**A.** An app needs some protected services but must not gain unrestricted hardware access. The controlled transition allows the kernel to validate the request.

**Q. What is a timer interrupt and why is it useful?**

**A.** A hardware timer periodically or at a programmed time signals the CPU, giving the OS a chance to regain control and preempt a task that runs too long.

**Q. Can a timer stop a program from running an infinite loop?**

**A.** It can prevent the loop from monopolizing the CPU by enabling preemption; it does **not** automatically fix or terminate the loop.

**Q. What is starvation in an OS?**

**A.** A process waits excessively or indefinitely for CPU time or another resource because others keep being favored. Example: a low-priority task never gets scheduled.

**Q. What is fairness in scheduling?**

**A.** Making resource allocation sufficiently balanced so tasks/users receive an appropriate share and none is unfairly denied needed resources.


## 7. Processes and memory management

**Q. What is a program?**

**A.** A passive set of instructions stored as a file, such as an executable on disk. It is not executing just because the file exists.

**Q. What is a process?**

**A.** A **running instance of a program**, including its code, memory, execution state and OS-managed resources. Example: opening two browser instances can create multiple processes.

**Q. How is a process different from a program?**

**A.** **Program = recipe** (instructions on disk). **Process = cooking the recipe** (instructions actively running with ingredients/resources).

**Q. What is a thread?**

**A.** A sequence of execution within a process. Threads in the same process typically share its address space and resources, but each has its own execution state, stack and program counter.

**Q. What is the difference between a process and a thread?**

**A.** A **process** is a resource and protection boundary; a **thread** is a path of execution inside that process. Threads usually share memory with sibling threads.

**Q. What does single-threaded mean?**

**A.** A process has one thread of execution, with one active instruction sequence and its associated program counter.

**Q. What does multithreaded mean?**

**A.** A process has multiple threads that can make progress concurrently, each with its own execution state. Example: a browser handling UI work and background tasks.

**Q. What resources does a process need?**

**A.** CPU time, memory, access to files and I/O devices, plus initial execution state. The OS acquires and releases these resources as needed.

**Q. What does process termination involve?**

**A.** The process stops, and the OS reclaims or releases resources such as memory, file handles and scheduling records.

**Q. What is memory management?**

**A.** The OS tracking RAM use and deciding how to assign, protect, map, move and reclaim memory for processes.

**Q. What is memory allocation?**

**A.** Giving a process or kernel component usable memory. Example: a program requests memory for an array.

**Q. What is memory deallocation?**

**A.** Releasing memory so it can be reused. Example: memory freed when a process exits.

**Q. Why must processes be isolated in memory?**

**A.** So one process cannot accidentally or maliciously read/overwrite another process’s private data. The OS uses hardware memory protection to help enforce this.

**Q. What is virtual memory?**

**A.** An abstraction that gives each process a virtual address space, mapped to physical memory and possibly backed by storage. It supports isolation and flexible memory use. This adds detail beyond the slides.


## 8. Files, I/O services and security

**Q. What is storage management?**

**A.** The OS organizing how data is stored, located, read and written across storage devices, typically through filesystems.

**Q. What is a filesystem?**

**A.** Rules and data structures used to name, organize and access files/directories on storage. Examples: ext4, NTFS and FAT32.

**Q. What is the I/O subsystem?**

**A.** The OS components that offer consistent ways to use different devices, including drivers, buffering, caching and device coordination.

**Q. What is spooling?**

**A.** Placing work in a queue or temporary storage so a slow shared device can handle it in order. Example: print jobs waiting in a printer queue.

**Q. How do buffering, caching and spooling differ?**

**A.** **Buffering:** smooth a transfer. **Caching:** speed repeated access. **Spooling:** queue jobs for a shared/slower service. Examples: streaming audio buffer, file cache, print queue.

**Q. What is protection in an operating system?**

**A.** Rules and mechanisms controlling which users/processes may access resources. Example: file permissions preventing others from reading your private folder.

**Q. What is security in an operating system?**

**A.** Defending the system and data from attacks, misuse and unauthorized access. Example: updates, authentication, firewalls and exploit defenses.

**Q. What is the difference between protection and security?**

**A.** **Protection:** who is allowed to do what. **Security:** defending against threats that try to violate those rules or disrupt the system.

**Q. What is a denial-of-service (DoS) attack?**

**A.** An attempt to make a service unavailable, often by exhausting resources or overwhelming it with requests.


## 9. Networked computing and open source

**Q. What is client-server computing?**

**A.** A model where a **client** requests a service and a **server** responds. Example: your web browser requests a webpage from a website server.

**Q. What is a compute server?**

**A.** A server that performs processing or offers an application service for clients. Example: a database server handling queries.

**Q. What is a file server?**

**A.** A server that stores files and lets clients read/write them over a network. Example: a shared office file drive.

**Q. What is peer-to-peer (P2P) computing?**

**A.** A model in which network nodes can both request and provide services, rather than having permanently fixed client/server roles. Example: BitTorrent peers exchange pieces of a file.

**Q. How is P2P different from client-server?**

**A.** **Client-server:** service roles are usually organized around central servers. **P2P:** participating nodes may act as both clients and servers.

**Q. What is NAT?**

**A.** **Network Address Translation:** a router rewrites address information so multiple private devices can share a public network address.

**Q. What is a VPN?**

**A.** A **Virtual Private Network** creates a protected logical network connection over another network, often used for remote access.

**Q. What is a firewall?**

**A.** A system that allows or blocks network traffic based on rules. Example: allowing HTTPS traffic but denying unexpected inbound connections.

**Q. What is DDNS?**

**A.** **Dynamic DNS:** a service that updates a hostname when a device’s public IP address changes.

**Q. What does open-source software mean?**

**A.** Software whose license makes source code available with rights to use, inspect, modify and redistribute under stated conditions. Merely being able to view code does not automatically make a license open source.

**Q. What is the GPL?**

**A.** The **GNU General Public License**, a copyleft free-software license: redistributed modified covered software generally must remain under GPL terms and include corresponding source code as required by the license.

**Q. What is copyleft?**

**A.** A licensing approach requiring certain derivative distributions to preserve the same software freedoms, rather than allowing covered code to become proprietary.

**Q. What is the difference between source code and binary code?**

**A.** **Source code:** human-readable programming instructions. **Binary/executable code:** machine-oriented compiled form run by a computer.

**Q. What are examples of open-source operating systems?**

**A.** GNU/Linux distributions and BSD-family operating systems are key examples. Note: macOS contains open-source components but the complete operating system is not open source.


## Quick exam comparisons

| Pair | Remember the difference |
|---|---|
| Kernel / distribution | Core OS manager / complete packaged OS |
| Program / process / thread | Stored instructions / running instance / execution path inside it |
| Process / core / logical CPU | Software work unit / physical processor engine / OS-visible execution context |
| Interrupt / polling | Event calls for attention / software repeatedly checks |
| Trap / hardware interrupt | Event caused by executing an instruction / event often signaled by a device or timer |
| Blocking / asynchronous I/O | Caller waits for result / caller can move on and collect result later |
| DMA / CPU-driven transfer | Controller transfers bulk bytes / CPU performs more of the copying |
| RAM / disk | Fast temporary working storage / persistent mass storage |
| Buffer / cache / spool | Smooth transfer / save repeat lookup / queue jobs |
| Concurrency / parallelism | Overlapping progress / simultaneous execution |
| Multiprogramming / time-sharing | Keep CPU busy / keep interaction responsive |
| User mode / kernel mode | Restricted / privileged execution |
| Protection / security | Access control / defense against threats |
| SMP / cluster | Processors within shared-memory system / separate networked computers |

## Your practical questions, answered

**1. Kernel vs Linux distribution?** `uname -s` and `uname -r` identify the kernel family and release; `/etc/os-release` identifies the distribution. Your saved commands show **Linux** and **Ubuntu 24.04.4 LTS** respectively; the exact kernel release reflects the machine at the time you ran it.

**2. Logical CPUs?** 1 socket × 2 cores per socket × 2 threads per core = **4 logical CPUs**.

**3. Why is a physical core not a logical CPU?** A physical core contains hardware execution resources; SMT creates multiple OS-visible execution contexts sharing parts of one core. Four logical CPUs do not necessarily perform like four full cores.

**4. Does 100 GB filesystem space mean 100 GB RAM?** No. Disk space stores files persistently, RAM holds working instructions and data.

**5. Why does Linux cache data in RAM?** Because otherwise idle RAM is wasted; clean reclaimable cache can be released when applications need memory.

**6. Which Linux commands help with RAM pressure and storage?** `free -h` for a memory snapshot (look at *available*), `vmstat 1` for activity, and `df -h` for filesystem capacity. For a large directory use `du -sh path`.

**Source notes:** Slides pp. 4–38 and your original converted notes. Topics including locality of reference, starvation, virtualization detail, and the practical Linux commands were already present in your notes or have been added as clearly explained supplementary context.
