#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int t[N][20], a[N];
void build(int n) {
    for(int i = 1; i <= n; ++i) t[i][0] = a[i];
    for(int k = 1; k < 20; ++k) {
      for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
        t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
      }
    }
}
int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return min(t[l][k], t[r - (1 << k) + 1][k]);
}
int z;
int yo(vector<int> a) {
  int n = a.size();
  vector<int> p(z + 1, 0);
  for (int i = 0; i < n; i++) {
    p[a[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!p[i]) return 0;
  }
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    z = n;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b.push_back(a[i]);
    }
    build(n);
    int l = 2, r = n, ans = n + 1;
    while (l <= r) {
      int mid = l + r >> 1;
      vector<int> b;
      for (int i = mid; i <= n; i++) {
        b.push_back(query(i - mid + 1, i));
      }
      if (yo(b)) {
        ans = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    if (yo(b)) cout << 1;
    else cout << 0;
    for (int i = 2; i <= n; i++) {
      if (i >= ans) cout << 1;
      else cout << 0;
    }
    cout << '\n';
  }
  return 0;
}