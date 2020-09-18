#include<bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

struct dsu {
	vector<int> par, rnk, size; int c;
	dsu(int n) : par(n+1), rnk(n+1,0), size(n+1,1), c(n) {
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; } //connected components
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1; else --c;
		if (rnk[i] > rnk[j]) swap(i, j);
		par[i] = j; size[j] += size[i];
		if (rnk[i] == rnk[j]) rnk[j]++;
		return j;
	}
};

const int N = 1e5 + 9;

long long d[N];
int near[N], vis[N];
vector<pair<int, int>> g[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	vector<array<long long, 3>> edges, ed;
	for (int i = 1; i <= m; i++) {
	    int u, v, w; cin >> u >> v >> w;
	    g[u].push_back({v, w});
	    g[v].push_back({u, w});
	    edges.push_back({u, v, w});
	}
	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}
	int k; cin >> k;
	set<pair<long long, int>> se;
	for (int i = 1; i <= k; i++) {
		int u; cin >> u;
		se.insert({0, u});
		near[u] = u;
		d[u] = 0;
	}
	while (!se.empty()) {
		auto x = *se.begin();
		se.erase(se.begin());
		int u = x.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto e: g[u]) {
			int v = e.first, w = e.second;
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				near[v] = near[u];
				se.insert({d[v], v});
			}
		}
	}
	for (auto e: edges) {
		if (near[e[0]] == near[e[1]]) continue;
		ed.push_back({d[e[0]] + d[e[1]] + e[2], near[e[0]], near[e[1]]});
	}
	sort(ed.begin(), ed.end());
	dsu D(n);
	long long ans = d[1];
	for (auto e: ed) {
		int u = e[1], v = e[2];
		long long w = e[0];
		if (D.same(u, v)) continue;
		ans += w;
		D.merge(u, v);
	}
	cout << ans << '\n';
    return 0;
}