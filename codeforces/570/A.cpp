#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,k,mx,ans,a[110],c[110]={0};
    cin>>n>>m;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cin>>a[j];
        }
        mx=a[1];
        ans=1;
        for(k=2;k<=n;k++){
            if(a[k]>mx){
                    mx=a[k];
                    ans=k;
            }
        }
        c[ans]++;
    }
    mx=c[1];
    ans=1;
    for(i=2;i<=n;i++){
        if(c[i]>mx){
            mx=c[i];
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
