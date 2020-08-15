#include<bits/stdc++.h>
using namespace std;

const int N = 3005;
int n, m, k, a[N][N];
long long dp[N][N][4];
long long yo(int i, int j, int k) {
	if (i > n || j > m) return 0;
	long long &ret = dp[i][j][k];
	if (ret != -1) return ret;
	long long ans = yo(i + 1, j, 0) + (k < 3 ? a[i][j] : 0);
	if (k < 3) ans = max(ans, yo(i, j + 1, k + 1) + a[i][j]);
	ans = max(ans, yo(i, j + 1, k));
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int r, c, x; cin >> r >> c >> x;
		a[r][c] = x;
	}
	memset(dp, -1, sizeof dp);
	cout << yo(1, 1, 0) << '\n';
    return 0;
}