#include<bits/stdc++.h>
using namespace std;

const int N = 1600;
#define PT array<int, 3>
long long cross(PT a, PT b) { return 1LL * a[0] * b[1] - 1LL * a[1] * b[0]; }
PT vec(PT a, PT b) {
	return PT({b[0] - a[0], b[1] - a[1], 1});
}
PT a[N];
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
int ans[N];
void yo(int u, int p, int l, int r) {
	sort(a + l, a + r + 1);
	sort(a + l + 1, a + r + 1, [&](PT x, PT y) {
		return cross(vec(a[l], x), vec(a[l], y)) > 0;
	});
	ans[a[l][2]] = u;
	l++;
	for (auto v: g[u]) {
		if (v ^ p) {
			yo(v, u, l, l + sz[v] - 1);
			l += sz[v];
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
	    int u, v; cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
		a[i][2] = i;
	}
	dfs(1);
	yo(1, 0, 1, n);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}