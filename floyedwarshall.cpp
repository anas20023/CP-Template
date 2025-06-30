#include <bits/stdc++.h>
using namespace std;

#define INF 100000007
void FloydWarshall(vector<vector<int>> &graph,int v){
    for (int k = 1; k <=v; k++)
    {
        for (int i = 1; i <=v; i++)
        {
            for (int j = 1; j <=v; j++)
            {
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
            
        }
        
    }
    for (int i = 1; i <=v; i++)
    {
        for (int j = 1; j <=v; j++)
        {
            if(i==j) cout<<0<<" ";
            else if(graph[i][j]==INF) cout<<"INF"<<" ";
            else cout<<graph[i][j]<<" ";
        }
        cout<<endl;
        
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
    }
    FloydWarshall(graph,v);
    
    return 0;
}