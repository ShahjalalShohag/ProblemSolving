#include<bits/stdc++.h>
using namespace std;

int a[4];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  for (int mask = 1; mask < (1 << 4); mask++) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      if (mask >> i & 1) {
        sum += a[i];
      }
      else {
        sum -= a[i];
      }
    }
    if (sum == 0) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}