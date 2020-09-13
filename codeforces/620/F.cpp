#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 2;
int a[N], ans[N], l[N], r[N], dp[N];
int f[1 << 20], g[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i < (1 << 20); i++) {
		f[i] = f[i - 1] ^ i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		g[i] = f[a[i]];
	}
	for (int i = 0; i < q; i++) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	for (int i = 0; i < n; i++) {
		dp[i] = a[i];
		for (int j = i + 1; j < n; j++) {
			int k = g[i] ^ g[j] ^ (a[i] < a[j] ? a[i] : a[j]);
			dp[j] = dp[j - 1] > k ? dp[j - 1] : k;
		}
		for (int j = 0; j < q; j++) {
			if (l[j] <= i && i <= r[j]) {
				ans[j] = ans[j] > dp[r[j]] ? ans[j] : dp[r[j]];
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
    return 0;
}