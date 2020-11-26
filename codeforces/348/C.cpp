#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, B = 320;

long long lazy[N], a[N], sum[N], st[N];
vector<int> id[N];
int f[N], cnt[N][B + 1];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q; cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> heavy;
  for (int i = 1; i <= m; i++) {
    int k; cin >> k;
    if (k >= B) {
      heavy.push_back(i);
    }
    while (k--) {
      int x; cin >> x;
      id[i].push_back(x);
      st[i] += a[x];
    }
  }
  for (int j = 0; j < heavy.size(); j++) {
    int k = heavy[j];
    for (auto x: id[k]) {
      f[x] = 1;
    }
    for (int i = 1; i <= m; i++) {
      for (auto x: id[i]) {
        cnt[i][j] += f[x];
      }
    }
    for (auto x: id[k]) {
      f[x] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] = 0;
  }
  while (q--) {
    char ty; cin >> ty;
    if (ty == '?') {
      int k; cin >> k;
      long long ans = st[k];
      if (id[k].size() >= B) {
        ans += sum[k];
      }
      else {
        for (auto x: id[k]) {
          ans += a[x];
        }
      }
      for (int j = 0; j < heavy.size(); j++) {
        ans += lazy[heavy[j]] * cnt[k][j];
      }
      cout << ans << '\n';
    }
    else {
      int k, x; cin >> k >> x;
      if (id[k].size() >= B) {
        lazy[k] += x;
      }
      else {
        for (auto p: id[k]) {
          a[p] += x;
        }
        for (int j = 0; j < heavy.size(); j++) {
          sum[heavy[j]] += 1LL * x * cnt[k][j];
        }
      }
    }
  }
  return 0;
}