#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int dp[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}
int main() {
    int n,i;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter the values of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }

    int W;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    printf("Maximum value in Knapsack = %d\n", knapSack(W, wt, val, n));

    return 0;
}

