#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int ok = 1;
      for (int j = 1; j <= n; j++) {
        ok &= (abs(x[i] - x[j]) + abs(y[i] - y[j])) <= k;
      }
      ans |= ok;
    }
    if (!ans) ans = -1;
    cout << ans << '\n';
  }
  return 0;
}