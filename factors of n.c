#include <stdio.h>
void printFactors(int n, int i) {
    if (i > n)
        return;

    if (n % i == 0) {
        printf("%d ", i);
    }

    printFactors(n, i + 1);
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Factors of %d: ", n);
    printFactors(n, 1);

    return 0;
}

