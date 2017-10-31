#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,b,s;
    cin>>a>>b>>s;
    a=abs(a);
    b=abs(b);
    if(s>=a+b&&(s-a-b)%2==0) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
