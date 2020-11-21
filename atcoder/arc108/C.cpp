#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], vis[N];
vector<pair<int, int>> g[N];

void dfs(int u, int f = 0, int last = 0) {
  vis[u] = 1;
  if (!f) {
    set<int> se;
    se.insert(last);
    for (auto x: g[u]) {
      int v = x.first, w = x.second;
      if (!vis[v]) {
        se.insert(w);
      }
    }
    int k = 1;
    while (se.find(k) != se.end()) ++k;
    a[u] = k;
    for (auto x: g[u]) {
      int v = x.first, w = x.second;
      if (!vis[v]) {
        dfs(v, 1, w);
      }
    }
  }
  else {
    a[u] = last;
    for (auto x: g[u]) {
      int v = x.first, w = x.second;
      if (!vis[v]) {
        dfs(v, (w != a[u]), w);
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; i++) {
      int u, v, w; cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) {
    auto vec = g[i];
    sort(vec.begin(), vec.end());
    g[i].clear();
    for (auto x: vec) {
      if (!g[i].empty() && g[i].back().first == x.first);
      else g[i].push_back(x);
    }
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    assert(1 <= a[i] && a[i] <= n);
    cout << a[i] << '\n';
  }
  return 0;
}