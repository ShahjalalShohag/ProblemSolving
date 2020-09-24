#include<bits/stdc++.h>
using namespace std;

const int N = 81, inf = 1e9;
int n, a[N];
int dp[2][N][N][N * (N - 1) / 2];
vector<int> pos;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	pos.push_back(0);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			pos.push_back(i);
		}
		else tot++;
	}
	for (int i = 0; i <= n; i++) {
		for (int o = 0; o < pos.size(); o++) {
			for (int z = 0; z <= tot; z++) {
				for (int k = 0; k <= n * (n - 1) / 2; k++) {
					if (i == 0) {
						dp[i & 1][o][z][k] = z * z;
						continue;
					}
					dp[i & 1][o][z][k] = inf;
					if (o && k >= abs(pos[o] - i)) dp[i & 1][o][z][k] = min(dp[i & 1][o][z][k], z * z + dp[(i - 1) & 1][o - 1][0][k - abs(pos[o] - i)]);
					if (i > o) dp[i & 1][o][z][k] = min(dp[i & 1][o][z][k], dp[(i - 1) & 1][o][z + 1][k]);
				}
			}
		}
	}
	for (int k = 0; k <= n * (n - 1) / 2; k++) {
		cout << (tot * tot - dp[n & 1][pos.size() - 1][0][k]) / 2 << ' ';
	}
    return 0;
}