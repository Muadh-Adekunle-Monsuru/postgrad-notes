## Program Modules and Math Library Functions

C programs utilize a "divide and conquer" approach by combining programmer-defined functions with prepackaged C standard library functions. This promotes software reusability, modularity, and abstraction. In a hierarchical structure, a calling function (the boss) invokes a called function (the worker) to perform specific tasks, hiding the implementation details from the caller.

The `<math.h>` library provides common mathematical functions, which typically receive and return `double` data types. Common functions include `sqrt(x)` for square root, `pow(x, y)` for exponential power, and `fabs(x)` for absolute value.

## Function Definitions and Prototypes

A function definition consists of a return value type, a function name, a parameter list, and a block of statements. If a function does not return a value, its return type is `void`. All parameters must be explicitly typed.

Function prototypes tell the compiler the function's name, return type, and the types and order of its parameters, allowing the compiler to validate function calls before execution. Prototypes also trigger argument coercion, which forces arguments to match the correct parameter types based on C's standard arithmetic conversion rules (e.g., automatically promoting an `int` to a `double`).

```c
#include <stdio.h>

int maximum(int x, int y, int z); 

int main(void) {
    int result = maximum(10, 25, 15);
    printf("Max is: %d\n", result);
    return 0;
}

int maximum(int x, int y, int z) {
    int max = x;
    if (y > max) { max = y; }
    if (z > max) { max = z; }
    return max;
}

```

## Function Call Stack and Pass-by-Value

C passes all function arguments by value, meaning the called function receives a copy of the argument, and any modifications do not affect the original variable in the caller.

The function call stack (or program execution stack) operates as a last-in, first-out (LIFO) data structure that manages function calls and returns.

* When a function is invoked, a stack frame is pushed onto the stack containing the function's return address and memory for its automatic (local) variables.


* When the function finishes, its stack frame is popped off the stack, destroying its local variables and returning control to the original calling address.


* If too many function calls occur (like in uncontrolled recursion), a fatal stack overflow error triggers due to finite memory.



## Random Number Generation

The `<stdlib.h>` library provides the `rand` function, which produces a pseudorandom integer between `0` and `RAND_MAX` (at least 32767). Random outputs are customized using shifting and scaling techniques via the modulo operator (`%`). Because `rand` generates the exact same sequence of numbers upon every program execution, the generator must be "seeded" using `srand`. By passing the current time `time(NULL)` from `<time.h>` to `srand`, the program achieves a different randomized sequence on each run.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    
    for (int i = 1; i <= 10; ++i) {
        int face = 1 + rand() % 6; 
        printf("%d ", face);
    }
    return 0;
}

```

## Storage Classes and Scope Rules

An identifier's storage class dictates its storage duration, scope, and linkage.

* **Automatic Storage (`auto`):** The default for local variables. They are created when a block is entered and destroyed when the block is exited.


* **Static Storage (`static`, `extern`):** These variables exist from the program's start to its termination. Global variables (`extern` by default) are accessible by any function after their declaration. Local variables declared with `static` retain their values between function calls rather than resetting.



An identifier's scope represents where it can be referenced in the code:

* **Block scope:** Variables declared inside a block or function (including parameters) are only visible within that specific block.


* **File scope:** Global variables or prototypes defined outside of any function can be accessed anywhere in the file following their declaration.


* **Function-prototype scope:** Identifiers written inside a function prototype parameter list.


* **Function scope:** Applies exclusively to labels (e.g., `start:`) used for `goto` or `switch` statements.



## Recursion vs. Iteration

A recursive function is one that calls itself to solve a problem.

* **The Base Case:** The simplest form of the problem that the function knows how to solve natively, which triggers the return cascade.


* **The Recursion Step:** The function divides the problem into a simpler piece, calling a fresh copy of itself to process the new subset, continuing until it converges on the base case.



Recursion is useful for mathematical concepts like factorials ($n! = n \times (n-1)!$) and the Fibonacci sequence. However, recursion repeatedly invokes the overhead of function calls and stack frames, which consumes substantial processor time and memory. Algorithms like the recursive Fibonacci sequence suffer from exponential complexity (approaching $2^n$ operations), making iterative loops (which use explicit repetition structures) far more memory- and processor-efficient.

```c
unsigned long long int factorial(unsigned int number) {
    if (number <= 1) {
        return 1; 
    } else {
        return (number * factorial(number - 1));
    }
}

```

## Secure C Programming

The standard `rand` function is not secure enough for cryptography or strict security applications because its sequences can be mathematically predictable. For secure generation, developers must use implementation-specific tools, such as `CryptGenRandom` on Windows or `random` on POSIX/Linux systems.