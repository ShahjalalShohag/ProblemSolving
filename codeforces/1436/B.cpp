#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (j >= i && j < i + 3) {
          cout << 1 << ' ';
        }
        else if (i == n && j == 1) {
          cout << 1 << ' ';
        }
        else {
          cout << 0 << ' ';
        }
      }
      cout << '\n';
    }
  }
  return 0;
}