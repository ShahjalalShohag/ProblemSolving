#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ans = -1, mx = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == mx) {
        int ok = 0;
        if (i != 1 && a[i - 1] != mx) {
          ok = 1;
        }
        if (i != n && a[i + 1] != mx) {
          ok = 1;
        }
        if (ok) {
          ans = i;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}