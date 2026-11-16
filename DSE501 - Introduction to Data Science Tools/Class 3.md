
## 1. Structures and `typedef`

A **structure** (`struct`) allows you to group related variables of _different_ data types under a single name. The `typedef` keyword is used to create a shorter alias (nickname) for a structure type so you don't have to keep writing `struct` every time you declare a variable.

  

### Code Example

C

```
// Defining a structure with a typedef alias
typedef struct auds {
    char *faces;
    char *suid;
} Auds;

int main(void) {
    // Declaring a variable using our new alias 'Auds'
    Auds record1;
    record1.faces = "Front";
    record1.suid = "ID12345";
    
    return 0;
}
```

- **Explanation:** `faces` and `suid` are pointers to characters (`char *`). The `typedef` at the end makes `Auds` synonymous with `struct auds`.
    
      
    

## 2. Linear Data Structures Overview

Different data structures manage data differently based on how and where you insert or remove items:

  

- **Linked List**
    
      
    - **Insertions / Deletions:** Anywhere (beginning, middle, or end) using pointers.
        
          
        
    - **Key Function:** `isEmpty()` to check if the list has nodes.
        
          
        
    - **Pro Tip:** _Always draw the linked list implementation diagrams before writing the code_ to visualize pointer connections and avoid memory leaks or lost references!
        
          
        
- **Stack (LIFO - Last In, First Out)**
    
      
    - **Insertions / Deletions:** Done exclusively at one end, known as the **top**.
        
          
        
    - **Key Operations:** `push()` (add to top), `pop()` (remove from top), `end()` or `peek()` (view top), and `isEmpty()`.
        
          
        
- **Queue (FIFO - First In, First Out)**
    
      
    - **Insertions:** Made at the back (**tail**).
        
          
        
    - **Deletions:** Made from the front (**head**).
        
          
        
    - **Key Operations:** `enqueue()` (insert at tail), `dequeue()` (remove from head), and `isEmpty()`.
        
          
        

## 3. Trees and Hierarchical Structures

Unlike linear lists or stacks, **trees** are non-linear data structures consisting of nodes connected by edges (commonly used to build hierarchical relationships, binary search trees, etc.).

  

- **Implementation:** Trees rely heavily on **self-referential structures** (structures containing pointers pointing to instances of the same structure type) and dynamic memory allocation (`malloc`, `free`) to create nodes dynamically at runtime.
    
      
    

## 4. Dynamic Memory Allocation Functions

To create data structures whose sizes can change while the program runs, C uses memory management functions from `<stdlib.h>`:

  

|**Function**|**Purpose**|**Arguments**|**Initialization**|
|---|---|---|---|
|**`malloc()`**|Allocates a specified number of bytes.|1 argument (total bytes, e.g., `sizeof(int) * 5`)|Contains **garbage values** (uninitialized).|
|**`calloc()`**|Allocates memory for an array of elements.|2 arguments (number of elements, size of each element)|Automatically **initialized to zero** (`0`).|
|**`realloc()`**|Resizes previously allocated memory.|2 arguments (pointer to old memory, new size in bytes)|Preserves existing data up to the old size.|
|**`free()`**|Deallocates memory to prevent memory leaks.|1 argument (pointer to the memory block)|N/A|
|**`sizeof()`**|Operator to find the exact byte size of a type or variable.|1 argument (type or variable name)|N/A|

### Code Example: `malloc` vs `calloc`

C

```
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // malloc: allocates space for 5 integers (contains garbage values)
    int *arr1 = (int *)malloc(5 * sizeof(int));
    
    // calloc: allocates space for 5 integers and sets all values to 0
    int *arr2 = (int *)calloc(5, sizeof(int));

    // Always free allocated memory when done!
    free(arr1);
    free(arr2);
    
    return 0;
}
```

## 5. Quick Concepts

- **NP (Non-Polynomial):** In computer science, NP problems are a class of computational problems for which no efficient (polynomial-time) solution is known to run quickly for large inputs (e.g., the Traveling Salesperson Problem).
    
      
    
- **Golden Rule of Coding Linked Lists:** _Always draw your pointer diagrams on paper first!_ Mapping out head, tail, `next` pointers, and temporary variables prevents segmentation faults.



## Quick self-check

After answering the questions, make sure you can explain these ideas  
without looking at the notes:

- Why a linked list can change size while a fixed-size array cannot.
- How pointers connect nodes and how `NULL` marks the end of a chain.
- Why `malloc()` and `free()` must be used carefully.
- The difference between LIFO and FIFO.
- Why a queue tracks both its front and rear.
- How a BST's ordering rule guides insertion and makes in-order  
    traversal produce sorted values.
- The difference between a structure variable and a pointer to a  
    structure.
- Why `typedef` is an alias rather than a new underlying type.

**S**