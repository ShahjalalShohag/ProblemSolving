#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin >> n;
  ++n;
  n *= 2;
  long long p = sqrtl(n * 1.0);
  while (p * (p + 1) <= n) ++p;
  while (p * (p + 1) > n) --p;
  cout << n / 2 - p << '\n';
  return 0;
}