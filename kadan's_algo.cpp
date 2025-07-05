#include <bits/stdc++.h>
using namespace std;
int max_Sum(vector<int>&v,int n){
    int mxsum=v[0],curr_sum=v[0];
    for (int i = 1; i < n; i++)
    {
        curr_sum=max(v[i],curr_sum+v[i]);
        mxsum=max(mxsum,curr_sum);

    }
    return mxsum;
    
}

void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans=max_Sum(v,n);
    cout<<ans<<endl;
}
int main(){
    // int t;cin>>t;
    // t=1;
    // while(t--){
    // }
    solve();
}