#ifndef MUADHMONSUR_DSE501_HWK1B_LIBRARY_H
#define MUADHMONSUR_DSE501_HWK1B_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for Instructor personal and address data
typedef struct {
    char first_name[50];
    char last_name[50];
    int age;
    char gender[50];
    char street_name[50];
    int street_number;
    char city[50];
    char country[50];
} Instructor;

// Function to read data from file line by line and store into struct array
int read_instructor_data(const char *filename, Instructor instructors[], int *num_rows) {
    FILE *ctPtr = fopen(filename, "r");
    if (ctPtr == NULL) {
        printf("File could not be opened \n");
        return 0;
    }
    
    *num_rows = 0;
    while (fscanf(ctPtr, " %[^,], %[^,], %d, %[^,], %[^,], %d, %[^,], %[^.]. \n",
                  instructors[*num_rows].first_name,
                  instructors[*num_rows].last_name,
                  &instructors[*num_rows].age,
                  instructors[*num_rows].gender,
                  instructors[*num_rows].street_name,
                  &instructors[*num_rows].street_number,
                  instructors[*num_rows].city,
                  instructors[*num_rows].country) == 8) {
        (*num_rows)++;
        if (*num_rows >= 50) break;
    }
    
    fclose(ctPtr);
    return 1;
}

// Function to swap two instructor structs (used for sorting)
void swap_instructors(Instructor *a, Instructor *b) {
    Instructor temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the struct array by age in ascending order
void sort_by_age(Instructor instructors[], int num_rows) {
    for (int i = 0; i < num_rows - 1; i++) {
        for (int j = 0; j < num_rows - i - 1; j++) {
            if (instructors[j].age > instructors[j+1].age) {
                swap_instructors(&instructors[j], &instructors[j+1]);
            }
        }
    }
}

// Function to print the instructor data in a formatted table
void print_data(Instructor instructors[], int num_rows) {
    printf("%-15s %-15s %-5s %-8s %-15s %-15s\n", "First Name", "Last Name", "Age", "Gender", "City", "Country");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_rows; i++) {
        // Clean leading space for country if present
        char *countryName = (instructors[i].country[0] == ' ') ? instructors[i].country + 1 : instructors[i].country;
        
        printf("%-15s %-15s %-5d %-8s %-15s %-15s\n", 
               instructors[i].first_name, 
               instructors[i].last_name, 
               instructors[i].age, 
               instructors[i].gender, 
               instructors[i].city, 
               countryName);
    }
    printf("\n");
}

#endif