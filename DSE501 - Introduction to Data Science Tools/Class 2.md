Write a calculator 
```C
#include <stdio.h>
#include <stdlib.h> // Required for atof




int main(int argc, char *argv[]){
    int firstNum = atoi(argv[1]);
    int secondNum = atoi(argv[2]);
    float answer;
    char sign = argv[3][0];

    if (argc < 3) {
        printf("Usage: %s <num1> <num2> <operator>\n", argv[0]);
        exit(-1); 
    }

    switch(sign){
        case '+':
            answer = firstNum + secondNum;
            break;
        case '-':
            answer = firstNum - secondNum;
            break;
        case '/':
            if(secondNum==0){
                printf("Error: cannot divide by zero \n");
                exit(-2);
            }
            answer =(float) firstNum / secondNum;
            break; 
        case 'x':
            answer = firstNum * secondNum;
            break;
        case '%':
            answer = firstNum % secondNum;
            break;
         
        default:
            printf("Error: Invalid operator '%c'\n", sign);
            return 1;
        
    }
    printf("\n The evaluation of the expression %d %s %d = %.2f \n\n",firstNum,&sign,secondNum,answer);

    return 0;
}
```

---

Write a function that takes a string as input count the number of each character, the each alphabet, numbers 

`Today, October6 , 2026, we covered a lot. Hope to see you write long programs.`


Read the note about file, 
develop a c code that reads the data into array and create functions


`include "myfunction.h"`
A normal variable directly contains a specific value, while a pointer is a variable that contains the memory address of another variable.

**Breaking Down Your Example**

1. `int a = 10;`
You create a standard integer variable named `a`. The computer stores the value `10` in a specific location in memory (for example, at memory address `600000`).


2. `int *aPtr = &a;`
You create a pointer named `aPtr`. The `*` in the declaration simply tells the compiler that the variable being defined is a pointer. The `&` (address operator) grabs the memory address of `a` and stores it in `aPtr`. Your pointer `aPtr` now holds the address `600000`.


3. `*aPtr = 25;`
The `*` here acts as the dereferencing (or indirection) operator. It tells the computer to go to the specific address stored in `aPtr` and change the value at that location to `25`. Because `aPtr` holds the exact address of `a`, this operation changes the actual value of `a` from `10` to `25`.



**The Core Operators**

* **`&` (Address Operator):** "Where does this live?" It returns the exact memory address of its operand.


* **`*` (Dereference Operator):** "What is inside this address?" It returns or modifies the actual value located at the exact memory address the pointer holds.



**Real-World Analogy**
Think of variables as houses and values as the people living inside.

* `int a = 10;` builds a house and puts 10 people inside.
* `&a` is the street address of that house.
* `int *aPtr = &a;` is a piece of paper with the street address written on it.
* `*aPtr = 25;` means you read the address from the paper, drive to that exact house, and change the number of people inside to 25.

**Why Use Pointers? (Pass-by-Reference)**
In C, functions usually receive a temporary copy of a variable's value (pass-by-value), meaning they cannot change the original variable. Pointers allow functions to modify an original variable by receiving its direct memory address, simulating pass-by-reference.

```c
#include <stdio.h>

/* The function expects a pointer (a memory address)[cite: 788, 791] */
void addBonus(int *scorePtr) {
    /* Goes to the original address and adds 50 to the value there[cite: 788] */
    *scorePtr = *scorePtr + 50; 
}

int main(void) {
    int myScore = 100;
    
    /* Pass the address of myScore, not the value 100[cite: 788, 789] */
    addBonus(&myScore); 
    
    /* myScore is now 150 because the function modified the data at its exact address */
    printf("Score: %d\n", myScore); 
    return 0;
}

```



A normal variable directly contains a specific value, while a pointer is a variable that contains the memory address of another variable.

**Breaking Down Your Example**

1. `int a = 10;`
You create a standard integer variable named `a`. The computer stores the value `10` in a specific location in memory (for example, at memory address `600000`).


2. `int *aPtr = &a;`
You create a pointer named `aPtr`. The `*` in the declaration simply tells the compiler that the variable being defined is a pointer. The `&` (address operator) grabs the memory address of `a` and stores it in `aPtr`. Your pointer `aPtr` now holds the address `600000`.


3. `*aPtr = 25;`
The `*` here acts as the dereferencing (or indirection) operator. It tells the computer to go to the specific address stored in `aPtr` and change the value at that location to `25`. Because `aPtr` holds the exact address of `a`, this operation changes the actual value of `a` from `10` to `25`.


