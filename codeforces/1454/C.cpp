#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      mp[k]++;
      a[i] = k;
      if (i && a[i - 1] == k) {
        mp[k]--;
      }
    }
    int ans = n + 1;
    for (auto x: mp) {
      ans = min(ans, max(0, x.second + 1 - (a[0] == x.first) - (a[n - 1] == x.first)));
    }
    cout << ans << '\n';
  }
  return 0;
}