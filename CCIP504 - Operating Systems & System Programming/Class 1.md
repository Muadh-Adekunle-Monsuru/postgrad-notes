Starvation: Unable to reach computer resources
Program -> functions
Process -> Threads
Busy waiting: Busy waiting (also known as spinning) is a synchronization technique where a process or thread repeatedly checks a condition to determine if it can proceed. Instead of yielding the processor and entering a sleep or blocked state, the process remains active, continuously executing a loop until a specific flag, lock, or hardware status changes.
System call- request to the operating system to allow user to wait for I/O completion
# Chapter 1: Introduction to Operating Systems

## 1. What is an Operating System?
An operating system (OS) is a program that acts as an intermediary between a user of a computer and the computer hardware.
*   **Goals:** 
    *   Execute user programs and make solving user problems easier.
    *   Make the computer system convenient to use.
    *   Use computer hardware efficiently.
    *   Provide safety, integrity, and reliability.
*   **Roles of an OS:**
    *   **Resource Allocator:** Manages all resources (CPU, memory, I/O) and decides between conflicting requests for efficient and fair usage.
    *   **Control Program:** Controls the execution of programs to prevent errors and improper use of the computer, restricting access to resources.
*   **Definition:** There is no universally accepted definition. A good approximation is "everything a vendor ships when you order an operating system," but technically, the OS is the **kernel**—the one program running at all times on the computer. Everything else is either a system program or an application program.

## 2. Computer System Structure
A computer system can be divided into four components:
1.  **Hardware:** Provides basic computing resources (CPU, memory, I/O devices).
2.  **Operating System:** Controls and coordinates the use of hardware among applications and users.
3.  **Application Programs:** Define how system resources are used to solve computing problems (e.g., word processors, compilers, web browsers, databases).
4.  **Users:** People, machines, or other computers.

## 3. Computer Startup
*   **Bootstrap Program:** A program loaded at power-up or reboot.
*   Typically stored in ROM or EPROM (known as firmware).
*   It initializes all aspects of the system, loads the operating system kernel into memory, and starts its execution.

## 4. Computer-System Organization and Operation
*   One or more CPUs and device controllers connect through a common bus providing access to shared memory.
*   CPUs and devices execute concurrently, competing for memory cycles.
*   Each device controller is in charge of a particular device type and has its own local buffers.
*   The CPU moves data between main memory and local buffers.
*   I/O occurs from the device to the local buffer of the controller.
*   **Interrupts:** The device controller informs the CPU that it has finished its operation by causing an interrupt.

### Interrupts
*   An interrupt transfers control to the interrupt service routine, generally through the **interrupt vector** (which contains addresses of all service routines).
*   **Trap:** A software-generated interrupt caused by an error or a user request.
*   Operating systems are inherently **interrupt-driven**.
*   **Handling:** The OS preserves the CPU state by storing registers and the program counter, determines the interrupt type (via polling or a vectored interrupt system), and executes the specific code segment for that interrupt.


![[Pasted image 20261009110847.png]]

The timeline in  illustrates how a computer's CPU and I/O devices operate concurrently using an interrupt-driven model.

Here is the step-by-step breakdown of the cycle shown in the diagram:
- **Normal Execution:** Initially, the CPU is running a user program (labeled "user process executing") while the I/O device sits in an "idle" state.
   
- **I/O Request:** When an I/O request is initiated, the I/O device begins "transferring" data. Crucially, the CPU does not stop to wait for this transfer; it continues executing the user process simultaneously.
   
- **Transfer Completion & Interrupt:** Once the I/O device finishes moving the data, the transfer is marked "transfer done," triggering a hardware interrupt. The I/O device then returns to its "idle" state.
   
- **Interrupt Processing:** Upon receiving the interrupt, the CPU temporarily suspends the user process and shifts to "I/O interrupt processing". During this brief window, the operating system handles the completed I/O operation (such as updating device status tables or copying data from a local buffer).
   
- **Resumption:** After the interrupt is processed, the CPU resumes executing the normal user process exactly where it left off. The second half of the diagram shows this exact cycle repeating for a subsequent I/O request.

This diagram highlights a modern asynchronous I/O approach, preventing the CPU from wasting valuable cycles idling or busy-waiting for the physical device to finish its mechanical or electrical work.

### I/O Structure
*   **Synchronous I/O (Primitive):** After I/O starts, control returns to the user program only upon I/O completion. The CPU idles (wait instruction) until the next interrupt. Only one I/O request outstanding at a time.
*   **Asynchronous I/O (Modern):** After I/O starts, control returns to the user program without waiting. 
    *   Uses **System Calls** to let a process wait while other processes run.
    *   Maintains a **Device-status table** containing an entry for each I/O device (type, address, state). The OS indexes this table to track device status and handle interrupts.

### Direct Memory Access (DMA)
*   **CRITICAL CONCEPT:** Used for high-speed I/O devices able to transmit info at near memory speeds.
*   The device controller transfers entire *blocks* of data from buffer storage directly to main memory without CPU intervention.
*   Generates only **one interrupt per block**, instead of one per byte. 
*   Without DMA, system performance is significantly slower and erratic.

## 5. Storage Structure
*   **Main Memory:** The only large storage media the CPU can access directly (volatile).
*   **Secondary Storage:** An extension of main memory providing large, nonvolatile capacity.
    *   *Magnetic disks:* Platters covered with magnetic material, divided into tracks and sectors. Controlled by a disk controller.
    *   *Flash memory:* Solid-state, emulates magnetic disk file systems.
*   **Storage Hierarchy:** Organized by Speed, Cost, and Volatility.
*   **Caching:** The crucial principle of copying information into a faster storage system temporarily. Checked first before accessing slower storage. Used at many levels (hardware, OS, software). Proper cache size and replacement policies are major design problems.

