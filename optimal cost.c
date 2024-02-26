#include <stdio.h>
#define MAX_ITEMS 100
struct Item {
    int weight;
    int value;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(struct Item items[], int n, int capacity) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
    if (items[n - 1].weight > capacity) {
        return knapsack(items, n - 1, capacity);
    } else {
        return max(items[n - 1].value + knapsack(items, n - 1, capacity - items[n - 1].weight),
                   knapsack(items, n - 1, capacity));
    }
}
int main() {
    struct Item items[MAX_ITEMS];
    int n, capacity,i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight and value for each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);
    int optimalCost = knapsack(items, n, capacity);
    printf("Optimal Cost: %d\n", optimalCost);
    return 0;
}

