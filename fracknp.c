#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

void calculate_ratios(Item items[], int count) {
    for (int i = 0; i < count; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
}

int compare_items(const void *a, const void *b) {
    const Item *item1 = (const Item *)a;
    const Item *item2 = (const Item *)b;
    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

double solve_fractional_knapsack(int capacity, Item items[], int count) {
    calculate_ratios(items, count);
    qsort(items, count, sizeof(Item), compare_items);
    
    double total_value = 0.0;
    int current_weight = 0;
    
    for (int i = 0; i < count; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining = capacity - current_weight;
            total_value += items[i].value * ((double)remaining / items[i].weight);
            break;
        }
    }
    
    return total_value;
}

int main() {
    int capacity, item_count;
    
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    printf("Enter number of items: ");
    scanf("%d", &item_count);
    
    Item *items = malloc(item_count * sizeof(Item));
    
    printf("Enter value and weight for each item:\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    
    clock_t start = clock();
    double max_value = solve_fractional_knapsack(capacity, items, item_count);
    clock_t end = clock();
    
    printf("\nMaximum achievable value: %.2f\n", max_value);
    printf("Execution time: %.6f seconds\n", 
          (double)(end - start) / CLOCKS_PER_SEC);
    
    free(items);
    return 0;
}