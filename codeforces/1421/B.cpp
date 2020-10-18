#include<bits/stdc++.h>
using namespace std;

string s[300];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<pair<int, int>> v;
    for (int k = 0; k < 2; k++) {
      v.clear();
      if (s[0][1] - '0' != k) {
        v.emplace_back(0, 1);
      }      
      if (s[1][0] - '0' != k) {
        v.emplace_back(1, 0);
      }    
      if (s[n - 2][n - 1] - '0' != 1 - k) {
        v.emplace_back(n - 2, n - 1);
      }     
      if (s[n - 1][n - 2] - '0' != 1 - k) {
        v.emplace_back(n - 1, n - 2);
      }
      if (v.size() <= 2) break;
    }
    cout << v.size() << '\n';
    for (auto x: v) {
      cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    }
  }
  return 0;
}