# Comprehensive Study Guide: Operating System Concepts - Chapter 3 (Processes)

---
page fault:
time slice
premption
thread in the same memory can share memory, but each thread needs its own cpu concept. 
Bookeeping: record keeping
difference between dispatch and scheduling
cpu burst
IO Bound process could be a reason of 
Banker algorithm
## 1. Process Concept

### Core Definitions
* **Program:** A **passive** entity stored on disk as an executable file.
* **Process:** An **active** entity—a program in execution. It progresses sequentially.
* **Multiprogramming/Time-Sharing:** Allows multiple processes to run concurrently by rapidly switching CPU time among them.

---

### Memory Layout of a Process

A process's address space in main memory is divided into four primary segments (typically mapped from low memory address $0$ to `max` high memory address):

```
+-----------------------+  Max Memory
|        Stack          |  (Grows Downwards ↓)
|          |            |
|          v            |
|                       |
|          ^            |
|          |            |
|        Heap           |  (Grows Upwards ↑)
+-----------------------+
|        Data           |  (Global & Static variables)
+-----------------------+
|        Text           |  (Program Code / Executable Instructions)
+-----------------------+  0
```

1. **Text Section:** Contains the compiled program executable code (read-only instruction stream).
2. **Data Section:** Stores global and static variables.
3. **Heap:** Memory dynamically allocated at runtime (e.g., using `malloc()` in C or `new` in C++/Java).
4. **Stack:** Temporary data storage for function calls, including:
   * Function parameters
   * Return addresses
   * Local variables

> **Intuitive Example (The Recipe Analogy):**
> * **Program:** A recipe printed in a cookbook sitting on a bookshelf (passive, static).
> * **Process:** A chef actively baking the cake using the recipe, mixing ingredients, keeping track of timers, and moving around the kitchen (active execution).
> * **Text:** The actual step-by-step printed text of the recipe.
> * **Data:** Pre-measured ingredients sitting on the counter ready for the whole session (global variables).
> * **Heap:** Extra space on the counter requested on-demand when mixing unexpected additional ingredients.
> * **Stack:** Sticky notes used temporarily while working on a sub-step (e.g., making frosting), which are discarded once that step finishes.

---

### Process States

As a process executes, its operational state transitions through five primary states:

```
                  [Admitted]               [Scheduler Dispatch]
   (NEW) ------------------------> (READY) --------------------> (RUNNING) ----> [Exit] ----> (TERMINATED)
                                     ^                             |
                                     |----- [Interrupt] -----------|
                                     ^                             |
                                     |-- [I/O or Event Completion] |
                                     |                             v
                                     +-------- (WAITING) <---------+
                                               [I/O or Event Wait]
```

1. **New:** The process is in the process of being created.
2. **Ready:** The process is loaded into main memory and is waiting to be assigned to a CPU core by the scheduler.
3. **Running:** Instructions are currently being executed on the CPU core.
4. **Waiting (Blocked):** The process is waiting for an external event to occur (e.g., I/O completion or receipt of a signal).
5. **Terminated:** The process has finished its execution and is awaiting cleanup.

---

### Process Control Block (PCB) / Task Control Block

The **PCB** is a kernel data structure containing all information associated with a specific process:

* **Process State:** Current state (New, Ready, Running, Waiting, Terminated).
* **Process Identification (PID):** Unique numerical ID assigned by the OS.
* **Program Counter (PC):** Indicates the address of the next instruction to execute for this process.
* **CPU Registers:** Contents of accumulator registers, index registers, stack pointers, and general-purpose registers.
* **CPU Scheduling Information:** Process priority, pointers to scheduling queues, and other scheduling parameters.
* **Memory-Management Information:** Value of base and limit registers, page tables, or segment tables depending on the OS memory model.
* **Accounting Information:** Amount of CPU time used, clock time elapsed, execution time limits, process account numbers.
* **I/O Status Information:** List of allocated I/O devices, list of open files descriptors.

