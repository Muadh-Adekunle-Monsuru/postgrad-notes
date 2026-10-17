## String Fundamentals & Character Handling (`<ctype.h>` & `<stdlib.h>`)

* **Strings:** In C, a string is a series of characters treated as a single unit, always terminated by a null character (`'\0'`). Strings are accessed via a pointer to their first character.


* **Character Library (`<ctype.h>`):** Provides functions to test individual characters for properties (e.g., `isdigit` for numbers, `isalpha` for letters, `isspace` for whitespace) and to convert casing (e.g., `tolower`, `toupper`).

- strlen() to get string length
* **String Conversion (`<stdlib.h>`):** Functions like `strtod`, `strtol`, and `strtoul` convert character strings into numeric types (`double`, `long int`, and `unsigned long int`). The integer conversion functions allow you to specify the numeric base (such as base 8, 10, or 16).


when include is called as `#include "name"`, it checks the current directory first
## String Input/Output (`<stdio.h>`)

* **Secure Input:** `fgets` safely reads strings from an input stream up to a specified maximum length, helping prevent buffer overflows. `getchar` reads characters one at a time from standard input.


* **In-Memory Formatting:** `sprintf` operates identically to `printf` but writes the formatted text directly into a character array instead of printing it to the screen. Conversely, `sscanf` reads formatted data from a character array instead of the keyboard.



## String Manipulation & Search (`<string.h>`)

* **Copying & Concatenating:** `strcpy` replaces the contents of one array with a string, while `strcat` appends a string to the end of another. The `strncpy` and `strncat` variants allow you to dictate the exact maximum number of characters to copy or append.


* **Comparison:** `strcmp` and `strncmp` evaluate strings based on the numeric codes of their characters. They return `0` if the strings are identical, a negative value if the first string is lesser, or a positive value if it is greater.


* **Searching & Tokenizing:** Functions like `strchr` and `strstr` return pointers to the first occurrence of a specific character or substring, respectively. `strtok` splits a string into smaller logical segments (tokens) using designated delimiter characters.



## Memory Operations & Security

* **Memory Functions (`<string.h>`):** Functions like `memcpy`, `memmove`, `memcmp`, and `memset` treat blocks of memory as raw character arrays. Because they use `void *` pointers, they can manipulate data of any type. If the source and destination memory blocks overlap, you must use `memmove` instead of `memcpy` to avoid undefined behavior.


* **Secure Programming:** C strings are susceptible to buffer overflows if data exceeds the array capacity. Optional Annex K of the C11 standard provides safer function alternatives that require an explicit array size parameter to prevent out-of-bounds writes. Additionally, you should never pass a user-provided string directly as a format-control argument to prevent malicious code execution.



```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stringOperations() {
    /* Character arrays must have enough space for the text and the '\0' terminator[cite: 213] */
    char dest[30] = "Hello"; 
    const char *src = " World";

    /* strcat replaces dest's '\0' with the first character of src[cite: 282] */
    strcat(dest, src); 

    /* strcmp evaluates equality; it strictly returns 0 when strings match[cite: 287, 290] */
    if (strcmp(dest, "Hello World") == 0) {
        char buffer[50];
        /* sprintf formats data into memory rather than standard output[cite: 267] */
        sprintf(buffer, "Output: %s", dest); 
    }

    /* strtok breaks a string into separate parts (tokens) using delimiters[cite: 309, 312] */
    char data[] = "C,C++,Java";
    char *token = strtok(data, ","); 
    
    /* strtol converts text into a long int and tracks where parsing stopped[cite: 245, 246] */
    char *remainder;
    long number = strtol("1024bytes", &remainder, 10); 
}

```