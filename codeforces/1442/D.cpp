#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

const int N = 3005;
long long dp[N][N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  for (int p = 1; p <= n; p++) {
    int x; cin >> x;
    long long s = 0;
    for (int j = 1; j <= k; j++) {
      dp[p][j] = dp[p - 1][j];
    }
    for (int i = 1; i <= x; i++) {
      int z; cin >> z;
      s += z;
      for (int j = i; j <= k; j++) {
        long long cur = dp[p - 1][j - i] + s;
        dp[p][j] = cur > dp[p][j] ? cur : dp[p][j];
      }
    }
  }
  cout << dp[n][k] << '\n';
  return 0;
}