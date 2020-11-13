#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

long long p[N], a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  set<pair<long long, int>> se;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
    auto it = se.rbegin();
    while (it != se.rend()) {
      auto x = *it;
      if (p[i] - a[i] * 2 <= x.first) {
        if ((a[x.second] ^ a[i]) == (p[i] - p[x.second - 1] - a[i] - a[x.second])) {
          ans++;
        }
      }
      else break;
      ++it;
    }
    if (i >= 2) {
      se.insert({p[i - 2] + a[i - 1] * 2, i - 1});
    }
  }
  cout << ans << '\n';
  return 0;
}