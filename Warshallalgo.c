#include <stdio.h>

int n, a[10][10], p[10][10];

void computePathMatrix() {
    int i, j, k;

    // Initialize path matrix with adjacency matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            p[i][j] = a[i][j];

    // Warshall's algorithm
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (p[i][k] && p[k][j])
                    p[i][j] = 1;
}

int main() {
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    computePathMatrix();

    printf("\nThe Path Matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }

    return 0;
}
