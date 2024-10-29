#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = newNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    // For undirected graph, uncomment:
    // newNode = newNode(src);
    // newNode->next = graph->adjLists[dest];
    // graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Adjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    scanf("%d", &n);
    struct Graph* graph = createGraph(n);
    while (1) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) break;
        addEdge(graph, src, dest);
    }
    printGraph(graph);
    return 0;
}
