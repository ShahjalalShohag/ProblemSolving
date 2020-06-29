#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

struct DSU {
	vector<int> par, rnk, sz, ed; int c;
	DSU(int n) : par(n + 1), rnk(n + 1,0), sz(n + 1,1), ed(n + 1, 0), c(n) {
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return sz[find(i)]; }
	int count() { return c; } //connected components
	int edge_count(int i) {return ed[find(i)]; }
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) {
			ed[i] ++;
			return -1; 
		}
		else --c;
		if (rnk[i] > rnk[j]) swap(i, j);
		par[i] = j; sz[j] += sz[i], ed[j] += ed[i] + 1;
		if (rnk[i] == rnk[j]) rnk[j]++;
		return j;
	}
};

map<int, int> mp;
int get_id(int k) {
	if (mp.find(k) != mp.end()) return mp[k];
	int z = mp.size() + 1;
	return mp[k] = z;
}
int a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], a[n + 1] ^= a[i];
	for (int i = 1; i <= n; i++) cin >> b[i], b[n + 1] ^= b[i];
	n++;
	// you can swap (a[i], a[n])
	// find the minimum number of swaps to tranform a to b
	vector<int> va, vb;
	for (int i = 1; i <= n; i++) va.push_back(a[i]);
	for (int i = 1; i <= n; i++) vb.push_back(b[i]);
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	if (va != vb) return cout << -1 << '\n', 0;
	for (int i = 1; i <= n; i++) a[i] = get_id(a[i]);
	for (int i = 1; i <= n; i++) b[i] = get_id(b[i]);
	DSU d(n);
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			d.merge(a[i], b[i]);
		}
	}
	int p = d.find(a[n]);
	set<int> se;
	for (int i = 1; i <= n; i++) {
		se.insert(d.find(i));
	}
	int ans = 0;
	for (auto u: se) {
		int e = d.edge_count(u);
		if (e) {
			if (u == p) {
				if (a[n] == b[n]) ans += e;
				else ans += e - 1;
			}
			else ans += e + 1;
		}
	}
	cout << ans << '\n';
    return 0;
}