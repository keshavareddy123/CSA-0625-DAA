#include <stdio.h>
#include <stdlib.h>
int optimalBST(int keys[], float probs[], int n) {
    float cost[n][n];
	int i,j,r,len;
    for ( i = 0; i < n; i++) {
        cost[i][i] = probs[i];
    }
    for ( len = 2; len <= n; len++) {
        for (i = 0; i <= n - len + 1; i++) {
            j = i + len - 1;
            cost[i][j] = __FLT_MAX__;
            for (r = i; r <= j; r++) {
                float temp = ((r > i) ? cost[i][r - 1] : 0) +
                             ((r < j) ? cost[r + 1][j] : 0) +
                             probs[r];

                if (temp < cost[i][j]) {
                    cost[i][j] = temp;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n,i;

    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n];
    float probs[n];

    printf("Enter the keys and their probabilities:\n");
    for (i = 0; i < n; i++) {
        printf("Key %d: ", i + 1);
        scanf("%d", &keys[i]);
        printf("Probability for Key %d: ", i + 1);
        scanf("%f", &probs[i]);
    }
    int result = optimalBST(keys, probs, n);
    printf("Cost of optimal binary search tree: %d\n", result);
    return 0;
}

