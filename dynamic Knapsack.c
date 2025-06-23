#include <stdio.h>

int getMax(int x, int y) {
    return (x > y) ? x : y;
}

void knapSack(int W, int n, int val[], int wt[]) {
    int i, weight;
    int V[n + 1][W + 1];

    // Initialize value table with 0
    for (i = 0; i <= n; i++) {
        for (weight = 0; weight <= W; weight++) {
            if (i == 0 || weight == 0) {
                V[i][weight] = 0;
            } else if (wt[i] <= weight) {
                V[i][weight] = getMax(val[i] + V[i - 1][weight - wt[i]], V[i - 1][weight]);
            } else {
                V[i][weight] = V[i - 1][weight];
            }
        }
    }

    // Print max value
    printf("Max Value: %d\n", V[n][W]);

    // Optional: Print selected items
    printf("Items included:\n");
    weight = W;
    for (i = n; i > 0 && weight > 0; i--) {
        if (V[i][weight] != V[i - 1][weight]) {
            printf("Item %d (Value: %d, Weight: %d)\n", i, val[i], wt[i]);
            weight -= wt[i];
        }
    }
}

int main(void) {
    int val[] = {-1, 100, 20, 60, 40}; // index starts at 1
    int wt[]  = {-1, 3,   2,  4,  1};
    int n = 4;
    int W = 5;

    knapSack(W, n, val, wt);
    return 0;
}
