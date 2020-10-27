#include<bits/stdc++.h>
using namespace std;

const int N = 420, inf = 1e9;
int dp[N][N], a[N], n;
int yo(int i, int k) {
  if (i == n) {
    return 0;
  }
  if (k > 400) {
    return inf;
  }
  int &ret = dp[i][k];
  if (ret != -1) {
    return ret;
  }
  return ret = min(abs(a[i] - k) + yo(i + 1, k + 1), yo(i, k + 1));
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    memset(dp, -1, sizeof dp);
    cout << yo(0, 1) << '\n';
  }
  return 0;
}