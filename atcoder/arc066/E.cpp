#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

long long a[N], dp[N], sum[N], nxt[N];
char s[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n >> a[1];
	sum[1] = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> s[i] >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	nxt[n + 1] = n + 1;
	for (int i = n; i >= 2; i--) {
		if (s[i] == '+') {
			dp[i] = dp[i + 1] + a[i];
			nxt[i] = nxt[i + 1];
		}
		else {
			dp[i] = dp[i + 1] - a[i];
			int k = nxt[i + 1];
			dp[i] = max(dp[i], sum[n] - sum[k - 1] - (sum[k - 1] - sum[i]) - a[i]);
			nxt[i] = i;
		}
	}
	cout << dp[2] + a[1] << '\n';
    return 0;
}