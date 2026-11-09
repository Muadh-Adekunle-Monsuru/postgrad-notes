/*
Assignment 1b by Muadh Monsur. Reading contents from file into structs and sorting by age.
*/
#include <stdio.h>
#include <stdlib.h>
#include "MuadhMonsur_DSE501_Hwk1b_Library.h"

int main(void) {
    Instructor instructors[50];
    int num_rows = 0;

    // Read data from file into struct array
    if (read_instructor_data("DSE501_Hwk1_Instructors.txt", instructors, &num_rows)) {
        
        // Sort data by age
        sort_by_age(instructors, num_rows);

        // Print the sorted data to the screen
        printf("--- Instructors Sorted by Age (Ascending) ---\n");
        print_data(instructors, num_rows);
    }

    return 0;
}