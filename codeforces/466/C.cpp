#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,s,ans=0,k=0,a[500005],sum[500005];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    sum[0]=a[0];
    s=a[0];
    for(i=1;i<n;i++){
            sum[i]=sum[i-1]+a[i];
            s+=a[i];
    }
    if(s%3!=0){
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<n-1;i++){
        if(sum[i]*3==2*s) ans+=k;
        if(sum[i]*3==s) k++;
    }
    cout<<ans<<endl;
    return 0;
}
