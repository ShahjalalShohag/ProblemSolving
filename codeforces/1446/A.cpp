#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; long long w; cin >> n >> w;
    vector<pair<int, int>> v;
    vector<int> ans;
    int f = -1;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      if (k >= (w + 1) / 2 && k <= w) {
        f = i;
      }
      v.push_back({k, i});
    }
    if (f != -1) {
      cout << 1 << '\n' << f << '\n';
    }
    else {
      sort(v.begin(), v.end());
      vector<int> ans;
      long long sum = 0;
      for (auto x: v) {
        sum += x.first;
        ans.push_back(x.second);
        if (sum >= (w + 1) / 2) break;
      }
      if (sum >= (w + 1) / 2 && sum <= w) {
        cout << ans.size() << '\n';
        for (auto x: ans) {
          cout << x << ' ';
        }
        cout << '\n';
      }
      else {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}