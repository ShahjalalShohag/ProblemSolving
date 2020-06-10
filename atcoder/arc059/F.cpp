#include<bits/stdc++.h>
using namespace std;

const int N = 5005, mod = 1e9 + 7;

int dp[N][N], n;
string s;
int yo(int i, int t) {
	if (t == n) return i == s.size();
	int &ret = dp[i][t];
	if (ret != -1) return ret;
	int ans = yo(i + 1, t + 1) * 2 % mod + yo(!i ? i : i - 1, t + 1);
	if (ans >= mod) ans -= mod;
	return ret = ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	memset(dp, -1, sizeof dp);
	int ans = yo(0, 0);
	for (int i = 1; i <= s.size(); i++) ans = 1LL * ans * (mod + 1) / 2 % mod;
	cout << ans << '\n';
    return 0;
}