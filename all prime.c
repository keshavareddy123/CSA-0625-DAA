#include <stdio.h>
#include <stdbool.h>
void generatePrimes(int current, int limit, bool isPrime[]) {
    if (current <= limit) {
        if (isPrime[current]) {
            printf("%d ", current);
        }
        generatePrimes(current + 1, limit, isPrime);
    }
}
void sieveOfEratosthenes(int limit, bool isPrime[]) {
	int i,p;
    for (i = 2; i <= limit; i++) {
        isPrime[i] = true;
    }
    for (p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
}
int main() {
    int limit;
    printf("Enter the limit for prime numbers: ");
    scanf("%d", &limit);
    bool isPrime[limit + 1];
    sieveOfEratosthenes(limit, isPrime);
    printf("Prime numbers up to %d are: ", limit);
    generatePrimes(2, limit, isPrime);
    return 0;
}

