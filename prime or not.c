#include<stdio.h>
#include<math.h>
int isPrime(int num, int i) {
    if (i <= 1) {
        return 1;
    }
    if (num % i == 0) {
        return 0;
    }
    return isPrime(num, i - 1);
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 2) {
        printf("%d is not a prime number.\n", num);
    } else {
        if (isPrime(num, (int)sqrt(num))) {
            printf("%d is a prime number.\n", num);
        } else {
            printf("%d is not a prime number.\n", num);
        }
    }
    return 0;
}

