# Chapter 4: Threads — Comprehensive Summary and Guide

## 1. Overview and Motivation

### What is a Thread?
A **thread** is a single sequential flow of control within a process. It is often called a **lightweight process (LWP)** because it is the fundamental unit of CPU utilization. 
* While a traditional process has its own heavy-weight address space, code, and file descriptors, multiple threads can exist *inside* a single process, sharing the same memory space, global variables, and open files while maintaining their own independent execution stack and register set.

### Why Multithreading?
1. **Responsiveness:** If an interactive application (like a web browser or word processor) runs on a single thread, a long-running operation (like downloading a large file or spelling checking) can freeze the entire user interface. Multithreading allows one thread to handle UI events while background threads perform tasks.
2. **Resource Sharing:** Threads automatically share the memory and resources of their parent process. Sharing memory between separate processes requires complex mechanisms like shared memory or message passing.
3. **Economy:** Creating a brand new process involves heavy overhead (allocating new page tables, memory maps, etc.). Thread creation is much faster and lighter; context-switching between threads is also much less expensive than switching between heavy processes.
4. **Scalability:** In modern multiprocessor and multicore architectures, threads can run truly in parallel across different cores.

> **Real-World Analogy:** Imagine a restaurant kitchen. 
> * **Single-threaded process:** One chef does everything—takes orders, chops vegetables, grills steak, washes dishes, and serves food. If they get stuck chopping onions, the whole kitchen halts.
> * **Multithreaded process:** A team of chefs (threads) working in the same kitchen (process). They share the same pantry and stove (resources), but each has a specific job (one grills, one chops, one handles the register), allowing the restaurant to operate smoothly and handle multiple customers at once.

---

## 2. Multicore Programming

Modern CPUs have multiple cores or hardware threads (e.g., hyper-threading). This shifts the burden onto programmers to design software that utilizes hardware concurrency effectively.

### Challenges in Multicore Programming
* **Dividing activities (Task decomposition):** Splitting work into separate concurrent tasks.
* **Balance:** Ensuring all cores stay busy rather than having one core do 90% of the work while others sit idle.
* **Data splitting:** Dividing data structures so that threads don't step on each other's toes.
* **Data dependency:** Managing situations where Task B requires the output of Task A.
* **Testing and debugging:** Multithreaded bugs (like race conditions and deadlocks) are notoriously difficult to reproduce and fix.

### Concurrency vs. Parallelism
* **Concurrency:** A system can support more than one task making progress by rapidly interleaving tasks on a single core (time-slicing).
* **Parallelism:** A system can perform *more than one task simultaneously* across multiple physical cores or processors.

### Types of Parallelism
1. **Data Parallelism:** Distributes subsets of the *same* data across multiple cores, performing the exact same operation on each piece.
   * *Example:* Adding two massive arrays of numbers $A$ and $B$. Core 1 adds indices $0$ to $999$, Core 2 adds indices $1000$ to $1999$, etc.
2. **Task Parallelism:** Distributes entirely *different* threads across cores, with each thread performing a unique operation.
   * *Example:* Core 1 fetches data from a database, Core 2 formats the user interface, Core 3 runs a background analytics script.

### Amdahl's Law
Amdahl's Law calculates the theoretical maximum speedup ($S$) of an application when adding more processor cores ($N$), given that an application contains both a serial (non-parallelizable) portion ($S$) and a parallel portion ($1 - S$):

$$\text{speedup} \le \frac{1}{S + \frac{1 - S}{N}}$$

* **Key Takeaway:** If an application is $75\%$ parallel and $25\%$ serial ($S = 0.25$), moving from 1 core to 2 cores gives a speedup of $1.6\times$. As $N$ approaches infinity, the maximum speedup is bounded by $1/S$ (in this case, $1 / 0.25 = 4\times$). The serial portion imposes a strict bottleneck on performance gains.

---

## 3. Multithreading Models

Threads exist at two levels: **User Threads** (managed by user-space thread libraries) and **Kernel Threads** (supported directly by the operating system kernel). To connect them, operating systems use three primary multithreading models:

### A. Many-to-One Model ($M:1$)
* **Mechanism:** Many user-level threads are mapped to a single kernel thread.
* **Pros & Cons:** Thread management is very fast because it happens in user space. However, if one thread makes a blocking system call (e.g., waiting for I/O), the *entire process blocks* because the kernel only sees one thread. Also, multiple threads cannot run in parallel on multicore systems.
* *Examples:* Solaris Green Threads, GNU Portable Threads.

### B. One-to-One Model ($1:1$)
* **Mechanism:** Each user-level thread maps directly to a dedicated kernel thread.
* **Pros & Cons:** Provides maximum concurrency. If one thread blocks, other threads can continue running. Multiple threads can run in parallel across multiple cores. However, creating a user thread requires creating a corresponding kernel thread, which increases system overhead, and some OSes restrict the total number of threads.
* *Examples:* Windows, Linux, modern Solaris.

### C. Many-to-Many Model ($M:N$)
* **Mechanism:** Multiplexes many user-level threads onto a smaller or equal number of kernel threads.
* **Pros & Cons:** The OS can create a sufficient number of kernel threads without overwhelming the system. If a thread blocks, the kernel can schedule another thread on a separate kernel thread.
* *Examples:* Older versions of Solaris, Windows with the ThreadFiber package.

