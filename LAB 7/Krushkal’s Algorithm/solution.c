#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX_NODES];

int find(int x) {
    if (parent[x] == -1)
        return x;
    return find(parent[x]);
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootX] = rootY;
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

void kruskalAlgo(Edge edges[], int n, int m) {
    int selectedEdges = 0;
    int totalWeight = 0;

    qsort(edges, m, sizeof(Edge), compareEdges);

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    printf("\nEdge Cost\n");

    for (int i = 0; i < m && selectedEdges < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            printf("%d--%d  %d\n", u, v, w);
            totalWeight += w;
            unionSets(u, v);
            selectedEdges++;
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

int main() {
    int v, e;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);

    printf("Enter the number of edges : ");
    scanf("%d", &e);

    Edge edges[MAX_EDGES];

    printf("Enter\nV1 V2 Distance\n");

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskalAlgo(edges, v, e);

    return 0;
}
