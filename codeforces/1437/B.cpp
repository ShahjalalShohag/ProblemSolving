#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += s[i] == s[i - 1];
    }
    cout << (ans + 1) / 2 << '\n';
  }
  return 0;
}