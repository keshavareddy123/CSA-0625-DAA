#include <stdio.h>
void copyString(char source[], char destination[], int index) {
    if (source[index] == '\0') {
        destination[index] = '\0'; 
        return;
    }
    destination[index] = source[index];
    copyString(source, destination, index + 1);
}
int main() {
    char source[100], destination[100];
    printf("Enter the source string: ");
    scanf("%s", source);
    copyString(source, destination, 0);
    printf("Source String: %s\n", source);
    printf("Copied String: %s\n", destination);
    return 0;
}
