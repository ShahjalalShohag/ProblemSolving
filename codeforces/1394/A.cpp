#include<bits/stdc++.h>
using namespace std;

vector<long long> a[2], p[2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, d, m; cin >> n >> d >> m;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		if (k > m) a[1].push_back(k);
		else a[0].push_back(k);
	}
	for (int i = 0; i < 2; i++) {
		sort(a[i].rbegin(), a[i].rend());
		for (int j = 0; j < a[i].size(); j++) {
			p[i].push_back(a[i][j]);
			if (j) p[i][j] += p[i][j - 1];
		}
	}
	long long ans = 0;
	for (int k = 0; k <= a[0].size(); k++) {
		long long cur = 0;
		if (k) cur = p[0][k - 1];
		int left = n - k, c = (left + d) / (d + 1);
		c = min(c, (int)a[1].size());
		if (c) cur += p[1][c - 1];
		ans = max(ans, cur);
	}
	cout << ans << '\n';
    return 0;
}