#include <stdio.h>
int linearSearch(int arr[], int n, int key) {
	int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[100], n, key, result,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found in the array\n");
    }
    return 0;
}

