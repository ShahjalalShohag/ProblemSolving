#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int ans = 0;
  while (n--) {
    int k; cin >> k;
    ans = __gcd(ans, k);
  }
  cout << ans << '\n';
  return 0;
}