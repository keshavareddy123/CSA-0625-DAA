#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent, rank;
};
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void KruskalMST(struct Edge edges[], int V, int E);
int main() {
    int V, E,i;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge *edges = (struct Edge *)malloc(E * sizeof(struct Edge));
    printf("Enter the edges (source destination weight):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    KruskalMST(edges, V, E);
    free(edges);
    return 0;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
void KruskalMST(struct Edge edges[], int V, int E) {
	int v;
    struct Edge *result = (struct Edge *)malloc((V - 1) * sizeof(struct Edge));
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    for (v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int i = 0; 
    int edgeCount = 0;
    while (edgeCount < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result[edgeCount++] = nextEdge;
            Union(subsets, x, y);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < V - 1; i++) {
        printf("%d -- %d : %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    free(result);
    free(subsets);
}
