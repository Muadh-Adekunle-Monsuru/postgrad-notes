 While arrays are great, their size is fixed once you compile your program. Dynamic data structures, on the other hand, can grow and shrink while your program runs. 
[[data_structures_code]]
To build these, we rely on two key concepts:
1. **Self-Referential Structures:** A `struct` that contains a pointer to another `struct` of the exact same type. Think of it as a person holding a piece of paper with the address of the next person.
2. **Dynamic Memory Allocation:** Using `malloc()` to grab memory for new data exactly when you need it, and `free()` to give it back when you're done.

---

## 1. The Foundation: Linked Lists
**What is it?** 
Imagine a train. Instead of one long contiguous metal box (like an array), a train is made of individual cars (nodes). Each car has some cargo (data) and a hitch connecting it to the next car (a pointer).

**Beginner Implementation in C:**
To build a linked list node, you define a struct with your data and a pointer to the next node.
```c
struct listNode {
    char data;                 // The cargo
    struct listNode *nextPtr;  // The hitch to the next car
};
```
*   **The Start:** You keep track of the list using a single pointer to the very first node (often called `startPtr` or `head`).
*   **The End:** The last node's `nextPtr` is set to `NULL` to signify the end of the train.
*   **Operations:** 
    *   *Insert:* You create a new node with `malloc()`, figure out where it goes, and update the pointers of the surrounding nodes to link it in.
    *   *Delete:* You change the pointer of the preceding node to "skip over" the deleted node, then use `free()` to destroy the deleted node.

---

## 2. Stacks (LIFO - Last-In, First-Out)
**What is it?**
Think of a stack of plates at a buffet. You can only put a new plate on the **top**, and you can only take a plate off the **top**. The last plate put down is the first one picked up.

**Beginner Implementation in C:**
A stack is just a linked list with rules! You only ever interact with the first node (the top).
```c
struct stackNode {
    int data; 
    struct stackNode *nextPtr; 
};
```
*   **Push (Insert):** You create a new node, point its `nextPtr` to the current top of the stack, and then update your `topPtr` variable to point to this new node.
*   **Pop (Remove):** You temporarily save the top node's data, move the `topPtr` to the second node, `free()` the old top node, and return the saved data.

---

## 3. Queues (FIFO - First-In, First-Out)
**What is it?**
Think of a checkout line at the grocery store. You join the line at the **back** (tail), and the cashier serves the person at the **front** (head). 

**Beginner Implementation in C:**
A queue is another restricted linked list, but you need to keep track of *both* ends to be efficient.
```c
struct queueNode {
    char data;
    struct queueNode *nextPtr;
};
```
*   **Pointers needed:** You will maintain a `headPtr` (front of the line) and a `tailPtr` (back of the line).
*   **Enqueue (Insert):** You create a new node, attach it to the `nextPtr` of the current tail, and then update your `tailPtr` to point to this new node.
*   **Dequeue (Remove):** You remove the node at the `headPtr`, move the `headPtr` to the next person in line, and `free()` the old head.

---

## 4. Binary Trees
**What is it?**
Unlike lists, stacks, and queues which are straight lines (linear), trees branch out. A binary tree is like a family tree where every node can have up to two children: a left child and a right child.

**Beginner Implementation in C:**
Instead of one "next" pointer, you need two!
```c
struct treeNode {
    int data;
    struct treeNode *leftPtr;   // Pointer to left child
    struct treeNode *rightPtr;  // Pointer to right child
};
```
*   **Binary Search Tree (BST) Rule:** To make finding data incredibly fast, we organize trees systematically. For any given node, all values in its left branching path are *smaller* than its value, and all values in its right branching path are *larger*.
*   **Inserting:** You start at the root (the very top node). If your new value is smaller, go left. If it's bigger, go right. Repeat until you hit a `NULL` pointer, and attach your new node there.
*   **Traversals:** To print the tree, you use recursion (functions calling themselves):
    *   *InOrder:* Visit Left -> Print Node -> Visit Right (Prints BSTs in numerical order!)
    *   *PreOrder:* Print Node -> Visit Left -> Visit Right
    *   *PostOrder:* Visit Left -> Visit Right -> Print Node

---

## Secure C Programming Cheat Sheet
When working with these structures, always follow these rules to prevent your program from crashing:
1. **Always check malloc:** Memory isn't infinite. If `malloc()` returns `NULL`, your computer is out of memory. Handle it gracefully!
2. **Never leave pointers dangling:** When you create a node, always set its pointer(s) to `NULL`.
3. **Avoid Memory Leaks:** If you remove a node, you **must** use `free()` on it. Otherwise, that memory is locked up forever. 
4. **Beware of the Double Free:** Never call `free()` on the same memory twice.