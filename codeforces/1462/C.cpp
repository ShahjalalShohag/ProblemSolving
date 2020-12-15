#include<bits/stdc++.h>
using namespace std;

long long ans[55];
void dfs(long long cur, int sum, int mask) {
  if (sum > 50) return;
  ans[sum] = min(ans[sum], cur);
  for (int i = 1; i <= 9; i++) {
    if ((mask >> i & 1) == 0) dfs(cur * 10 + i, sum + i, mask | 1 << i);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i <= 50; i++) ans[i] = 2e18;
  dfs(0, 0, 0);
  int t; cin >> t;
  while (t--) {
    int k; cin >> k;
    cout << (ans[k] == 2e18? -1 : ans[k]) << '\n';
  }
  return 0;
}