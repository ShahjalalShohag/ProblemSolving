#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int a[N];
struct ST {
  int t[4 * N];
  ST() {
      memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e) {
      if(b == e) {
          t[n] = a[b];
          return;
      }
      int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
      build(l, b, mid);
      build(r, mid + 1, e);
      t[n] = min(t[l], t[r]);
  }
  int query(int n, int b, int e, int i, int j) {
      if(b > j || e < i) return 1e9;
      if(b >= i && e <= j) return t[n];
      int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
      int L = query(l, b, mid, i, j);
      int R = query(r, mid + 1, e, i, j);
      return min(L, R);
  }
}t;
int smx[N], n;
int yo(vector<int> &a, int k) {
  auto it = upper_bound(a.begin(), a.end(), k);
  if (it == a.end()) {
    return n + 1;
  }
  else return *it;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    cin >> n;
    map<int, vector<int>> id, idmx;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      id[a[i]].push_back(i);
    }
    t.build(1, 1, n);
    smx[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      smx[i] = max(smx[i + 1], a[i]);
    }
    for (int i = 1; i <= n; i++) {
      idmx[smx[i]].push_back(i);
    }
    int mx = 0, x = -1, y = -1, z = -1;
    for (int i = 1; i <= n; i++) {
      mx = max(mx, a[i]);
      int f = yo(id[mx], i);
      if (f < n) {
        int g = yo(idmx[mx], f);
        if (g <= n) {
          if (t.query(1, 1, n, i + 1, g - 1) == mx) {
            x = i; y = g - i - 1, z = n - g + 1;
            break;
          }
        }
      }
    }
    if (x != -1) {
      cout << "YES\n";
      cout << x << ' ' << y << ' ' << z << '\n';
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}