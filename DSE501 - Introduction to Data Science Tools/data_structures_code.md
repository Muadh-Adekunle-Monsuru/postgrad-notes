# C Data Structures: Code Implementations & Explanations

This guide breaks down the core functions for Stacks, Queues, and Binary Trees. By understanding what each line does, you'll see how pointers and dynamic memory work together to manage data.

---

## 1. Stack Implementation (LIFO)

A stack requires two main actions: `push` (add to top) and `pop` (remove from top). Assume we have a struct named `StackNode` and a pointer type `StackNodePtr`.

### The `push` Function
This function adds a new integer to the top of the stack.

```c
1  void push(StackNodePtr *topPtr, int info) {
2      StackNodePtr newPtr = malloc(sizeof(StackNode));
3      
4      if (newPtr != NULL) {
5          newPtr->data = info;
6          newPtr->nextPtr = *topPtr;
7          *topPtr = newPtr;
8      } else {
9          printf("No memory available.\n");
10     }
11 }
```

**Line-by-Line Explanation:**
* **Line 1:** We define the function. It takes a double pointer `*topPtr` (the address of the pointer pointing to the top of the stack) so we can modify the original stack pointer, and the `info` (integer) we want to store.
* **Line 2:** We ask the system for memory using `malloc`. `sizeof(StackNode)` tells the computer exactly how many bytes we need. We store the address of this new memory in `newPtr`.
* **Line 3:** A blank line for readability.
* **Line 4:** We check if `newPtr` is not `NULL`. If it is `NULL`, the computer is out of memory.
* **Line 5:** We take the integer `info` and store it inside the `data` part of our newly created node.
* **Line 6:** We set the new node's `nextPtr` to point to the *current* top of the stack (`*topPtr`). The new node is now holding hands with the old top node.
* **Line 7:** We update the main stack pointer (`*topPtr`) to point to our `newPtr`. The new node is officially the top of the stack.
* **Line 8 & 9 & 10:** If `malloc` failed (returned `NULL`), we print an error message safely instead of crashing the program.

### The `pop` Function
This function removes the top item and returns its value.

```c
1  int pop(StackNodePtr *topPtr) {
2      StackNodePtr tempPtr = *topPtr;
3      int popValue = (*topPtr)->data;
4      
5      *topPtr = (*topPtr)->nextPtr;
6      free(tempPtr);
7      return popValue;
8  }
```

**Line-by-Line Explanation:**
* **Line 1:** We define the function. It takes the address of the top pointer and will return an `int` (the data we are removing).
* **Line 2:** We create a temporary pointer `tempPtr` and point it at the current top node. We need this so we don't lose the node's address when we adjust the stack.
* **Line 3:** We extract the integer data from the top node and save it in a variable called `popValue` so we can return it later.
* **Line 4:** Blank line.
* **Line 5:** We update the main stack pointer (`*topPtr`) to point to the *second* node in the stack (`(*topPtr)->nextPtr`). The first node is now detached from the stack.
* **Line 6:** We use `free()` on `tempPtr` to give the memory of the detached node back to the computer. 
* **Line 7:** We return the integer value we saved in step 3 back to whoever called the function.

---

## 2. Queue Implementation (FIFO)

A queue adds to the back (`enqueue`) and removes from the front (`dequeue`).

### The `enqueue` Function
This function adds a character to the back of the line.

```c
1  void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value) {
2      QueueNodePtr newPtr = malloc(sizeof(QueueNode));
3      
4      if (newPtr != NULL) {
5          newPtr->data = value;
6          newPtr->nextPtr = NULL;
7          
8          if (*headPtr == NULL) {
9              *headPtr = newPtr;
10         } else {
11             (*tailPtr)->nextPtr = newPtr;
12         }
13         *tailPtr = newPtr;
14     }
15 }
```

**Line-by-Line Explanation:**
* **Line 1:** The function takes pointers to both the front (`headPtr`) and back (`tailPtr`) of the queue, plus the `value` to insert.
* **Line 2:** We allocate memory for the new node and save its address in `newPtr`.
* **Line 4:** We verify that memory was successfully allocated.
* **Line 5:** We insert our character `value` into the new node's data field.
* **Line 6:** Because this node will go at the very back of the line, it doesn't point to anyone else. We set its `nextPtr` to `NULL`.
* **Line 8 & 9:** We check if the queue is entirely empty (`*headPtr == NULL`). If it is, this new node is the *first and only* person in line, so the head pointer must point to it.
* **Line 10 & 11:** If the queue is *not* empty, we tell the current last person in line (`*tailPtr`) to point their `nextPtr` to our `newPtr`.
* **Line 13:** Regardless of whether the queue was empty or not, our new node is now the last one in line. We update the main `*tailPtr` to point to it.

---

## 3. Binary Search Tree (BST)

Trees use recursion (functions that call themselves) to navigate the left and right branches.

### The `insertNode` Function
This function places a new integer into the correct sorted position.

```c
1  void insertNode(TreeNodePtr *treePtr, int value) {
2      if (*treePtr == NULL) {
3          *treePtr = malloc(sizeof(TreeNode));
4          
5          if (*treePtr != NULL) {
6              (*treePtr)->data = value;
7              (*treePtr)->leftPtr = NULL;
8              (*treePtr)->rightPtr = NULL;
9          }
10     } else {
11         if (value < (*treePtr)->data) {
12             insertNode(&((*treePtr)->leftPtr), value);
13         } else if (value > (*treePtr)->data) {
14             insertNode(&((*treePtr)->rightPtr), value);
15         }
16     }
17 }
```

**Line-by-Line Explanation:**
* **Line 1:** Takes the address of a tree node pointer and the `value` to insert.
* **Line 2:** The Base Case! If the pointer is `NULL`, we have found an empty spot in the tree where our new node belongs.
* **Line 3:** We allocate memory for the new node directly into that empty spot (`*treePtr`).
* **Line 5 to 9:** We ensure the memory allocation worked. Then, we set the node's `data` to our `value`. Because this is a new leaf on the tree, it has no children, so both `leftPtr` and `rightPtr` are set to `NULL`.
* **Line 10:** If `*treePtr` is *not* `NULL`, it means a node already exists here. We must decide whether to go left or right.
* **Line 11 & 12:** We check if our new `value` is *less* than the current node's data. If it is, we use recursion: we call `insertNode` again, but this time we pass it the address of the current node's `leftPtr`.
* **Line 13 & 14:** If the `value` is *greater* than the current node's data, we use recursion to pass the address of the current node's `rightPtr`. 
* *(Note: If the value is exactly equal, the function does nothing, which automatically ignores duplicates!)*