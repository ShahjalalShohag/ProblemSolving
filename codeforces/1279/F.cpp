#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

long long dp[N];
int cnt[N], a[N], n, l, k;
pair<long long, int> yo(int c) {
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + a[i];
    cnt[i] = cnt[i - 1];
    long long cur = dp[max(0, i - l)] + c;
    if (cur < dp[i]) {
      dp[i] = cur;
      cnt[i] = cnt[max(0, i - l)] + 1;
    }
    else if (cur == dp[i]) {
      cnt[i] = min(cnt[i], cnt[max(0, i - l)] + 1);
    }
  }
  return {dp[n], cnt[n]};
}
int solve() {
  int l = 0, r = 1e6 + 10;
  long long ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    auto cur = yo(mid);
    if (cur.second <= k) {
      ans = cur.first - 1LL * k * mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> l;
  k = min(k, n - l + 1);
  string s; cin >> s;
  for (int i = 0; i < n; i++) {
    a[i + 1] = s[i] >= 'a' && s[i] <= 'z';
  }
  int ans = solve();
  for (int i = 1; i <= n; i++) {
    a[i] ^= 1;
  }
  ans = min(ans, solve());
  cout << ans << '\n';
  return 0;
}