#include <stdio.h>
int reverseNumber(int num, int reversedNum) {
    if (num == 0) {
        return reversedNum;
    } else {
        int lastDigit = num % 10;
        reversedNum = (reversedNum * 10) + lastDigit;
        return reverseNumber(num / 10, reversedNum);
    }
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Original number: %d\n", num);
    printf("Reversed number: %d\n", reverseNumber(num, 0));

    return 0;
}

