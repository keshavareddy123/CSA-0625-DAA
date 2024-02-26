#include <stdio.h>
void findMinMaxSequence(int arr[], int size) {
	int i;
    if (size <= 0) {
        printf("Invalid size of the list.\n");
        return;
    }
    int minSequenceStart = 0, maxSequenceStart = 0;
    int currentMin = arr[0], currentMax = arr[0];
    int globalMin = arr[0], globalMax = arr[0];
    for ( i = 1; i < size; i++) {
        if (currentMin > 0)
            currentMin = arr[i];
        else
            currentMin += arr[i];
        if (currentMax < 0)
            currentMax = arr[i];
        else
            currentMax += arr[i];
        if (currentMin < globalMin) {
            globalMin = currentMin;
            minSequenceStart = i;
        }
        if (currentMax > globalMax) {
            globalMax = currentMax;
            maxSequenceStart = i;
        }
    }
    printf("Minimum Value Sequence: ");
    for ( i = minSequenceStart; i >= 0; i--) {
        printf("%d ", arr[i]);
        if (arr[i] == globalMin)
            break;
    }
    printf("\nMaximum Value Sequence: ");
    for ( i = maxSequenceStart; i >= 0; i--) {
        printf("%d ", arr[i]);
        if (arr[i] == globalMax)
            break;
    }
    printf("\n");
}
int main() {
    int size, i;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the list:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    findMinMaxSequence(arr, size);
    return 0;
}
