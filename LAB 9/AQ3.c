#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    char userName[50];
    int time;
    struct Node *next, *prev;
};

// Function to create a new node
struct Node* createNode(char* name, int time) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->userName, name);
    newNode->time = time;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Function to add a user to the circular doubly linked list
void addUser(struct Node** head, char* name, int time) {
    struct Node* newNode = createNode(name, time);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

// Function to simulate the renting system
void simulateRenting(struct Node** head) {
    struct Node* current = *head;
    while (current) {
        printf("Washing Machine in use by: %s for %d minutes\n", current->userName, current->time);
        current = current->next;
        if (current == *head) break;  // Completed one cycle
    }
}

// Main function
int main() {
    struct Node* queue = NULL;

    addUser(&queue, "Alice", 30);
    addUser(&queue, "Bob", 20);
    addUser(&queue, "Charlie", 40);

    printf("Washing Machine Renting System Simulation:\n");
    simulateRenting(&queue);

    return 0;
}
