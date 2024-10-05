#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100

int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V], int vertices) {
    int TotalCost = 0;
    printf("\nMST Tree adjacent:\n");
    for (int i = 0; i < vertices; i++) {
        TotalCost += graph[i][parent[i]];
        for (int j = 0; j < vertices; j++) {
            if (parent[i] == j || parent[j] == i) {
                printf("%d  ", graph[i][j]);
            } else {
                printf("0  ");
            }
        }
        printf("\n");
    }
    printf("\nTotal Weight of spanning tree : %d\n", TotalCost);
}

void primMST(int graph[V][V], int vertices, int startVertex) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[startVertex] = 0;

    parent[startVertex] = -1;
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);

        mstSet[u] = 1;
        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph, vertices);
}

int main() {
    FILE *f;
    int v, s, i, j;
    f = fopen("inUnAdjMat.dat", "r");

    if (f == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    printf("Enter the number of vertices : ");
    scanf("%d", &v);

    printf("Enter the starting vertex : ");
    scanf("%d", &s);

    int graph[V][V];

    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            fscanf(f, "%d", &graph[i][j]);

    fclose(f);

    primMST(graph, v, s);
    return 0;
}
