#include<bits/stdc++.h>
using namespace std;

const int N = 202;
int n;
vector<pair<int, int>> g[N];
vector<long long> dijkstra(int s, int t)
{
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
    return d;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, x, y; cin >> a >> b >> x >> y;
  n = 200;
  for (int i = 1; i <= 100; i++) {
    g[i].push_back({i + 100, x});
    g[i + 100].push_back({i, x});
    if (i < 100) {
      g[i + 1].push_back({i + 100, x});
      g[i + 100].push_back({i + 1, x});
      g[i].push_back({i + 1, y});
      g[i + 1].push_back({i, y});      
      g[i + 101].push_back({i + 100, y});
      g[i + 100].push_back({i + 101, y});
    }
  }
  auto d = dijkstra(a, b + 100);
  cout << d[b + 100] << '\n';
  return 0;
}