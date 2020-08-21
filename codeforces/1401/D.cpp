#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;

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
		dfs(1);
		vector<long long> v;
		for (int i = 2; i <= n; i++) {
			v.push_back(1LL * sz[i] * (n - sz[i]));
		}
		sort(v.rbegin(), v.rend());
		int m; cin >> m;
		vector<long long> p(m);
		for (auto &x: p) cin >> x;
		sort(p.begin(), p.end());
		long long ans = 0;
		while (p.size() > n - 1) {
			p[(int)p.size() - 2] *= p.back();
			p[(int)p.size() - 2] %= mod;
			p.pop_back();
		}
		for (auto x: v) {
			long long cur = 1;
			if (p.size()) {
				cur = p.back() % mod;
				p.pop_back();
			}
			ans += x % mod * cur;
			ans %= mod;
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) g[i].clear();
	}
    return 0;
}