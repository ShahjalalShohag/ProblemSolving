#include<bits/stdc++.h>
using namespace std;

const int N = 6005, M = 2e5 + 9;

vector<int> a, id[M];
int dp[N][N];
int yo(int l, int r) {
	if (l > r) return 0;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	int ans = max(yo(l + 1, r), yo(l, r - 1));
	int k = ans, f = 0;
	for (auto z: id[a[l]]) {
		if (z <= r) {
			if (z == l) ans = max(ans, 1 + yo(z + 1, r));
			else if (z == r) f = 1;
			else ans = max(ans, yo(l, z) + yo(z + 1, r));
		}
		else break;
	}
	return ret = ans + f;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		a.clear();
		for (int i = 1; i <= n; i++) {
			int l, r; cin >> l >> r;
			a.push_back(l);
			a.push_back(r);
			id[l].push_back(r);
		}
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		for (auto i: a) {
			sort(id[i].begin(), id[i].end());
			for (auto &z: id[i]) {
				z = lower_bound(a.begin(), a.end(), z) - a.begin();
			}
		}
		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= a.size(); j++) {
				dp[i][j] = -1;
			}
		}
		cout << yo(0, (int)a.size() - 1) << '\n';
		for (auto i: a) id[i].clear();
	}
    return 0;
}