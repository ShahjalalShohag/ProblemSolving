#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      a.push_back({k, i});
    }
    sort(a.begin(), a.end());
    if (a[0].first == a[n - 1].first) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
      for (int i = 0; i < n - 1; i++) {
        if (a[i].first != a[n - 1].first) {
          cout << a[i].second << ' ' << a[n - 1].second << '\n';
        }
      }
      for (int i = n - 2; i >= 0; i--) {
        if (a[i].first == a[n - 1].first) {
          cout << a[i].second << ' ' << a[0].second << '\n';
        }
      }
    }
  }
  return 0;
}