#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, a[N][N], d[N][N];
void dfs(int i, int j) {
  int f = 0;
  for (int k = 0; k < 4; k++) {
    int ni = i + dx[k];
    int nj = j + dy[k];
    if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
      if (a[ni][nj] == a[i][j]) {
        f = 1;
      }
    }
  }
  if (f == 0) return;
  if (d[i][j] == 1) a[i][j]--, d[i][j]--;
  else a[i][j]++, d[i][j]++;
  for (int k = 0; k < 4; k++) {
    int ni = i + dx[k];
    int nj = j + dy[k];
    if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
      if (a[ni][nj] == a[i][j]) {
        dfs(ni, nj);
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    memset(d, 0, sizeof d);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dfs(i, j);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}