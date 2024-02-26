#include <stdio.h>
#include <stdbool.h>

#define V 5 

int path[V];

void printSolution() {
	int i;
    printf("Hamiltonian Circuit found:\n");
    for ( i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); 
}
bool isSafe(int v, int graph[V][V], int path[], int pos) {
	int i;
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCircuitUtil(int graph[V][V], int path[], int pos) {
	int v;
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for ( v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCircuitUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCircuit(int graph[V][V]) {
	int i;
    for (i = 0; i < V; i++)
        path[i] = -1; 

    path[0] = 0;
    if (!hamiltonianCircuitUtil(graph, path, 1)) {
        printf("Hamiltonian Circuit does not exist.\n");
        return false;
    }
    printSolution();
    return true;
}
int main() {
    int graph[V][V],i,j;

    printf("Enter the adjacency matrix (1 if there is an edge, 0 otherwise):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    hamiltonianCircuit(graph);
    return 0;
}

