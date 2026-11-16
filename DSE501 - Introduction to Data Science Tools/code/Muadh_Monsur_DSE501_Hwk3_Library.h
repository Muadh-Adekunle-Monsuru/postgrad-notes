#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Instructor
{
    char title[50];
    char first_name[50];
    char last_name[50];
    int age;
    char gender[50];
    char street_name[50];
    int street_number;
    char city[50];
    char country[50];
    struct Instructor *nextPtr;
} Instructor;
void create_node(Instructor **headPtr, char title[50], char first_name[50], char last_name[50], int age, char gender[50], char street_name[50], int street_number, char city[50], char country[50]);
FILE *extract_file(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Correct usage: %s <data-file>", argv[0]);
        exit(-1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("error opening file");
        exit(-1);
    }
    return file;
}

void parse_data(FILE *file, Instructor **headPtr, int *row)
{
    char title[50], first_name[50], last_name[50], gender[50], street_name[50], city[50], country[50];
    int age, street_number;

    while (fscanf(file, " %49[^,], %49[^,], %49[^,], %d, %49[^,], %49[^,], %d, %49[^,], %49[^.].\n", title, first_name, last_name, &age, gender, street_name, &street_number, city, country) == 9)
    {
        create_node(headPtr, title, first_name, last_name, age, gender, street_name, street_number, city, country);
        (*row)++;
    }
    printf("%d row(s) successfuly parsed \n", *row);

    fclose(file);
}

void create_node(Instructor **headPtr, char title[50], char first_name[50], char last_name[50], int age, char gender[50], char street_name[50], int street_number, char city[50], char country[50])
{
    Instructor *newNode = (Instructor *)malloc(sizeof(Instructor));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory for node");
        return;
    }
    strcpy(newNode->title, title);
    strcpy(newNode->first_name, first_name);
    strcpy(newNode->last_name, last_name);
    newNode->age = age;
    strcpy(newNode->gender, gender);
    strcpy(newNode->street_name, street_name);
    newNode->street_number, street_number;
    strcpy(newNode->city, city);
    strcpy(newNode->country, country);

    newNode->nextPtr = *headPtr;
    *headPtr = newNode;
}

void print_nodes(Instructor *headPtr)
{
    Instructor *currentNode = headPtr;
    if (currentNode == NULL)
    {
        printf("Linked list is empty \n");
        return;
    }

    while (currentNode != NULL)
    {
        printf("%-10s %-10s %-15s \n", currentNode->title, currentNode->first_name, currentNode->last_name);
        currentNode = currentNode->nextPtr;
    }
}

void sort_nodes(Instructor *headPtr)
{
    if (headPtr == NULL)
        return;

    int swapped;
    Instructor *ptr1;
    Instructor *lptr = NULL; // Marks the end of sorted portion

    do
    {
        swapped = 0;
        ptr1 = headPtr;

        while (ptr1->nextPtr != lptr)
        {
            // strcmp returns > 0 if ptr1->last_name comes AFTER nextPtr->last_name alphabetically
            // We use > 0 for Ascending order (A to Z)
            if (strcmp(ptr1->last_name, ptr1->nextPtr->last_name) > 0)
            {
                // Swap all fields between ptr1 and ptr1->nextPtr

                // Swap strings using a temporary buffer
                char temp_str[50];

                strcpy(temp_str, ptr1->title);
                strcpy(ptr1->title, ptr1->nextPtr->title);
                strcpy(ptr1->nextPtr->title, temp_str);

                strcpy(temp_str, ptr1->first_name);
                strcpy(ptr1->first_name, ptr1->nextPtr->first_name);
                strcpy(ptr1->nextPtr->first_name, temp_str);

                strcpy(temp_str, ptr1->last_name);
                strcpy(ptr1->last_name, ptr1->nextPtr->last_name);
                strcpy(ptr1->nextPtr->last_name, temp_str);

                // Swap integers (age, street_number)
                int temp_int = ptr1->age;
                ptr1->age = ptr1->nextPtr->age;
                ptr1->nextPtr->age = temp_int;

                strcpy(temp_str, ptr1->gender);
                strcpy(ptr1->gender, ptr1->nextPtr->gender);
                strcpy(ptr1->nextPtr->gender, temp_str);

                strcpy(temp_str, ptr1->street_name);
                strcpy(ptr1->street_name, ptr1->nextPtr->street_name);
                strcpy(ptr1->nextPtr->street_name, temp_str);

                temp_int = ptr1->street_number;
                ptr1->street_number = ptr1->nextPtr->street_number;
                ptr1->nextPtr->street_number = temp_int;

                strcpy(temp_str, ptr1->city);
                strcpy(ptr1->city, ptr1->nextPtr->city);
                strcpy(ptr1->nextPtr->city, temp_str);

                strcpy(temp_str, ptr1->country);
                strcpy(ptr1->country, ptr1->nextPtr->country);
                strcpy(ptr1->nextPtr->country, temp_str);

                swapped = 1;
            }
            ptr1 = ptr1->nextPtr;
        }
        lptr = ptr1;
    } while (swapped);
}