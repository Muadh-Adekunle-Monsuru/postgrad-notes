# Chapter 2: Operating-System Structures

Based on *Operating System Concepts* (9th Edition) by Silberschatz, Galvin, and Gagne.

---

## 1. Operating System Services

An operating system provides an environment for the execution of programs and delivers services to both users and system processes.

### A. User-Focused Services
These services provide functions designed to assist the user in interacting with and running software on the system:

* **User Interface (UI):** Provides a mechanism for users to communicate with the system.
  * *Command-Line Interface (CLI):* Uses text-based commands.
  * *Graphical User Interface (GUI):* Uses visual elements like windows, icons, and menus.
  * *Batch Interface:* Executes series of commands provided in batch scripts.
* **Program Execution:** Loads executable files into memory, executes them, and handles both normal termination and abnormal termination (errors).
* **I/O Operations:** Manages input/output requests (e.g., writing to disk, displaying on screen) on behalf of running user programs.
* **File-System Manipulation:** Provides routines for reading, writing, creating, deleting, searching, and managing file permissions and directory structures.
* **Communications:** Facilitates information exchange between processes on the same device or across a network.
  * *Shared Memory:* Multiple processes share a memory region.
  * *Message Passing:* Information packets are routed through the OS kernel.
* **Error Detection:** Continuously monitors hardware and software for errors (CPU faults, memory corruption, network failures, out-of-paper warnings, user program exceptions) and takes corrective action.

### B. System-Efficiency Services
These functions ensure the efficient operation of the system itself through resource sharing:

* **Resource Allocation:** Distributes hardware resources (CPU cycles, main memory, file storage, and I/O devices) among multiple concurrent tasks or users.
* **Accounting:** Keeps track of resource utilization parameters (usage duration, storage allocated, CPU time) per user or process for tracking and billing.
* **Protection and Security:** 
  * *Protection:* Ensures all access to system resources is controlled and processes do not interfere with one another.
  * *Security:* Authenticates users and defends system resources and external devices against unauthorized access.

---

## 2. User Operating System Interface

### Command-Line Interface (CLI) / Shell
* **Function:** Directly accepts and executes commands typed by the user.
* **Implementation:** Can be integrated into the kernel or implemented as a system program (shell).
* **Command Types:**
  * *Built-in Commands:* Code for execution resides directly inside the command interpreter.
  * *Program-based Commands:* Commands match executable program names. Adding new functionality does not require modifying the shell.
* **Common Shell Commands (e.g., Bourne Shell):**
  * `ls`: Lists files in a directory.
  * `pwd`: Prints the current working directory path.
  * `ping 192.168.1.1`: Sends ICMP echo requests to verify network connectivity.
  * `iostat 5`: Displays I/O statistics updated every 5 seconds.
  * `w`: Displays connected users and system load averages.

### Graphical User Interface (GUI)
* Uses a desktop metaphor with a mouse, keyboard, and monitor.
* Mouse pointer interacts with icons representing files, directories (folders), and programs.
* Developed at Xerox PARC.
* **Hybrid Interfaces:** Modern OSs feature both interfaces (e.g., Windows GUI with Command Prompt/PowerShell, macOS Aqua GUI over a UNIX kernel, Linux GNOME/KDE over a command shell).

### Touchscreen Interfaces
* Optimized for touch interaction using gestures (swipes, taps, pinches) instead of physical mice.
* Incorporates virtual keyboards and voice-assisted commands.

---

## 3. System Calls & Application Programming Interfaces (APIs)

### System Calls
* Provide the functional interface between a running program and the OS kernel.
* Typically written in low/mid-level languages ($C$ or $C++$).
* Usually called indirect through higher-level Application Programming Interfaces (APIs) to ensure portability and ease of programming.

### Common APIs
1. **Win32 API:** Used on Microsoft Windows systems.
2. **POSIX API:** Used on POSIX-compliant systems (UNIX, Linux, macOS).
3. **Java API:** Used programs targeted for the Java Virtual Machine (JVM).

### System Call Execution Example (`read()` API)
The POSIX `read()` function signature:
```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
```
* `fd`: File descriptor specifying the open file.
* `buf`: Buffer memory address where read data will be stored.
* `count`: Maximum number of bytes to read into the buffer.
* **Return Value:** Returns bytes read on success, `0` at End-of-File (EOF), or `-1` on error.

### Sequence Example: File Copy Program
A simple file copy operation involves multiple system calls:
1. Prompt and obtain source filename from user.
2. Prompt and obtain destination filename from user.
3. Open source file (abort if file does not exist).
4. Create destination file (abort if file already exists).
5. Loop:
   * Read data from source file.
   * Write data to destination file.
   * Repeat until `read()` returns EOF.
