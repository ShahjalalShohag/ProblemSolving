#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, LG = 17;

int a[N], dp[LG][N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l, q; cin >> l >> q;
	for (int i = 1; i <= n; i++) {
		dp[0][i] = upper_bound(a + i, a + n + 1, a[i] + l) - a - 1;
	}
	for (int k = 1; k < LG; k++) {
		for (int i = 1; i <= n; i++) dp[k][i] = dp[k - 1][dp[k - 1][i]];
	}
	while (q--) {
		int x, y; cin >> x >> y;
		if (x > y) swap(x, y);
		int ans = 0;
		for (int k = LG - 1; k >= 0; k--) {
			if (dp[k][x] < y) {
				x = dp[k][x];
				ans += 1 << k;
			}
		}
		ans++;
		cout << ans << '\n';
	}
    return 0;
}