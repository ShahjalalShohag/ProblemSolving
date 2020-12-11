#include<bits/stdc++.h>
using namespace std;

using T = __int128;
// ax + by = __gcd(a, b)
// returns __gcd(a, b)
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = y = 0;
  T yy = x = 1;
  while (b) {
    T q = a / b;
    T t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}

// find z such that z % x = a, z % y = b. 
// here, z is unique modulo M = lcm(x,y).
// returns (z, M). on failure, M = -1.
pair<T, T> CRT(T x, T a, T y, T b) {
  T s, t;
  T d = extended_euclid(x, y, s, t);
  if (a % d != b % d) return make_pair(0, -1);
  T m = x * y;
  s %= m; s = (s + m) % m;
  t %= m; t = (t + m) % m;
  return make_pair((s * b % m * x % m + t * a % m * y % m) %  m / d, m / d);
}

// chinese remainder theorem: find z such that z % x[i] = a[i] for all i. 
// note that the solution is unique modulo M = lcm_i (x[i]). 
// returns (z, M). on failure, M = -1. 
// note that we do not require the a[i]'s to be relatively prime.
pair<long long, long long> CRT(vector<long long> &x, vector<long long> &a) {
  pair<long long, long long> ret = make_pair(a[0], x[0]);
  for (int i = 1; i < x.size(); i++) {
    ret = CRT(ret.second, ret.first, x[i], a[i]);
    if (ret.second == -1) break;
  }
  return ret;
}
const long long inf = 1e18;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m; cin >> n >> m;
  int k; cin >> k;
  long long lc = 1;
  vector<long long> a(k), b(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    b[i] = ((a[i] - i) % a[i] + a[i]) % a[i];
    long long g = __gcd(lc, a[i]);
    lc /= g;
    if (lc <= inf / a[i]) lc *= a[i];
    else lc = inf;
  }
  if (lc > n) {
    cout << "NO\n"; return 0;
  }
  auto p = CRT(a, b);
  if (p.second == -1) {
    cout << "NO\n";
    return 0;
  }
  if (p.first == 0) {
    p.first += lc;
  }
  for (long long j = p.first; j <= p.first + k - 1; j++) {
    if (j > m || __gcd(lc, j) != a[j - p.first]) {
      cout << "NO\n"; return 0;
    }
  }
  cout << "YES\n";
  return 0;
}