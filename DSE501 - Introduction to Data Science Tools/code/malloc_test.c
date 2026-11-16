#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *arr;
    int length = 0;

    printf("What is the length of the array: ");
    scanf("%d", &length);

    arr = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        arr[i] = i * 10;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d: %d \n", i, arr[i]);
    }

    return 0;
}