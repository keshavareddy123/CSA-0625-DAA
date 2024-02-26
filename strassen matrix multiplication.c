#include <stdio.h>
void strassenMultiply(int A[][2], int B[][2], int C[][2]) {
	int P1,P2,P3,P4,P5,P6,P7;
	P1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    P2 = (A[1][0] + A[1][1]) * B[0][0];
    P3 = A[0][0] * (B[0][1] - B[1][1]);
    P4 = A[1][1] * (B[1][0] - B[0][0]);
    P5 = (A[0][0] + A[0][1]) * B[1][1];
    P6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    P7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    C[0][0] = P1 + P4 - P5 + P7;
    C[0][1] = P3 + P5;
    C[1][0] = P2 + P4;
    C[1][1] = P1 - P2 + P3 + P6;
}
void displayMatrix(int matrix[][2]) {
	int i,j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int A[2][2], B[2][2], C[2][2],i,j;
    printf("Enter values for Matrix A (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter values for Matrix B (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    strassenMultiply(A, B, C);
    printf("\nMatrix A:\n");
    displayMatrix(A);
    printf("\nMatrix B:\n");
    displayMatrix(B);
    printf("\nResultant Matrix C (Strassen's Multiplication):\n");
    displayMatrix(C);
    return 0;
}

