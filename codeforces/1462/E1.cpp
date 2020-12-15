#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      int j = upper_bound(a + i, a + n + 1, a[i] + 2) - a - 1;
      ans += j - i - 1 >= 0 ? 1LL * (j - i - 1) * (j - i) / 2 : 0;
    }
    cout << ans << '\n';
  }
  return 0;
}