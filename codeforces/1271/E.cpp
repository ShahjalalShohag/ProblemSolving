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

ll res=0, n;
void cnt(ll l, ll r)
{
    if(l>n){
        return;
    }
    if(r>n){
        res+=n-l+1;
        return;
    }
    res+=r-l+1;
    cnt(l*2, r*2+1);
}
ll yo(ll k)
{
    res=0;
    if(k%2==0) cnt(k, k+1);
    else cnt(k, k);
    return res;
}
ll odd(ll l, ll r, ll k)
{
    if(l>r) return 0;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(yo((mid-1)*2+1)>=k) ans=(mid-1)*2+1, l=mid+1;
        else r=mid-1;
    }
    return ans;
}
ll even(ll l, ll r, ll k)
{
    if(l>r) return 0;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(yo(mid*2)>=k) ans=mid*2, l=mid+1;
        else r=mid-1;
    }
    return ans;
}

int32_t main()
{
    ll k;
    cin>>n>>k;
    ll ans=1;
    ans=max(ans, odd(1, (n+1)/2, k));
    ans=max(ans, even(1, n/2, k));
    cout<<ans<<nl;
    return 0;
}
