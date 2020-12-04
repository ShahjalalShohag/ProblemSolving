#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int dp[N][N], nxt[N], a[N], b[N], n, m;
vector<int> id[N];
int yo(int i, int p) {
  if (i > n || p >= m) return 0;
  int &ret = dp[i][p];
  if (ret != -1) return ret;
  ret = yo(i + 1, p);
  if (a[i] > b[p]) {
    for (auto x: id[i]) {
      if (x > p) {
        ret = max(ret, 1 + yo(i + 1, x));
      }
    }
  }
  return ret;
}
int ans;
void dfs(int i, int p) {
  if (!ans) return;
  if (yo(i + 1, p) == ans) {
    dfs(i + 1, p);
    return;
  }
  cout << a[i] << ' ';
  for (auto x: id[i]) {
    if (x > p) {
      if (yo(i + 1, x) == ans - 1) {
        ans--;
        dfs(i + 1, x);
        return;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }  
  cin >> m;
  b[0] = -1;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        id[i].push_back(j);
      }
    }
  }
  memset(dp, -1, sizeof dp);
  ans = yo(1, 0);
  cout << ans << '\n';
  dfs(1, 0);
  return 0;
}