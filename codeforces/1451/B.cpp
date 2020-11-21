#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = "#" + s;
    int pref[n + 2][2], suf[n + 2][2];
    memset(pref, 0, sizeof pref);
    memset(suf, 0, sizeof suf);
    for (int i = 1; i <= n; i++) {
      pref[i][0] = pref[i - 1][0] + (s[i] == '0');
      pref[i][1] = pref[i - 1][1] + (s[i] == '1');
    }    
    for (int i = n; i >= 1; i--) {
      suf[i][0] = suf[i + 1][0] + (s[i] == '0');
      suf[i][1] = suf[i + 1][1] + (s[i] == '1');
    }
    while (q--) {
      int l, r; cin >> l >> r;
      if (pref[l - 1][s[l] - '0'] || suf[r + 1][s[r] - '0']) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}