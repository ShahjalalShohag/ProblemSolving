#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

bool vis[N];
vector<int> g[N], r[N], vec;
void dfs1(int u) {
    vis[u] = 1;
    for(auto v: g[u]) if(!vis[v]) dfs1(v);
    vec.push_back(u);
}

vector<int> comp;
void dfs2(int u) {
    comp.push_back(u);
    vis[u] = 1;
    for(auto v: r[u]) if(!vis[v]) dfs2(v);
}
int u[N], v[N], w[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i];
  }
  int L = 0, R = 1e9, ans = -1;
  while (L <= R) {
    int mid = L + R >> 1;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      r[i].clear();
    }
    for (int i = 0; i < m; i++) {
      if (w[i] <= mid) {
        g[u[i]].push_back(v[i]);
        r[v[i]].push_back(u[i]);
        if (u[i] == v[i]) {
          f[u[i]] = 1;
        }
      }
    }
    memset(vis, 0, sizeof vis);
    vec.clear();
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs1(i);
    reverse(vec.begin(), vec.end());
    memset(vis, 0, sizeof vis);
    int ok = 1;
    for(auto u: vec){
      if(!vis[u]){
        comp.clear();
        dfs2(u);
        if (comp.size() == 1 && f[comp[0]] == 0) {
          ok = 0; break;
        }
      }
    }
    if (ok) {
      ans = mid; R = mid - 1;
    }
    else {
      L = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}