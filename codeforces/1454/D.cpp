#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    long long p, mx = 0, x = n;
    int it = 0;
    for (long long i = 2; i * i <= n; i++) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        ++cnt;
      }
      if (cnt > mx) {
        mx = cnt;
        p = i;
      }
    }
    if (n > 1) {
      if (mx == 0) {
        mx = 1;
        p = n;
      }
    }
    cout << mx << '\n';
    mx--;
    while (mx--) {
      cout << p << ' ';
      x /= p;
    }
    cout << x << '\n';
  }
  return 0;
}