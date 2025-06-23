#include <stdio.h>

int main() {
    int cost[10][10], visited[10] = {0}, i, j, n;
    int no_e = 1, min, a = -1, b = -1, min_cost = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost in form of adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 1000; // Treat 0 as no connection
        }
    }

    visited[1] = 1; // Start from node 1

    while (no_e < n) {
        min = 1000;
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (visited[b] == 0) {
            printf("\nEdge %d: %d -> %d cost = %d", no_e, a, b, min);
            visited[b] = 1;
            min_cost += min;
            no_e++;
        }

        // Remove the selected edge from consideration
        cost[a][b] = cost[b][a] = 1000;
    }

    printf("\nMinimum cost of spanning tree: %d\n", min_cost);
    return 0;
}
