#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
vector<int>tree[N];
vector<int> subtreesize(N);
void dfs(int u,int par){
   // cout<<"Visiting "<<u<<" From Parent "<<par<<endl;
    subtreesize[u]=1;
    for(auto v:tree[u]){
        if(v==par) continue;
        dfs(v,u);
        subtreesize[u]+=subtreesize[v];
    }
}
int main()
{
    int v;cin>>v;
    subtreesize.resize(v);
    for (int i = 0; i < v-1; i++)
    {
        int n1,n2;cin>>n1>>n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    dfs(1,-1);
    for (int i = 1; i <=v; i++)
    {
        cout<<"Node "<<i<<" Subtree Size : "<<subtreesize[i]<<endl;
    }
    
    
    return 0;
}