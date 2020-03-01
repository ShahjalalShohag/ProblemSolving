#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

vector<int> g[N], b[N];
int vis[N];
set<int> cur;
void dfs(int u)
{
    vis[u] = 1;
    cur.insert(u);
    for(auto v: g[u]) if(!vis[v]) dfs(v);
}
int ans[N];
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    while(m--){
        int u, v; cin >> u >> v; g[u].emplace_back(v); g[v].emplace_back(u);
    }
    while(k--){
        int u, v; cin >> u >> v; b[u].emplace_back(v); b[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++) if(!vis[i]){
        dfs(i);
        for(auto u: cur){
            ans[u] = cur.size();
            ans[u] -= g[u].size();
            for(auto v: b[u]) ans[u] -= cur.find(v) != cur.end();
        }
        cur.clear();
    }
    for(int i = 1; i <= n; i++) cout << ans[i] - 1<< ' ';
    cout << nl;
    return 0;
}
