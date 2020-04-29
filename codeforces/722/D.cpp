#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
struct Kuhn {
	int n; vector<vector<int>> g;
	vector<int> l, r; vector<bool> vis;
	Kuhn(int _n, int _m) {
		n = _n;
		g.resize(n + 1); vis.resize(n + 1, false);
		l.resize(n + 1, -1); r.resize(_m + 1, -1);
	}
	void add_edge(int a, int b) {
		g[a].push_back(b);
	}
	bool yo(int u) {
		if (vis[u])  return false;
		vis[u] = true;
		for (auto v : g[u]) {
			if (r[v] == -69) continue;
			if (r[v] == -1 || yo(r[v])) {
				l[u] = v;
				r[v] = u;
				return true;
			}
		}
		return false;
	}
	int maximum_matching() {
		bool ok = true;
		while (ok) {
			ok = false;
			vis.assign(n + 1, false);
			for (int i = 1; i <= n; i++) if(l[i] == -1) ok |= yo(i);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += l[i] != -1;
		return ans;
	}
};
int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		for (int k = a[i]; k; k >>= 1) v.push_back(k);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int m = v.size();
	Kuhn M(n, m);
	for (int i = 1; i <= n; i++) {
		for (int k = a[i]; k; k >>= 1) {
			int id = upper_bound(v.begin(), v.end(), k) - v.begin();
			M.add_edge(i, id);
		}
	}
	int l = 1, r = m, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		for (int i = 1; i <= m; i++) M.r[i] = i <= mid ? -1 : -69;
		for (int i = 1; i <= n; i++) M.l[i] = -1;
		if (M.maximum_matching() < n) l = mid + 1;
		else ans = mid, r = mid - 1;
	}
	for (int i = 1; i <= m; i++) M.r[i] = i <= ans ? -1 : -69;
	for (int i = 1; i <= n; i++) M.l[i] = -1;
	M.maximum_matching();
	for (int i = 1; i <= n; i++) cout << v[M.l[i] - 1] << ' '; cout << '\n';
    return 0;
}