#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0,i,j,mx,a[200];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    mx=*max_element(a,a+n);
    for(i=0;i<n;i++){
        ans+=mx-a[i];
    }
    cout<<ans<<endl;
    return 0;
}
