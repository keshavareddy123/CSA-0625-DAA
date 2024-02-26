#include <stdio.h>
int binarySearch(int arr[], int target, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main() {
    int size, target,i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the sorted elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &target);
    int result = binarySearch(array, target, 0, size - 1);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found.\n");
    return 0;
}

