#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,p,q,a[100100],mn[100100],mx[100100];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    mn[0]=abs(a[0]-a[1]);
    mx[0]=abs(a[0]-a[n-1]);
    mn[n-1]=abs(a[n-1]-a[n-2]);
    mx[n-1]=abs(a[n-1]-a[0]);
    for(i=1;i<n-1;i++){
            p=abs(a[i]-a[i-1]);
            q=abs(a[i+1]-a[i]);
            p>q?mn[i]=q:mn[i]=p;
            p=abs(a[i]-a[0]);
            q=abs(a[i]-a[n-1]);
            p>q?mx[i]=p:mx[i]=q;
    }
    for(i=0;i<n;i++) cout<<mn[i]<<" "<<mx[i]<<endl;
    return 0;
}
