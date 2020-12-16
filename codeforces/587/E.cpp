#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
struct Basis {
  vector<int> a;
  Basis() {}
  void insert(int x) {
      for (auto &i: a) x = min(x, x ^ i);
      if (!x) return;
      for (auto &i: a) if ((i ^ x) < i) i ^= x;
      a.push_back(x);
  }
};
int a[N];
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  Basis t[4 * N];
  ST() {}
  inline Basis combine(Basis a,Basis b) {
    if (a.a.size() < b.a.size()) swap(a, b);
    for (auto x: b.a) a.insert(x);
    return a;
  }
  inline void pull(int n) {
    t[n] = combine(t[lc], t[rc]);
  }
  void build(int n, int b, int e) {
    t[n].a.clear();
    if (b == e) {
      t[n].insert(a[b]);
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int v) {
    if (i < b || e < i) return;
    if (i == b && e == i) {
      t[n].a.clear();
      a[i] ^= v;
      t[n].insert(a[i]);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, v);
    upd(rc, mid + 1, e, i, v);
    pull(n);
  }
  Basis query(int n, int b, int e, int i, int j) {
    if (i > e || b > j) return Basis(); //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}t;

template <class T>
struct BIT { //1-indexed
  int n; vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n,0);
  }
  T query(int i) {
    T ans = 0;
    for (; i >= 1; i -= (i & -i)) ans ^= t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0) return;
    for (; i < n; i += (i & -i)) t[i] ^= val;
  }
  void upd(int l, int r, T val) {
    upd(l, val);
    upd(r + 1, val);
  }
};
int b[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    a[i] = b[i - 1] ^ b[i];
  }
  BIT<int> bt(n + 5);
  for (int i = 1; i <= n; i++) {
    bt.upd(i, i, b[i]);
  }
  t.build(1, 1, n);
  while (q--) {
    int ty, l, r; cin >> ty >> l >> r;
    if (ty == 1) {
      int k; cin >> k;
      t.upd(1, 1, n, l, k);
      if (r + 1 <= n) t.upd(1, 1, n, r + 1, k);
      bt.upd(l, r, k);
    }
    else {
      Basis cur;
      if (l + 1 <= r) cur = t.query(1, 1, n, l + 1, r);
      cur.insert(bt.query(l));
      cout << (1LL << cur.a.size()) << '\n';
    }
  }
  return 0;
}