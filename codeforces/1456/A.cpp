#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, p, k; cin >> n >> p >> k;
    string s; cin >> s;
    s = "0" + s;
    vector<int> dp(n + 2, 0);
    for (int i = n; i >= 1; i--) {
      dp[i] = s[i] == '0';
      if (i + k <= n) dp[i] += dp[i + k];
    }
    int x, y; cin >> x >> y;
    int ans = 2e9;
    for (int i = 1; i <= n - p + 1; i++) {
      ans = min(ans, (i - 1) * y + dp[i + p - 1] * x);
    }
    cout << ans << '\n';
  }
  return 0;
}