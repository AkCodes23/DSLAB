#include <stdio.h>
#include <stdlib.h>

// Node structure for the tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to copy a tree
struct Node* copyTree(struct Node* original) {
    if (original == NULL)
        return NULL;

    struct Node* newNode = createNode(original->data);
    newNode->left = copyTree(original->left);
    newNode->right = copyTree(original->right);
    return newNode;
}

// Function to perform in-order traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    struct Node *original = createNode(1);
    original->left = createNode(2);
    original->right = createNode(3);

    printf("Original Tree (In-order): ");
    inorder(original);
    printf("\n");

    struct Node *copy = copyTree(original);
    printf("Copied Tree (In-order): ");
    inorder(copy);
    printf("\n");

    return 0;
}
