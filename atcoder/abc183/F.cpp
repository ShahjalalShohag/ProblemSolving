#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

map<int, int> se[N];
int par[N];
int rep(int u) {
  return par[u] = (u == par[u] ? u : rep(par[u]));
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    par[i] = i;
    se[i][k]++;
  }
  while (q--) {
    int ty, u, v; cin >> ty >> u >> v;
    if (ty == 1) {
      u = rep(u), v = rep(v);
      if (u != v) {
        if (se[u].size() < se[v].size()) {
          swap(u, v);
        }
        for (auto x: se[v]) {
          se[u][x.first] += x.second;
        }
        par[v] = u;
      }
    }
    else {
      u = rep(u);
      int ans = se[u].find(v) == se[u].end() ? 0 : se[u][v];
      cout << ans << '\n';
    }
  }
  return 0;
}