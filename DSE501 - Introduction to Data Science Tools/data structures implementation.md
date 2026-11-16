
```C
#include <stdio.h>
#include <stdlib.h>

/* ==========================================================================
 * 1. LINKED LIST IMPLEMENTATION
 * ========================================================================== */
typedef struct ListNode {
    int id;
    float score;
    struct ListNode *next;
} ListNode;

void insertLinkedList(ListNode **head, int id, float score) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->id = id;
    newNode->score = score;
    newNode->next = *head;
    *head = newNode;
}

void printLinkedList(ListNode *head) {
    printf("\n--- Linked List (Student Records) ---\n");
    ListNode *current = head;
    while (current != NULL) {
        printf("Student ID: %d | Score: %.2f\n", current->id, current->score);
        current = current->next;
    }
}

void freeLinkedList(ListNode *head) {
    ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ==========================================================================
 * 2. STACK IMPLEMENTATION (LIFO - Last In, First Out)
 * ========================================================================== */
typedef struct StackNode {
    int id;
    float score;
    struct StackNode *next;
} StackNode;

void push(StackNode **top, int id, float score) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->id = id;
    newNode->score = score;
    newNode->next = *top;
    *top = newNode;
}

void pop(StackNode **top) {
    if (*top == NULL) {
        printf("Stack Underflow: No records to pop.\n");
        return;
    }
    StackNode *temp = *top;
    printf("Popped Student ID: %d | Score: %.2f\n", temp->id, temp->score);
    *top = (*top)->next;
    free(temp);
}

void freeStack(StackNode *top) {
    StackNode *temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

/* ==========================================================================
 * 3. QUEUE IMPLEMENTATION (FIFO - First In, First Out)
 * ========================================================================== */
typedef struct QueueNode {
    int id;
    float score;
    struct QueueNode *next;
} QueueNode;

void enqueue(QueueNode **head, QueueNode **tail, int id, float score) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->id = id;
    newNode->score = score;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*tail)->next = newNode;
    }
    *tail = newNode;
}

void dequeue(QueueNode **head, QueueNode **tail) {
    if (*head == NULL) {
        printf("Queue Underflow: No records to dequeue.\n");
        return;
    }
    QueueNode *temp = *head;
    printf("Dequeued Student ID: %d | Score: %.2f\n", temp->id, temp->score);
    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }
    free(temp);
}

void freeQueue(QueueNode *head) {
    QueueNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ==========================================================================
 * 4. BINARY SEARCH TREE IMPLEMENTATION (Sorted by Student ID)
 * ========================================================================== */
typedef struct TreeNode {
    int id;
    float score;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void insertTree(TreeNode **root, int id, float score) {
    if (*root == NULL) {
        *root = (TreeNode *)malloc(sizeof(TreeNode));
        if (*root != NULL) {
            (*root)->id = id;
            (*root)->score = score;
            (*root)->left = NULL;
            (*root)->right = NULL;
        }
        return;
    }

    if (id < (*root)->id) {
        insertTree(&((*root)->left), id, score);
    } else if (id > (*root)->id) {
        insertTree(&((*root)->right), id, score);
    } else {
        printf("Duplicate Student ID %d ignored.\n", id);
    }
}

void inOrderTraversal(TreeNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Student ID: %d | Score: %.2f\n", root->id, root->score);
        inOrderTraversal(root->right);
    }
}

void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/* ==========================================================================
 * MAIN EXECUTION
 * ========================================================================== */
int main(void) {
    // 1. Linked List Demo
    ListNode *listHead = NULL;
    insertLinkedList(&listHead, 101, 88.5);
    insertLinkedList(&listHead, 102, 92.0);
    insertLinkedList(&listHead, 103, 75.4);
    printLinkedList(listHead);

    // 2. Stack Demo (LIFO)
    printf("\n--- Stack Operations (Assignment Submissions) ---\n");
    StackNode *stackTop = NULL;
    push(&stackTop, 101, 88.5);
    push(&stackTop, 102, 92.0);
    push(&stackTop, 103, 75.4);
    pop(&stackTop); // Removes ID 103
    pop(&stackTop); // Removes ID 102

    // 3. Queue Demo (FIFO)
    printf("\n--- Queue Operations (Admissions Line) ---\n");
    QueueNode *qHead = NULL, *qTail = NULL;
    enqueue(&qHead, &qTail, 101, 88.5);
    enqueue(&qHead, &qTail, 102, 92.0);
    enqueue(&qHead, &qTail, 103, 75.4);
    dequeue(&qHead, &qTail); // Removes ID 101
    dequeue(&qHead, &qTail); // Removes ID 102

    // 4. BST Demo (In-Order Traversal prints sorted by ID)
    printf("\n--- Binary Search Tree (Sorted Lookup) ---\n");
    TreeNode *treeRoot = NULL;
    insertTree(&treeRoot, 102, 92.0);
    insertTree(&treeRoot, 101, 88.5);
    insertTree(&treeRoot, 104, 95.0);
    insertTree(&treeRoot, 103, 75.4);
    inOrderTraversal(treeRoot);

    // Clean up allocated memory
    freeLinkedList(listHead);
    freeStack(stackTop);
    freeQueue(qHead);
    freeTree(treeRoot);

    return 0;
}
```