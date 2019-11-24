#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;

ll a,b,x;
ll yo(ll n)
{
    ll ans=n*a;
    int cnt=0;
    while(n) cnt++,n/=10;
    ans+=b*cnt;
    return ans;
}
int32_t main()
{
    cin>>a>>b>>x;
    ll res=0;
    for(ll nw=1;nw<1e9;nw*=10){
        ll l=nw;
        ll r=l*10-1;
        ll ans=0;
        while(l<=r){
            ll mid=(l+r)/2;
            if(yo(mid)<=x) ans=mid,l=mid+1;
            else r=mid-1;
        }
        res=max(res,ans);
    }
    if(yo(1e9)<=x) res=1e9;
    cout<<res<<nl;
    return 0;
}
