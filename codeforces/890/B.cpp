#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,ans,a[200100],flag[200100];
    memset(flag,1,sizeof(flag));
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=n-1;i>=0;i--){
        if(flag[a[i]]!=0){
            ans=a[i];
            flag[a[i]]=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}

