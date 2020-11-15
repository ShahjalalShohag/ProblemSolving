#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  cout << fixed << setprecision(10) << x1 + 1.0 * y1 * (x2 - x1) / (y1 + y2) << '\n';
  return 0;
}