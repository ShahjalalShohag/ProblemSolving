#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,i,a[100010],ans;
    cin>>n>>m;
    cin>>a[0];
    ans=a[0]-1;
    for(i=1;i<m;i++){
        cin>>a[i];
        if(a[i]>=a[i-1]) ans+=a[i]-a[i-1];
        else ans+=n-a[i-1]+a[i];
    }
    cout<<ans<<endl;
    return 0;
}
