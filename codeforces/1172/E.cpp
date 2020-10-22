#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9;

struct node {
  int p = 0, c[2] = {0, 0}, pp = 0;
  bool flip = 0;
  int sz = 0, ssz = 0, vsz = 0; // sz -> aux tree size, ssz = subtree size in rep tree, vsz = virtual tree size
  long long val = 0;
  node() {}
  node(int x) {
    val = 0;
    sz = 1;
    ssz = 1; vsz = 0;
  }
};
struct LCT {
  vector<node> t;
  LCT() {}
  LCT(int n) : t(n + 1) {}

  // <independant splay tree code>
  int dir(int x, int y) { return t[x].c[1] == y; }
  void set(int x, int d, int y) {
    if (x) t[x].c[d] = y, pull(x);
    if (y) t[y].p = x;
  }
  void pull(int x) {
    if (!x) return;
    int &l = t[x].c[0], &r = t[x].c[1];
    t[x].sz = t[l].sz + t[r].sz + 1;
    t[x].ssz = t[l].ssz + t[r].ssz + t[x].vsz + 1;
  }
  void push(int x) { 
    if (!x) return;
    int &l = t[x].c[0], &r = t[x].c[1];
    if (t[x].flip) {
      swap(l, r); 
      if (l) t[l].flip ^= 1; 
      if (r) t[r].flip ^= 1;
      t[x].flip = 0;
    }
  }
  void rotate(int x, int d) { 
    int y = t[x].p, z = t[y].p, w = t[x].c[d];
    swap(t[x].pp, t[y].pp);
    set(y, !d, w);
    set(x, d, y);
    set(z, dir(z, y), x);
  }
  void splay(int x) { 
    for (push(x); t[x].p;) {
      int y = t[x].p, z = t[y].p;
      push(z); push(y); push(x);
      int dx = dir(y, x), dy = dir(z, y);
      if (!z) rotate(x, !dx); 
      else if (dx == dy) rotate(y, !dx), rotate(x, !dx); 
      else rotate(x, dy), rotate(x, dx);
    }
  }
  // </independant splay tree code>

  // make the path from root to u a preferred path
  // returns last path-parent of a node as it moves up the tree
  int access(int _u) {
    int last = _u;
    for (int v = 0, u = _u; u; u = t[v = u].pp) {
      splay(u); splay(v);
      t[u].vsz -= t[v].ssz;
      t[u].val -= 1LL * t[v].ssz * t[v].ssz;
      int r = t[u].c[1];
      t[u].vsz += t[r].ssz;
      t[u].val += 1LL * t[r].ssz * t[r].ssz;
      t[v].pp = 0;
      swap(t[r].p, t[r].pp);
      set(u, 1, v);
      last = u;
    }
    splay(_u);
    return last;
  }
  // root of the rep. tree containing this node
  int find_root(int u) {
    access(u); splay(u); push(u);
    while (t[u].c[0]) {
      u = t[u].c[0]; push(u);
    }
    splay(u);
    return u;
  }
  // sum of the square sizes of the sons of root(u)
  long long yo(int u) {
    u = find_root(u);
    splay(u);
    return t[u].val + 1LL * t[t[u].c[1]].ssz * t[t[u].c[1]].ssz;
  }
  long long ans = 0;
  void link(int u, int v) { // u -> v
    // assert(!connected(u, v));
    ans -= yo(u);
    ans -= yo(v);
    access(u);
    access(v);
    t[v].pp = u;
    t[u].vsz += t[v].ssz;
    t[u].val += 1LL * t[v].ssz * t[v].ssz;
    ans += yo(u);
  }
  void cut(int u) { // cut par[u] -> u, u is non root vertex
    ans -= yo(u);
    access(u);
    assert(t[u].c[0] != 0);
    t[t[u].c[0]].p = 0;
    int v = t[u].c[0];
    t[u].c[0] = 0;
    pull(u);
    ans += yo(u) + yo(v);
  }
};
int c[N], par[N], col[N];
long long ans[N];
vector<pair<int, int>> Q[N];
vector<int> g[N];
void dfs(int u = 1, int pre = 0) {
  par[u] = pre;
  for(auto v: g[u]) if(v != pre) dfs(v, u);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }
  dfs(1, n + 1);
  for (int i = 1; i <= n; i++) Q[c[i]].push_back({i, 0});
  for (int i = 1; i <= q; i++) {
    int id, x; cin >> id >> x;
    Q[c[id]].push_back({id, i});
    c[id] = x;
    Q[c[id]].push_back({id, i});
  }
  LCT lct(n + 1);
  for (int i = 1; i <= n + 1; i++) col[i] = 1, lct.t[i] = node(i);
  for (int i = 1; i <= n; i++) lct.link(par[i], i);
  for (int c = 1; c <= n; c++) {
    long long last = 0;
    for (auto x: Q[c]) {
      int u = x.first, id = x.second;
      if (col[u]) lct.cut(u);
      else lct.link(par[u], u);
      col[u] ^= 1;
      ans[id] += 1LL * n * n - lct.ans - last;
      last = 1LL * n * n - lct.ans;
    }
    for (auto x: Q[c]) {
      int u = x.first, id = x.second;
      if (!col[u]) lct.link(par[u], u), col[u] ^= 1;
    }
  }
  for (int i = 1; i <= q; i++) ans[i] += ans[i - 1];
  for (int i = 0; i <= q; i++){
    cout << ans[i] << '\n';
  }
  return 0;
}