#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Function to print the vertex cover
void printVertexCover(bool vertexCover[V]) {
    printf("Vertex Cover:\n");
    for (int i = 0; i < V; i++) {
        if (vertexCover[i]) {
            printf("Vertex %d\n", i);
        }
    }
}

// Function to find an approximation of the Vertex Cover
void vertexCoverApproximation(int graph[V][V]) {
    bool vertexCover[V] = {false};  // To keep track of vertices included in the cover
    bool visited[V] = {false};      // To keep track of visited edges

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            // If there is an edge and it hasn't been visited yet
            if (graph[u][v] && !visited[u * V + v]) {
                // Add both vertices to the vertex cover
                vertexCover[u] = true;
                vertexCover[v] = true;

                // Mark all edges incident to these vertices as visited
                for (int k = 0; k < V; k++) {
                    if (graph[u][k]) visited[u * V + k] = true;
                    if (graph[v][k]) visited[v * V + k] = true;
                }
            }
        }
    }

    printVertexCover(vertexCover);
}

int main() {
    // Example graph represented by an adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    vertexCoverApproximation(graph);

    return 0;
}

