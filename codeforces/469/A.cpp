#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p,q,a[110],b[110],c[110]={0},i,ans;
    cin>>n;
    cin>>p;
    for(i=1;i<=p;i++){
        cin>>a[i];
        c[a[i]]=1;
    }
    cin>>q;
    for(i=1;i<=q;i++){
        cin>>b[i];
        c[b[i]]=1;
    }
    for(i=1;i<=n;i++){
        if(c[i]==0){
            cout<<"Oh, my keyboard!"<<endl;
            return 0;
        }
    }
    cout<<"I become the guy."<<endl;
    return 0;
}
