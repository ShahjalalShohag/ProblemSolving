#include<bits/stdc++.h>
using namespace std;

long long yo(int n, int k, vector<int> a) {
  if (k == 1) a[k] = a[k + 1];
  else a[k] = a[k - 1];
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += abs(a[i] - a[i - 1]);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (i > 1) cur += abs(a[i] - a[i - 1]);
    }
    long long ans = cur;
    for (int i = 2; i < n; i++) {
      ans = min(ans, cur - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i - 1]));
    }
    ans = min(ans, yo(n, 1, a));
    ans = min(ans, yo(n, n, a));
    cout << ans << '\n';
  }
  return 0;
}