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
    int t = in();
    while(t--){
        ll n = in();
        ll ans = 0;
        while(n > 0){
            ll nw = 1, p = n;
            while(p){
                nw *= 10;
                p /= 10;
            }
            nw /= 10;
            ans += nw;
            n -= nw;
            n += nw / 10;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
