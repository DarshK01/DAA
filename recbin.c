#include <stdio.h>
#include <time.h>

int binarySearch(int array[], int x, int low, int high) {
    if (high >= low) {
        int mid = (high + low) / 2;

        if (x == array[mid])
            return mid;

        if (x > array[mid])
            return binarySearch(array, x, mid + 1, high);

        return binarySearch(array, x, low, mid - 1);
    }
    return -1;
}

int main(void) {
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(array) / sizeof(array[0]);
    int x = 9;

    clock_t start = clock();

    int result = binarySearch(array, x, 0, n - 1);

    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    if (result == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", result);

    printf("Time taken: %f seconds\n", time_spent);

    return 0;
}