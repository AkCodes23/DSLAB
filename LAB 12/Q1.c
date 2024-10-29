#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adj_matrix[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    // Input edges (directed or undirected)
    printf("Enter the edges (format: source destination):\n");
    while (1) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) {
            break;
        }
        adj_matrix[src][dest] = 1;
        adj_matrix[dest][src] = 1;
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
