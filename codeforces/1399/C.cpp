#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> sum[200];
int a[200];
bool vis[200];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				sum[a[i] + a[j]].push_back({i, j});
			}
		}
		for (int k = 1; k <= 2 * n; k++) {
			memset(vis, 0, sizeof vis);
			int cur = 0;
			for (auto x: sum[k]) {
				if (vis[x.first] || vis[x.second]) continue;
				cur++;
				vis[x.first] = 1;
				vis[x.second] = 1;
			}
			ans = max(ans, cur);
			sum[k].clear();
		}
		cout << ans << '\n';
	}
    return 0;
}