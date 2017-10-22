#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i,ans,a[100100];
    cin>>n;
    cin>>a[0];
    ans=1;
    for(i=1;i<n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
