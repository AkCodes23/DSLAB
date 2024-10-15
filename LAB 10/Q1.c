#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Iterative In-order Traversal
void inOrderTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Iterative Pre-order Traversal
void preOrderTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

// Iterative Post-order Traversal
void postOrderTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }
    while (top2 != -1) {
        struct Node* node = stack2[top2--];
        printf("%d ", node->data);
    }
}

// Function to print the parent of a given element
void printParent(struct Node* root, int element, struct Node* parent) {
    if (root == NULL) return;
    if (root->data == element) {
        if (parent != NULL) {
            printf("Parent of %d is %d\n", element, parent->data);
        } else {
            printf("%d is the root node and has no parent\n", element);
        }
        return;
    }
    printParent(root->left, element, root);
    printParent(root->right, element, root);
}

// Function to print the depth of the tree
int depth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Function to print the ancestors of a given element
int printAncestors(struct Node* root, int element) {
    if (root == NULL) return 0;
    if (root->data == element) return 1;
    if (printAncestors(root->left, element) || printAncestors(root->right, element)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// Function to count the number of leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Main function to take user input and perform operations
int main() {
    struct Node* root = NULL;
    int n, data, element;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Enter the element to find its parent: ");
    scanf("%d", &element);
    printParent(root, element, NULL);

    printf("Depth of the tree: %d\n", depth(root));

    printf("Enter the element to find its ancestors: ");
    scanf("%d", &element);
    printf("Ancestors of %d: ", element);
    if (!printAncestors(root, element)) {
        printf("No ancestors found (element might not be in the tree)");
    }
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
