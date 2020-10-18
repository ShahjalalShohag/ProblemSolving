#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string p = "atcoder";
    string s; cin >> s;
    int n = s.size();
    int ans = n;
    if (s > p) {
      ans = 0;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(s[i], s[j]);
        if (s > p) {
          ans = min(ans, j - i);
        }
        swap(s[i], s[j]);
      }
    }
    if (ans == n) {
      ans = -1;
    }
    cout << ans << '\n';
  }
  return 0;
}