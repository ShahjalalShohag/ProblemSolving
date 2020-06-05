#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

vector<int> g[N];
int a[N], ans[N];
int yo(int u) {
	int sz = 1;
	for (auto v: g[u]) sz += yo(v);
	if (sz <= a[u]) {
		cout << "NO\n", 0;
		exit(0);
	}
	return sz;
}
vector<int> v;
void dfs(int u) {
	ans[u] = v[a[u]];
	v.erase(v.begin() + a[u]);
	for (auto v: g[u]) dfs(v);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k >> a[i];
		g[k].push_back(i);
	}
	for (int i = 1; i <= n; i++) v.push_back(i);
	yo(g[0][0]);
	dfs(g[0][0]);
	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
    return 0;
}