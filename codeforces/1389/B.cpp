#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], n, dp[N][6][2];
int yo(int i, int k, int z, int last) {
	if (!k) return 0;
	int &ret = dp[i][z][last];
	if (ret != -1) return ret;
	int ans = 0;
	if (i + 1 <= n) ans = max(ans, a[i + 1] + yo(i + 1, k - 1, z, 1));
	if (last && z && i > 1) ans = max(ans, a[i - 1] + yo(i - 1, k - 1, z - 1, 0));
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int k, z; cin >> n >> k >> z;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 0; i <= n; i++) {
			memset(dp[i], -1, sizeof dp[i]);
		}
		cout << yo(1, k, z, 1) + a[1] << '\n';
	}
    return 0;
}