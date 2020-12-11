#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cout << char('a' + i % 3);
    }
    cout << '\n';
  }
  return 0;
}