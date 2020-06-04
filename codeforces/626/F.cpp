#include<bits/stdc++.h>
using namespace std;

const int N = 205, mod = 1e9 + 7;

int a[N], n, k, dp[N][N][1005];
int yo(int i, int open, int bal) {
	if (bal > k) return 0;
	if (i == n + 1) return open == 0;
	int &ret = dp[i][open][bal];
	if (ret != -1) return ret;
	int nbal = bal + open * (a[i] - a[i - 1]);;
	long long ans = yo(i + 1, open, nbal);
	ans += yo(i + 1, open + 1, nbal);
	if (open) ans += 1LL * open * yo(i + 1, open - 1, nbal);
	ans += 1LL * open * yo(i + 1, open, nbal);
	ans %= mod;
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	memset(dp, -1, sizeof dp);
	cout << yo(1, 0, 0) << '\n';
    return 0;
}