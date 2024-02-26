#include <stdio.h>
void printReverse(char str[], int index) {
    if (str[index] == '\0') {
        return;
    }
    printReverse(str, index + 1);
    printf("%c", str[index]);
}
int main() {
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);
    printf("Reverse of the string: ");
    printReverse(inputString, 0);
    return 0;
}
