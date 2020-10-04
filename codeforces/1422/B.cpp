#include<bits/stdc++.h>
using namespace std;

int a[200][200];
vector<int> g[200 * 200];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0, k = m - 1; j < k; j++, k--) {
        g[i * m + j].push_back(i * m + k);
        g[i * m + k].push_back(i * m + j);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0, k = n - 1; j < k; j++, k--) {
        g[j * m + i].push_back(k * m + i);
        g[k * m + i].push_back(j * m + i);
      }
    }
    vector<int> v;
    vector<int> vis(n * m, 0);
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      v.push_back(a[u / m][u % m]);
      for (auto v: g[u]) {
        if (vis[v]) continue;
        dfs(v);
      }
    };
    long long ans = 0;
    for (int i = 0; i < n * m; i++) {
      if (vis[i]) continue;
      v.clear();
      dfs(i);
      sort(v.begin(), v.end());
      int k = v[(v.size() / 2)];
      for (auto x: v) {
        ans += abs(x - k);
      }
    }
    cout << ans << '\n';
    for (int i = 0; i < n * m; i++) {
      g[i].clear();
    }
  }
  return 0;
}