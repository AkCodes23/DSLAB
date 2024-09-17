#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void concatenate(struct Node** X1, struct Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
        return;
    }

    struct Node* temp = *X1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = X2;
    if (X2 != NULL) {
        X2->prev = temp;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    int n1, n2;
    printf("Enter the number of nodes for the first list: ");
    scanf("%d", &n1);
    struct Node* X1 = createList(n1);
    printf("Enter the number of nodes for the second list: ");
    scanf("%d", &n2);
    struct Node* X2 = createList(n2);
    concatenate(&X1, X2);
    printf("Concatenated list: ");
    printList(X1);

    return 0;
}
