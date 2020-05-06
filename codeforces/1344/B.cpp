#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int r[N], c[N], dr[N], dc[N];
string s[N];
int n, m, vis[N][N];
void dfs(int u, int v) {
	if (vis[u][v]) return;
	vis[u][v] = 1;
	for (int i = 0; i < 4; i++) {
		int nu = u + dx[i];
		int nv = v + dy[i];
		if (nu >= 0 && nu < n && nv >= 0 && nv < m && s[nu][nv] == '#') {
			dfs(nu, nv);
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') r[i]++, c[j]++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (r[i]) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '#') {
					while (j < m && s[i][j] == '#') cnt++, j++;
					break;
				}
			}
			if (cnt != r[i]) return cout << -1 << '\n', 0;
		}
	}	
	for (int j = 0; j < m; j++) {
		if (c[j]) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (s[i][j] == '#') {
					while (i < n && s[i][j] == '#') cnt++, i++;
					break;
				}
			}
			if (cnt != c[j]) return cout << -1 << '\n', 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (r[i] == 0 && c[j] == 0) dr[i] = 1, dc[j] = 1;
			else if (s[i][j] == '#') dr[i] = 1, dc[j] = 1;
		}
	}
	for (int i = 0; i < n; i++) if (!dr[i]) return cout << - 1<< '\n', 0;
	for (int i = 0; i < m; i++) if (!dc[i]) return cout << - 1<< '\n', 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#' && !vis[i][j]) {
				ans ++;
				dfs(i, j);
			}
		}
	}
	cout << ans << '\n';
    return 0;
}