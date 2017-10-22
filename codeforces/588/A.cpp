#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100100],p[100100],i,j,ans,mn;
    cin>>n;
    cin>>a[0]>>p[0];
    ans=a[0]*p[0];
    mn=p[0];
    for(i=1;i<n;i++){
        cin>>a[i]>>p[i];
        if(p[i]>=mn) ans+=a[i]*mn;
        else {
            ans+=a[i]*p[i];
            mn=p[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
