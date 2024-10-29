#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) { queue[++rear] = x; }
int dequeue() { return queue[++front]; }
int isEmpty() { return front == rear; }

void BFS(int adj_matrix[MAX][MAX], int n, int start_vertex) {
    int visited[MAX] = {0}, i;
    visited[start_vertex] = 1;
    enqueue(start_vertex);
    while (!isEmpty()) {
        int current_vertex = dequeue();
        printf("%d ", current_vertex);
        for (i = 0; i < n; i++)
            if (adj_matrix[current_vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
    }
}

int main() {
    int n, i, j, start_vertex;
    scanf("%d", &n);
    int adj_matrix[MAX][MAX];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj_matrix[i][j] = 0;
    while (1) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) break;
        adj_matrix[src][dest] = 1;
        // For undirected graphs, uncomment:
        // adj_matrix[dest][src] = 1;
    }
    scanf("%d", &start_vertex);
    BFS(adj_matrix, n, start_vertex);
    return 0;
}
