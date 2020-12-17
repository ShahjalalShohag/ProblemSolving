#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int a, b, c; cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum % 9 == 0 && min({a, b, c}) >= sum / 9) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}