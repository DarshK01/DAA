#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int min(int num1, int num2) {
    return (num1 < num2) ? num1 : num2;
}

void printJobSeq(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), compare);
    
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    printf("Job sequence for max profit: ");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%d ", arr[result[i]].id);
        }
    }
    printf("\n");
}

int main() {
    clock_t t = clock();
    int j;
    
    printf("Enter number of jobs: ");
    scanf("%d", &j);
    
    Job jobs[j];
    printf("Enter id, deadline, and profit of jobs:\n");
    for (int i = 0; i < j; i++) {
        printf("Job %d: ", i+1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    
    printf("Following is sequence for max profit:\n");
    printJobSeq(jobs, j);
    
    double time_taken = ((double)(clock() - t)) / CLOCKS_PER_SEC;
    printf("The job sequencing with deadline took %f seconds\n", time_taken);
    
    return 0;
}