#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtRear(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteAtRear() {
    if (head == NULL) {
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp == head) {
        head = NULL;
    } else {
        temp->prev->next = NULL;
    }
    free(temp);
}

void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }

        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteAtPosition(int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position.\n");
            return;
        }

        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete->next != NULL) {
            toDelete->next->prev = temp;
        }
        free(toDelete);
    }
}

void insertAfter(int data, int afterData) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterData) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void insertBefore(int data, int beforeData) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != beforeData) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
}

void traverse() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int main() {
    int choice, data, position;

    while (1) {
        printf("1. Insert at rear\n");
        printf("2. Delete at rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete at position\n");
        printf("5. Insert after\n");
        printf("6. Insert before\n");
        printf("7. Traverse\n");
        printf("8. Reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtRear(data);
                break;
            case 2:
                deleteAtRear();
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(data, position);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 5:
                printf("Enter data and after which element: ");
                scanf("%d %d", &data, &afterData);
                insertAfter(data, afterData);
                break;
            case 6:
                printf("Enter data and before which element: ");
                scanf("%d %d", &data, &beforeData);
                insertBefore(data, beforeData);
                break;
            case 7:
                traverse();
                break;
            case 8:
                reverse();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
