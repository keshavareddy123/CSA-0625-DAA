#include <stdio.h>

#define MAX 100

void subsetSum(int set[], int n, int target, int currentSum, int index, int subset[], int subsetSize) {
	int i;
    if (currentSum == target) {
        printf("Subset found: ");
        for (i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    for (i = index; i < n; i++) {
        if (currentSum + set[i] <= target) {
            subset[subsetSize] = set[i];
            subsetSum(set, n, target, currentSum + set[i], i + 1, subset, subsetSize + 1);
        }
    }
}

void generateSubsets(int set[], int n, int target) {
    int subset[MAX];
    subsetSum(set, n, target, 0, 0, subset, 0);
}

int main() {
    int set[MAX], n, target,i;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    generateSubsets(set, n, target);
    return 0;
}

