#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

long long sum[N], ans[N];
vector<int> g[N]; int a[N], sz[N];
inline long long nc2(long long n) {
	return n * (n + 1) / 2;
}
void dfs(int u, int p = 0) {
	sz[u] = 1;
	int c = a[u];
	long long tot = 0;
	for (auto v: g[u]) if (v != p) {
		long long last = sum[c];
		dfs(v, u);
		ans[c] += nc2(sz[v] - (sum[c] - last));
		tot += sum[c] - last;
		sz[u] += sz[v];
	}
	sum[c] -= tot; sum[c] += sz[u];
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) ans[i] += nc2(n - sum[i]);
   	for (int i = 1; i <= n; i++) ans[i] = nc2(n) - ans[i];
   	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}