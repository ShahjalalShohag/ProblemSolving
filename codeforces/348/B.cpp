#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
const long long inf = 2e18;

long long mul(long long a, long long b) {
  if (a == 0 || b == 0 || a <= inf / b) return a * b;
  return inf;
}
long long dp[N], a[N];
vector<int> g[N];
int leaf[N];
void dfs(int u, int p = 0) {
  dp[u] = mul(dp[p], u == 1 ? g[u].size() : max(1, (int)g[u].size() - 1));
  leaf[u] = 1;
  for (auto v: g[u]) {
    if (v ^ p) {
      leaf[u] = 0;
      dfs(v, u);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dp[0] = 1;
  dfs(1);
  long long cur = inf, lc = 1, s = 0;
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (leaf[i]) {
      ok &= dp[i] < inf;
      s += a[i];
      cur = min(cur, mul(dp[i], a[i]));
      long long g = __gcd(lc, dp[i]);
      lc = mul(lc / g, dp[i]);
    }
  }
  long long ans = s;
  if (ok && cur < inf && lc <= cur) {
    long long x = cur - cur % lc;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      if (leaf[i]) {
        ok &= (x / dp[i]) <= a[i];
        ans += a[i] - x / dp[i];
      }
    }
    if (!ok) ans = s;
  }
  cout << ans << '\n';
  return 0;
}