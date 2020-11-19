#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    multiset<int> se;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      se.insert(a[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      se.erase(se.find(a[i]));
      int mx = *se.rbegin();
      long long cur = 1LL * mx * (n - 1) - (sum - a[i]);
      if (a[i] <= cur) cur -= a[i];
      else cur = ((n - 1) - (a[i] - cur) % (n - 1)) % (n - 1);
      se.insert(a[i]);
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}