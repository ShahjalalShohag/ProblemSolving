#include<bits/stdc++.h>
using namespace std;

const int N = 55;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;
string s[N];
bool vis[N][N];
void dfs(int i, int j) {
	if (vis[i][j]) return;
	vis[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int ni = i + dx[k], nj = j + dy[k];
		if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] != '#') dfs(ni, nj);
	}
}
int yo() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'B') {
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] == '.') s[ni][nj] = '#';
				}
			}
		}
	}
	memset(vis, 0, sizeof vis);
	if (s[n - 1][m - 1] != '#') dfs(n - 1, m - 1);
	int ok = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'G' && !vis[i][j]) ok = 0;
			if (s[i][j] == 'B' && vis[i][j]) ok = 0;
		}
	}
	return ok;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		if (yo()) cout << "Yes\n";
		else cout << "No\n";
	}
    return 0;
}