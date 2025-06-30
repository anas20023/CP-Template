// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// Number of vertices in given graph
#define MAX_V 100 // Adjust the maximum number of vertices as needed

/* Returns true if there is a path from source 's' to sink
    't' in residual graph. Also fills parent[] to store the
    path */
bool bfs(int rGraph[MAX_V][MAX_V], int s, int t, int parent[], int V)
{
        // Create a visited array and mark all vertices as not
        // visited
        bool visited[MAX_V];
        memset(visited, 0, sizeof(visited));

        // Create a queue, enqueue source vertex and mark source
        // vertex as visited
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        // Standard BFS Loop
        while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 1; v <= V; v++) { // Adjust loop for 1-based indexing
                        if (visited[v] == false && rGraph[u][v] > 0) {
                                // If we find a connection to the sink node,
                                // then there is no point in BFS anymore We
                                // just have to set its parent and can return
                                // true
                                if (v == t) {
                                        parent[v] = u;
                                        return true;
                                }
                                q.push(v);
                                parent[v] = u;
                                visited[v] = true;
                        }
                }
        }

        // We didn't reach sink in BFS starting from source, so
        // return false
        return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[MAX_V][MAX_V], int s, int t, int V)
{
        int u, v;

        // Create a residual graph and fill the residual graph
        // with given capacities in the original graph as
        // residual capacities in residual graph
        int rGraph[MAX_V][MAX_V]; // Adjust size for 1-based indexing
        for (u = 1; u <= V; u++) // Adjust loop for 1-based indexing
                for (v = 1; v <= V; v++) // Adjust loop for 1-based indexing
                        rGraph[u][v] = graph[u][v];

        int parent[MAX_V]; // This array is filled by BFS and to
                                             // store path

        int max_flow = 0; // There is no flow initially

        // Augment the flow while there is path from source to
        // sink
        while (bfs(rGraph, s, t, parent, V)) {
                // Find minimum residual capacity of the edges along
                // the path filled by BFS. Or we can say find the
                // maximum flow through the path found.
                int path_flow = INT_MAX;
                for (v = t; v != s; v = parent[v]) {
                        u = parent[v];
                        path_flow = min(path_flow, rGraph[u][v]);
                }

                // update residual capacities of the edges and
                // reverse edges along the path
                for (v = t; v != s; v = parent[v]) {
                        u = parent[v];
                        rGraph[u][v] -= path_flow;
                        rGraph[v][u] += path_flow;
                }

                // Add path flow to overall flow
                max_flow += path_flow;
        }

        // Return the overall flow
        return max_flow;
}

// Driver program to test above functions
int main()
{
        // Take input for the graph
        int graph[MAX_V][MAX_V] = {0}; // Initialize the adjacency matrix with zeros
        int V, E;
        cin >> V >> E; // Input number of vertices and edges

        for (int i = 0; i < E; i++) {
                int v1, v2, w;
                cin >> v1 >> v2 >> w; // Input edge and its weight
                graph[v1][v2] = w;    // Set the weight in the adjacency matrix
        }

        cout << "The maximum possible flow is "
                 << fordFulkerson(graph, 1, V, V); // Adjust for 1-based indexing

        return 0;
}
