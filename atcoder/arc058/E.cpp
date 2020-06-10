#include<bits/stdc++.h>
using namespace std;

const int N = 18, mod = 1e9 + 7;

int dp[44][1 << N], x, y, z;
int yo(int n, int mask) {
	mask &= (1 << 18) - 1;
	if (mask >> x & 1 && mask >> (x + y) & 1 && mask >> (x + y + z) & 1) return 0;
	if (n == 0) return 1;
	int &ret = dp[n][mask];
	if (ret != -1) return ret;
	int ans = 0;
	for (int i = 1; i <= 10; i++) {
		ans += yo(n - 1, (mask << i) | (1 << i));
		if (ans >= mod) ans -= mod;
	}
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n >> x >> y >> z;
	memset(dp, -1, sizeof dp);
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = 1LL * ans * 10 % mod;
	ans = (ans - yo(n, 0) + mod) % mod;
	cout << ans << '\n';
    return 0;
}