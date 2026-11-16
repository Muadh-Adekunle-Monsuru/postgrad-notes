#include <stdio.h>
#include <string.h>

struct Student
{
    char id[50];
    char name[50];
    int age;
    int grades[50];
};

typedef struct
{
    int x;
    int y;
} Point;

void print_student(struct Student student);
void print_points(Point points[]);

int main()
{

    struct Student adam;

    strcpy(adam.id, "001");
    strcpy(adam.name, "Adam");
    adam.age = 50;
    adam.grades[0] = 10;
    adam.grades[1] = 40;
    adam.grades[2] = 50;
    adam.grades[3] = 30;
    adam.grades[4] = 80;
    print_student(adam);

    Point first = {34, 54};
    printf("first.x: %d\n", first.x);
    printf("first.y: %d\n", first.y);

    Point coordinates[10];

    for (int i = 0; i < 10; i++)
    {
        coordinates[i].x = i * 5;
        coordinates[i].y = i + 7;
    }
    print_points(coordinates);
    return 0;
}

void print_points(Point points[])
{
    for (int j = 0; j < 10; j++)
    {
        printf("%d = (%d, %d); \n", j, points[j].x, points[j].y);
    }
}
void print_student(struct Student student)
{
    printf("ID: %s \n", student.id);
    printf("Name: %s \n", student.name);
    printf("Age: %d \n", student.age);
    printf("Grades: ");
    for (int i = 0; i < 5; i++)
        printf("%d | ", student.grades[i]);
    printf("\n");
}