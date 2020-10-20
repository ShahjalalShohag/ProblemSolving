#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
vector<pair<int, int>> g[N];
vector<int> dijkstra(int n, int s) {
    const int inf = 1e9 + 9;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> d(n + 1, inf); vector<bool> vis(n + 1, 0);
    q.push({0, s});
    d[s] = 0;
    while(!q.empty()){
        auto x = q.top(); q.pop();
        int u = x.second;
        if(vis[u]) continue; vis[u] = 1;
        for(auto y: g[u]){
            int v = y.first; int w = y.second;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w; q.push({d[v], v});
            }
        }
    }
    return d;
}
int u[N], v[N], w[N], x[N], y[N];
vector<int> d[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    g[u[i]].push_back({v[i], w[i]});
    g[v[i]].push_back({u[i], w[i]});
  }
  for (int i = 1; i <= k; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    d[i] = dijkstra(n, i);
  }
  int ans = 1e9 + 9;
  for (int i = 1; i <= m; i++) {
    int cur = 0;
    for (int j = 1; j <= k; j++) {
      cur += min({d[x[j]][y[j]], d[x[j]][u[i]] + d[v[i]][y[j]], d[x[j]][v[i]] + d[u[i]][y[j]]});
    }
    ans = min(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}