> **Implementation Note (Linux):** In the Linux kernel, a process is represented by the C struct `task_struct` (found in `<linux/sched.h>`). It contains fields like `pid_t pid`, `long state`, `struct task_struct *parent`, `struct list_head children`, `struct files_struct *files`, and `struct mm_struct *mm`.

---

### Context Switch

A **Context Switch** occurs when the CPU switches execution from one process ($P_0$) to another ($P_1$). 

```
Process P0                 Operating System                 Process P1
   |                              |                             |
   |-- Executing                  |                             |
   |   (Interrupt/Syscall)        |                             |
   +----------------------------->|                             |
   |   [Idle]                     |-- Save state to PCB0        |  [Idle]
   |                              |-- Reload state from PCB1    |
   |                              +---------------------------->|
   |                              |                             |-- Executing
   |                              |   (Interrupt/Syscall)       |
   |                              |<----------------------------+
   |   [Idle]                     |-- Save state to PCB1        |   [Idle]
   |                              |-- Reload state from PCB0    |
   |<-----------------------------+                             |
   |-- Executing                  |                             |
```

* **Overhead:** During context switching, the system performs no useful computation. Switch speed depends on hardware support (e.g., multiple register sets accelerate switching).

---

## 2. Process Scheduling

### Objectives & Types of Workloads
* **Multiprogramming Goal:** Have some process running at all times to maximize CPU utilization.
* **Time-Sharing Goal:** Switch the CPU among processes so frequently that users can interact with each program while it runs.
* **Workload Characteristics:**
  * **I/O-Bound Process:** Spends more time doing I/O than computation; characterized by many short CPU bursts.
  * **CPU-Bound Process:** Spends more time doing computations; characterized by a few very long CPU bursts.

---

### Scheduling Queues
1. **Job Queue:** Set of all processes in the system (including those on disk).
2. **Ready Queue:** Set of all processes residing in main memory, ready and waiting to execute on a CPU core.
3. **Device Queues (I/O Queues):** Set of processes waiting for a specific I/O device (e.g., disk drive, terminal).

---

### Types of Schedulers

| Scheduler Type | Also Known As | Frequency of Invocation | Primary Function / Key Concept |
| :--- | :--- | :--- | :--- |
| **Short-Term** | CPU Scheduler | Very Frequent (milliseconds) | Selects a process from the **Ready Queue** and allocates the CPU core to it. Must be extremely fast. |
| **Long-Term** | Job Scheduler | Infrequent (seconds/minutes) | Selects processes from disk and loads them into memory. Controls the **degree of multiprogramming**. |
| **Medium-Term** | Swapper | Intermediate | Removes processes from main memory to disk (Swap Out) and brings them back (Swap In) to reduce memory pressure. |

> **Degree of Multiprogramming:** The total number of processes maintained in main memory simultaneously.

---

### Mobile OS Multitasking Architectures

* **iOS:**
  * Historically restricted true background processes due to resource/battery constraints.
  * **Foreground Process:** Controls the UI display.
  * **Background Processes:** Suspended in memory or restricted to specific tasks (e.g., audio playback, location services, push notifications).
* **Android:**
  * Runs both foreground and background tasks simultaneously with fewer restrictions.
  * Uses **Services** (background components without a UI) that run even if the parent application is suspended.

---

## 3. Operations on Processes

### Process Creation

Processes are organized hierarchically as a **tree structure** originating from an initial root process (e.g., `init` or `systemd` with PID = 1 in Unix/Linux).

#### Resource Sharing Options
1. Parent and child share all system resources.
2. Child shares a subset of the parent's resources.
3. Parent and child share no resources.

#### Execution Options
1. Parent and child execute concurrently.
2. Parent waits (`wait()`) until all or some children terminate.

#### UNIX Implementation Mechanics

```
Parent Process
     |
  fork() -------> Child Process (Exact duplicate of parent)
     |                 |
  wait()            exec()  (Overwrites memory with new executable code)
     |                 |
     |              exit()  (Terminates child and returns exit code)
     |<----------------+
  Resumes
```

