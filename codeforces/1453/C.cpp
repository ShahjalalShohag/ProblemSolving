#include<bits/stdc++.h>
using namespace std;

int yo(vector<string> &s, int n, int d) {
  vector<int> r(n, 0);
  for (int i = 0; i < n; i++) {
    for (auto x: s[i]) {
      r[i] += (x - '0') == d;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!r[i]) continue;
    int mn = n - 1, mx;
    for (int j = 0; j < n; j++) {
      if ((s[i][j] - '0') == d) {
        mn = min(mn, j);
        mx = j;
      }
    }
    int p = max(mx, n - mn - 1);
    for (int j = 0; j < n; j++) {
      if (j != i) {
        ans = max(ans, (mx - mn) * abs(i - j));
        if (r[j]) ans = max(ans, p * abs(i - j));
      }
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<string> s(n), p(n, string(n, ' '));
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < n; j++) {
        p[j][i] = s[i][j];
      }
    }
    for (int d = 0; d < 10; d++) {
      cout << max(yo(s, n, d), yo(p, n, d)) << ' ';
    }
    cout << '\n';
  }
  return 0;
}