#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, inf = 1e9 + 1;

set<int> se;
void yo(vector<int> &a) {
  if (a.empty()) return;
  long long sum = 0;
  int mn = inf, mx = 0;
  for (auto x: a) {
    sum += x;
    mn = min(mn, x);
    mx = max(mx, x);
  }
  if (sum <= inf) se.insert(sum);
  if (mn == mx) return;
  if (a.size() == 1) return;
  vector<int> l, r;
  int mid = (mn + mx) >> 1;
  for (auto x: a) {
    if (x <= mid) {
      l.push_back(x);
    }
    else {
      r.push_back(x);
    }
  }
  yo(l);
  yo(r);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto &x: a) {
      cin >> x;
    }
    se.clear();
    yo(a);
    while (q--) {
      int k; cin >> k;
      if (se.find(k) != se.end()) {
        cout << "Yes\n";
      }
      else {
        cout << "No\n";
      }
    }
  }
  return 0;
}