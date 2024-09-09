#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) {
    stack1[++top1] = x;}

int pop1() {
    return stack1[top1--];
}

void push2(int x) {
    stack2[++top2] = x;
}

int pop2() {
    return stack2[top2--];
}

void enqueue(int x) {
    push1(x);
}

int dequeue() {
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    if (top2 == -1) {
        printf("Queue is empty.\n");
        exit(1);
    }
    return pop2();
}

int main() {
    int choice, element;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue());
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
