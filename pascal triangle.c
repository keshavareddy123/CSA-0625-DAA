#include <stdio.h>
long binomialCoeff(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    else
        return binomialCoeff(n - 1, r - 1) + binomialCoeff(n - 1, r);
}
void generatePascalsTriangle(int rows) {
	int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("%ld ", binomialCoeff(i, j));
        }
        printf("\n");
    }
}
int main() {
    int rows;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);
    generatePascalsTriangle(rows);
    return 0;
}

