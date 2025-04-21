#include <stdio.h>
#include <time.h>

#define max(a, b) ((a > b) ? a : b)

// Function to calculate the maximum profit
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];
    
    // Initializing the profit and weight matrix
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n, W;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int val[n], wt[n];
    printf("Enter value and weight of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }
    
    printf("Enter size of knapsack: ");
    scanf("%d", &W);
    
    clock_t t;
    t = clock();
    printf("The maximum profit obtained is: %d\n", knapSack(W, wt, val, n));
    t = clock() - t;
    
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("The Knapsack problem took %f seconds to execute\n", time_taken);
    
    return 0;
}