* `fork()`: Creates a new process by cloning the parent's address space. Returns:
  * `0` to the child process.
  * Child's `PID` (> 0) to the parent process.
  * `< 0` if creation fails.
* `exec()` (e.g., `execlp()`): System call used after `fork()` to replace the process's address space with a completely new binary program.

---

### Process Termination

* **Normal Termination:** A process executes its final statement and calls `exit(status)` to request deletion by the OS. Returns status data to its waiting parent via `wait(&status)`.
* **Abnormal Termination (Abort):** Parent calls `abort()` to terminate a child due to:
  * Overallocated/exceeded resources.
  * Assigned task no longer required.
  * Cascading termination enforced by the system.

#### Special Process States: Zombies and Orphans

| Term | Cause / Condition | Resolution |
| :--- | :--- | :--- |
| **Zombie Process** | A process has terminated via `exit()`, but its parent has **not yet called `wait()`**. Its entry remains in the process table. | Cleaned up once the parent invokes `wait()`. |
| **Orphan Process** | A parent process terminates without calling `wait()`, leaving its child processes still running. | Adopted by the `init`/`systemd` process, which periodically calls `wait()` to collect their status and release their PIDs. |

---

### Case Study: Chrome Multiprocess Architecture

Modern browsers prevent single-tab crashes from breaking the entire application by separating concerns into distinct process types:

1. **Browser Process:** Manages the main GUI, address bar, user inputs, and disk/network I/O.
2. **Renderer Process:** Parses HTML, CSS, JavaScript, and renders the layout. A separate renderer process is spawned for each opened tab/website. Runs in a restricted **sandbox** to prevent unauthorized disk/network access.
3. **Plug-in Process:** Runs each active plug-in (Flash, ActiveX, etc.) in isolation.

---

## 4. Interprocess Communication (IPC)

Processes executing concurrently can be **Independent** (cannot affect or be affected by other processes) or **Cooperating** (can affect or be affected by other processes).

### Reasons for Process Cooperation
1. **Information Sharing** (e.g., shared files)
2. **Computation Speedup** (parallelizing sub-tasks across multi-core processors)
3. **Modularity** (dividing system functions into discrete tasks)
4. **Convenience** (allowing user to perform multiple tasks simultaneously)

---

### Models of Interprocess Communication

```
   (a) Shared Memory                        (b) Message Passing
+-------------------+                    +-------------------+
|    Process A      |                    |    Process A      |
|  +-------------+  |                    +---------|---------+
|  | Shared Mem  |  |                              | send(msg)
|  +-------------+  |                    +---------v---------+
|    Process B      |                    |  Kernel Queue     |
+-------------------+                    +---------|---------+
                                                   | receive(msg)
                                         +---------v---------+
                                         |    Process B      |
                                         +-------------------+
```

| Feature | Shared Memory | Message Passing |
| :--- | :--- | :--- |
| **Mechanism** | Region of memory mapped into address space of participating processes. | Messages exchanged via kernel primitives (`send`/`receive`). |
| **Speed** | **Fastest** (Memory speeds, no kernel intervention after setup). | Slower (Requires system calls and kernel copy overhead). |
| **Data Size** | Excellent for large volumes of data. | Best for smaller message payloads. |
| **Synchronization** | Must be manually managed by user applications (e.g., locks, semaphores). | Automatically handled by kernel message passing routines. |
| **Hardware Fit** | Best for local multi-core systems. | Ideal for distributed/networked systems. |

---

### The Producer-Consumer Problem

A foundational paradigm for cooperating processes: a **Producer** process generates information that a **Consumer** process reads.

* **Unbounded Buffer:** Unlimited buffer size; consumer waits for new items, producer never has to wait.
* **Bounded Buffer:** Fixed buffer size $N$. Producer waits if the buffer is full; consumer waits if the buffer is empty.

#### Bounded Buffer Implementation (Shared Memory Solution)

