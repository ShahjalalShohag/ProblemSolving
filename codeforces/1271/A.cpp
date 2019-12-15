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
    int a=in(), b=in(), c=in(), d=in(), e=in(), f=in();
    ll ans=0;
    for(int i=0; i<=d; i++){
        ll nw=1LL*e*min(a, i);
        nw+=1LL*f*min({b, c, d-i});
        ans=max(ans, nw);
    }
    cout<<ans<<nl;
    return 0;
}
