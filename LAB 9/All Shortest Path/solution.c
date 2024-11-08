#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Function to read the graph from the file and initialize the adjacency matrix
void read_graph_from_file(char *filename, int graph[MAX_VERTICES][MAX_VERTICES], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the adjacency matrix from the file
    int i = 0, j = 0;
    while (fscanf(file, "%d", &graph[i][j]) != EOF) {
        j++;
        if (fgetc(file) == '\n') {  // Check for line break
            i++;
            j = 0;
        }
    }
    *n = i;  // Number of vertices is the number of lines
    fclose(file);
}

// Floyd-Warshall algorithm to compute shortest paths and intermediate vertices
void floyd_warshall(int graph[MAX_VERTICES][MAX_VERTICES], int dist[MAX_VERTICES][MAX_VERTICES], int next[MAX_VERTICES][MAX_VERTICES], int n) {
    // Initialize distance and next matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
                next[i][j] = j;
            } else if (i == j) {
                dist[i][j] = 0;
                next[i][j] = -1;
            } else {
                dist[i][j] = INF;
                next[i][j] = -1;
            }
        }
    }

    // Floyd-Warshall's algorithm to update distances and intermediate vertices
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

// Function to reconstruct the path from source to destination using the `next` matrix
void reconstruct_path(int next[MAX_VERTICES][MAX_VERTICES], int start, int end) {
    if (next[start][end] == -1) {
        printf("No path exists from vertex %d to vertex %d\n", start + 1, end + 1);
        return;
    }
    
    printf("Path from vertex %d to vertex %d: ", start + 1, end + 1);
    
    int current = start;
    while (current != end) {
        printf("%d -> ", current + 1);
        current = next[current][end];
    }
    printf("%d\n", end + 1);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES], dist[MAX_VERTICES][MAX_VERTICES], next[MAX_VERTICES][MAX_VERTICES];
    int n;

    // Read graph from the file "inDiAdjMat2.dat"
    read_graph_from_file("inDiAdjMat2.dat", graph, &n);

    // Apply Floyd-Warshall algorithm
    floyd_warshall(graph, dist, next, n);

    // Print the shortest path weight matrix
    printf("Shortest Path Matrix (Distances):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    // Ask the user for source and destination
    int source, destination;
    printf("Enter the source vertex (1 to %d): ", n);
    scanf("%d", &source);
    printf("Enter the destination vertex (1 to %d): ", n);
    scanf("%d", &destination);

    // Convert user input to zero-indexed
    source -= 1;
    destination -= 1;

    // Display the shortest path from source to destination
    reconstruct_path(next, source, destination);

    return 0;
}
