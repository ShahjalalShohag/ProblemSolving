#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<pair<int, long long>> g[N];
long long dijkstra(int n, int s, int t) {
  const long long inf = 1e18;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
  vector<long long> d(n + 1, inf); vector<bool> vis(n + 1, 0);
  q.push({0, s});
  d[s] = 0;
  while(!q.empty()){
    auto x = q.top(); q.pop();
    int u = x.second;
    if(vis[u]) continue; vis[u] = 1;
    for(auto y: g[u]){
      int v = y.first; long long w = y.second;
      if(d[u] + w < d[v]){
        d[v] = d[u] + w; q.push({d[v], v});
      }
    }
  }
  return d[t];
}
array<int, 3> a[N];
void add_edge(int u, int v, int d) {
  g[u].push_back({v, d});
  g[v].push_back({u, d});
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
  for (int i = 0; i < m; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i + 1;
  }
  sort(a, a + m);
  for (int i = 0; i + 1 < m; i++) {
    int d = min(abs(a[i][0] - a[i + 1][0]), abs(a[i][1] - a[i + 1][1]));
    add_edge(a[i][2], a[i + 1][2], d);
  }  
  sort(a, a + m, [&](array<int, 3> x, array<int, 3> y) {
    return x[1] < y[1];
  });
  for (int i = 0; i + 1 < m; i++) {
    int d = min(abs(a[i][0] - a[i + 1][0]), abs(a[i][1] - a[i + 1][1]));
    add_edge(a[i][2], a[i + 1][2], d);
  }  
  for (int i = 0; i < m; i++) {
    int d = min(abs(a[i][0] - sx), abs(a[i][1] - sy));
    add_edge(a[i][2], m + 1, d);
  }  
  for (int i = 0; i < m; i++) {
    int d = abs(a[i][0] - ex) + abs(a[i][1] - ey);
    add_edge(a[i][2], m + 2, d);
  }
  int d = abs(sx - ex) + abs(sy - ey);
  add_edge(m + 1, m + 2, d);
  cout << dijkstra(m + 2, m + 1, m + 2) << '\n';
  return 0;
}