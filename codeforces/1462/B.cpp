#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int ok = 0;
    for (int i = 0; i <= 4; i++) {
      string cur = s.substr(0, i);
      cur += s.substr(n - (4 - i));
      if (cur == "2020") {
        ok = 1;
      }
    }
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}