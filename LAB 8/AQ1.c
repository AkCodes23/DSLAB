#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct Node {
    int data;
    struct Node *prev, *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list
void display(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Helper function to search if a value exists in a list
int search(struct Node* head, int value) {
    while (head) {
        if (head->data == value)
            return 1;
        head = head->next;
    }
    return 0;
}

// Function to get the union of two doubly linked lists
struct Node* getUnion(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp = list1;

    while (temp) {
        insertEnd(&result, temp->data);
        temp = temp->next;
    }

    temp = list2;
    while (temp) {
        if (!search(result, temp->data))
            insertEnd(&result, temp->data);
        temp = temp->next;
    }
    return result;
}

// Function to get the intersection of two doubly linked lists
struct Node* getIntersection(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp = list1;

    while (temp) {
        if (search(list2, temp->data))
            insertEnd(&result, temp->data);
        temp = temp->next;
    }
    return result;
}

// Main function
int main() {
    struct Node *list1 = NULL, *list2 = NULL;

    insertEnd(&list1, 10);
    insertEnd(&list1, 15);
    insertEnd(&list1, 20);

    insertEnd(&list2, 15);
    insertEnd(&list2, 20);
    insertEnd(&list2, 25);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node* unionList = getUnion(list1, list2);
    printf("Union: ");
    display(unionList);

    struct Node* intersectionList = getIntersection(list1, list2);
    printf("Intersection: ");
    display(intersectionList);

    return 0;
}
