#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

struct Basis {
	vector<int> a;
	void insert(int x) {
	    for (auto &i: a) x = min(x, x ^ i);
	    if (!x) return;
	    for (auto &i: a) if ((i ^ x) < i) i ^= x;
	    a.push_back(x);
	}	
	int minxor(int x = 0) {
	    for (auto &i: a) x = min(x, x ^ i);
		return x;
	}
}B[N * 4];

struct PDSU {
	int par[N], sz[N], w[N];
	vector<int> ops;
	PDSU() {
	    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1, w[i] = 0;
	}
	pair<int, int> find(int u) {
	    int ans = 0;
	    while (par[u] != u)  {
	        ans ^= w[u];
	        u = par[u];
	    }
	    return make_pair(u, ans);
	}
	bool merge(int u, int v, int x) {
	    auto pu = find(u), pv = find(v);
	    u = pu.first;
	    v = pv.first;
	    int z = pu.second ^ pv.second ^ x;
	    if (u == v)   return false;
	    if (sz[u] > sz[v]) swap(u, v);
	    par[u] = v;
	    w[u] = z;
	    sz[v] += sz[u];
	    ops.push_back(u);
	    return true;
	}
	void rollback() {
	    int u = ops.back();
	    sz[par[u]] -= sz[u];
	    par[u] = u;
	    w[u] = 0;
	    ops.pop_back();
	}
}D;

vector<array<int, 3>> t[N * 4];
void upd(int n, int b, int e, int l, int r, int u, int v, int w) {
	if (e < l || b > r || b > e) return;
	if (l <= b && e <= r) {
		t[n].push_back({u, v, w});
		return;
	}
	if (b == e) return;
	int mid = b + e >> 1;
	upd(n << 1, b, mid, l, r, u, v, w);
	upd(n << 1 | 1, mid + 1, e, l, r, u, v, w);
}

int ans[N];
array<int, 3> Q[N];
void yo(int n, int b, int e) {
	if (b > e) return;
	B[n] = B[n >> 1];
	int cnt = 0;
	for (auto x: t[n]) {
		if (D.merge(x[0], x[1], x[2])) cnt++;
		else B[n].insert(x[2] ^ D.find(x[0]).second ^ D.find(x[1]).second);
	}
	if (b == e) {
		if (Q[b][2]) {
			ans[b] = B[n].minxor(D.find(Q[b][0]).second ^ D.find(Q[b][1]).second);
		}
		while (cnt--) D.rollback();
		return;
	}
	int mid = b + e >> 1;
	yo(n << 1, b, mid);
	yo(n << 1 | 1, mid + 1, e);
	while (cnt--) D.rollback();
}

map<pair<int, int>, pair<int, int>> mp;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, d; cin >> u >> v >> d;
		mp[{u, v}] = {1, d};
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int ty, u, v; cin >> ty >> u >> v;
		if (ty == 1) {
			int d; cin >> d;
			mp[{u, v}] = {i, d};
		}
		else if (ty == 2) {
			auto it = mp.find({u, v});
			upd(1, 1, q, it -> second.first, i - 1, u, v, it -> second.second);
			mp.erase(it);
		}
		else {
			Q[i] = {u, v, 1};
		}
	}
	for (auto z: mp) {
		auto x = z.first, y = z.second;
		upd(1, 1, q, y.first, q, x.first, x.second, y.second);
	}
	yo(1, 1, q);
	for (int i = 1; i <= q; i++) {
		if (Q[i][2]) cout << ans[i] << '\n';
	}
    return 0;
}