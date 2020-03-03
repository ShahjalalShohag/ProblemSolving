#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 9;
const int mod = 1e9 + 7;


bool is_prime(int n)
{
    for(int i = 2; i < n; i++) if(n % i == 0) return 0;
    return 1;
}
int n; ll a[N], b[N];
set<ll> se;
ll yo(ll x)
{
    if(se.find(x) != se.end()) return 1e15;
    se.insert(x);
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += a[i] < x ? x - a[i] : min(a[i] % x, x - a[i] % x);
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    ll ans = 1e15;
    for(int i = 2; i <= 200; i++) if(is_prime(i)) ans = min(ans, yo(i));
    int it = 20;
    int m = unique(b + 1, b + n + 1) - b - 1;
    while(it--){
        int k = rnd() % m + 1;
        for(ll d = -2; d <= 2; d++){
            ll x = b[k] + d;
            if(x <= 1) continue;
            for(ll i = 2; i * i <= x; i++){
                if(x % i == 0){
                    ans = min(ans, yo(i));
                    while( x % i == 0) x /= i;
                }
            }
            if(x > 1) ans = min(ans, yo(x));
        }
    }
    cout << ans << nl;
    return 0;
}
