/*
AIM: Write program to implement KrusKal's Aglorithm in order to find the 
     Minimum Spanning Tree of connected ,weighted and undirected graph.
*/
#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent, rank;
};
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
int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V];  
    int e = 0;              
    int i = 0;              

    qsort(edges, E, sizeof(edges[0]), compare);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    int totalWeight = 0;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Minimum Cost of Spanning Tree: %d\n", totalWeight);
}
int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("Enter edges (u v w)u=starting vertex ,v=ending vertex ,w=weight:\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[i].src = u - 1;
        edges[i].dest = v - 1;
        edges[i].weight = w;
    }
    KruskalMST(edges, V, E);
    return 0;
}
