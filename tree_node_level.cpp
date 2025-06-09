#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
vector<int>tree[N];
vector<int> level(N);
void dfs(int u,int par){
   // cout<<"Visiting "<<u<<" From Parent "<<par<<endl;
    for(auto v:tree[u]){
        if(v==par) continue;
        level[v]=level[u]+1;
        dfs(v,u);
        
    }
}
int main()
{
    int v;cin>>v;
    level.resize(v);
    for (int i = 0; i < v-1; i++)
    {
        int n1,n2;cin>>n1>>n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    dfs(1,0);
    for (int i = 1; i <=v; i++)
    {
        cout<<"Level of Node "<<i<<" is: "<<level[i]<<endl;
    } 
    return 0;
}