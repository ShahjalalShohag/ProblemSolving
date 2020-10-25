#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

vector<int> a[N];
int b[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 6; i++) {
    cin >> b[i];
  }
  int n; cin >> n;
  set<pair<int, int>> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    for (int j = 1; j <= 6; j++) {
      a[i].push_back(x - b[j]);
    }
    sort(a[i].rbegin(), a[i].rend());
    se.insert({a[i].back(), i});
  }
  int ans = 1e9;
  while (1) {
    ans = min(ans, (*se.rbegin()).first - (*se.begin()).first);
    int k = (*se.begin()).second;
    se.erase(se.begin());
    a[k].pop_back();
    if (a[k].empty()) {
      break;
    }
    se.insert({a[k].back(), k});
  }
  cout << ans << '\n';
  return 0;
}