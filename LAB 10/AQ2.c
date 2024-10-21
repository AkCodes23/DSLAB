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

// Function to check if two trees are mirror images of each other
int areMirrors(struct Node* tree1, struct Node* tree2) {
    if (tree1 == NULL && tree2 == NULL)
        return 1;
    if (tree1 == NULL || tree2 == NULL)
        return 0;
    return (tree1->data == tree2->data) &&
           areMirrors(tree1->left, tree2->right) &&
           areMirrors(tree1->right, tree2->left);
}

// Main function
int main() {
    struct Node *tree1 = createNode(1);
    tree1->left = createNode(2);
    tree1->right = createNode(3);

    struct Node *tree2 = createNode(1);
    tree2->left = createNode(3);
    tree2->right = createNode(2);

    if (areMirrors(tree1, tree2))
        printf("The two trees are mirror images.\n");
    else
        printf("The two trees are not mirror images.\n");

    return 0;
}
