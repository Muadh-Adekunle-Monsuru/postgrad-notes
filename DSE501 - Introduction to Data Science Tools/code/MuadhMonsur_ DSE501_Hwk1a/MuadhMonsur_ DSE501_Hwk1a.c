/*
Assignment 1a by Muadh Monsur. Reading contents from file and using it
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MuadhMonsur_DSE501_Hwk1_Library.h"

int main(void){
    char first_name[50], last_name[50], gender[50], street_name[50], city[50], country[50];
    int age, street_number, row = 0;
    char dataArray[50][8][50];
    FILE *ctPtr;

    if((ctPtr = fopen("DSE501_Hwk1_Instructors.txt", "r")) == NULL){
        printf("File could not be opened \n");
        exit(-1);
    } else {
        while(fscanf(ctPtr, " %[^,], %[^,], %d, %[^,], %[^,], %d, %[^,], %[^.]. \n", 
                     first_name, last_name, &age, gender, street_name, &street_number, city, country) == 8) {
            
            strcpy(dataArray[row][0], first_name);
            strcpy(dataArray[row][1], last_name);
            sprintf(dataArray[row][2], "%d", age);
            strcpy(dataArray[row][3], gender);
            strcpy(dataArray[row][4], street_name);
            sprintf(dataArray[row][5], "%d", street_number);
            strcpy(dataArray[row][6], city);
            strcpy(dataArray[row][7], country);
            row++;
        }

        // Basic Stats
        get_male_count(dataArray, row);
        get_female_count(dataArray, row);
        average_age(dataArray, row);

        // Data Filtering and Breakdown
        country_breakdown(dataArray, row);
        print_age_less_than(dataArray, row, 30); 

        // Sorting 
        sort_by_first_name(dataArray, row);
        sort_by_age(dataArray, row);

        fclose(ctPtr);
    }

    return 0;
}