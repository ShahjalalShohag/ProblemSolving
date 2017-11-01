#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,ans,sum=0,a[200];
    cin>>n;
    for(i=0;i<n;i++) {
            cin>>a[i];
            sum+=a[i];
    }
    ans=2*sum/n;
    for(i=0;i<n;i++){
        if(a[i]==0) continue;
        cout<<i+1<<" ";
        for(j=i+1;j<n;j++){
            if(a[j]==ans-a[i]) {
                    cout<<j+1<<endl;
                    a[j]=0;
                    break;
            }
        }
    }
    return 0;
}
