#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 1e6 + 9;
const int mod = 1e9 + 7;

vector<pair<char, int>> g[N];
int dp[N], ans[N], id[N], imp[N], cur;
void dfs(int u, int mn)
{
    if(imp[u]){
        dp[u] = min(dp[u], cur + imp[u] + mn);
        ans[id[u]] = dp[u];
    }
    int p = cur;
    cur += imp[u];
    for(auto x: g[u]){
        int v = x.second;
        dp[v] = dp[u] + 1;
        dfs(v, min(mn, dp[u] - p));
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int p; char ch;
        cin >> p >> ch;
        g[p].emplace_back(ch, i);
    }
    int k; cin >> k;
    for(int i = 1; i <= k; i++){
        int u; cin >> u; imp[u] = 1; id[u] = i;
    }
    for(int i = 0; i <= n; i++) sort(g[i].begin(), g[i].end());
    dfs(0, 1e9);
    for(int i = 1; i <= k; i++) cout << ans[i] << ' ';
    return 0;
}
