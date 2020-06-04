#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

vector<int> g[N];
int ans[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
	    int u, v; cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		v.push_back({k, i});
	}
	sort(v.begin(), v.end());
	for (auto x: v) {
		int u = x.second;
		set<int> se;
		for (auto v: g[u]) {
			se.insert(ans[v]);
		}
		int k = 1; 
		while (se.find(k) != se.end()) k++;
		if (k != x.first) return cout << -1 << '\n', 0;
		ans[u] = k;
	}
	for (auto x: v) cout << x.second << ' '; cout << '\n';
    return 0;
}