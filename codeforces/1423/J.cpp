#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int yo(long long n, int i) {
  if (i == -1) return n == 0;
  int ans = 0;
  for (int k = 0; k <= 7; k++) {
    if (n - (1LL << i) * k >= 0) {
      ans += yo(n - (1LL << i) * k, i - 1);
    }
  }
  return ans;
}
long long f(long long n) {
  if (n % 2 == 0) return n / 2 % mod * ((n + 1) % mod) % mod;
  return (n + 1) / 2 % mod * (n % mod) % mod;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
/*  for (int i = 1; i <= 100; i++) {
    cout << yo(i, 20) - yo(i - 1, 20) << '\n';
  }*/
  int t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }    
    if (n == 2) {
      cout << 2 << '\n';
      continue;
    }
    long long k = n;
    while (n % 4 != 2) n--;
    long long ans = f(n / 4 + 1) * 2 % mod;
    ++n;
    while (n <= k) {
      ans += n % 2 == 0 ? n / 4 + 1 : 0;
      ans %= mod;
      ++n;
    }
    cout << ans % mod << '\n';
  }
  return 0;
}