```c
#define BUFFER_SIZE 10

typedef struct {
    // Shared data fields
} item;

item buffer[BUFFER_SIZE];
int in = 0;  // Pointers to the next free position
int out = 0; // Pointers to the first full position
```

> **Important Constraint:** This simple circular array algorithm can only use **$\text{BUFFER\_SIZE} - 1$** elements simultaneously. 
> * Buffer is **Empty** when: `in == out`
> * Buffer is **Full** when: `((in + 1) % BUFFER_SIZE) == out`

**Producer Logic:**
```c
item next_produced;

while (true) {
    /* Produce an item */
    
    // Busy wait if buffer is full
    while (((in + 1) % BUFFER_SIZE) == out)
        ; /* Do nothing */

    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
}
```

**Consumer Logic:**
```c
item next_consumed;

while (true) {
    // Busy wait if buffer is empty
    while (in == out)
        ; /* Do nothing */

    next_consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    /* Consume the item */
}
```

---

### Message-Passing Systems

Provides two basic operations: `send(message)` and `receive(message)`.

#### 1. Communication Links & Addressing

##### Direct Communication
Processes explicitly address each other by name:
* `send(P, message)`: Send a message directly to process `P`.
* `receive(Q, message)`: Receive a message from process `Q`.
* **Properties:** A link is established automatically between every pair of communicating processes; exactly one link exists per pair; usually bidirectional.

##### Indirect Communication
Messages are routed to and received from intermediate shared objects called **Mailboxes** or **Ports** (each having a unique identifier):
* `send(A, message)`: Send a message to mailbox `A`.
* `receive(A, message)`: Receive a message from mailbox `A`.
* **Properties:** Link established only if processes share a common mailbox; a link can be associated with multiple processes.
* **Mailbox Ownership Options if multiple receivers exist ($P_1$ sends to Mailbox $A$, $P_2$ and $P_3$ receive):**
  1. Allow link association with at most two processes.
  2. Allow only one process at a time to execute a `receive()`.
  3. Let the system select the receiver arbitrarily and notify the sender.

---

#### 2. Synchronization Mechanisms

Message passing can be synchronous or asynchronous:

* **Blocking Send:** Sender is blocked until the message is received by the receiving process or mailbox.
* **Non-Blocking Send:** Sender delivers message and immediately resumes operation.
* **Blocking Receive:** Receiver blocks until a message becomes available.
* **Non-Blocking Receive:** Receiver retrieves either a valid message or a null indicator without waiting.

> **Rendezvous:** When both `send()` and `receive()` are **blocking**, a strict synchronous exchange occurs between sender and receiver.

---

#### 3. Buffering Capacity Options
1. **Zero Capacity:** Queue length of $0$. Sender **must block** until receiver completes reception (Rendezvous required).
2. **Bounded Capacity:** Queue length of $N$. Sender blocks only if queue is full.
3. **Unbounded Capacity:** Infinite queue size. Sender **never blocks**.

---

## 5. Real-World IPC System Examples

### POSIX Shared Memory API
POSIX shared memory is implemented using memory-mapped files via system calls:

1. `shm_open(name, O_CREAT | O_RDWR, mode)`: Creates or opens a shared memory object, returning a file descriptor (`shm_fd`).
2. `ftruncate(shm_fd, size)`: Configures the object size in bytes.
3. `mmap(..., shm_fd, ...)`: Maps the memory object into the process's virtual address space, returning a memory pointer.
4. `shm_unlink(name)`: Removes the shared memory object.

---

### Mach Operating System
* Kernels are message-based; even system calls are sent as internal messages.
* Tasks are created with two default mailboxes: **Kernel** and **Notify**.
* System calls: `msg_send()`, `msg_receive()`, `msg_rpc()`.
* Port creation: `port_allocate()`.

---

### Windows Advanced Local Procedure Calls (ALPC)
* Used for communication between processes on the **same system**.
* Uses **Connection Ports** and **Communication Ports**:
  1. Client sends connection request to server's connection port object.
  2. Server creates two private communication ports and hands one back to the client.
  3. Client and server use these dedicated handles to send messages or map a small shared section ($ \le 256$ bytes) for fast data exchange.

