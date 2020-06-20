#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 9, LG = 15;

vector<int> g[N];
int par[N][LG + 1], dep[N];
void dfs(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v: g[u]) if (v != p) {
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
    if (u == v) return u;
    for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}
int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}
pair<int, int> query(vector<int> v) {
	cout << "? " << v.size();
	for (auto x: v) cout << " " << x;
	cout << '\n';
	cout.flush();
	int u, d; cin >> u >> d;
	return {u, d};
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
		vector<int> vec;
		for (int i = 1; i <= n; i++) vec.push_back(i);
		auto z = query(vec);
		int u = z.first, f = z.second;
		dfs(u);
		int l = 1, r = 0, v = 1;
		for (int i = 1; i <= n; i++) r = max(r, dep[i]);
		l = (f + 1) / 2, r = min(r, f + 1);
		while (l <= r) {
			int mid = l + r >> 1;
			vector<int> cur;
			for (int i = 1; i <= n; i++) {
				if (dep[i] == mid) cur.push_back(i);
			}
			auto nw = query(cur);
			if (nw.second == f) {
				v = nw.first; l = mid + 1;
			}
			else r = mid - 1;
		}
		vector<int> cur;
		for (int i = 1; i <= n; i++) if (dist(i, v) == f) {
			cur.push_back(i);
		}
		auto nw = query(cur);
		cout << "! " << v << ' ' << nw.first << '\n';
		cout.flush();
		string s; cin >> s;
		for (int i = 1; i <= n; i++) g[i].clear();
	}
    return 0;
}