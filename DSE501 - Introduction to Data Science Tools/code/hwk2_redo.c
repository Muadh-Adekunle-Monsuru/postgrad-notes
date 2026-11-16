#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hwk2_redo_library.h"

typedef struct
{
    char first_name[50];
    char last_name[50];
    int age;
    char gender[50];
    char street_name[50];
    int house_number;
    char city[50];
    char country[50];
} Data;

// reading from file
FILE *file_open(char *argv[]);
// breaking into pieces
void parse_data(FILE *file, Data data_struct[]);

// sorting data
void sort_data(Data data_struct[]);
// printing the data
void print_data(Data data_struct[]);
int main(int argc, char *argv[])
{
    FILE *file = file_open(argv);
    Data data_array[50];
    parse_data(file, data_array);
    sort_data(data_array);
    print_data(data_array);
    return 0;
}

void parse_data(FILE *file, Data data_struct[])
{
    char line[500];
    int row = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {

        char *first_name = strtok(line, ",");
        if (first_name != NULL && *first_name == ' ')
        {
            first_name++;
        }
        strcpy(data_struct[row].first_name, first_name);

        char *last_name = strtok(NULL, ",");
        if (last_name != NULL && *last_name == ' ')
        {
            last_name++;
        }
        strcpy(data_struct[row].last_name, last_name);

        char *token = strtok(NULL, ",");
        if (token != NULL && *token == ' ')
        {
            token++;
        }
        data_struct[row].age = atoi(token);

        char *gender = strtok(NULL, ",");
        if (gender != NULL && *gender == ' ')
        {
            gender++;
        }
        strcpy(data_struct[row].gender, gender);

        char *street = strtok(NULL, ",");
        if (street != NULL && *street == ' ')
        {
            street++;
        }
        strcpy(data_struct[row].street_name, street);

        token = strtok(NULL, ",");
        if (token != NULL && *token == ' ')
        {
            token++;
        }
        data_struct[row].house_number = atoi(token);

        char *city = strtok(NULL, ",");
        if (city != NULL && *city == ' ')
        {
            city++;
        }
        strcpy(data_struct[row].city, city);

        char *country = strtok(NULL, ",");
        if (country != NULL && *country == ' ')
        {
            country++;
        }
        strcpy(data_struct[row].country, country);

        row++;
    }

    fclose(file);
}

void sort_data(Data data_struct[])
{
    for (int i = 0; i < 49; i++)
    {
        for (int j = i + 1; j < 50; j++)
        {
            if (data_struct[i].age < data_struct[j].age)
            {
                Data temp;
                temp = data_struct[i];
                data_struct[i] = data_struct[j];
                data_struct[j] = temp;
            }
        }
    }
}

void print_data(Data data_struct[])
{
    printf("%-15s %-15s %-15s %-15s% -15s %-15s %-15s %-15s \n", "First Name", "Last Name", "Age", "Gender", "Street Name", "Street Number", "City", "Country");
    for (int i = 0; i < 50; i++)
    {
        printf("%-15s %-15s %-15d %-15s% -15s %-15d %-15s %-15s \n", data_struct[i].first_name, data_struct[i].last_name, data_struct[i].age, data_struct[i].gender, data_struct[i].street_name, data_struct[i].house_number, data_struct[i].city, data_struct[i].country);
    }
}