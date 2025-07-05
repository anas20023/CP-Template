#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
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
         dfs(v,3-nxt_color);
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
   for (int i = 1; i <=v; ++i)
   {
       if(!vis[i])  dfs(i,1);
   }
    if(!is_ok) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0; 
    }
    for (int i = 1; i <=v ; ++i)
    {
        cout<<color[i]<<" ";
    }
}