#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,ans,f[1010];
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>f[i];
    }
    sort(f,f+m);
    ans=f[n-1]-f[0];
    for(i=1;i<=m-n;i++){
        if(f[i+n-1]-f[i]<ans) ans=f[i+n-1]-f[i];
    }
    cout<<ans;
    return 0;
}
