#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,ans;
    cin>>a>>b>>c;
    ans=min(a,b)+min(a+b,c);
    if(a>b) ans+=min(a,b+c);
    else ans+=min(b,a+c);
    cout<<ans<<endl;
    return 0;
}
