### What is a Memory Copy?

A **memory copy** is a low-level operation that copies a specific number of raw bytes from one memory address to another. In C, this is typically handled by functions like `memcpy()` or `memmove()`.

Unlike copying a variable with an assignment operator (`=` syntax), a memory copy does not care about data types (like `int`, `float`, or `char`). It just looks at a starting memory address, measures a specific size in bytes, and clones those exact bits directly into a destination address.

For example, when you used a loop to swap entire rows of your `data_array` earlier, you were using `strcpy` (string copy), but you could also perform a memory copy using `memcpy` to duplicate entire blocks of memory at once:

```c
memcpy(destination, source, sizeof(destination));

```

---

### Other Types of Copies in C

Depending on what you are copying and how C handles variables, copies generally fall into these categories:

#### 1. Shallow Copy (Value Copy)

* **What it is:** This is the standard copy that happens when you use the assignment operator (`=`) on primitive data types (like `int`, `char`, `float`) or when you pass arguments by value to a function.
* **How it works:** It copies the actual value stored in that variable into a new memory location.
* **Example:**
```c
int a = 10;
int b = a; // 'b' gets a separate, independent copy of the value 10

```



#### 2. Deep Copy

* **What it is:** A manual or custom copy process used when your data structure contains pointers (memory addresses) pointing to *other* allocated memory blocks.
* **Why it matters:** If you do a shallow copy of a structure containing pointers, you only copy the *addresses*, meaning both variables end up pointing to the exact same external data. Changing data in one affects the other. A **deep copy** allocates entirely new memory for the underlying data and copies the actual contents over, keeping them completely independent.

#### 3. String Copy (`strcpy` / `strncpy`)

* **What it is:** A specialized text copy designed for C-style strings (character arrays terminated by a null character `\0`).
* **How it works:** It copies characters sequentially from a source string into a destination buffer until it encounters the null terminator.
* **Difference from Memory Copy:** A standard memory copy (`memcpy`) requires you to explicitly tell it how many bytes to copy. `strcpy` automatically stops when it sees `\0`.

#### 4. Logical / Field-by-Field Copy

* **What it is:** Copying complex data structures (like structs or multi-dimensional arrays, as you did in your sorting function) element-by-element or field-by-field.
* **How it works:** Instead of treating the whole structure as one raw block of bytes, you loop through its individual components (like your loop from `k = 0` to `7` copying each string column individually) to ensure everything maps safely to its correct parallel counterpart.