#include <bits/stdc++.h>
using namespace std;
#define INF 10000007
void BellmanFord(vector<vector<int>>& graph, int src, int v) {
    vector<int> dist(v + 1, INF);
    dist[src] = 0;

    // Relax all edges v-1 times
    for (int k = 0; k < v - 1; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (graph[i][j] != INF && dist[i] != INF && dist[i] + graph[i][j] < dist[j]) {
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
    }

    // Negative weight cycle detection
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (graph[i][j] != INF && dist[i] != INF && dist[i] + graph[i][j] < dist[j]) {
                cout << "Negative weight cycle detected!" << endl;
                return;
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 1; i <= v; ++i) {
        if (dist[i] == INF)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}
int main()
{
    int v,e;cin>>v>>e;
    vector<vector<int>>graph(v+1,vector<int>(v+1,INF));
    for (int i = 0; i < e; i++)
    {
        int v1,v2,w;cin>>v1>>v2>>w;
        graph[v1][v2]=w;
       // graph[v2][v1]=w;
    }
    BellmanFord(graph,1,v);
    return 0;
}