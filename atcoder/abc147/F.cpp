#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

ll yo(ll n)
{
    if(n<=0) return 0;
    return n*(n+1)/2;
}
map<ll, vector<pll> > mp;
int32_t main()
{
    int n=in(), a=in(), d=in();
    if(d==0){
        if(a==0) return cout<<1<<nl,0;
        cout<<n+1<<nl;
        return 0;
    }
    if(d<0) d=-d, a=-a;
    for(int k=0; k<=n; k++){
        ll l=yo(k-1);
        ll r=yo(n-1)-yo(n-k-1);
        ll p=1LL*k*a;
        ll st=(p%d+d)%d;
        l+=(p-st)/d;
        r+=(p-st)/d;
        if(l<=r) mp[st].eb(l, r);
    }
    ll ans=0;
    for(auto& x: mp){
        auto v=x.second;
        vector<pair<ll,int>> a;
        for(auto x: v) a.eb(x.first, 0), a.eb(x.second, 1);
        sort(a.begin(), a.end());
        int op=0;
        ll last=0;
        for(auto x: a){
            if(x.second&&op==1) ans+=x.first-last+1;
            if(x.second==0&&op==0) last=x.first;
            if(x.second) op--;
            else op++;
        }
    }
    cout<<ans<<nl;
    return 0;
}
