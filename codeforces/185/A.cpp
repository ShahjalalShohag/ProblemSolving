#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,ans,res=1,base=2,m=1000000007;
    cin>>n;
    while(n){
        if(n%2) res=(base*res)%m;
        base=(base*base)%m;
        n=n/2;
    }
    ans=((res*(res+1))/2)%m;
    cout<<ans<<endl;
    return 0;
}
