#include <bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>graph[N];
vector<bool> vis(N);

void DFS(int u){
    vis[u]=true;
   // cout<<"Node "<<u<<endl;
    //cout<<u<<" ";
    for(int v:graph[u]){
        if(!vis[v]){
           // cout<<"Parent "<<u<<" Child "<<v<<endl;
            DFS(v);
            //cout<<"BackTracking from "<<v<<endl;
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
 DFS(1);
}