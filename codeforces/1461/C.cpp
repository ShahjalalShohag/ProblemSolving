#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int f = -1;
    for (int i = n; i >= 1; i--) {
      if (a[i] != i) {
        f = i; break;
      }
    }
    long double ans = 1.0L;
    while (m--) {
      int i; long double p; cin >> i >> p;
      if (i >= f) {
        ans *= (1.0L - p);
      }
    }
    ans = 1.0L - ans;
    if (f == -1) ans = 1.0L;
    cout << fixed << setprecision(10) << ans << '\n';
  }
  return 0;
}