#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      a[i] = a[i - 1] + (!k);
      if (k) {
        if (!l) {
          l = i;
        }
        r = i;
      }
    }
    cout << a[r] - a[l] << '\n';
  }
  return 0;
}