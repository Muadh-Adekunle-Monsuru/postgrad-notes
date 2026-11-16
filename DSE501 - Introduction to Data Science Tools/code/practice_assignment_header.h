#include <stdio.h>

FILE *parse_file(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <data-filename>", argv[0]);
        exit(-1);
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "File is empty");
        exit(-1);
    }

    return file;
}

void parse_data(FILE *file, char data_array[50][8][50], int *row)
{
    char first_name[50], last_name[50], gender[50], team_name[50], city[50], country[50];
    int score, jersey_number;

    while (fscanf(file, " %[^,], %[^,], %d, %[^,], %[^,], %d, %[^,], %[^\n\r]", first_name, last_name, &score, gender, team_name, &jersey_number, city, country) == 8)
    {

        // Fix 1: Removed [50] so it passes the string base address (char *)
        // Fix 2: Shifted indices to range from 0 to 7 to prevent out-of-bounds access
        strcpy(data_array[*row][0], first_name);
        strcpy(data_array[*row][1], last_name);
        sprintf(data_array[*row][2], "%d", score); // Fix 3: Removed '&' from score
        strcpy(data_array[*row][3], gender);
        strcpy(data_array[*row][4], team_name);
        sprintf(data_array[*row][5], "%d", jersey_number); // Fix 4: Removed '&' from jersey_number
        strcpy(data_array[*row][6], city);
        strcpy(data_array[*row][7], country);

        (*row)++; // Fix 5: Increment the value of row, not the pointer itself
    }

    printf("Total rows: %d", *row); // Fix 6: Dereference row to print the final integer value
    fclose(file);
}

void sort_data(char data_array[50][8][50], int row)
{
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = i + 1; j < row; j++)
        {
            if (atoi(data_array[i][2]) < atoi(data_array[j][2]))
            {
                char temp[50];
                for (int k = 0; k < 8; k++)
                {
                    strcpy(temp, data_array[i][k]);
                    strcpy(data_array[i][k], data_array[j][k]);
                    strcpy(data_array[j][k], temp);
                }
            }
        }
    }
}

void print_data(char data_array[50][8][50], int row)
{
    printf("%-15s %-15s %-7s %-7s %-20s %-7s %-15s %-15s \n\n ", "first_name", "last_name", "score", "gender", "team_name", "jersey_number", "city", "country");
    for (int i = 0; i < row; i++)
    {
        printf("%-15s %-15s %-7s %-7s %-20s %-7s %-15s %-15s \n ", data_array[i][0], data_array[i][1], data_array[i][2], data_array[i][3], data_array[i][4], data_array[i][5], data_array[i][6], data_array[i][7]);
    }
}