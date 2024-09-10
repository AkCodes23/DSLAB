#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(struct Node* head) {
    return !head;
}

void push(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
    printf("%d pushed to stack\n", data);
}

int pop(struct Node** head) {
    if (isEmpty(*head)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* node = newNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
    printf("%d enqueued to queue\n", data);
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    int dequeued = temp->data;
    free(temp);
    return dequeued;
}

int front(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    return queue->front->data;
}

int rear(struct Queue* queue) {
    if (queue->rear == NULL) {
        return -1;
    }
    return queue->rear->data;
}

int main() {
    struct Node* stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("%d popped from stack\n", pop(&stack));
    

    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front element is %d\n", front(queue));
    printf("Rear element is %d\n", rear(queue));

    return 0;
}
