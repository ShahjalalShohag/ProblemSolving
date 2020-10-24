#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  if (n == 1) {
    if (m == 0) {
      cout << 1 << ' ' << 2 << '\n';
    }
    else {
      cout << -1 << '\n';
    }
    return 0;
  }
  if (m >= 0 && m <= n - 2) {
    for (int i = 1; i < n; i++) {
      cout << 10 * i << ' ' << 10 * i + 1 << '\n';
    }
    int d = n - 2 - m;
    cout << 1 << ' ' << 10 * (n - 1 - d) + 2 << '\n';
  }
  else {
    cout << -1 << '\n';
  }
  return 0;
}