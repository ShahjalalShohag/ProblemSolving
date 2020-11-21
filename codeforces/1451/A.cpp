#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n <= 3) cout << n - 1 << '\n';
    else cout << 2 + n % 2 << '\n';
  }
  return 0;
}