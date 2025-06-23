#include <stdio.h>

// Greedy knapsack function
void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], totalProfit = 0;
    int i;
    float remaining = capacity;

    // Initialize all fractions to 0
    for (i = 0; i < n; i++)
        x[i] = 0.0;

    // Greedy selection
    for (i = 0; i < n; i++) {
        if (weight[i] <= remaining) {
            x[i] = 1.0;
            totalProfit += profit[i];
            remaining -= weight[i];
        } else {
            x[i] = remaining / weight[i];
            totalProfit += x[i] * profit[i];
            break;  // No more capacity
        }
    }

    // Output
    printf("\nResult vector (fractions of items included):\n");
    for (i = 0; i < n; i++)
        printf("%.2f\t", x[i]);

    printf("\nMaximum profit: %.2f\n", totalProfit);
}

int main() {
    float weight[20], profit[20], ratio[20], capacity, temp;
    int n, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit for each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Sort items by ratio (profit/weight) in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                // Swap corresponding weights
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
                // Swap corresponding profits
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // Call the knapsack function
    knapsack(n, weight, profit, capacity);

    return 0;
}
