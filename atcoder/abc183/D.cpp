#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

long long a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x, y, z; cin >> x >> y >> z;
    a[x] += z;
    a[y] -= z;
  }
  for (int i = 0; i < N; i++) {
    if (i) {
      a[i] += a[i - 1];
    }
    if (a[i] > k) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}