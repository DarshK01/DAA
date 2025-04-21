#include <stdio.h>
#include <time.h>

void displaySubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subsetSum(int set[], int subset[], int n, int subsetSize, int total, int nodeCount, int sum) {
    if (total == sum) {
        displaySubset(subset, subsetSize); // Print the subset
        // For other subsets
        subsetSum(set, subset, n, subsetSize - 1, total - set[nodeCount - 1], nodeCount - 1, sum);
        return;
    } else {
        for (int i = nodeCount; i < n; i++) {
            subset[subsetSize] = set[i];
            // Do for next node in depth
            subsetSum(set, subset, n, subsetSize + 1, total + set[i], i + 1, sum);
        }
    }
}

void findSubset(int set[], int size, int sum) {
    int subset[size]; // Create subset array to pass parameter of subsetSum
    subsetSum(set, subset, size, 0, 0, 0, sum);
}

int main() {
    clock_t t; 
    int size, sum;
    
    printf("Enter the number count: ");
    scanf("%d", &size);
    
    int weight[size];
    printf("Enter the numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &weight[i]);
    }
    
    printf("Enter the sum: ");
    scanf("%d", &sum);
    
    t = clock(); 
    findSubset(weight, size, sum); 
    t = clock() - t;
    
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("The sum of subsets problem took %f seconds to execute\n", time_taken);
    
    return 0;
}