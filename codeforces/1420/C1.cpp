#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<long long> dp(2, 0);
		dp[0] = -1e12;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			dp[0] = max(dp[0], dp[1] + k);
			dp[1] = max(dp[1], dp[0] - k);
		}
		cout << max(dp[0], dp[1]) << '\n';
	}
    return 0;
}