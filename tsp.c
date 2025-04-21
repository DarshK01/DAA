#include <stdio.h>
#include <limits.h>
#include <time.h>

// Function to calculate the minimum TSP cost using memoization
int totalCost(int mask, int pos, int n, int cost[n][n], int dp[1 << n][n]) {
    // If all cities have been visited, return cost to starting city
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    // If already computed, return the stored value
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        // If city i hasn't been visited yet
        if ((mask & (1 << i)) == 0) {
            int newCost = cost[pos][i] + totalCost(mask | (1 << i), i, n, cost, dp);
            if (newCost < ans) {
                ans = newCost;
            }
        }
    }

    return dp[mask][pos] = ans;
}

int tsp(int cost[][4], int n) {
    // DP table initialization
    int dp[1 << n][n];
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    return totalCost(1, 0, n, cost, dp); // Start with mask 1 (0th city visited)
}

int main() {
    int n = 4; // Number of cities
    int cost[4][4] = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    clock_t t;
    t = clock();
    int res = tsp(cost, n);
    t = clock() - t;

    printf("Minimum TSP cost is: %d\n", res);
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}