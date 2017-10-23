#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,ans=0,a[12];
    cin>>n;
    for(i=0;i<12;i++) cin>>a[i];
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    sort(a,a+12,greater<int>());
    for(i=0;i<12;i++){
        ans+=a[i];
        if(ans>=n){
            cout<<i+1<<endl;
            return  0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
