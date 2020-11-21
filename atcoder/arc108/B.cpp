#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  string cur = "";
  for (int i = 0; i < n; i++) {
    cur += s[i];
    while (cur.size() >= 3) {
      int k = cur.size();
      if (cur.substr(k - 3) == "fox") {
        cur.pop_back();
        cur.pop_back();
        cur.pop_back();
      }
      else break;
    }
  }
  cout << cur.size() << '\n';
  return 0;
}