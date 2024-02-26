#include <stdio.h>
#include <limits.h>
#define V 4 
int tsp(int graph[V][V], int mask, int pos, int dp[V][1 << V]) {
	int nextCity;
    if (mask == (1 << V) - 1) {
        return graph[pos][0];
    }
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int minCost = INT_MAX;
    for (nextCity = 0; nextCity < V; nextCity++) {
        if (!(mask & (1 << nextCity))) {
            int newCost = graph[pos][nextCity] + tsp(graph, mask | (1 << nextCity), nextCity, dp);

            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }
    return dp[pos][mask] = minCost;
}
int travelingSalesman(int graph[V][V]) {
    int dp[V][1 << V],i,j;
    for ( i = 0; i < V; i++) {
        for (j = 0; j < (1 << V); j++) {
            dp[i][j] = -1;
        }
    }
    return tsp(graph, 1, 0, dp); 
}
int main() {
    int graph[V][V],i,j;
    printf("Enter the weighted adjacency matrix for the graph (4x4 matrix in this example):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int minCost = travelingSalesman(graph);
    printf("Minimum cost of the Traveling Salesman Problem is: %d\n", minCost);
    return 0;
}

