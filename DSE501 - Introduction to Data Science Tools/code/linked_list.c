#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int ID;
    double CGPA;
    struct ListNode *nextPtr;
} ListNode;

void insertNode(ListNode **headPtr, int ID, double CGPA);
void printNode(ListNode *headPtr);
void freeMem(ListNode *headPtr);

int main(void)
{

    ListNode *headNode = NULL;
    insertNode(&headNode, 101, 4.5);
    insertNode(&headNode, 102, 3.5);
    insertNode(&headNode, 103, 2.8);
    insertNode(&headNode, 104, 5.0);
    printNode(headNode);

    freeMem(headNode);
    return 0;
}

void insertNode(ListNode **headPtr, int ID, double CGPA)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        printf("No memory available");
        exit(-1);
    }
    newNode->ID = ID;
    newNode->CGPA = CGPA;
    newNode->nextPtr = *headPtr;
    *headPtr = newNode;
}

void printNode(ListNode *headPtr)
{
    printf("Student Records in LinkedList \n");
    ListNode *current = headPtr;
    while (current != NULL)
    {
        printf("Student ID: %d | CGPA: %lf \n", current->ID, current->CGPA);
        current = current->nextPtr;
    }
}

void freeMem(ListNode *headPtr)
{
    ListNode *temp;
    while (headPtr != NULL)
    {
        temp = headPtr;
        headPtr = headPtr->nextPtr;
        free(temp);
    }
}