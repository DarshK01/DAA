#include <stdio.h>
#include <limits.h>
#include <time.h>

#define N 12 // Number of nodes
#define INF INT_MAX

// Graph adjacency matrix (INF represents no direct path)
int graph[N][N] = {
    {0, 9, 7, 3, 2, INF, INF, INF, INF, INF, INF, INF},
    {INF, 0, INF, INF, INF, 4, 2, 1, INF, INF, INF, INF},
    {INF, INF, 0, INF, INF, 2, 7, INF, INF, INF, INF, INF},
    {INF, INF, INF, 0, INF, INF, INF, 11, INF, INF, INF, INF},
    {INF, INF, INF, INF, 0, INF, 11, 8, INF, INF, INF, INF},
    {INF, INF, INF, INF, INF, 0, INF, INF, 6, 5, INF, INF},
    {INF, INF, INF, INF, INF, INF, 0, INF, 4, 3, INF, INF},
    {INF, INF, INF, INF, INF, INF, INF, 0, INF, 5, 6, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, 4},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, 2},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 5},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}
};

void shortestPath(int stages) {
    int cost[N], path[N];
    int i, j;

    cost[N-1] = 0; // Cost at destination node is 0

    // Backward computation of minimum cost
    for (i = N-2; i >= 0; i--) {
        cost[i] = INF;
        for (j = i+1; j < N; j++) {
            if (graph[i][j] != INF && cost[j] + graph[i][j] < cost[i]) {
                cost[i] = cost[j] + graph[i][j];
                path[i] = j;
            }
        }
    }

    // Print shortest path (converting to 1-based indexing for output)
    printf("Shortest Path: 1");
    i = 0;
    while (i != N-1) {
        printf(" -> %d", path[i]+1);
        i = path[i];
    }
    printf("\nMinimum Cost: %d\n", cost[0]);
}

int main() {
    int stages = 5; // Number of stages
    
    clock_t t;
    t = clock();
    shortestPath(stages);
    t = clock() - t;
    
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", time_taken);
    
    return 0;
}