# Operating System Concepts - Chapter 3 (Processes)
## Comprehensive Exam Question & Answer Bank

---

### Section 1: Process Concept & Memory Layout

#### Question 1
**Explain the fundamental differences between a program and a process. Under what circumstances can a single program correspond to multiple processes?**

**Answer:**
* **Program vs. Process:** A **program** is a passive entity stored on disk as an executable file (a sequence of instructions). A **process** is an active entity—a program in execution with a program counter, CPU registers, and assigned system resources.
* **One-to-Many Relationship:** A single program becomes multiple processes when executed multiple times concurrently by one or more users. For example, if three users run the `gcc` compiler simultaneously, there is one program file on disk, but three distinct active processes exist in main memory, each with its own state, stack, and data section.

---

#### Question 2
**Describe the four major sections of a process in memory. Specify the direction in which dynamic memory structures grow.**

**Answer:**
1. **Text Section:** Contains the executable code (read-only instruction stream).
2. **Data Section:** Stores global and static variables initialized before execution.
3. **Heap:** Dynamically allocated memory requested at runtime (e.g., via `malloc()` or `new`). It grows **upward** toward higher memory addresses.
4. **Stack:** Temporary storage for function call frames, local variables, function parameters, and return addresses. It grows **downward** toward lower memory addresses.

---

#### Question 3
**What occurs in the process memory layout when a recursive function executes indefinitely without a base case? Which memory section is affected?**

**Answer:**
Indefinite recursion continuously pushes new stack frames (containing parameters, return addresses, and local variables) onto the **Stack**. As a result, the stack grows downward toward the heap until it exceeds its allocated boundaries, causing a **Stack Overflow** runtime error and process crash.

---

### Section 2: Process States & Process Control Block (PCB)

#### Question 4
**List the five principal states of a process lifecycle and describe the exact trigger that causes each state transition.**

**Answer:**
1. **New $\rightarrow$ Ready:** Admitted by the OS long-term scheduler into main memory.
2. **Ready $\rightarrow$ Running:** Dispatched by the CPU short-term scheduler.
3. **Running $\rightarrow$ Ready:** Interrupted by the OS (e.g., timer interrupt / time-slice expiration) or preemption.
4. **Running $\rightarrow$ Waiting:** Process requests an I/O operation or waits for an event signal.
5. **Waiting $\rightarrow$ Ready:** I/O operation finishes or the waited event completes.
6. **Running $\rightarrow$ Terminated:** Execution completes normally via `exit()` or abnormally via an exception/abort call.

---

#### Question 5
**What is a Process Control Block (PCB)? List at least six distinct pieces of information maintained inside a PCB.**

**Answer:**
A PCB (or Task Control Block) is a kernel data structure holding all operational context and metadata associated with a specific process.
* **Key Components:**
  1. *Process State* (New, Ready, Running, Waiting, Terminated)
  2. *Process ID (PID)*
  3. *Program Counter (PC)*
  4. *CPU Registers* (accumulators, index registers, stack pointers)
  5. *CPU Scheduling Information* (priority levels, queue pointers)
  6. *Memory-Management Information* (page tables, base/limit registers)
  7. *Accounting Information* (elapsed CPU time, execution time limits)
  8. *I/O Status Information* (allocated devices, open file descriptors)

---

#### Question 6
**Define a Context Switch. Why is context switching considered system overhead, and how can hardware design mitigate this overhead?**

**Answer:**
* **Definition:** A context switch is the task of stopping the execution of a running process ($P_0$), saving its state to its PCB ($PCB_0$), and loading the saved context from another process's PCB ($PCB_1$) into hardware registers so $P_1$ can run.
* **Overhead:** During a context switch, the system performs no useful computation for user processes. The time spent switching is pure administrative overhead.
* **Hardware Mitigation:** Hardware providing multiple sets of CPU registers allows the OS to switch contexts by simply changing a register pointer, rather than physically copying register contents to and from RAM.

---

#### Question 7
**How is a process represented inside the Linux kernel? Name the specific C structure and at least three of its key fields.**

