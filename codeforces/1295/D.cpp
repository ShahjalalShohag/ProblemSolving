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

ll ans[N];
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll a, m; cin >> a >> m;
        vector<ll> v;
        for(int ll i = 1; i * i <= m; i++){
            if(m % i ==0){
                v.eb(i);
                if(i != m/i) v.eb(m/i);
            }
        }
        sort(v.begin(), v.end());
        int n = v.size();
        ll g = __gcd(a, m);
        int id = 0;
        for(int i = n - 1; i >= 0; i--){
            if(g == v[i]) id = i;
            ans[i] = (a + m -1) / v[i] - (a - 1) / v[i];
            for(int j = i + 1; j < n ; j++) if(v[j] % v[i] == 0) ans[i] -= ans[j];
        }
        cout << ans[id] << nl;
    }
    return 0;
}
