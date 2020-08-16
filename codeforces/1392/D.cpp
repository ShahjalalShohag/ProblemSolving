#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int n, a[N], dp[N][2][2], f[2];
int yo(int i, int l1, int l2) {
	if (i == n) {
		if (l1 == l2 && l2 == f[0]) return n;
		if (l2 == f[0] && f[0] == f[1]) return n;
		return 0;
	}
	int &ret = dp[i][l1][l2];
	if (ret != -1) return ret;
	int ans = n;
	for (int k = 0; k < 2; k++) {
		if (l1 == l2 && l2 == k);
		else {
			ans = min(ans, yo(i + 1, l2, k) + (a[i] != k));
		}
	}
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		string s; cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') a[i] = 0;
			else a[i] = 1;
		}
		int ans = n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				f[0] = i; f[1] = j;
				for (int k = 0; k < n; k++) {
					memset(dp[k], -1, sizeof dp[k]);
				}
				ans = min(ans, yo(2, i, j) + (a[0] != i) + (a[1] != j));
			}
		}
		cout << ans << '\n';
	}
    return 0;
}