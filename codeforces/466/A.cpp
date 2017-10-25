#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,ans;
    cin>>n>>m>>a>>b;
    if(b/m<a){
        ans=(n/m)*b;
        int k=(n%m)*a;
        if(k>b) ans+=b;
        else ans+=k;
    }
    else ans=n*a;
    cout<<ans<<endl;
    return 0;
}