**Answer:**
* In Linux, processes are represented by the C structure `task_struct` (located in `<linux/sched.h>`).
* **Key Fields:**
  * `pid_t pid` (Process Identifier)
  * `long state` (Process state: running, runnable, stopped, etc.)
  * `struct task_struct *parent` (Pointer to parent process)
  * `struct list_head children` (List of child processes)
  * `struct files_struct *files` (Pointer to open file descriptors)
  * `struct mm_struct *mm` (Pointer to process memory layout)

---

### Section 3: CPU Scheduling & Queues

#### Question 8
**Differentiate between an I/O-bound process and a CPU-bound process. Which type should a scheduler prioritize to maintain balanced system performance?**

**Answer:**
* **I/O-Bound Process:** Spends more time performing I/O operations than calculations; exhibits many short CPU bursts followed by I/O requests.
* **CPU-Bound Process:** Spends most of its time performing computations; exhibits very long CPU bursts and infrequent I/O requests.
* **Priority Strategy:** A scheduler should prioritize I/O-bound processes. Because I/O bursts are short, executing an I/O-bound process quickly yields the CPU back, keeping I/O devices busy while CPU-bound processes utilize the remaining CPU cycles, maintaining high system throughput.

---

#### Question 9
**Compare the roles of the Short-Term Scheduler, Long-Term Scheduler, and Medium-Term Scheduler.**

**Answer:**

| Scheduler | Frequency of Execution | Primary Role |
| :--- | :--- | :--- |
| **Short-Term (CPU Scheduler)** | Very High (milliseconds) | Selects a process from the Ready Queue and assigns it to a CPU core. Must be extremely fast. |
| **Long-Term (Job Scheduler)** | Low (seconds/minutes) | Selects processes from disk and loads them into memory; controls the **degree of multiprogramming**. |
| **Medium-Term (Swapper)** | Intermediate | Removes partially executed processes from main memory to disk (Swap Out) and brings them back (Swap In) to manage memory pressure. |

---

#### Question 10
**Explain how multitasking is managed differently in mobile operating systems (iOS vs. Android) compared to traditional desktop operating systems.**

**Answer:**
* **iOS:** Prioritizes user interaction and battery management. Historically ran a single foreground application while suspending background apps in memory. Allows background execution only for restricted tasks (e.g., audio playback, location services, push notifications).
* **Android:** Supports parallel background processing with fewer restrictions. Apps use **Services**—background components without a UI—that continue running even when the main background application is suspended.

---

### Section 4: Operations on Processes (Creation & Termination)

#### Question 11
**Describe the UNIX process creation mechanism involving `fork()` and `exec()`. What does `fork()` return to the parent and child processes respectively?**

**Answer:**
* **Mechanism:** A parent creates a child using the `fork()` system call, which creates an exact duplicate copy of the parent's address space. The child then typically invokes `exec()` (e.g., `execlp()`) to overwrite its address space with a new executable program.
* **`fork()` Return Values:**
  * Returns **`0`** to the newly created child process.
  * Returns the **PID of the child process ($>0$)** to the parent process.
  * Returns a **negative integer ($<0$)** if process creation fails.

---

