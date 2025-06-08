#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<vector<pair<int, int>>> g(N); 
int cost = INT_MIN;
void dfs(int src, int parent, int current_cost, int v) {
    ///// check for leaf node
    bool is_leaf = true;
    for (auto [neighbor, weight] : g[src]) {
        if (neighbor != parent) {
            is_leaf = false;
            break;
        }
    }
    
    if (is_leaf) {
        cost = max(cost, current_cost);
        return;
    }
    /// leaf hoile cost backtrack korbe
    
    // leaf na hoile baki gular jonne dfs call
    for (auto [neighbor, weight] : g[src]) {
        if (neighbor != parent) {
            dfs(neighbor, src, current_cost + weight, v);
        }
    }
}
void solve(){
    int v;
   cin>>v;
   for (int i = 0; i < v - 1; i++) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        g[v1].push_back({v2, c});
        g[v2].push_back({v1, c});
    }

    
    dfs(0, -1, 0, v);
   cout<<cost<<endl;
   
   
    
}
int main()
{
    int tc = 1;
    //cin >> tc;
    while (tc--)
    {
       solve();
    }

    return 0;
}   