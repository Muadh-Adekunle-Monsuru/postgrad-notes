## Files and Streams in C
- getc() -> fgetc()
- getchar() -> fgetchar()
- scanf() -> fscanf()
- gets() -> fgets()

C treats files as a sequential stream of bytes ending with an end-of-file (EOF) marker. When a program begins execution, it automatically opens three standard streams: `stdin` (standard input), `stdout` (standard output), and `stderr` (standard error). To manipulate other files, C uses a `FILE` structure pointer (`FILE *`), which allows the operating system to administer the file via a file control block (FCB).

Files are opened using `fopen`, which requires a filename and a file open mode (e.g., `"w"` for writing, `"r"` for reading, `"a"` for appending, and `"r+"` for updating). Files should always be closed using `fclose` as soon as they are no longer needed to free system resources. while `"b"` indicates binary. `rb+` open the file in binary and allow other functionality

## Sequential-Access Files

Sequential-access files are typically used for plain text and are read or written in consecutive order.

* **Creating and Writing:** You use `fprintf` to write formatted data to the file, which works identically to `printf` but requires a `FILE` pointer.


* **Reading:** You use `fscanf` to read data back. The `feof` function is used to check if the end-of-file indicator has been reached. You can reset the file position pointer to the beginning of the file using `rewind`.


* **Limitations:** Because `fprintf` writes variable-length fields, records vary in size. This makes it impossible to safely update a single record in place without overwriting adjacent data, usually requiring the entire file to be rewritten to make modifications.



```c
FILE *cfPtr;
/* Open file for writing[cite: 955, 958] */
if ((cfPtr = fopen("clients.dat", "w")) != NULL) {
    int account = 100;
    char name[] = "Jones";
    double balance = 24.98;
    
    /* Write data to the sequential file[cite: 956, 965] */
    fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
    
    /* Close the file[cite: 956, 966] */
    fclose(cfPtr); 
}

```

## Random-Access Files

Random-access files solve the update problem by using fixed-length records, allowing the program to calculate the exact byte location of any record and jump directly to it. This enables instant data retrieval and in-place updates without destroying adjacent data.

* **Raw Data Transfer:** Instead of formatted text, random-access files use `fwrite` and `fread` to transfer raw bytes of memory to and from the disk.


* **Positioning:** The `fseek` function moves the file position pointer to a specific byte offset before reading or writing. The offset is usually calculated using the record key and the `sizeof` operator.


* **Structures:** Fixed-length records are typically modeled using C `struct`s to guarantee a consistent byte size.



```c
struct clientData {
    unsigned int acctNum;
    char lastName[15];
    double balance;
};

FILE *cfPtr;
/* Open for binary reading and writing ("rb+")[cite: 1015, 1035] */
if ((cfPtr = fopen("credit.dat", "rb+")) != NULL) {
    struct clientData client = {37, "Barker", 0.00};
    
    /* Move pointer to the correct fixed-length byte offset[cite: 1016, 1019] */
    fseek(cfPtr, (client.acctNum - 1) * sizeof(struct clientData), SEEK_SET);
    
    /* Write the raw struct bytes to the file[cite: 1011, 1016] */
    fwrite(&client, sizeof(struct clientData), 1, cfPtr);
    
    fclose(cfPtr);
}

```

## Secure C Programming Best Practices

* **Pointer Validation:** Standard input/output functions like `fprintf` and `fscanf` can cause vulnerabilities if passed a `NULL` pointer. The C11 Annex K provides secure alternatives (`fprintf_s` and `fscanf_s`) that perform runtime constraints to ensure pointers are not `NULL` before execution.


* **File Constraints:** Always check the return values of functions like `fopen`, `fread`, `fwrite`, and `fseek` to guarantee the operation was successful.


* **Exclusive Mode:** When opening files, C11 introduces an exclusive write mode (appending 'x' to modes like `"w"`) that fails if the file already exists, preventing accidental truncation of existing data.