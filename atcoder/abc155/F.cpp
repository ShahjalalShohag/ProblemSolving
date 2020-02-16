#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

vector<pair<int, int>> g[N];
int vis[N], a[N], b[N];
vector<int> ans;
int dfs(int u)
{
    vis[u] = 1;
    int ret = b[u];
    for(auto x: g[u]){
        int v = x.first;
        if(!vis[v]){
            int k = dfs(v);
            //cout << u << v << k << nl;
            if(k) ans.eb(x.second);
            ret ^= k;
        }
    }
    return ret;
}
pair<int, int> c[N];
int32_t main()
{
    int n = in();
    int q = in();
    for(int i = 1; i <= n; i++) c[i].first = in(), c[i].second = in();
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++) a[i] = c[i].first, b[i] = c[i].second;
    for(int i = n + 1; i >= 1; i--) b[i] =b[i - 1] ^ b[i];
    for(int i = 1; i <= q; i++){
        int l = in(), r = in();
        int u = lower_bound(a + 1, a + n + 1, l) - a;
        if(u == n + 1 || a[u] > r) continue;
        int v = upper_bound(a + 1, a + n + 1, r) - a;
        //deb(u); deb(v);
        g[u].eb(v, i);
        g[v].eb(u, i);
    }
    for(int i = 1; i <= n + 1; i++){
        if(!vis[i]){
            if(dfs(i)) return cout << - 1 << nl, 0;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for(auto x: ans) printf("%d ", x);
    cout << nl;
    return 0;
}
