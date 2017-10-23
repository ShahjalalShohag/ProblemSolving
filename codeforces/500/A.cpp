#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i,j=0,cell=1,a[30010];
    cin>>n>>t;
    for(i=1;i<n;i++){
        cin>>a[i];
        if(cell==i) cell+=a[i];
        if(cell==t) j=1;
    }
    j==1?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}
