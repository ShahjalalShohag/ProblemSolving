#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; n > 0; i++) {
      n -= i;
      ++ans;
    }
    if (n == -1) ++ans;
    cout << ans << '\n';
  }
  return 0;
}