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

int32_t main()
{
    ll n;
    cin>>n;
    ll ans=0;
    for(ll k=5; k<=n; k*=5){
        ll nw=n/k;
        ans+=nw/2;
    }
    if(n%2==1) ans=0;
    cout<<ans<<nl;
    return 0;
}
