#include <bits/stdc++.h>
using namespace std;
#define INF 10000007

int min_dist_vertx(vector<int>&dist,vector<bool>&vis,int v){
    int minval=INT_MAX,minidx=-1;
    for (int i = 1; i <=v; i++)
    {
        if(!vis[i] && dist[i]<minval){
            minval=dist[i];
            minidx=i;
        }
    }
    return minidx;
    
}
void Dijkstra(vector<vector<int>>&graph , int src ,int v){
    vector<int>dist(v+1,INF);
    vector<bool>vis(v+1,false);
    dist[src]=0;
    for (int i = 1; i <=v; i++)
    {
        int u=min_dist_vertx(dist,vis,v);
        vis[u]=true;
        for (int i = 1; i <=v; i++)
        {
            if(!vis[i] && graph[u][i]>0 && graph[u][i]+dist[u]<dist[i]){
                dist[i]=graph[u][i]+dist[u];
            }
        }
        
    }
    for (int i = 1; i <=v; i++)
    {
        if(dist[i]==INF) cout<<i<<" : Not Connected"<<endl;
        else cout<<i<<" : "<<dist[i]<<endl;
    }
    
    
}
int main()
{
    int v,e;cin>>v>>e;
    vector<vector<int>>graph(v+1,vector<int>(v+1,0));
    for (int i = 0; i < e; i++)
    {
        int v1,v2,w;cin>>v1>>v2>>w;
        graph[v1][v2]=w;
        //graph[v2][v1]=w;
    }
   // cout<<"x";
    Dijkstra(graph,1,v);
    return 0;
}