#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,a[100100],b[100100],c[100100];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n-1;i++) cin>>b[i];
    for(i=0;i<n-2;i++) cin>>c[i];
    sort(a,a+n);
    sort(b,b+n-1);
    sort(c,c+n-2);
    b[n-1]=-1;
    c[n-2]=-1;
    for(i=0;i<n;i++){
        if(a[i]!=b[i]){
            cout<<a[i]<<endl;
            break;
        }
    }
    for(i=0;i<n-1;i++){
        if(b[i]!=c[i]){
            cout<<b[i]<<endl;
            break;
        }
    }
    return 0;
}
