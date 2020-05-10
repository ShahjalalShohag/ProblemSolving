#include<bits/stdc++.h>
using namespace std;

const int N = 14;

int a[N][N], c[N], val[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x; cin >> n >> m >> x;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}
	int ans = 1e9;
	for (int mask = 1; mask < (1 << n); mask++) {
		int nw = 0;
		memset(val, 0, sizeof val);
		for (int i = 0; i < n; i++) if (mask >> i & 1) {
			for (int j = 0; j < m; j++) val[j] += a[i][j];
			nw += c[i];
		}
		int ok = 1;
		for (int i = 0; i < m; i++) if (val[i] < x) ok = 0;
		if (ok) ans = min(ans, nw);
	}
	if (ans == 1e9) ans = -1;
	cout << ans << '\n';
    return 0;
}