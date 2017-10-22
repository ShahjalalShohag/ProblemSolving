#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,c1,c2,c3,m,m1,m2,m3,n;
    cin>>c1>>c2>>c3>>m1>>m2>>m3>>n;
    c=c1+c2+c3;
    m=m1+m2+m3;
    n-=(c+4)/5;
    if(m<=10*n) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