#### Question 12
**Analyze the C code snippet below. Assuming all system calls succeed, how many total processes (including the original parent) are created?**

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    return 0;
}
```

**Answer:**
* **Formula:** $2^n$ processes are created for $n$ sequential `fork()` calls.
* **Calculation:** With $n = 3$, total processes $= 2^3 = 8$ processes (1 original parent + 7 child processes).

---

#### Question 13
**Explain what happens to a process when it calls `exit()`. What is the role of `wait()` in process termination?**

**Answer:**
* **`exit()` Call:** The process requests the OS to delete it. The OS deallocates its physical memory, open file descriptors, and system resources. It retains only an exit status entry in the kernel process table.
* **`wait()` Call:** The parent process executes `wait(&status)` to read the child's exit status and process ID. Once `wait()` is called by the parent, the remaining process table entry of the child is completely purged.

---

#### Question 14
**Define a Zombie process and an Orphan process. How does an operating system resolve each state?**

**Answer:**
* **Zombie Process:** A child process that has finished execution (`exit()`), but whose parent has **not yet invoked `wait()`**. It remains in the process table.
  * *Resolution:* Cleaned up as soon as the parent executes `wait()`.
* **Orphan Process:** A child process whose parent process terminated without calling `wait()`.
  * *Resolution:* Adopted by the root system process (`init` or `systemd`, PID = 1), which periodically invokes `wait()` to clear terminated children.

---

#### Question 15
**What is Cascading Termination? Is it initiated by user processes or the operating system?**

**Answer:**
Cascading termination is a mechanism where, if a parent process terminates (either normally or abnormally), the operating system automatically terminates all of its child, grandchild, and descendant processes. It is initiated by the operating system on platforms that do not permit child processes to exist without an active parent.

---

#### Question 16
**Describe the multiprocess architecture of the Google Chrome web browser. Why does it use separate processes instead of single-threaded execution?**

**Answer:**
Chrome splits browser tasks across three process types:
1. **Browser Process:** Manages UI, address bar, network, and disk I/O.
2. **Renderer Process:** Parses HTML, CSS, JavaScript, and renders layouts. A unique renderer process is created for each tab/website.
3. **Plug-in Process:** Runs extensions/plugins in isolation.
* **Advantage:** Prevents application-wide crashes. If a single web page crashes or contains malicious scripts, only its isolated Renderer process crashes (sandboxed), while the main browser interface and other tabs remain operational.

---

### Section 5: Interprocess Communication (IPC)

#### Question 17
**What are Cooperating Processes? List four reasons why an operating system design allows process cooperation.**

**Answer:**
Cooperating processes are processes that can affect or be affected by other processes executing concurrently.
* **Reasons for Cooperation:**
  1. *Information Sharing:* Allowing simultaneous access to shared data files.
  2. *Computation Speedup:* Breaking tasks into sub-tasks to run in parallel on multi-core systems.
  3. *Modularity:* Dividing system functions into discrete cooperative modules.
  4. *Convenience:* Enabling individual users to run multiple interactive tasks at once.

---

#### Question 18
**Compare the two primary models of IPC: Shared Memory and Message Passing.**

**Answer:**

| Characteristic | Shared Memory | Message Passing |
| :--- | :--- | :--- |
| **Mechanism** | processes share a mapped memory region directly. | System calls (`send`/`receive`) pass messages through the OS kernel. |
| **Performance** | **Faster**; zero kernel intervention after memory region setup. | **Slower**; requires kernel system calls and data copying. |
| **Synchronization** | User application must explicitly manage synchronization. | Handled automatically by kernel primitives. |
| **Best Suited For** | Large data exchange on local multi-core machines. | Distributed systems or sending small data blocks across networks. |

---

#### Question 19
**In a bounded-buffer shared-memory implementation with array length $N = \text{BUFFER\_SIZE}$, why can only $N - 1$ items be stored simultaneously in the simple circular queue algorithm?**

**Answer:**
The algorithm uses two variables: `in` (points to the next free buffer slot) and `out` (points to the first occupied slot).
* **Buffer Empty Condition:** `in == out`
* **Buffer Full Condition:** `((in + 1) % BUFFER_SIZE) == out`
If all $N$ slots were filled, `in` would increment around to equal `out`, making the "Full" state indistinguishable from the "Empty" state (`in == out`). Therefore, one buffer slot remains empty to unambiguously separate empty and full conditions.

---

#### Question 20
**Given a bounded-buffer implementation with `BUFFER_SIZE = 5`, `in = 4`, and `out = 0`. Is the buffer empty, full, or containing items? How many items are stored?**

**Answer:**
* Check Full: `((4 + 1) % 5) == 0` $\rightarrow$ `(5 % 5) == 0` $\rightarrow$ `0 == 0` (True).
* The buffer is **FULL**.
* Number of items stored $= \text{BUFFER\_SIZE} - 1 = 5 - 1 = 4$ items.

---

#### Question 21
**Explain the difference between Symmetric Direct Addressing and Asymmetric Direct Addressing in IPC message passing.**

**Answer:**
* **Symmetric Direct Addressing:** Both sender and receiver must explicitly name each other:
  * `send(P, message)` – Send to process $P$.
  * `receive(Q, message)` – Receive from process $Q$.
* **Asymmetric Direct Addressing:** Only the sender names the recipient; the receiver uses a generic placeholder variable to receive messages from any process:
  * `send(P, message)` – Send to process $P$.
  * `receive(id, message)` – Receive from any process; `id` is set to the sender's identity.

---

#### Question 22
**What is Indirect Communication in message passing? Describe three ownership/selection strategies when multiple processes share a single mailbox and a message arrives.**

**Answer:**
In **Indirect Communication**, messages are sent to and received from intermediate storage structures called **mailboxes** or **ports** (`send(A, msg)`, `receive(A, msg)`).
* **Strategies when $P_1$ sends to Mailbox $A$, and both $P_2$ and $P_3$ attempt to receive:**
  1. Limit communication links so a mailbox connects to at most two processes.
  2. Allow only one process at a time to execute a `receive()` operation.
  3. Allow the system to arbitrarily select the receiver, notifying the sender who received it.

---

#### Question 23
**Define the four combinations of Synchronization in Message-Passing systems.**

**Answer:**
1. **Blocking Send:** The sending process is blocked until the message is received by the recipient or mailbox.
2. **Non-Blocking Send:** The sending process delivers the message and immediately resumes operation.
3. **Blocking Receive:** The receiving process blocks until a message becomes available.
4. **Non-Blocking Receive:** The receiving process retrieves either a valid message or a null indicator without waiting.

---

#### Question 24
**What is a Rendezvous in IPC message passing? Under what specific synchronization condition does it occur?**

**Answer:**
A **Rendezvous** is a strict, synchronous point of arrival and data transfer between a sender and receiver process. It occurs when **both `send()` and `receive()` are blocking primitives**. The first process to reach the communication call blocks until the second process arrives.

---

#### Question 25
**List and describe the three Message Buffering capacity implementations available to a communication link.**

**Answer:**
1. **Zero Capacity:** Queue length of $0$. Link cannot hold messages. Sender **must block** until receiver fetches the message (enforces Rendezvous).
2. **Bounded Capacity:** Finite queue length of $n$ messages. Sender blocks if the queue is full.
3. **Unbounded Capacity:** Infinite queue length. Sender **never blocks**.

---

### Section 6: Advanced IPC Examples (POSIX, Mach, Windows)

#### Question 26
**Outline the sequential POSIX C API calls required for two processes to establish, write, read, and delete a shared memory region.**

**Answer:**
1. **`shm_open()`:** Creates or opens a named shared memory object, returning a file descriptor.
2. **`ftruncate()`:** Configures the size of the shared memory object in bytes.
3. **`mmap()`:** Maps the shared memory file descriptor into the process's virtual memory address space, returning a pointer.
4. *(Data read/write operations occur directly via memory pointers)*
5. **`shm_unlink()`:** Removes the shared memory object name from the file system.

---

#### Question 27
**How does the Mach operating system implement IPC? Name its default system mailboxes and its primary message handling syscalls.**

**Answer:**
* Mach is microkernel-based and handles communication entirely via **messages** (even system calls are messages).
* **Default Mailboxes:** Each created task receives two initial system mailboxes:
  1. *Kernel Mailbox* (used for kernel-task communication)
  2. *Notify Mailbox* (used by the kernel to send system event notifications)
* **Primary Syscalls:** `msg_send()`, `msg_receive()`, `msg_rpc()`. Ports are created via `port_allocate()`.

---

#### Question 28
**Explain the operation of Advanced Local Procedure Calls (ALPC) in Windows OS.**

**Answer:**
ALPC is a message-passing facility used for communication between processes on the **same Windows machine**.
1. The client opens a handle to the server's published **Connection Port Object** and sends a connection request.
2. The server creates two private communication ports (**Client Communication Port** and **Server Communication Port**) and passes the handle back to the client.
3. Small messages ($\le 256$ bytes) are passed directly via the message queue. Larger payloads use a **Shared Section Object** allocated between the processes.

---

### Section 7: Client-Server Communication (Sockets, RPC, Pipes)

#### Question 29
**Define a Socket. What constitutes a socket identifier, and what is the role of well-known ports?**

**Answer:**
* **Socket:** An endpoint for network communication between two applications.
* **Identifier:** Formed by concatenating an **IP Address** and a **Port Number** (e.g., `146.86.5.20:1625`).
* **Well-Known Ports:** Ports below 1024 (e.g., Port 80 for HTTP, Port 22 for SSH, Port 21 for FTP) reserved for standard system services.

---

#### Question 30
**What is the Loopback IP address? Give its numerical IP and explain its utility during application development.**

**Answer:**
* **Loopback IP:** `127.0.0.1`
* **Utility:** Points directly to the local host operating the system. It allows developers to test client-server socket code locally on a single machine without requiring a physical network connection.

---

#### Question 31
**Explain the components and workflow of a Remote Procedure Call (RPC) system.**

**Answer:**
RPC abstracts client-server interprocess communication so a remote function call appears identical to a local function call.
1. **Client Stub:** Locates the server procedure, **marshalls** parameters (serializes data into a unified byte stream), and sends the network message.
2. **Server Stub:** Listens on a designated port, unpacks marshalled parameters, and calls the local procedure on the server host.
3. Output values follow the reverse path back to the client stub.

---

#### Question 32
**What is External Data Representation (XDR) in RPC systems, and why is it essential?**

**Answer:**
XDR is a standardized data formatting specification used in RPCs to resolve architecture differences between heterogeneous machine architectures communicating across networks (e.g., resolving **Big-Endian** vs. **Little-Endian** byte ordering or differing structure padding).

---

#### Question 33
**What is the role of a Matchmaker (Rendezvous) service in an RPC framework?**

**Answer:**
A Matchmaker service runs on a server host at a known port. When a client wants to call an RPC procedure, it queries the matchmaker on the server machine to look up which port number the required RPC daemon is currently listening on.

---

#### Question 34
**Compare Ordinary Pipes (Anonymous Pipes) and Named Pipes (FIFOs).**

**Answer:**

| Feature | Ordinary Pipes (Anonymous) | Named Pipes (FIFOs) |
| :--- | :--- | :--- |
| **Directionality** | Unidirectional (1-way). | Bidirectional (2-way). |
| **Relationship Requirement** | Requires explicit Parent-Child relationship. | No parent-child relationship required; accessible by unrelated processes. |
| **Lifespan** | Exists only while processes are running. | Persists in the file system until explicitly removed. |
| **Network Capability** | Local system only. | UNIX FIFOs: Local only; Windows Named Pipes: Supports network communication. |

---

#### Question 35
**In UNIX ordinary pipe implementations, what do `fd[0]` and `fd[1]` represent? Which end is used by a producer, and which by a consumer?**

**Answer:**
UNIX `pipe(int fd[2])` creates a unidirectional pipe accessed via two file descriptors:
* **`fd[0]`:** The **Read-End** of the pipe (used by the **Consumer** process).
* **`fd[1]`:** The **Write-End** of the pipe (used by the **Producer** process).

---

#### Question 36
**Consider an application where Process $A$ writes logs to a pipe and Process $B$ reads them. If Process $A$ writes faster than Process $B$ can read using an ordinary pipe, what happens when the pipe buffer fills up?**

**Answer:**
Ordinary pipes use a bounded kernel memory buffer. When the pipe buffer becomes full, any subsequent call to `write()` by Process $A$ will **block** until Process $B$ reads enough data from `fd[0]` to free up space in the pipe buffer.

---

#### Question 37
**Analyze the C code below. Trace execution and determine what output string is printed by the parent process.**

```c
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        value += 15;
        return 0;
    }
    else if (pid > 0) {
        wait(NULL);
        printf("PARENT: value = %d\n", value);
        return 0;
    }
}
```

**Answer:**
* **Output:** `PARENT: value = 5`
* **Explanation:** `fork()` creates an exact duplicate of the parent process memory space for the child. The child updates its own isolated copy of `value` ($5 + 15 = 20$). The parent's copy of `value` remains $5$. When the parent executes `printf()` after `wait()`, it prints its own unmodified variable value ($5$).

---

#### Question 38
**Why does Shared Memory IPC require explicit user-level synchronization mechanisms, whereas Message Passing does not?**

**Answer:**
* **Shared Memory:** The OS maps a shared memory region directly into the virtual address space of user processes. Once mapped, accesses bypass the kernel completely. Therefore, the OS kernel cannot monitor or coordinate concurrent memory writes, requiring applications to implement locks, mutexes, or semaphores.
* **Message Passing:** Data transfer relies on kernel system call primitives (`send`/`receive`). Because the OS kernel manages the message queues directly, it enforces internal synchronization and safety automatically.