6. Close both files.
7. Print completion message to screen.
8. Terminate process normally.

### Implementation Mechanics
* Every system call is assigned an integer index number.
* The system call interface maintains a lookup table indexed by these numbers.
* The **Run-Time Support Library** handles details, intercepting library calls, executing machine-level software interrupts/traps, transitioning execution from **User Mode** to **Kernel Mode**, and returning execution context back to user space upon completion.

### Parameter Passing Methods
When system calls require parameters beyond the call number, three strategies are used:
1. **Registers:** Parameters are loaded directly into CPU registers. *Limit:* Number of registers is bounded.
2. **Block / Table in Memory:** Parameters are placed in a contiguous memory block, and the memory address is passed in a register. *Used by Linux and Solaris.*
3. **Stack:** Parameters are pushed onto the program stack by the caller and popped off by the operating system kernel.

---

## 4. Types of System Calls

| Category | Description | Windows System Calls | UNIX/Linux System Calls |
| :--- | :--- | :--- | :--- |
| **Process Control** | Process creation, termination, execution, waiting, event signaling, memory allocation/deallocation, locks. | `CreateProcess()`, `ExitProcess()`, `WaitForSingleObject()` | `fork()`, `exit()`, `wait()` |
| **File Management** | File creation, deletion, opening, closing, reading, writing, repositioning, attribute management. | `CreateFile()`, `ReadFile()`, `WriteFile()`, `CloseHandle()` | `open()`, `read()`, `write()`, `close()` |
| **Device Management** | Device requests, releases, standard read/write, logical attachment/detachment. | `SetConsoleMode()`, `ReadConsole()`, `WriteConsole()` | `ioctl()`, `read()`, `write()` |
| **Information Maintenance** | Getting/setting system time, process IDs, system metrics, performance data. | `GetCurrentProcessID()`, `SetTimer()`, `Sleep()` | `getpid()`, `alarm()`, `sleep()` |
| **Communications** | Creating/deleting network sockets or IPC channels, sending/receiving messages, attaching shared memory. | `CreatePipe()`, `CreateFileMapping()`, `MapViewOfFile()` | `pipe()`, `mmap()`, `shmget()` |
| **Protection** | Access control settings, permission manipulation, ownership settings. | `SetFileSecurity()`, `InitializeSecurityDescriptor()` | `chmod()`, `umask()`, `chown()` |

### Execution Flow Examples
* **Standard C Library:** Calling high-level functions like `printf("Greetings")` transparently calls lower-level library code that executes the `write()` system call to enter kernel mode.
* **MS-DOS (Single-Tasking):** Loads a program into memory, overwriting parts of the command interpreter. When the process finishes, the command interpreter is reloaded from storage.
* **FreeBSD/UNIX (Multitasking):** The shell invokes `fork()` to create a child process copy, followed by `exec()` to replace the child's memory image with the requested binary program. The parent shell waits (`wait()`) or continues accepting commands.

---

## 5. System Programs

System programs provide an environment for program development and execution. They bridge user space and system calls.

* **File Management:** Utilities to create, delete, copy, rename, print, list, and format files and directories.
* **Status Information:** Tools displaying system parameters (date, memory, disk usage, active users) and performance monitors. Configuration details are often stored in central registries (e.g., Windows Registry).
* **File Modification:** Text editors and file processing utilities (searching, regex text transformations).
* **Programming-Language Support:** Compilers, linkers, assemblers, debuggers, and interpreters provided with the system.
* **Program Loading and Execution:** Absolute loaders, relocatable loaders, linkage editors, overlay loaders.
* **Communications:** Tools for web browsing, email, file transfer (FTP, SCP), and remote logins (SSH).
* **Background Services (Daemons/Subsystems):** Long-running processes launched during boot that run in user context (e.g., print spoolers, scheduler daemons, network monitors, error loggers).

---

## 6. Operating System Design and Implementation

### Design Goals
* **User Goals:** System should be convenient, intuitive, reliable, safe, and fast.
* **System Goals:** System should be easy to design, implement, and maintain, while being flexible, fault-tolerant, and resource-efficient.

### Mechanisms vs. Policies
A fundamental principle in software engineering is separating policies from mechanisms:
* **Mechanism:** Defines *how* to do something (e.g., CPU timer interrupts).
* **Policy:** Defines *what* will be done (e.g., setting time slice quantum length for process scheduling).
* *Separation allows policy changes without rewriting underlying mechanisms.*

### Implementation Languages
* Historical OS kernels were written in Assembly.
* Modern kernels are written in high-level languages like $C$ and $C++$.
* High-level languages increase code portability and development speed, though they may introduce minor performance overheads compared to raw hand-tuned assembly.

---

## 7. Operating System Structures

