#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
vector<bool>vis(N);
vector<int>color(N);
bool is_ok=true;
void dfs(int src, int nxt_color){

    if(vis[src]){
        if(color[src]==nxt_color) {return;}
        else{ is_ok=false;return;}
    }

    vis[src]=true;
    color[src]=nxt_color;
    for(auto v:graph[src]){
        if(color[src]==1) dfs(v,2);
        else dfs(v,1);
    }
}
int main()
{
    int v,e;cin>>v>>e;
    for (int i = 0; i < e; ++i)
    {
        int v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1,1);
    for (int i = 1; i <=v ; ++i)
    {
        cout<<color[i]<<" ";
    }
}