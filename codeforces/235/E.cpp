#include<bits/stdc++.h>
using namespace std;

const int N = 2010;

int d[N], mob[N], f[N * N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c; cin >> a >> b >> c;
  mob[1] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      mob[j] -= mob[i];
    }
  }
  for (int i = 1; i <= c; i++) {
    for (int j = i; j <= c; j += i) {
      d[i] += c / j;
    }
  }
  for (int i = 1; i < N; i++) {
    if (mob[i] == 0) continue;
    for (int j = i; j < N * N; j += i) {
      f[j] += mob[i] * d[i];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (__gcd(i, j) == 1) {
        ans += 1LL * (a / i) * (b / j) * f[i * j];
      }
    }
  }
  cout << ans % (1 << 30) << '\n';
  return 0;
}