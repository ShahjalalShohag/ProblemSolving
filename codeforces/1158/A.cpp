#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  long long ans = 0;
  int mx = 0, smx = 0;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    if (k > mx) {
      smx = mx;
      mx = k;
    }
    else if (k > smx) {
      smx = k;
    }
    ans += 1LL * k * m;
  }
  int f = 0;
  for (int i = 1; i <= m; i++) {
    int k; cin >> k;
    if (k < mx) {
      cout << -1 << '\n';
      return 0;
    }
    ans += k - mx;
    f += k == mx;
  }
  if (!f) ans += mx - smx;
  cout << ans << '\n';
  return 0;
}