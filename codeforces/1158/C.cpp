#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

int a[N], ans[N], T, ok;
vector<int> id[N];
void yo(int l, int r) {
  if (!ok) return;
  vector<pair<int, int>> v;
  int last = l, f = 0;
  for (auto x: id[r + 1]) {
    if (x < l || x > r) {
      ok = 0;
      return;
    }
    f |= x == r;
    ans[x] = T--;
    v.push_back({last, x - 1});
    last = x + 1;
  }
  if (!f) {
    ok = 0;
    return;
  }
  for (auto x: v) {
    if (x.first <= x.second) {
      yo(x.first, x.second);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == -1) {
        a[i] = i + 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      id[a[i]].push_back(i);
    }
    T = n;
    ok = 1;
    yo(1, n);
    if (!ok) cout << -1 << '\n';
    else {
      for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
      }
      cout << '\n';
    }
    for (int i = 1; i <= n + 1; i++) {
      id[i].clear();
    }
  }
  return 0;
}