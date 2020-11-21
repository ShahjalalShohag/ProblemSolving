#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m; cin >> n >> m;
  for (long long i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      if (i + m / i == n) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}