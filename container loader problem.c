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
	int i,w;
    int dp[MAX_ITEMS + 1][capacity + 1];
    for ( i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}
int main() {
    struct Item items[MAX_ITEMS];
    int n,i, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight and value for each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    printf("Enter the maximum capacity of the container: ");
    scanf("%d", &capacity);
    int optimalCost = knapsack(items, n, capacity);
    printf("Optimal Cost for Container Loading: %d\n", optimalCost);
    return 0;
}

