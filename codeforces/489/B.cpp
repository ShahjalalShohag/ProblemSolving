#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,m,ans=0,a[1010],b[1010];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    j=0;
    for(i=0;i<n&&j<m;){
        if(abs(a[i]-b[j])<=1){
            ans++;
            j++;
            i++;
        }
        else if(a[i]>b[j]) j++;
        else i++;
    }
    cout<<ans<<endl;
    return 0;
}

