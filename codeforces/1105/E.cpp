#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int N = 42;

int g[N][N], n;
long long edges[N];
map<long long, int> dp;
int yo(long long mask)
{
    if(mask == 0) return 0;
    if(dp.find(mask) != dp.end()) return dp[mask];
    int i = __builtin_ctzll(mask);
    int ans = yo(mask - (1LL << i));
    ans = max(ans, 1 + yo(mask & edges[i]));
    return dp[mask] = ans;
}
int max_clique_brute(int m)
{
    dp.clear();
    n = m;
    for(int i = 1; i <= n; i++){
        edges[i] = 0;
        for(int j = 1; j <= n; j++) if(g[i][j]) edges[i - 1] |= 1LL << (j - 1);
    }
    return yo((1LL << n) - 1);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> mp;
    set<int>se;
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n + 1; i++){
        int ty;
        if(i <= n) cin >> ty;
        if(ty == 1 || i > n){
            for(auto x: se) for(auto y: se) g[x][y] = 1, g[y][x] = 1;
            se.clear();
        }
        else{
            string s; cin >> s;
            if(mp.find(s) == mp.end()){
                mp[s]; mp[s] = mp.size();
            }
            int p = mp[s]; se.insert(p);
        }
    }
    for(int i = 1; i <= m; i++) for(int j = 1; j <= m; j++) g[i][j] = !g[i][j];
    for(int i = 1; i <= m; i++) g[i][i] = 0;
    cout << max_clique_brute(m) << '\n';
    return 0;
}
