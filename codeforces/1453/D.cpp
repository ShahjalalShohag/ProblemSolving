#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    if (n & 1) {
      cout << -1 << '\n';
      continue;
    }
    bool f = false;
    for (int len = 1; len <= 200; len++) {
      long long p = n + len * 2;
      if (p % 4) continue;
      multiset<int> se;
      int on = 0;
      for (int i = 60; i >= 2; i--) {
        if (p >> i & 1) {
          if (i - 1 > 1) se.insert(i - 1);
          else on++;
        }
      }
      while (!se.empty() && on + se.size() < len) {
        auto it = se.begin();
        int k = *it;
        se.erase(it);
        if (k == 2) {
          on += 2;
        }
        else {
          se.insert(k - 1);
          se.insert(k - 1);
        }
      }
      while (on--) se.insert(1);
      if (se.size() == len) {
        vector<int> v({1});
        for (auto x: se) {
          for (int j = 1; j < x; j++) {
            v.push_back(0);
          }
          v.push_back(1);
        }
        v.pop_back();
        if (v.size() <= 2000) {
          cout << v.size() << '\n';
          for (auto x: v) cout << x << ' ';
          cout << '\n';
          f = true;
          break;
        }
      }
    }
    if (!f) {
      cout << -1 << '\n';
    }
  }
  return 0;
}