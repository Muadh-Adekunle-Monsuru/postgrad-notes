## 6.1 – 6.4: Fundamentals, Initialization, and Examples

Arrays are static data structures consisting of contiguous memory locations holding items of the same type.

* **Initialization and Sizing:** Using symbolic constants (`#define SIZE`) makes array sizing scalable. If an initializer list has fewer elements than the array, the remaining elements automatically initialize to zero.


* **Data Types:** The `size_t` unsigned integral type is recommended for variables representing array sizes or subscripts.


* **Strings:** Character strings are stored in character arrays and must include a terminating null character (`'\0'`).


* **Storage Duration:** `static` local arrays are initialized to zero by default before program startup and retain their values between function calls, unlike automatic arrays which are re-initialized each time the function executes.



```c
#define SIZE 10 /* Symbolic constant for scalability[cite: 30, 31] */

void arrayDemo() {
    /* Implicitly sized to 6 to accommodate 'h', 'e', 'l', 'l', 'o', '\0'[cite: 61] */
    char str[] = "hello"; 
    
    /* Retains modifications across function calls[cite: 72, 73] */
    static int statArray[SIZE]; 
}

```

## 6.5: Passing Arrays to Functions

* **Pass by Reference:** Specifying an array name without brackets passes it by reference, because the array name evaluates to the address of its first element. Modifications in the called function alter the original array.


* **Pass by Value:** Individual array elements (scalars) passed to functions are passed by value.


* **Immutability:** Applying the `const` type qualifier to an array parameter triggers a compile-time error if the function attempts to modify the array.



```c
/* 'const' prevents modification of the original array[cite: 92, 97] */
void printArray(const int b[], size_t size) {
    /* b[0] = 5; // This would cause a compile-time error[cite: 97, 98] */
}

```

## 6.6 – 6.7: Sorting Arrays & Statistical Analysis

* **Bubble Sort:** This algorithm requires multiple passes through the array to place data in order. It compares adjacent elements and swaps them if they are in the wrong order using a temporary hold variable. Large values "sink" to the bottom, while small values "bubble" to the top.


* **Case Study:** Arrays are highly effective for survey data analysis, such as computing the mean (arithmetic average), median (middle value of a sorted array), and mode (most frequent value).



```c
/* Bubble sort core logic: swapping adjacent elements[cite: 105, 110] */
if (a[i] > a[i + 1]) {
    int hold = a[i];   /* Temporary storage prevents data loss[cite: 110, 111] */
    a[i] = a[i + 1];
    a[i + 1] = hold;
}

```

## 6.8: Searching Arrays

* **Linear Search:** Best for small or unsorted arrays. It compares the search key to every element sequentially, averaging comparisons against half the array's elements.


* **Binary Search:** Highly efficient but requires a sorted array. It repeatedly halves the search space by comparing the key to the middle element. An array of 1,048,576 elements takes a maximum of only 20 comparisons ($2^{20}$).



## 6.9: Multidimensional Arrays

* **Structure:** Arrays can have multiple subscripts, most commonly double-subscripted arrays representing tables with rows and columns.


* **Memory Layout:** Regardless of dimensions, all array elements are stored consecutively in memory.


* **Function Parameters:** When passing multidimensional arrays, all subscripts except the first must be explicitly specified so the compiler can correctly locate elements in memory.



```c
/* A 3-by-4 array definition[cite: 150] */
int a[3][4] = { {1, 2}, {3, 4} }; /* Unspecified elements initialize to 0[cite: 155] */

/* Nested loops commonly process multidimensional arrays[cite: 164] */
for (int row = 0; row <= 2; ++row) {
    for (int col = 0; col <= 3; ++col) {
        a[row][col] = 0; /* Clears all elements[cite: 164, 165] */
    }
}

```

## 6.10: Variable-Length Arrays (VLAs)

* **Runtime Sizing:** Introduced in the C standard, VLAs allow an array's length to be defined by an expression evaluated at execution time rather than compilation time.


* **Sizeof Operator:** When applied to a VLA, the `sizeof` operator operates at runtime to evaluate the dynamic size.



```c
int arraySize;
scanf("%d", &arraySize);
int array[arraySize]; /* VLA size determined at execution time[cite: 183, 185] */

```

## 6.11: Secure C Programming

* **Bounds Checking:** C does not automatically prevent a program from referring to array indices outside defined bounds. Writing out-of-bounds causes buffer overflows that can corrupt data or execute malicious code.


* **Secure Input:** Functions like `scanf_s` require an explicit argument defining the character array's capacity to prevent buffer overflows.


* **Format String Vulnerabilities:** Never use user-provided strings directly as format-control strings in functions like `printf`, as attackers can supply malicious conversion specifiers.