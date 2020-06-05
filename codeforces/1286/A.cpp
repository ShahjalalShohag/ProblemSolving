#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int dp[N][N][2], a[N], n;
int yo(int i, int odd, int last) {
	if (odd < 0) return 1e9;
	if (i == n + 1) {
		if (odd == 0) return 0;
		else return 1e9;
	}
	int &ret = dp[i][odd][last];
	if (ret != -1) return ret;
	int ans;
	if (a[i]) ans = (a[i] % 2 != last) + yo(i + 1, odd, a[i] % 2);
	else {
		ans = (last != 1) + yo(i + 1, odd - 1, 1);
		ans = min(ans, (last != 0) + yo(i + 1, odd, 0));
	}
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int odd = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], odd += a[i] % 2;
	odd = (n + 1) / 2 - odd;
	memset(dp, -1, sizeof dp);
	cout << min(yo(1, odd, 0), yo(1, odd, 1)) << '\n';
    return 0;
}