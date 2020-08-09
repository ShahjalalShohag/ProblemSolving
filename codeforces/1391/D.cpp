#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, inf = 1e8 + 9;

int f(int n, int k) {
	return n >> k & 1;
}
string p[N], s[N];
int n, m;
int dp[N][8];
int change(int i, int mask) {
	int ans = 0;
	for (int k = 0; k < n; k++) {
		ans += (s[k][i] - '0') != f(mask, k);
	}
	return ans;
}
int yo(int i, int last) {
	if (i == m) return 0;
	int &ans = dp[i][last];
	if (ans != -1) return ans;
	ans = inf;
	for (int mask = 0; mask < (1 << n); mask++) {
		int ok = 1;
		for (int i = 0; i < n - 1; i++) {
			int cnt = f(last, i) + f(last, i + 1) + 
				f(mask, i) + f(mask, i + 1);
			ok &= cnt % 2 == 1;
		}
		if (ok) {
			ans = min(ans, change(i, mask) + yo(i + 1, mask));
		}
	}
	return ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if (n >= 4 && m >= 4) return cout << -1 << '\n', 0;
	if (n == 1 || m == 1) return cout << 0 << '\n', 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		s[i] = p[i];
	}
	if (n > m) {
		swap(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				s[i][j] = p[j][i];
			}
		}
	}
	memset(dp, -1, sizeof dp);
	int ans = inf;
	for (int mask = 0; mask < (1 << n); mask++) {
		ans = min(ans, change(0, mask) + yo(1, mask));
	}
	if (ans == inf) ans = -1;
	cout << ans << '\n';
    return 0;
}