#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* create_list(int data[], int size) {
    if (size == 0) {
        return NULL;
    } else {
        struct Node* head = (struct Node*)malloc(sizeof(struct Node));
        head->data = data[0];
        head->next = create_list(data + 1, size - 1);
        return head;
    }
}

void print_list(struct Node* head) {
    if (head == NULL) {
        return;
    } else {
        printf("%d ", head->data);
        print_list(head->next);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int data[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    struct Node* head = create_list(data, n);
    printf("Traversing the list:\n");
    print_list(head);

    return 0;
}
