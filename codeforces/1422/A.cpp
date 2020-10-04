#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    vector<int> a(3);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    cout << a[1] + a[2] - a[0] << '\n';
  }
  return 0;
}