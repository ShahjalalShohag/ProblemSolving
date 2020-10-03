#include<bits/stdc++.h>
using namespace std;

const int N = 102;
int dp[N][N * N * N / 2], m[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, mod; cin >> n >> k >> mod;
  int sum = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    sum += i;
    memset(m, 0, sizeof m);
    for (int s = 0; s <= sum * k; s++) {
      int c = s % i;
      m[c] += dp[i - 1][s];
      if (m[c] >= mod) m[c] -= mod;
      if (s - i * (k + 1) >= 0) {
        m[c] -= dp[i - 1][s - i * (k + 1)];
        if (m[c] < 0) m[c] += mod;
      }
      dp[i][s] = m[c];
    }
  }
  sum = 0;
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    sum += i;
    for (int s = 0; s <= sum * k; s++) {
      ans += 1LL * dp[i - 1][s] * dp[n - i][s] % mod;
      if (ans >= mod) ans -= mod;
    }
    ans = 1LL * ans * (k + 1) % mod;
    ans--;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
  }
  return 0;
}