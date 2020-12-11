#include<bits/stdc++.h>
using namespace std;

long long l, r, t, x, y;
set<long long> vis;
void yo(long long k) {
  if (t <= 0 || vis.find(k) != vis.end()) {
    cout << "Yes\n";
    exit(0);
  }
  vis.insert(k);
  long long L = (k - l) / x;
  long long R = (r - (k - L * x)) / y;
  R = min(R, L);
  t -= L;
  long long nxt = k - L * x + R * y;
  if (!L && k == nxt) {
    return;
  }
  yo(nxt);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long k; cin >> k >> l >> r >> t >> x >> y;
  if (k + y <= r) k += y;
  yo(k);
  cout << "No\n";
  return 0;
}