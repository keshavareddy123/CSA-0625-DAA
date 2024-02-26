#include <stdio.h>
struct Item {
    int value;
    int weight;
};
void knapsackFractional(struct Item items[], int n, int capacity) {
    double ratios[n];
    int i,j;
    for (i = 0; i < n; i++) {
        ratios[i] = (double) items[i].value / items[i].weight;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratios[j] < ratios[j + 1]) {
                double tempRatio = ratios[j];
                ratios[j] = ratios[j + 1];
                ratios[j + 1] = tempRatio;

                struct Item tempItem = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tempItem;
            }
        }
    }
    int totalWeight = 0;
    double finalResult = 0.0;
    for ( i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            finalResult += items[i].value;
        } else {
            double fraction = (double)(capacity - totalWeight) / items[i].weight;
            finalResult += fraction * items[i].value;
            break;
        }
    }
    printf("Maximum value in the knapsack: %.2lf\n", finalResult);
}
int main() {
    int n, capacity,i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for ( i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    knapsackFractional(items, n, capacity);
    return 0;
}

