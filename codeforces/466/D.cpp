#include<bits/stdc++.h>
using namespace std;

const int N = 2020, mod = 1e9 + 7;

int a[N], n, h, dp[N][N];
int yo(int i, int open) {
	if (i == n + 1) return open == 0;
	int &ret = dp[i][open];
	if (ret != -1) return ret;
	long long ans = 0;
	if (open == a[i]) {
		ans += 1LL * open * yo(i + 1, open - 1);
		ans += yo(i + 1, open);
	}
	else if (open + 1 == a[i]) {
		ans += yo(i + 1, open + 1);
		ans += yo(i + 1, open);
		ans += 1LL * open * yo(i + 1, open);
	}
	ans %= mod;
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > h) return cout << 0 << '\n', 0;
		a[i] = h - a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << yo(1, 0) << '\n';
    return 0;
}