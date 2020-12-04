#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    set<int> se;
    while (n--) {
      int k; cin >> k;
      se.insert(k);
    }
    int ans = 0;
    while (m--) {
      int k; cin >> k;
      if (se.find(k) != se.end()) ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}