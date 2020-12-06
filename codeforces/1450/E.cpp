#include<bits/stdc++.h>
using namespace std;

const int N = 202;

int w[N][N], vis[N];
vector<int> g[N];
void dfs(int u, int c = 1) {
  vis[u] = c;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v, 3 - c);
    }
    else if (vis[u] == vis[v]) {
      cout << "NO\n";
      exit(0);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      w[i][j] = 1e9;
    }
    w[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, k; cin >> u >> v >> k;
    g[u].push_back(v);
    g[v].push_back(u);
    if (k) {
      w[u][v] = 1;
      w[v][u] = -1;
    }
    else {
      w[u][v] = w[v][u] = 1;
    }
  }
  dfs(1);
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (w[i][i] < 0) {
      cout << "NO\n";
      return 0;
    }
  }
  int s, mx = -1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (w[i][j] > mx) {
        mx = w[i][j];
        s = i;
      }
    }
  }
  cout << "YES\n";
  cout << mx << '\n';
  for (int i = 1; i <= n; i++) {
    cout << w[s][i] << ' ';
  }
  return 0;
}