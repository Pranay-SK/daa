#include <stdio.h>

int main() {
    int cost[10][10], distance[10], path[10][10];
    int n, v, p, row, column, min, index = 1, i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter destination node to visit: ");
    scanf("%d", &v);

    printf("Enter number of paths for the selected node: ");
    scanf("%d", &p);

    printf("Enter path matrix (each path as sequence of nodes, end with 0):\n");
    for (i = 1; i <= p; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &path[i][j]);
        }
    }

    // Calculate cost of each path
    for (i = 1; i <= p; i++) {
        distance[i] = 0;
        row = path[i][1];
        for (j = 1; path[i][j + 1] != 0 && j < n; j++) {
            column = path[i][j + 1];
            distance[i] += cost[row][column];
            row = column;
        }
    }

    // Find minimum distance
    min = distance[1];
    index = 1;
    for (i = 2; i <= p; i++) {
        if (distance[i] < min) {
            min = distance[i];
            index = i;
        }
    }

    // Print result
    printf("\nMinimum distance is %d\n", min);
    printf("Path with minimum distance:\n");
    for (i = 1; i <= n && path[index][i] != 0; i++) {
        printf("%s%d", (i == 1) ? "" : " -> ", path[index][i]);
    }
    printf("\n");

    return 0;
}
