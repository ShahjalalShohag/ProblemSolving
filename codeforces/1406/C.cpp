#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int sz[N];
void dfs(int u, int p = 0) {
	sz[u] = 1;
	for (auto v: g[u]) {
		if (v ^ p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i < n; i++) {
		    int u, v; cin >> u >> v;
		    g[u].push_back(v);
		    g[v].push_back(u);
		}
		int u = 1;
		dfs(u);
		while (1) {
			int tmp = -1;
			for (auto v: g[u]) {
				if (sz[v] > sz[u]) continue;
				if (2 * sz[v] >= n) tmp = v;
			}
			if (tmp == -1) break;
			u = tmp;
		}
		dfs(u);
		bool f = 0;
		for (auto v: g[u]) {
			if (2 * sz[v] == n) {
				f = 1;
				assert(g[u].size() > 1);
				int k = g[u][0];
				if (k == v) k = g[u][1];
				cout << u << ' ' << k << '\n';
				cout << v << ' ' << k << '\n';
				break;
			}
		}
		if (!f) {
			cout << 1 << ' ' << g[1][0] << '\n';
			cout << 1 << ' ' << g[1][0] << '\n';
		}
		for (int i = 1; i <= n; i++) g[i].clear();
	}
    return 0;
}