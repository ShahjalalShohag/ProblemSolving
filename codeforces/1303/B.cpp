#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        ll n, g, b; cin >> n >> g >> b;
        ll l = 0, r = 2e18, ans = 0;
        while(l <= r){
            ll mid = (l + r) / 2;
            ll p = mid / (g + b);
            ll tot = p * g + min(g, mid % (g + b));
            if(tot * 2 >= n && mid >= n) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << nl;
    }
    return 0;
}
