#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    map<char, int> mp;
    int ans = 0;
    for (auto x: s) {
      if (x == '(' || x == '[') {
        mp[x]++;
      }
      else {
        if (x == ')') {
          if (mp['(']) {
            ans++;
            mp['(']--;
          }
        }        
        else {
          if (mp['[']) {
            ans++;
            mp['[']--;
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}