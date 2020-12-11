#include<bits/stdc++.h>
using namespace std;

int yo(vector<int> a) {
  int n = a.size();
  vector<int> r(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    r[i] = min(a[i], r[i + 1] + 1);
  }
  int ans = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    cur = min(cur + 1, a[i]);
    ans += min(cur, r[i]);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      vector<int> a(m, 0);
      for (int j = 0; j < m; j++) {
        for (int k = i; k >= 0; k--) {
          if (s[k][j] != '*') break;
          a[j]++;
        }
      }
      ans += yo(a);
    }
    cout << ans << '\n';
  }
  return 0;
}