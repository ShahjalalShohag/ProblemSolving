#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,mxpos,mnpos,mx,mn,a[110];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    mx=*max_element(a,a+n);
    mxpos=distance(a,find(a,a+n,mx));
    mn=*min_element(a,a+n);
    for(i=n-1;i>=0;i--) if(a[i]==mn) break;
    mnpos=i;
    if(mxpos>mnpos) cout<<n-1-mnpos+mxpos-1<<endl;
    else cout<<n-1-mnpos+mxpos<<endl;
    return 0;
}
