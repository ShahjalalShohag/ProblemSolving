#include<bits/stdc++.h>
using namespace std;

#define int long long
vector<array<int, 3>> op;
void transform(int a, int b) { 
  assert(b % a == 0);
  int k = b / a;
  for (int i = 1; i < k; i *= 2) {
    op.push_back({i * a, i * a, 0});
  }
  int sum = 0;
  for (int i = 0; i < 60; i++) {
    if (k >> i & 1) {
      if (sum == 0) {
        sum += (1LL << i) * a;
      }
      else {
        op.push_back({sum, (1LL << i) * a, 0});
        sum += (1LL << i) * a;
      }
    }
  }
}
void yo(int a, int b, int n) {
  for (int i = 1; i <= a; i++) {
    int rem = n - i * b;
    if (rem % a == 0) {
      transform(a, rem);
      transform(b, i * b);
      op.push_back({rem, i * b, 0});
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x; cin >> x;
  for (int i = 1; ; i++) {
    int y = x ^ (i * x);
    if (__gcd(x, y) == 1) {
      transform(x, i * x);
      op.push_back({x, i * x, 1});
      int k = 0;
      while ((1LL << k) <= x * y) {
        ++k;
      }
      yo(x, y, (1LL << k));
      yo(x, y, (1LL << k) + 1);
      op.push_back({(1LL << k), (1LL << k) + 1, 1});
      break;
    }
  }
  cout << op.size() << '\n';
  assert(op.size() <= 100000);
  for (auto x: op) {
    cout << x[0] << ' ' << (x[2] == 0 ? '+' : '^') << ' ' << x[1] << '\n';
  }
  return 0;
}