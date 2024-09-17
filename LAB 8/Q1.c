#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int data[MAX];
int next[MAX];
int prev[MAX];
int head = -1;
int tail = -1;
int freeIndex = 0;

void insertAtEnd(int value);
void deleteFromEnd();
void insertAtPosition(int value, int position);
void deleteFromPosition(int position);
void insertAfterElement(int value, int element);
void insertBeforeElement(int value, int element);
void traverseList();
void reverseList();

int main() {
    int choice, value, position, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete from end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from position\n");
        printf("5. Insert after element\n");
        printf("6. Insert before element\n");
        printf("7. Traverse list\n");
        printf("8. Reverse list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                deleteFromEnd();
                break;
            case 3:
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &value);
                insertAtPosition(value, position);
                break;
            case 4:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 5:
                printf("Enter element to insert after: ");
                scanf("%d", &element);
                printf("Enter data to insert: ");
                scanf("%d", &value);
                insertAfterElement(value, element);
                break;
            case 6:
                printf("Enter element to insert before: ");
                scanf("%d", &element);
                printf("Enter data to insert: ");
                scanf("%d", &value);
                insertBeforeElement(value, element);
                break;
            case 7:
                traverseList();
                break;
            case 8:
                reverseList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void insertAtEnd(int value) {
    if (freeIndex >= MAX) {
        printf("List is full!\n");
        return;
    }

    data[freeIndex] = value;
    next[freeIndex] = -1;
    prev[freeIndex] = tail;

    if (tail != -1) {
        next[tail] = freeIndex;
    } else {
        head = freeIndex;
    }

    tail = freeIndex;
    freeIndex++;
}

void deleteFromEnd() {
    if (tail == -1) {
        printf("List is empty!\n");
        return;
    }

    int temp = tail;
    tail = prev[tail];

    if (tail != -1) {
        next[tail] = -1;
    } else {
        head = -1;
    }

    freeIndex--;
}

void insertAtPosition(int value, int position) {
    if (freeIndex >= MAX) {
        printf("List is full!\n");
        return;
    }

    if (position < 1 || position > freeIndex + 1) {
        printf("Position out of range!\n");
        return;
    }

    if (position == freeIndex + 1) {
        insertAtEnd(value);
        return;
    }

    int newIndex = freeIndex;
    data[newIndex] = value;

    if (position == 1) {
        next[newIndex] = head;
        prev[newIndex] = -1;
        prev[head] = newIndex;
        head = newIndex;
    } else {
        int temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = next[temp];
        }

        next[newIndex] = next[temp];
        prev[newIndex] = temp;
        prev[next[temp]] = newIndex;
        next[temp] = newIndex;
    }

    freeIndex++;
}

void deleteFromPosition(int position) {
    if (position < 1 || position > freeIndex) {
        printf("Position out of range!\n");
        return;
    }

    if (position == freeIndex) {
        deleteFromEnd();
        return;
    }

    int temp = head;
    for (int i = 1; i < position; i++) {
        temp = next[temp];
    }

    if (prev[temp] != -1) {
        next[prev[temp]] = next[temp];
    } else {
        head = next[temp];
    }

    if (next[temp] != -1) {
        prev[next[temp]] = prev[temp];
    } else {
        tail = prev[temp];
    }

    freeIndex--;
}

void insertAfterElement(int value, int element) {
    int temp = head;
    while (temp != -1 && data[temp] != element) {
        temp = next[temp];
    }

    if (temp == -1) {
        printf("Element not found!\n");
        return;
    }

    int newIndex = freeIndex;
    data[newIndex] = value;
    next[newIndex] = next[temp];
    prev[newIndex] = temp;

    if (next[temp] != -1) {
        prev[next[temp]] = newIndex;
    } else {
        tail = newIndex;
    }

    next[temp] = newIndex;
    freeIndex++;
}

void insertBeforeElement(int value, int element) {
    int temp = head;
    while (temp != -1 && data[temp] != element) {
        temp = next[temp];
    }

    if (temp == -1) {
        printf("Element not found!\n");
        return;
    }

    int newIndex = freeIndex;
    data[newIndex] = value;
    next[newIndex] = temp;
    prev[newIndex] = prev[temp];

    if (prev[temp] != -1) {
        next[prev[temp]] = newIndex;
    } else {
        head = newIndex;
    }

    prev[temp] = newIndex;
    freeIndex++;
}

void traverseList() {
    int temp = head;
    while (temp != -1) {
        printf(" %d ", data[temp]);
        temp = next[temp];
    }
    printf("\n");
}

void reverseList() {
    int temp = head;
    int prevTemp = -1;
    int nextTemp;

    while (temp != -1) {
        nextTemp = next[temp];
        next[temp] = prevTemp;
        prev[temp] = nextTemp;
        prevTemp = temp;
        temp = nextTemp;
    }

    temp = head;
    head = tail;
    tail = temp;
}
//SurajShuban was here
