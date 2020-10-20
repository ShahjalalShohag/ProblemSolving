#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  n /= 2;
  --n;
  long long ans = 1;
  for (int i = 1; i <= 2 * n + 1; i++) {
    if (i != n + 1) {
      ans *= i;
    }
  }
  cout << ans << '\n';
  return 0;
}