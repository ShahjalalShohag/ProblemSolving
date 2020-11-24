#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> mp, id;
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      mp[k]++;
      id[k] = i;
    }
    int ans = -1;
    for (auto x: mp) {
      if (x.second == 1) {
        ans = id[x.first] + 1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}