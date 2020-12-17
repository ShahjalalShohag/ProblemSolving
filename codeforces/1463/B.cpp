#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<long long> sum(2, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i % 2] += a[i];
    }
    int best = sum[0] < sum[1];
    for (int i = 1; i <= n; i++) {
      if (i % 2 == best) {
        cout << a[i] << ' ';
      }
      else {
        cout << 1 << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}