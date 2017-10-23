#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n,m;
    cin>>n>>m;
    a=n;
    while(n/m>0){
        a+=n/m;
        n=n%m+n/m;
    }
    cout<<a<<endl;
    return 0;
}
