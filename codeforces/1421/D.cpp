#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    vector<long long> c(6, 0), a(6, 0);
    long long x, y; cin >> x >> y;
    for (int i = 0; i < 6; i++) {
      cin >> c[i];
    }
    auto nxt = [&](int k, int dir) {
      k += dir ? -1 : 1;
      k += 6;
      k %= 6;
      return k;
    };
    for (int i = 0; i < 6; i++) {
      a[i] = c[i];
      for (int j = 0; j < 6; j++) {
        if (i == j) continue;
        for (int dir = 0; dir < 2; dir++) {
          long long cur = c[j];
          int k = j;
          while (k != i) {
            k = nxt(k, dir);
            cur += c[nxt(k, dir)];
          }
          a[i] = min(a[i], cur);
        }
      }
    }
    auto f = [&](long long x, int k) {
      if (!k) {
        if (x < 0) {
          return a[2];
        }
        else {
          return a[5];
        }
      }      
      else {
        if (x < 0) {
          return a[4];
        }
        else {
          return a[1];
        }
      }
    };
    auto solve = [&](long long x, long long y) {
      return abs(x) * f(x, 0) + abs(y) * f(y, 1);
    };
    long long ans = solve(x, y);
    if (x > 0 && y > 0) {
      auto k = min(x, y);
      ans = min(ans, k * a[0] + solve(x - k, y - k));
    }
    if (x < 0 && y < 0) {
      auto k = max(x, y);
      ans = min(ans, -k * a[3] + solve(x - k, y - k));
    }
    cout << ans << '\n';
  }
  return 0;
}