#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,k,j,sz=100010;
    long long int ans[sz],cnt[sz]={0};
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>k;
        cnt[k]++;
    }
    ans[0]=0;
    ans[1]=cnt[1];
    for(i=2;i<=sz;i++){
        ans[i]=max(ans[i-1],(ans[i-2]+i*cnt[i]));
    }
    cout<<ans[sz]<<endl;
    return 0;
}

