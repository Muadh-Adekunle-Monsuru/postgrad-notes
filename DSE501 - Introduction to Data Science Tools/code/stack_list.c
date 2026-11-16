#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int ID;
    float CGPA;
    struct StackNode *nextPtr;
} StackNode;

void push(StackNode **headPtr, int ID, float CGPA);
void printNodes(StackNode *headPtr);
void pop(StackNode **headPtr);
void freeMem(StackNode *headPtr);

int main()
{
    StackNode *headPtr = NULL;
    push(&headPtr, 101, 4.6);
    push(&headPtr, 102, 6.6);
    push(&headPtr, 103, 4.8);
    pop(&headPtr);
    push(&headPtr, 104, 1.2);
    push(&headPtr, 105, 3.6);
    printNodes(headPtr);
    pop(&headPtr);
    pop(&headPtr);
    printNodes(headPtr);

    freeMem(headPtr);
    return 0;
}

void push(StackNode **headPtr, int ID, float CGPA)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        printf("No new memory\n");
        return;
    }
    newNode->ID = ID;
    newNode->CGPA = CGPA;
    newNode->nextPtr = *headPtr;
    *headPtr = newNode;
}

void printNodes(StackNode *headPtr)
{
    StackNode *current = headPtr;
    while (current != NULL)
    {
        printf("Student ID: %d | CGPA: %f \n", current->ID, current->CGPA);
        current = current->nextPtr;
    }
}

void pop(StackNode **headPtr)
{
    if (*headPtr == NULL)
    {
        printf("Nothing to pop() off; \n");
        return;
    }
    StackNode *temp = *headPtr;
    printf("Popping off record ID: %d \n", temp->ID);
    *headPtr = (*headPtr)->nextPtr;
    free(temp);
}

void freeMem(StackNode *headPtr)
{
    StackNode *temp;
    while (headPtr != NULL)
    {
        temp = headPtr;
        headPtr = headPtr->nextPtr;
        free(temp);
    }
}