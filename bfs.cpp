#include <bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>graph[N];
vector<bool> vis(N);

void BFS(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:graph[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
   
}
int main() {
 //cout<<"Working"<<endl;
 int n,m;cin>>n>>m;
 for(int i=0;i<m;i++){
     int v1,v2;cin>>v1>>v2;
     graph[v1].push_back(v2);
     graph[v2].push_back(v1);
 }
 BFS(1);
}