**Locality of reference**
Locality of reference is a principle in computer science stating that a processor tends to access the same set of memory locations repetitively over a short period of time.
- **Temporal Locality:** If a particular memory location is accessed, it is highly likely to be accessed again in the near future (e.g., counters or variables executing within a loop).
- **Spatial Locality:** If a memory location is accessed, memory locations physically adjacent to it are highly likely to be accessed soon (e.g., iterating through items sequentially in an array).
Hardware and operating systems heavily exploit this predictable behavior to optimize performance, most notably by loading these clustered memory addresses into high-speed, fast-access hardware caches.
## 6. Computer-System Architecture
*   **Multiprocessor Systems:** (Parallel or tightly-coupled systems) are growing in importance.
    *   *Advantages:* Increased throughput, economy of scale, increased reliability (fault tolerance/graceful degradation).
    *   *Types:* Asymmetric Multiprocessing vs. **Symmetric Multiprocessing (SMP)**.
*   **Multi-Core:** A Dual-Core design places multiple CPU cores on the same chip, each with their own registers and local cache, sharing memory.
*   **Clustered Systems:** Multiple independent systems working together, usually sharing storage via a Storage-Area Network (SAN). Provides high-availability services.
    *   *Asymmetric clustering:* One machine is in hot-standby mode.
    *   *Symmetric clustering:* Multiple nodes run applications and monitor each other.
    *   Used heavily in High-Performance Computing (HPC), requiring parallelized applications.

## 7. Operating System Structure and Operations
*   **Multiprogramming:** Organizes jobs (code and data) so the CPU always has one to execute, preventing idle time. Keeps a subset of total jobs in memory and switches when one has to wait (e.g., for I/O).
*   **Timesharing (Multitasking):** A logical extension of multiprogramming. The CPU switches jobs so rapidly that users can interact with each job while it runs (response time < 1 second). 
*   **Dual-Mode Operation (CRUCIAL):**
    *   Allows the OS to protect itself and other system components.
    *   Hardware provides a **Mode Bit** (User mode = 1, Kernel mode = 0).
    *   Certain privileged instructions are only executable in Kernel mode.
    *   A System Call triggers a trap, switching the mode bit to 0 (kernel). Upon returning, it resets to 1 (user).
*   **Timers:** Used to prevent infinite loops or processes hogging resources. The OS sets a counter that decrements; when it hits zero, it generates an interrupt, passing control back to the OS.

## 8. Core Management Functions
### Process Management
*   A **process** is a program in execution (an active entity, whereas a program is passive).
*   Requires resources: CPU, memory, I/O, files, initialization data.
*   Single-threaded processes have one program counter; multi-threaded processes have one per thread.
*   The OS manages concurrency by multiplexing CPUs among processes/threads.

### Memory Management
*   Instructions and data must be in memory to execute.
*   Optimizes CPU utilization and user response time.
*   Involves keeping track of memory usage, deciding what to load/unload (swapping), and allocating/deallocating space.

### Storage Management & I/O Subsystem
*   Provides a uniform, logical view of information storage (File-System management).
*   **I/O Subsystem** hides the hardware peculiarities from the user. Includes memory management of I/O (buffering, caching, spooling) and handles device drivers.

### Protection and Security
*   **Protection:** Mechanisms for controlling access of processes/users to system resources.
*   **Security:** Defending the system against internal and external attacks (DoS, worms, viruses, identity theft).

## 9. Computing Environments
*   **Traditional / Office:** Evolving over time from batch terminals to connected PCs and network portals.
*   **Home Networks:** Feature WiFi, NAT, VPNs, DDNS, and Firewalls on "home" routers.
*   **Client-Server:** Compute-servers (database interfaces) and File-servers (storage interfaces) responding to client requests.
*   **Peer-to-Peer (P2P):** Distributed system where there is no strict client/server distinction. All nodes are peers. Uses discovery protocols or central lookup registries (e.g., Napster, Gnutella).

## 10. Open-Source Operating Systems
*   OSs made available in source-code format rather than closed-source binary (countering DRM).
*   Started by the Free Software Foundation (FSF) with the GNU Public License (GPL).
*   **Examples:** GNU/Linux, BSD UNIX (core of Mac OS X), Sun Solaris.
*   Widely used in web servers, appliances, routers, multimedia devices, and mini-laptops.



---
Practical

1. What is the difference between the kernel and a Linux distribution? Use your output as an example.
		riskgratis@rgtech:~$ uname -s 
		Linux
		riskgratis@rgtech:~$ uname -r
		7.0.0-34-generic
		riskgratis@rgtech:~$ cat /etc/os-release
		PRETTY_NAME="Ubuntu 24.04.4 LTS"
		NAME="Ubuntu"
		VERSION_ID="24.04"
		VERSION="24.04.4 LTS (Noble Numbat)"
		VERSION_CODENAME=noble
		ID=ubuntu
		ID_LIKE=debian
		HOME_URL="https://www.ubuntu.com/"
		SUPPORT_URL="https://help.ubuntu.com/"
		BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
		PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
		UBUNTU_CODENAME=noble
		LOGO=ubuntu-logo

2. A hypothetical system has 1 socket, 2 cores per socket and 2 threads per core. How many logical CPUs does it expose? Show your calculation.

3. Why should we distinguish a physical core from a logical CPU?

4. Does 100 GB of available filesystem space mean that the computer has 100 GB of RAM? Explain the distinction.
5. Why can Linux use RAM for caching even when applications may need more memory later?
6. Which command would you use to investigate RAM pressure, and which would you use when a filesystem is nearly full?