#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 4
void printAssignment(int assignment[N]) {
	int i;
    printf("Assignment: ");
    for ( i = 0; i < N; i++) {
        printf("Agent %d -> Task %d ", i + 1, assignment[i] + 1);
        if (i != N - 1) printf("| ");
    }
    printf("\n");
}
int findMin(int costMatrix[N][N], int row, int col, int assignedRow[], int assignedCol[]) {
    int min = INT_MAX,i,j;
    int minIndexRow, minIndexCol;
    for (i = 0; i < N; i++) {
        if (!assignedRow[i]) {
            for (j = 0; j < N; j++) {
                if (!assignedCol[j] && costMatrix[i][j] < min) {
                    min = costMatrix[i][j];
                    minIndexRow = i;
                    minIndexCol = j;
                }
            }
        }
    }

    assignedRow[minIndexRow] = 1;
    assignedCol[minIndexCol] = 1;

    return min;
}
void branchAndBound(int costMatrix[N][N], int assignedRow[], int assignedCol[], int assignment[N], int cost, int level) {
	int i;
    if (level == N) {
        if (cost < assignment[N]) {
            for (i = 0; i < N; i++) {
                assignment[i] = assignedCol[i];
            }
            assignment[N] = cost;
        }
        return;
    }

    for (i = 0; i < N; i++) {
        if (!assignedRow[i]) {
            assignedRow[i] = 1;
            assignedCol[level] = i;
            branchAndBound(costMatrix, assignedRow, assignedCol, assignment, cost + costMatrix[i][level], level + 1);

            assignedRow[i] = 0;
            assignedCol[level] = -1;
        }
    }
}

int main() {
    int costMatrix[N][N],i,j;
    int assignedRow[N] = {0};
    int assignedCol[N] = {0};
    int assignment[N + 1];
    assignment[N] = INT_MAX;
    printf("Enter the cost matrix (dimensions %dx%d):\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }
    branchAndBound(costMatrix, assignedRow, assignedCol, assignment, 0, 0);
    printf("Optimal Assignment:\n");
    printAssignment(assignment);
    printf("Minimum Cost: %d\n", assignment[N]);
    return 0;
}

