#include<bits/stdc++.h>
using namespace std;

const int N = 1505;

string s[N];
bool vis[N][N];
pair<int, int> a[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
void dfs(int u, int v) {
	int x = (u % n + n) % n;
	int y = (v % m + m) % m;
	if (s[x][y] == '#') return;
	if (vis[x][y]) {
		if (a[x][y] != make_pair(u, v)) {
			cout << "Yes\n";
			exit(0);
		}
		return;
	}
	vis[x][y] = 1;
	a[x][y] = {u, v};
	for (int i = 0; i < 4; i++) {
		dfs(u + dx[i], v + dy[i]);
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'S') {
				x = i, y = j;
			}
		}
	}
	dfs(x, y);
	cout << "No\n";
    return 0;
}