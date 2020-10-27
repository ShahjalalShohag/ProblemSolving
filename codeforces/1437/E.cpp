#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
int f[N], a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] -= i;
  }
  vector<int> v;
  for (int i = 1; i <= m; i++) {
    int k; cin >> k;
    f[k] = 1;
  }
  f[n + 1] = 1;
  a[n + 1] = 1e9;
  int ans = 0, sz = 0, last = -1e9;
  for (int i = 1; i <= n + 1; i++) {
    if (f[i]) {
      if (a[i] < last) {
        cout << -1 << '\n';
        return 0;
      }
      last = a[i];
      int cur = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
      ans += sz - cur;
      sz = 0;
      v.clear();
    }
    else {
      if (a[i] >= last) {
        auto it = upper_bound(v.begin(), v.end(), a[i]);
        if (it == v.end()) v.push_back(a[i]);
        else *it = a[i];
      }
      ++sz;
    }
  }
  cout << ans << '\n';
  return 0;
}