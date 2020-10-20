#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
      int k = 0;
      while (k * 10 + i < 10000) {
        k = k * 10 + i;
        ans += to_string(k).length();
        if (k == n) {
          break;
        }
      }
      if (k == n) {
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}