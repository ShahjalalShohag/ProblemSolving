#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
struct HopcroftKarp {
    static const int inf = 1e9;
    int n; vector<int> l, r, d, ok;
    vector<vector<int>> g;
    HopcroftKarp(int _n, int _m) {
    	n = _n; int p = _n + _m + 1; g.resize(p);
    	l.resize(p, 0); r.resize(p, 0); d.resize(p, 0); ok.resize(p, 0);
    }
    void add_edge(int u, int v) {
        g[u].push_back(v + n); //right id is increased by n, so is l[u]
    }
    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (!l[u]) d[u] = 0, q.push(u);
            else d[u] = inf;
        }
        d[0] = inf;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v: g[u]) {
            	if (!ok[v]) continue;
                if (d[r[v]] == inf) {
                    d[r[v]] = d[u] + 1;
                    q.push(r[v]);
                }
            }
        }
        return d[0] != inf;
    }
    bool dfs(int u) {
        if (!u) return true;
        for (auto v: g[u]) {
        	if (!ok[v]) continue;
            if(d[r[v]] == d[u] + 1 && dfs(r[v])) {
                l[u] = v; r[v] = u;
                return true;
            }
        }
        d[u] = inf;
        return false;
    }
    int maximum_matching() {
        int ans = 0;
        while (bfs()) {
            for(int u = 1; u <= n; u++) if (!l[u] && dfs(u)) ans++;
        }
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
	HopcroftKarp M(n, m);
	for (int i = 1; i <= n; i++) {
		for (int k = a[i]; k; k >>= 1) {
			int id = upper_bound(v.begin(), v.end(), k) - v.begin();
			M.add_edge(i, id);
		}
	}
	int l = 1, r = m, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		for (int i = 1; i <= m; i++) M.r[n + i] = 0;
		for (int i = 1; i <= m; i++) M.ok[n + i] = i <= mid ? 1 : 0;
		for (int i = 1; i <= n; i++) M.l[i] = 0;
		if (M.maximum_matching() < n) l = mid + 1;
		else ans = mid, r = mid - 1;
	}
	for (int i = 1; i <= m; i++) M.r[n + i] = 0;
	for (int i = 1; i <= m; i++) M.ok[n + i] = i <= ans ? 1 : 0;
	for (int i = 1; i <= n; i++) M.l[i] = 0;
	M.maximum_matching();
	for (int i = 1; i <= n; i++) cout << v[M.l[i] - n - 1] << ' '; cout << '\n';
    return 0;
}