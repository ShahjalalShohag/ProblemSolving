#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll get(ll n)
{
    ll ans=n/3;
    if(n%3==1||n%3==2) ans++;
    return ans;
}

ll get3(ll n)
{
    ll ans=n/3;
    if(n%3==2) ans++;
    return ans;
}
const int mod=1e9+7;
const int N=2e5+9;
ll dp[N][3],n,t,t2,t3;
ll yo(ll i,ll m)
{
    if(i==n+1){
        if(m==0) return 1;
        else return 0;
    }
    ll &ret=dp[i][m];
    if(ret!=-1) return ret;
    else return ret=((t*yo(i+1,m)%mod+t2*yo(i+1,(m+1)%3)%mod)%mod+t3*yo(i+1,(m+2)%3)%mod)%mod;
}
int main()
{
    //BeatMeScanf;
    ll i,j,k,l,r,m;
    cin>>n>>l>>r;
    t=r/3-(l-1)/3;
    t2=get(r)-get(l-1);
    t3=get3(r)-get3(l-1);
    memset(dp,-1,sizeof dp);
    cout<<yo(1,0)<<endl;
    return 0;
}
