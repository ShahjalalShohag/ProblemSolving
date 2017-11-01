#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,n,d;
    cin>>a>>n>>d;
    if(d==0&&n==a) cout<<"YES\n";
    else if((n>a&&d<0)||(n<a&&d>0)) cout<<"NO\n";
    else if(d!=0&&(n-a)%d==0) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
