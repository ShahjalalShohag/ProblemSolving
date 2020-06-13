#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<int> g[N];
int dep[N], k, par[N], vis[N];
void dfs(int u, int p = 0) {
	par[u] = p; vis[u] = 1;
	dep[u] = dep[p] + 1;
	int mn = N, en;
	for (auto v: g[u]) if (v != p) {
		if (vis[v]) {
			int cyc = dep[u] - dep[v] + 1;
			if (cyc < mn) mn = cyc, en = v;
		}
		else dfs(v, u);
	}
	if (mn != N) {
		vector<int> v;
		while (u != en) {
			v.push_back(u);
			u = par[u];
			assert(u != 0);
		}
		v.push_back(en);
		if (mn <= k) {
			cout << 2 << '\n' << mn << '\n';
			for (auto x: v) cout << x << ' '; cout << '\n';
		}
		else {
			vector<int> ans;
			for (int i = 0; i + 1 < v.size(); i += 2) ans.push_back(v[i]);
			assert(ans.size() >= (k + 1) / 2);
			cout << 1 << '\n';
			for (int i = 0; i < (k + 1) / 2; i++) cout << ans[i] << ' '; cout << '\n';
		}
		exit(0);
	}
}
vector<int> col[2];
void dfs2(int u, int p = 0, int c = 0) {
	col[c].push_back(u);
	for (auto v: g[u]) if (v != p) dfs2(v, u, c ^ 1);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
	    int u, v; cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	int z = rnd() % n + 1;
	dfs(z);
	dfs2(z);
	if (col[1].size() > col[0].size()) swap(col[0], col[1]);
	assert(col[0].size() >= (k + 1) / 2);
	cout << 1 << '\n';
	for (int i = 0; i < (k + 1) / 2; i++) cout << col[0][i] << ' '; cout << '\n';
    return 0;
}