---

## 6. Client-Server Communication Models

```
 +------------------------+              +------------------------+
 |         Client         |              |         Server         |
 | Host: 146.86.5.20      |              | Host: 161.25.19.8      |
 | Socket: 146.86.5.20:1625--------------> Socket: 161.25.19.8:80 |
 +------------------------+              +------------------------+
```

### 1. Sockets
* A **Socket** is an endpoint for network communication identified by an **IP Address concatenated with a Port Number**.
* Example: `161.25.19.8:80` (Port 80 on host 161.25.19.8).
* Ports $< 1024$ are well-known ports reserved for standard services (e.g., HTTP = 80, FTP = 21, SSH = 22).
* **Loopback IP (`127.0.0.1`):** Refers locally to the host executing the code.

#### Java Socket Classes
* **TCP (Connection-oriented):** `ServerSocket` (Server) and `Socket` (Client).
* **UDP (Connectionless):** `DatagramSocket`.
* **Multicast:** `MulticastSocket` (delivers data to multiple hosts).

---

### 2. Remote Procedure Calls (RPC)

RPC abstracts network IPC to make remote calls look like local function invocations.

```
Client Process                               Server Process
+-------------------------+                  +-------------------------+
|  Client Code            |                  |  Server Procedure       |
|            |            |                  |            ^            |
|            v            |                  |            |            |
|  Client Stub            |                  |  Server Stub            |
|  (Marshalls Parameters) |                  |  (Unpacks Parameters)   |
+------------|------------+                  +------------^------------+
             | Network Message                            | Network Message
             +--------------------------------------------+
```

* **Stubs:** Code proxies on both sides:
  * **Client Stub:** Locates server, **marshalls** (packs) parameters into a network-independent payload, sends message over the network.
  * **Server Stub:** Receives network message, unpacks parameters, executes the local target procedure, and marshalls return values back.
* **External Data Representation (XDR):** Resolves architecture-dependent formatting discrepancies (e.g., Big-Endian vs. Little-Endian integer encoding).
* **Matchmaker Service (Rendezvous):** Dynamic lookup daemon on the server host that assigns dynamic port numbers to incoming client RPC calls.

---

### 3. Pipes

Pipes act as data conduits connecting two processes.

```
Ordinary Unidirectional Pipe:
Process A (Parent) ---> [ Write End: fd[1] ] === Pipe ===> [ Read End: fd[0] ] ---> Process B (Child)
```

#### Comparison of Pipe Types

| Property | Ordinary Pipes (Anonymous Pipes) | Named Pipes (FIFOs) |
| :--- | :--- | :--- |
| **Directionality** | Unidirectional (1-way communication). | Bidirectional (2-way communication). |
| **Relationship Needed?** | **Yes.** Requires explicit Parent-Child inheritance. | **No.** Unrelated processes can attach to it. |
| **Lifespan** | Exists only while processes are running. | Persists in the file system until explicitly deleted. |
| **OS Support** | Supported on UNIX & Windows. | Supported on UNIX & Windows. |
| **Network Support** | Local machine only. | UNIX FIFOs: Local machine; Windows: Networkable. |

---

## 7. Concept Self-Check & Glossary

* **PCB (Process Control Block):** Repository holding all process details needed to pause and resume execution seamlessly.
* **Context Switch Overhead:** The unproductive processor time lost while saving one process context and loading another into hardware registers.
* **Degree of Multiprogramming:** Count of active processes resident in main memory competing for CPU execution.
* **Zombie vs Orphan:** A Zombie is a dead child waiting for its parent to read its exit status; an Orphan is a live child whose parent has already died.
* **Cascading Termination:** System-enforced deletion of all child and descendant processes when a parent process is terminated.
* **Rendezvous:** Synchronous message passing where both sender and receiver block until message transfer completes.
* **Marshalling:** The process of serializing complex parameters into a unified format for cross-network transmission during RPC calls.