#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int x, y, z, dp[1010][4], C[4];
int yo(ll val, int last)
{
    if(val <= 0) return 0;
    if(val > 1000) val = (val - 200) % C[last] + 200;
    if(val == 0) return 0;
    if(dp[val][last] != -1) return dp[val][last];
    set<int> se;
    se.insert(yo(val - x, 0));
    if(last != 1)  se.insert(yo(val - y, 1));
    if(last != 2)  se.insert(yo(val - z, 2));
    int i = 0;
    while(se.find(i) != se.end()) i++;
    return dp[val][last] = i;
}
ll a[N];
int g[N];
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        memset(dp, -1 , sizeof dp);
        int n; cin >> n >> x >> y >> z;
        C[0] = C[1] = C[2] = 0;
        for(int cycle = 1; cycle <= 200; cycle++){
            for(int last = 0; last < 3; last++){
                if(C[last]) continue;
                int ok = 1;
                for(int i = 200; i < 500; i ++) ok &= yo(i, last) == yo(i + cycle, last);
                if(ok){
                    C[last] = cycle;
                }
            }
        }
        assert(C[0]);
        int XOR = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            g[i] = yo(a[i], 0);
            XOR ^= g[i];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int p = XOR ^ g[i];
            p ^= yo(a[i] - x, 0), ans += p == 0;
            p = XOR ^ g[i];
            p ^= yo(a[i] - y, 1), ans += p == 0;
            p = XOR ^ g[i];
            p ^= yo(a[i] - z, 2), ans += p == 0;
        }
        cout << ans << nl;
    }
    return 0;
}
