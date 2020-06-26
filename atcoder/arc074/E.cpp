#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[305][305][305], n;
vector<pair<int, int>> a[305];
int yo(int i, int r, int g, int b) {
	int &ret = dp[r][g][b];
	if (ret != -1) return ret;
	for (auto x: a[i - 1]) {
		int l = x.first;
		int cnt = (l <= r) + (l <= g) + (l <= b);
		if (cnt != x.second) return ret = 0;
	}
	if (i == n + 1) return 1;
	ret = yo(i + 1, i, g, b) + yo(i + 1, r, i, b);
	if (ret >= mod) ret -= mod;
	ret += yo(i + 1, r, g, i);
	if (ret >= mod) ret -= mod;
	return ret;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m; cin >> n >> m;
	while (m--) {
		int l, r, k; cin >> l >> r >> k;
		a[r].push_back({l, k});
	}
	memset(dp, -1, sizeof dp);
	cout << yo(1, 0, 0, 0) << '\n';
    return 0;
}