#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,c,ans=0,a[100100];
    cin>>n>>c;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=n-1;i>0;i--){
        if(a[i]-a[i-1]<=c) ans++;
        else break;
    }
    cout<<ans+1<<endl;
    return 0;
}
