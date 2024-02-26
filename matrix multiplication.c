#include <stdio.h>
void multiplyMatrices(int firstMatrix[][100], int secondMatrix[][100], int result[][100], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    int i,j,k;
    for ( i = 0; i < rowFirst; ++i) {
        for ( j = 0; j < columnSecond; ++j) {
            result[i][j] = 0;
        }
    }
    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < columnSecond; ++j) {
            for (k = 0; k < columnFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}
void displayMatrix(int matrix[][100], int row, int column) {
	int i,j;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            printf("%d  ", matrix[i][j]);
            if (j == column - 1) {
                printf("\n");
            }
        }
    }
}
int main() {
    int firstMatrix[100][100], secondMatrix[100][100], result[100][100], rowFirst, columnFirst, rowSecond, columnSecond,i,j;
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &columnFirst);
    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < columnFirst; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &firstMatrix[i][j]);
        }
    }
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &columnSecond);
    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < rowSecond; ++i) {
        for (j = 0; j < columnSecond; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &secondMatrix[i][j]);
        }
    }
    if (columnFirst != rowSecond) {
        printf("Error! Matrix multiplication not possible.\n");
        return 0;
    }
    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);
    printf("\nResultant matrix:\n");
    displayMatrix(result, rowFirst, columnSecond);
    int scalarMultiplications = rowFirst * columnFirst * columnSecond;
    int scalarAdditions = rowFirst * columnFirst * (columnSecond - 1);
    int totalOperations = scalarMultiplications + scalarAdditions;
    printf("\nEstimated Time Complexity (in terms of scalar operations): %d\n", totalOperations);
    return 0;
}

