#include<bits/stdc++.h>
using namespace std;

const int N = 3005, mod = 998244353;

int n, m, dp[N][N];
int yo(int i, int j) {
	if (i < n || j < m) return 0;
	if (i == n && j == m) return 1;
	int &ret = dp[i][j];
	if (ret != -1) return ret;
	long long ans = 1LL * yo(i - 1, j) * j + 1LL * yo(i, j - 1) * i;
	ans -= 1LL * yo(i - 1, j - 1) * (i - 1) * (j - 1);
	ans %= mod;
	ans = (ans + mod) % mod;
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p, q; cin >> n >> m >> p >> q;
	memset(dp, -1, sizeof dp);
	cout << yo(p, q) << '\n';
    return 0;
}