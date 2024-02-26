#include <stdio.h>
unsigned long long binomialCoefficient(int n, int k) {
	int i,j;
    unsigned long long dp[n + 1][k + 1];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][k];
}
int main() {
    int n, k;
    printf("Enter values for n and k (separated by space): ");
    scanf("%d %d", &n, &k);
    printf("Binomial Coefficient C(%d, %d) is %llu\n", n, k, binomialCoefficient(n, k));
    return 0;
}

