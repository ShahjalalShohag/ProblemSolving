#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ok = 1, a = 1e9, b = 0;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      int d = min(a, k - b);
      if (d < 0) {
        ok = 0;
      }
      a = d;
      b = k - a;
    }
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}