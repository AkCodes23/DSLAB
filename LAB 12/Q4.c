#include <stdio.h>

void DFS(int adj_matrix[MAX][MAX], int n, int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj_matrix[v][i] == 1 && !visited[i])
            DFS(adj_matrix, n, visited, i);
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
    int visited[MAX] = {0};
    DFS(adj_matrix, n, visited, start_vertex);
    return 0;
}
