#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const long long inf = 4e18;
long long a[N][N], dp[N][N];
int n, m;
long long yo(long long x) {
	if (a[0][0] < x) return inf;
	dp[0][0] = a[0][0] - x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i || j) dp[i][j] = inf;
			long long val = x + i + j;
			if (i &&  val <= a[i][j]) dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j] - val);
			if (j &&  val <= a[i][j]) dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j] - val);
		}
	}
	return dp[n - 1][m - 1];
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cin >> a[i][j];
		}
		long long ans = inf;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = min(ans, yo(a[i][j] - i - j));
			}
		}
		cout << ans << '\n';
	}
    return 0;
}