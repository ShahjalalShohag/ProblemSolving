#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,m,ans=0;
    cin>>n>>m;
    if(n>=m){
        cout<<n-m<<endl;
        return 0;
    }
    while(m!=n){
        if(m>n&&(m%2==0)) m/=2;
        else m++;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
