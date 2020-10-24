#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 9, inf = 2e9;
 
long long ans[N];
 
struct node {
  int mx1, mx2; long long mx_sum;
  node(int a = -inf, int b = -inf, long long c = 0) {
    mx1 = a, mx2 = b, mx_sum = c;
  }
  friend inline node merge(node u, node v) {
    if (u.mx1 < v.mx1) {
      u.mx1 = v.mx1;
      u.mx2 = max(u.mx1, v.mx2);
      u.mx_sum = v.mx_sum;
    }
    else if (u.mx1 == v.mx1) {
      u.mx_sum += v.mx_sum;
      u.mx2 = max(u.mx2, v.mx2);
    }
    else u.mx2 = max(u.mx2, v.mx1);
    return u;
  }
};
struct sgt_node {
  node p; long long sum; int mn_lazy;
  sgt_node(node a = node(), long long b = 0) {
    p = a, sum = b, mn_lazy = inf;
  }
  inline void set_min(int x) {
    if (x >= p.mx1) return;
    sum += 1LL * (x - p.mx1) * p.mx_sum;
    p.mx1 = mn_lazy = x;
  }
  friend inline sgt_node merge(sgt_node u, sgt_node v) {
    u.p = merge(u.p, v.p);
    u.sum += v.sum;
    u.mn_lazy = inf;
    return u;
  }
};
sgt_node t[N * 4];
inline void push(int n) {
  for (auto p: {n << 1, n << 1 | 1}) {
    t[p].set_min(t[n].mn_lazy);
  }
  t[n].mn_lazy = inf;
}
inline void pull(int n) {
  t[n] = merge(t[n << 1], t[n << 1 | 1]);
}
void build(int n, int b, int e) {
  if (b == e) {
    node x; x.mx1 = b, x.mx_sum = 1;
    long long sum = b;
    t[n] = {x, sum};
    return;
  }
  int mid = b + e >> 1;
  build(n << 1, b, mid);
  build(n << 1 | 1, mid + 1, e);
  pull(n);
}
void upd(int n, int b, int e, int l, int r, int x) {
  if (r < b || e < l) return;
  if (l <= b && e <= r && t[n].p.mx2 < x) return t[n].set_min(x);
  push(n);
  int mid = b + e >> 1;
  upd(n << 1, b, mid, l, r, x);
  upd(n << 1 | 1, mid + 1, e, l, r, x);
  pull(n);
}
vector<int> id[N];
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    --a[i];
    id[a[i]].push_back(i);
  }
  for (int i = 0; i <= n; i++) id[i].push_back(n + 1);
  build(1, 1, n);
  ans[0] = t[1].sum;
  for (int k = 0; k < n; k++) {
    if (id[k][0] != 1) upd(1, 1, n, 1, id[k][0] - 1, 0);
    for (int i = 0; i + 1 < id[k].size(); i++) {
      upd(1, 1, n, id[k][i], id[k][i + 1] - 1, id[k][i]);
    }
    ans[k + 1] = t[1].sum;
  }
  for (int i = 0; i <= n; i++) ans[i] = ans[i] - ans[i + 1];
  for (int i = 0; i <= n + 1; i++) {
    if (ans[i] == 0) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  return 0;
} 