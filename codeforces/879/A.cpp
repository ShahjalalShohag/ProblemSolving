#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,ans,m,k,s[1100],d[1100];
    cin>>n;
    for(i=0;i<n;i++) cin>>s[i]>>d[i];
    ans=s[0];
    for(i=1;i<n;i++){
            m=0;
        for(k=s[i];k<=ans;k=s[i]+m*d[i]){
            m++;
        }
        ans=k;
    }
    cout<<ans<<endl;
    return 0;
}
