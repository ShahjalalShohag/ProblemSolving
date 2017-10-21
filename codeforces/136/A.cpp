#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,a[111];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=1;i<=n;i++){
        x=distance(a,find(a,a+n,i));
        cout<<x+1;
        if(i!=n) cout<<" ";
    }
    cout<<endl;
    return 0;
}
