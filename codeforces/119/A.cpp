#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n,i,j;
    cin>>a>>b>>n;
    while(n>0){
        n-=__gcd(a,n);
        if(n==0){
            cout<<0<<endl;
            return 0;
        }
        else n-=__gcd(b,n);
    }
    cout<<1<<endl;
    return 0;
}
