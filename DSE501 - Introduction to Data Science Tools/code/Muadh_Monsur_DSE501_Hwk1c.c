#include <stdio.h>
#include <stdlib.h>
#include "Muadh_Monsur_DSE501_Hwk3_Library.h"

FILE *extract_file(int argc, char *argv[]);
void parse_data(FILE *file, Instructor **headPtr, int *row);
void print_nodes(Instructor *headPtr);
void sort_nodes(Instructor *headPtr);

int main(int argc, char *argv[])
{
    Instructor *headPtr;
    int row_count = 0;
    FILE *file = extract_file(argc, argv);
    parse_data(file, &headPtr, &row_count);
    sort_nodes(headPtr);
    print_nodes(headPtr);
    return 0;
}