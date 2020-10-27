#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int l, r; cin >> l >> r;
    if (2 * l <= r) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
  return 0;
}