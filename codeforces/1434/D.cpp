#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

int a[N], r[N];
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  int t[4 * N][2], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    swap(t[n][0], t[n][1]);
    if (b != e) {
      lazy[lc] = lazy[lc] ^ lazy[n];
      lazy[rc] = lazy[rc] ^ lazy[n];
    }
    lazy[n] = 0;
  }
  inline void pull(int n) {
    t[n][0] = max(t[lc][0], t[rc][0]);
    t[n][1] = max(t[lc][1], t[rc][1]);
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      t[n][0] = a[r[b]];
      t[n][1] = 0;
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = 1; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j);
    upd(rc, mid + 1, e, i, j);
    pull(n);
  }
}t;

vector<pair<int, int>> g[N];
int farthest(int s, int n, vector<int> &d) {
  d.assign(n + 1, N); d[s] = 0;
  vector<bool> vis(n + 1);
  queue<int> q; q.push(s);
  vis[s] = 1; int last = s;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto x: g[u]) {
      int v = x.first;
      if (vis[v]) continue;
      d[v] = d[u] + 1;
      q.push(v); vis[v] = 1;
    }
    last = u;
  }
  return last;
}

int T = 0, st[N], en[N];
void dfs(int u, int p = 0) {
  a[u] = a[p] + 1;
  st[u] = ++T;
  r[T] = u;
  for (auto x: g[u]) {
    int v = x.first;
    if (v ^ p) {
      dfs(v, u);
    }
  }
  en[u] = T;
}
int ans[N], Q[N], u[N], v[N], f[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u[i] >> v[i] >> f[i];
    g[u[i]].push_back({v[i], f[i]});
    g[v[i]].push_back({u[i], f[i]});
  }
  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> Q[i];
  }
  vector<int> d1, d2;
  int x = farthest(1, n, d1);
  int y = farthest(x, n, d2);
  T = 0; dfs(x);
  t.build(1, 1, n);
  for (int i = 1; i < n; i++) {
    if (a[u[i]] > a[v[i]]) {
      swap(u[i], v[i]);
    }
    if (f[i]) {
      t.upd(1, 1, n, st[v[i]], en[v[i]]);
    }
  }
  for (int i = 1; i <= q; i++) {
    t.upd(1, 1, n, st[v[Q[i]]], en[v[Q[i]]]);
    ans[i] = max(ans[i], t.t[1][0]);
  }
  T = 0; dfs(y);
  t.build(1, 1, n);
  for (int i = 1; i < n; i++) {
    if (a[u[i]] > a[v[i]]) {
      swap(u[i], v[i]);
    }
    if (f[i]) {
      t.upd(1, 1, n, st[v[i]], en[v[i]]);
    }
  }
  for (int i = 1; i <= q; i++) {
    t.upd(1, 1, n, st[v[Q[i]]], en[v[Q[i]]]);
    ans[i] = max(ans[i], t.t[1][0]);
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] - 1 << '\n';
  }
  return 0;
}