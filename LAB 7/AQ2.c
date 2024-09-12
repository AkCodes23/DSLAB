#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
            } else {
                tail->next = head1;
                tail = tail->next;
            }
            head1 = head1->next;
        } else {
            if (head == NULL) {
                head = head2;
                tail = head2;
            } else {
                tail->next = head2;
                tail = tail->next;
            }
            head2 = head2->next;
        }
    }

    if (head1 != NULL) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    return head;
}

struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);

    struct Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    struct Node* mergedList = mergeLists(head1, head2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
