#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin >> n;
  long long a = 1;
  for (int i = 1; a <= n; i++) {
    a *= 3;
    long long b = 1;
    for (int j = 1; a + b <= n; j++) {
      b *= 5;
      if (a + b == n) {
        cout << i << ' ' << j << '\n';
        return 0;
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}