#include <stdio.h>
#include <stdlib.h>

#define INF 9999
#define MAX 10

int main() {
    int adj[MAX][MAX], dist[MAX][MAX];
    int i, j, k, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    printf("NOTE: Use %d for infinity (no direct path).\n", INF);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    // Initialize distance matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = adj[i][j];

    // Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }

        // Print current state of distance matrix
        printf("\nAfter considering node %d:\n", k + 1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] == INF)
                    printf("INF\t");
                else
                    printf("%d\t", dist[i][j]);
            }
            printf("\n");
        }
    }

    printf("\nFinal All-Pairs Shortest Path Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
