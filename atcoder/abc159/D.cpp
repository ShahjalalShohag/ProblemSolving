#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

ll f(ll n)
{
    return n * (n - 1) / 2;
}
int a[N], cnt[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int k; cin >> k; cnt[k]++;
        a[i] = k;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += f(cnt[i]);
    for(int i = 1; i <= n; i++){
        int k = a[i];
        ll p = ans;
        ans -= f(cnt[k]);
        cnt[k] --;
        ans += f(cnt[k]);
        cout << ans << nl;
        cnt[k]++;
        ans = p;
    }
    return 0;
}
