#include<bits/stdc++.h>
using namespace std;

const int N = 2010;

int d[N];
vector<int> p[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) {
    int k = i;
    for (int j = 2; j <= k; j++) {
      if (k % j == 0) {
        p[i].push_back(j);
        while (k % j == 0) k /= j;
      }
    }
  }
  int a, b, c; cin >> a >> b >> c;
  for (int i = 1; i <= c; i++) {
    for (int j = i; j <= c; j += i) {
      d[i] += c / j;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (__gcd(i, j) == 1) {
        vector<int> v;
        for (auto x: p[i]) v.push_back(x);
        for (auto x: p[j]) v.push_back(x);
        int s = v.size(), cur = 0;
        for (int mask = 0; mask < (1 << s); mask++) {
          int mul = 1, sgn = 1;
          for (int k = 0; k < s; k++) {
            if (mask >> k & 1) {
              mul *= v[k];
              sgn *= -1;
            }
          }
          if (mul <= c) cur += d[mul] * sgn;
        }
        ans += 1LL * (a / i) * (b / j) * cur;
      }
    }
  }
  cout << ans % (1 << 30) << '\n';
  return 0;
}