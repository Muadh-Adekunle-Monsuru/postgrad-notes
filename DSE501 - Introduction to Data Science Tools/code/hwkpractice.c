#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "practice_assignment_header.h"

FILE *parse_file(int argc, char *argv[]);
void parse_data(FILE *file, char data_array[50][8][50], int *row);
void sort_data(char data_array[50][8][50], int row);
void print_data(char data_array[50][8][50], int row);

int main(int argc, char *argv[])
{
    char data_array[50][8][50] = {0};
    int row = 0;

    FILE *file = parse_file(argc, argv);
    parse_data(file, data_array, &row);
    sort_data(data_array, row);
    print_data(data_array, row);

    return 0;
}