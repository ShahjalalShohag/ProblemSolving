#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1010],b[1010],ans=0,i,j;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i]>>b[i];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        if(i!=j&&a[i]==b[j]) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
