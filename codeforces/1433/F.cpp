#include<bits/stdc++.h>
using namespace std;

const int N = 71;
int dp[N][N][N][N], a[N][N];
bool vis[N][N][N][N];
int n, m, k; 
int yo(int i, int j, int c, int mod) {
  if (i == n) {
    return mod == 0 ? 0 : -10000000;
  }
  if (vis[i][j][c][mod]) {
    return dp[i][j][c][mod];
  }
  vis[i][j][c][mod] = 1;
  int ni = i, nj = j + 1;
  if (j == m - 1) {
    ni = i + 1;
    nj = 0;
  }
  int ret = yo(ni, nj, (nj == 0 ? 0 : c), mod);
  if (c < m / 2) {
    ret = max(ret, a[i][j] + yo(ni, nj, (nj == 0 ? 0 : c + 1), (mod + a[i][j]) % k));
  }
  return dp[i][j][c][mod] = ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  cout << max(0, yo(0, 0, 0, 0)) << '\n';
  return 0;
}