#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l,a[1010];
    cin>>n>>l;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    double ans=a[0];
    for(int i=1;i<n;i++){
        if((double)(a[i]-a[i-1])/2>ans) ans=(double)(a[i]-a[i-1])/2;
    }
    if((l-a[n-1])>ans) ans=(l-a[n-1]);
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}
