#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
long long a[N];
long long dp[N][2];
void dfs(int u, int p = 0) {
	for (auto v: g[u]) {
		if (v ^ p) {
			dfs(v, u);
			dp[u][0] = max(dp[u][0], dp[v][0]);
			dp[u][1] = max(dp[u][1], dp[v][1]);
		}
	}
	a[u] += dp[u][0] - dp[u][1];
	if (a[u] < 0) dp[u][0] += -a[u];
	else dp[u][1] += a[u];
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
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1);
	cout << dp[1][0] + dp[1][1] << '\n';
    return 0;
}