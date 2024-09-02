#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertBefore(Node **head, int data, int beforeData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL || (*head)->data == beforeData) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL && temp->next->data != beforeData)
            temp = temp->next;
        if (temp->next != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void insertAfter(Node **head, int data, int afterData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL)
        *head = newNode;
    else {
        Node *temp = *head;
        while (temp != NULL && temp->data != afterData)
            temp = temp->next;
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteNode(Node **head, int data) {
    if (*head == NULL)
        return;
    if ((*head)->data == data) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        Node *temp = *head;
        while (temp->next != NULL && temp->next->data != data)
            temp = temp->next;
        if (temp->next != NULL) {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
    }
}

void traverse(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sort(Node **head) {
    Node *current = *head;
    Node *next = NULL;
    int temp;
    while (current != NULL) {
        next = current->next;
        while (next != NULL) {
            if (current->data > next->data) {
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
}

void deleteAlternate(Node **head) {
    Node *current = *head;
    Node *next = NULL;
    while (current != NULL && current->next != NULL) {
        next = current->next;
        current->next = next->next;
        free(next);
        current = current->next;
    }
}

void insertSorted(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL && temp->next->data < data)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node *head = NULL;
    int choice, data, beforeData, afterData;
    while (1) {
        printf("1. Insert before\n");
        printf("2. Insert after\n");
        printf("3. Delete node\n");
        printf("4. Traverse\n");
        printf("5. Reverse\n");
        printf("6. Sort\n");
        printf("7. Delete alternate nodes\n");
        printf("8. Insert in sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data and before data: ");
                scanf("%d %d", &data, &beforeData);
                insertBefore(&head, data, beforeData);
                break;
            case 2:
                printf("Enter data and after data: ");
                scanf("%d %d", &data, &afterData);
                insertAfter(&head, data, afterData);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                reverse(&head);
                break;
            case 6:
                sort(&head);
                break;
            case 7:
                deleteAlternate(&head);
                break;
            case 8:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertSorted(&head, data);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
