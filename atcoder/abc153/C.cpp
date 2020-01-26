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
    int n = in(), k = in();
    vector<int> a(n);
    for(auto &x: a) x = in();
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for(int i = k; i < n; i++) ans += a[i];
    cout << ans << nl;
    return 0;
}