```
MS-DOS Structure (Simple)            Layered Architecture
+-----------------------+            +-----------------------+
|  Application Program  |            | Layer N: User Interface|
+-----------------------+            +-----------------------+
| Resident System Prog. |            | Layer 1: Subsystems   |
+-----------------------+            +-----------------------+
| MS-DOS Device Drivers |            | Layer 0: Hardware     |
+-----------------------+            +-----------------------+
| ROM BIOS Drivers      |
+-----------------------+
```

1. **Simple Structure (e.g., MS-DOS):**
   * Designed for minimal memory footprint.
   * Lacks hardware privilege separation (no distinct user/kernel mode execution separation). Application software can write directly to hardware or BIOS routines.

2. **Monolithic Structure (e.g., Traditional UNIX):**
   * Kernel contains all core OS functionality (file system, hardware drivers, memory management, scheduler) in a single massive address space.
   * Very efficient execution speed, but difficult to modify and maintain without bugs affecting the whole system.

3. **Layered Approach:**
   * OS is broken into discrete layers numbered $0$ through $N$.
   * **Layer 0:** Hardware interface.
   * **Layer N:** User Interface.
   * *Strict Rule:* Each layer uses functions and services of lower-level layers only. Modularity aids debugging, but can suffer from performance bottlenecks.

4. **Microkernel Architecture (e.g., Mach):**
   * Moves as much code out of kernel mode into user space as possible.
   * Kernel contains only fundamental primitives: Interprocess Communication (IPC), basic memory management, and CPU scheduling.
   * Services (File systems, drivers) run as user-space servers.
   * *Pros:* Easily extensible, highly portable, reliable, and secure.
   * *Cons:* High IPC performance overhead due to repeated context switches between user and kernel modes.

5. **Loadable Kernel Modules (LKM) (e.g., Modern Linux, Solaris):**
   * Object-oriented approach where the core kernel provides basic services, and additional functionality (file systems, network protocols, hardware drivers) is dynamically loaded on demand during runtime via known interfaces.

6. **Hybrid Systems:**
   * Modern production operating systems combine multiple approaches for efficiency, usability, and stability.
   * **macOS / iOS:** Aqua/Cocoa Touch UI layered over a kernel environment composed of Mach (microkernel) and BSD UNIX, along with an I/O Kit and dynamic kernel extensions.
   * **Android:** Standard Linux kernel (modified with power management) running native C/C++ libraries (SQLite, WebKit), Android Runtime (Dalvik VM executing Java bytecode), and Application Frameworks.

---

## 8. OS Debugging & Performance Tuning

### System Diagnostics & Debugging
* **Log Files:** Record error codes and execution state information.
* **Core Dumps:** File generated capturing the memory state of a crashed user-space application.
* **Crash Dumps:** File generated capturing the kernel memory state during an operating system failure (kernel panic/BSOD).

### Profiling & Performance Tuning
* **System Monitors:** Applications that display real-time usage metrics of CPU, memory, processes, and networks (e.g., `top` in Linux, Windows Task Manager).
* **Profiling:** Periodically sampling the program counter/instruction pointer to generate statistical execution maps and identify code performance bottlenecks.
* **Tracing:** Recording timestamped sequences of specific system events or function calls.

### DTrace Instrumentation
* Live instrumentation tool integrated into Solaris, FreeBSD, and macOS.
* Dynamic probes trigger inside production code without recompilation to record system statistics.
* *Example (DTrace script monitoring process CPU run-time in nanoseconds):*
```dtrace
sched:::on-cpu
/uid == 101/
{
    self->ts = timestamp;
}

sched:::off-cpu
/self->ts/
{
    @time[execname] = sum(timestamp - self->ts);
    self->ts = 0;
}
```

---

## 9. System Generation & System Boot

### System Generation (SYSGEN)
* Customizes generic operating system source code or binaries for specific physical machine hardware profiles.
* Scans hardware configurations (CPU topology, RAM capacity, attached disk controllers) to generate an optimized kernel build.

### System Boot Sequence
1. **Power Initialization:** CPU registers reset to default values and begin execution at a fixed initial memory address in non-volatile ROM/EEPROM firmware (BIOS/UEFI).
2. **Bootstrap Loader:** Small piece of code located in ROM that executes hardware checks (POST), locates the operating system kernel on persistent storage, loads it into main memory, and jumps to the kernel starting entry point.
3. **Multi-Stage Booting:** Firmware loads a small **Boot Block** from disk, which in turn launches a full feature bootloader like **GRUB** (Grand Unified Bootloader). GRUB presents options to select kernel parameters, safe modes, or alternative OS installations.
4. **Kernel Initialization:** Kernel initializes system memory, loads device drivers, mounts root storage partitions, starts initial user-space initialization processes (e.g., `init` or `systemd`), and presents user interfaces.