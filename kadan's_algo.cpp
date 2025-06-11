#include <bits/stdc++.h>
using namespace std;
int Mx_sub_Sum(vector<int>&v, int n){
    int res=v[0];
    int maxtillnow=v[0];
    for (int i = 1; i < n; i++)
    {
        maxtillnow=max(maxtillnow+v[i],v[i]);
        res=max(maxtillnow,res);
    }
    return res;
    
}

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans=Mx_sub_Sum(v,n);
    cout<<ans<<endl;
    return 0;
}