### D. Two-Level Model
* A variation of the Many-to-Many model that also allows a specific user thread to be permanently bound to a specific kernel thread.

---

## 4. Thread Libraries

A thread library provides programmers with an API for creating and managing threads. Three major libraries are widely used:

### 1. POSIX Pthreads
* A standard IEEE POSIX ($1003.1c$) specification for thread creation and synchronization. It defines *behavior*, not implementation. Commonly used in UNIX-based systems (Linux, macOS, Solaris).

> **Pthreads Code Example (Summation):**
> ```c
> #include <pthread.h>
> #include <stdio.h>
> #include <stdlib.h>
> 
> int sum; /* shared data */
> void *runner(void *param); /* thread function */
> 
> int main(int argc, char *argv[]) {
>     pthread_t tid; 
>     pthread_attr_t attr;
>     
>     pthread_attr_init(&attr);
>     pthread_create(&tid, &attr, runner, argv[1]);
>     pthread_join(tid, NULL);
>     
>     printf("sum = %d\n", sum);
>     return 0;
> }
> 
> void *runner(void *param) {
>     int upper = atoi(param);
>     sum = 0;
>     for (int i = 1; i <= upper; i++) {
>         sum += i;
>     }
>     pthread_exit(0);
> }
> ```

### 2. Windows Threads
* Native API used in Windows environments (`CreateThread`, `WaitForSingleObject`, etc.) utilizing a $1:1$ kernel thread model.

### 3. Java Threads
* Managed by the Java Virtual Machine (JVM). Java threads are typically implemented on top of the host operating system's native thread library. They can be created by extending the `Thread` class or implementing the `Runnable` interface.

---

## 5. Implicit Threading

As applications grow to use hundreds or thousands of threads, manual management becomes extremely error-prone. **Implicit threading** shifts thread creation and management from the programmer to compilers and run-time libraries.

### Common Approaches:
1. **Thread Pools:** Create a fixed number of threads at startup. When a task arrives, it is handed to a thread from the pool. Once finished, the thread returns to the pool to await new work. 
   * *Analogy:* A taxi stand. Taxis (threads) wait in a queue for passengers (tasks) rather than building a brand new taxi every time someone needs a ride.
2. **OpenMP:** A set of compiler directives and APIs for C, C++ and Fortran that automatically parallelize shared-memory blocks.
   * *Example:* `#pragma omp parallel for` automatically splits a loop across available CPU cores.
3. **Grand Central Dispatch (GCD):** Apple’s technology for macOS and iOS that places code blocks into serial or concurrent dispatch queues, managing thread pools automatically behind the scenes.

---

## 6. Threading Issues & Advanced Concepts

### 1. Semantics of `fork()` and `exec()`
* If a thread calls `fork()`, does the new process duplicate *all* threads, or just the single thread that called `fork()`? Most UNIX systems provide both variants. 
* If `exec()` is called right after, the entire process (including all its threads) is replaced by a new program anyway.

### 2. Signal Handling (UNIX)
* Signals are asynchronous interrupts used to notify a process of events (e.g., division by zero, Ctrl+C interrupt).
* In a multithreaded program, where should a signal go? Options include delivering it to the specific thread it applies to, to every thread, to specific designated threads, or assigning a single thread to receive all process signals.

### 3. Thread Cancellation
Terminating a thread before it has completed its work.
* **Asynchronous Cancellation:** Immediately terminates the target thread. (Dangerous if the thread was holding a shared lock or modifying shared memory).
* **Deferred Cancellation:** The target thread periodically checks whether it should cancel, allowing it to exit safely at a designated **cancellation point**.

### 4. Thread-Local Storage (TLS)
* While local variables exist only during a single function call, and global variables are shared across all threads, **TLS** gives each thread its own unique copy of data that persists *across* function invocations. It is especially useful when using thread pools where you cannot pass custom parameters directly.

### 5. Scheduler Activations
* Used in $M:N$ and Two-Level models to bridge user and kernel threads. It utilizes **Lightweight Processes (LWPs)** as virtual processors and uses **upcalls** (kernel-to-application notifications) to ensure the application always has the correct number of kernel threads allocated.

---

## 7. Operating System Examples

### Windows Threads
* Implements a $1:1$ model.
* Core data structures include:
  * **ETHREAD (Executive Thread Block):** Kernel space; points to the parent process and KTHREAD.
  * **KTHREAD (Kernel Thread Block):** Kernel space; contains scheduling/synchronization info and the kernel stack.
  * **TEB (Thread Environment Block):** User space; contains the thread ID, user-mode stack, and thread-local storage.

### Linux Threads
* Linux does not distinguish heavily between processes and threads; it refers to both as **tasks**.
* Threads are created using the versatile `clone()` system call. Flags like `CLONE_VM` (share memory space), `CLONE_FILES` (share open files), and `CLONE_SIGHAND` (share signal handlers) dictate whether the new task acts as a separate process or a lightweight thread sharing the parent's environment.