#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    if (n > m) swap(n, m);
    cout << 2 * n + max(0, 2 * (m - n) - 1) << '\n';
  }
  return 0;
}