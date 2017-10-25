#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i;
    cin>>n>>t;
    if(n==1&&t==10) {cout<<-1<<endl;return 0;}
    if(t==10){
        cout<<1;
        for(i=2;i<=n;i++) cout<<0;
        cout<<endl;
        return 0;
    }
    for(i=1;i<=n;i++) cout<<t;
    cout<<endl;
    return 0;
}
