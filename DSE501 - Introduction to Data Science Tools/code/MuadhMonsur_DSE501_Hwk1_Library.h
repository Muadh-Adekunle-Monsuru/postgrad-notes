#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap_rows(char data[50][8][50], int row1, int row2) {
    char temp[50];
    for(int col = 0; col < 8; col++) {
        strcpy(temp, data[row1][col]);
        strcpy(data[row1][col], data[row2][col]);
        strcpy(data[row2][col], temp);
    }
}


void print_data(char data[50][8][50], int num_rows) {
    printf("%-15s %-15s %-5s %-8s %-15s %-15s\n", "First Name", "Last Name", "Age", "Gender", "City", "Country");
    printf("-------------------------------------------------------------------------------\n");
    for(int i = 0; i < num_rows; i++) {
        printf("%-15s %-15s %-5s %-8s %-15s %-15s\n", 
               data[i][0], data[i][1], data[i][2], data[i][3], data[i][6], data[i][7]);
    }
    printf("\n");
}


void get_male_count(char data[50][8][50], int num_rows) {
    int count = 0;
    for(int i = 0; i < num_rows; i++) {
        if(data[i][3][0] == 'M' || (data[i][3][0] == ' ' && data[i][3][1] == 'M')) {
            count++;
        } 
    }
    printf("There are %d males.\n", count);
}

void get_female_count(char data[50][8][50], int num_rows) {
    int count = 0;
    for(int i = 0; i < num_rows; i++) {
        if(data[i][3][0] == 'F' || (data[i][3][0] == ' ' && data[i][3][1] == 'F')) {
            count++;
        } 
    }
    printf("There are %d females.\n\n", count);
}

void average_age(char data[50][8][50], int num_rows) {
    int sum = 0;
    if (num_rows == 0) return; 
    
    for(int i = 0; i < num_rows; i++) {
        sum += atoi(data[i][2]); 
    }
    printf("The average age is %.2lf.\n\n", (double)sum / num_rows);
}


void country_breakdown(char data[50][8][50], int num_rows) {
    int visited[50] = {0}; 
    
    printf("--- Country Breakdown ---\n");
    for(int i = 0; i < num_rows; i++) {
        if(visited[i] == 1) continue; 
        
        int count = 1;
        for(int j = i + 1; j < num_rows; j++) {
            if(strcmp(data[i][7], data[j][7]) == 0) {
                visited[j] = 1; // Mark as counted
                count++;
            }
        }
        // Remove leading spaces for cleaner printing if they exist
        char *countryName = (data[i][7][0] == ' ') ? data[i][7] + 1 : data[i][7];
        printf("%s: %d\n", countryName, count);
    }
    printf("\n");
}

void print_age_less_than(char data[50][8][50], int num_rows, int target_age) {
    printf("--- People younger than %d ---\n", target_age);
    for(int i = 0; i < num_rows; i++) {
        if(atoi(data[i][2]) < target_age) {
            printf("%s %s (Age: %s)\n", data[i][0], data[i][1], data[i][2]);
        }
    }
    printf("\n");
}

void sort_by_age(char data[50][8][50], int num_rows) {
    for(int i = 0; i < num_rows - 1; i++) {
        for(int j = 0; j < num_rows - i - 1; j++) {
            if(atoi(data[j][2]) > atoi(data[j+1][2])) {
                swap_rows(data, j, j+1);
            }
        }
    }
    printf("--- Data Sorted by Age (Ascending) ---\n");
    print_data(data, num_rows);
}

void sort_by_first_name(char data[50][8][50], int num_rows) {
    for(int i = 0; i < num_rows - 1; i++) {
        for(int j = 0; j < num_rows - i - 1; j++) {
            if(strcmp(data[j][0], data[j+1][0]) > 0) {
                swap_rows(data, j, j+1);
            }
        }
    }
    printf("--- Data Sorted by First Name (A-Z) ---\n");
    print_data(data, num_rows);
}
