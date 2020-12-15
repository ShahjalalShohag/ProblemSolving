#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = n - 1, ideal = 0;
    for (int i = 1; i < n; i++) {
      ideal += a[i];
      int cur = 0, op = i - 1;
      for (int j = i + 1; j <= n; j++) {
        op += cur > 0;
        cur += a[j];
        if (cur == ideal) {
          cur = 0;
        }
      }
      if (cur != 0) op = n - 1;
      ans = min(ans, op);
    }
    cout << ans << '\n';
  }
  return 0;
}