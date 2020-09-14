#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N], dp[N][2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dp[n + 1][0] = dp[n + 1][1] = 0;
		for (int i = n; i >= 1; i--) {
			dp[i][0] = dp[i][1] = n;
			int cnt = 0;
			for (int j = i; j <= min(i + 1, n); j++) {
				cnt += a[j];
				dp[i][0] = min(dp[i][0], cnt + dp[j + 1][1]);
				dp[i][1] = min(dp[i][1], dp[j + 1][0]);
			}
		}
		cout << dp[1][0] << '\n';
	}
    return 0;
}