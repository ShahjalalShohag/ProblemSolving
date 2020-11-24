#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

vector<int> g[N];
int vis[N], vis2[N], par[N], f, vis3[N];
void dfs(int u, int p = 0) {
  if (f) return;
  par[u] = p;
  vis[u] = 1;
  for (auto v: g[u]) {
    if (f) return;
    else if (!vis[v]) {
      dfs(v, u);
    }
    else if (v ^ p) {
      int cur = u;
      while (cur != v) {
        vis2[cur] = 1;
        cur = par[cur];
      }
      vis2[v] = 1;
      f = 1;
      return;
    }
  }
}
int cnt = 0;
void dfs2(int u) {
  ++cnt;
  vis3[u] = 1;
  for (auto v: g[u]) {
    if (!vis2[v] && !vis3[v]) {
      dfs2(v);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    f = 0;
    dfs(1);
    long long ans = 1LL * n * (n - 1);
    for (int i = 1; i <= n; i++) {
      if (vis2[i]) {
        cnt = 0;
        dfs2(i);
        ans -= 1LL * cnt * (cnt - 1) / 2;
      }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      vis[i] = vis2[i] = vis3[i] = par[i] = 0;
    }
  }
  return 0;
}