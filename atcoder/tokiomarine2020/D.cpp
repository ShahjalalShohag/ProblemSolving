#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, T = 10;

int a[1 << T][N], val[1 << 18], c[1 << 18];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> val[i] >> c[i];
	for (int i = 1; i < min(n + 1, (1 << T)); i++) {
		vector<int> v;
		int k = i;
		while (k) v.push_back(k), k >>= 1;
		int sz = v.size();
		for (int mask = 1; mask < (1 << sz); mask++) {
			int tw = 0, tv = 0;
			for (int i = 0; i < sz; i++) if (mask >> i & 1) {
				tv += val[v[i]];
				tw += c[v[i]];
			}
			if (tw < N) a[i][tw] = max(a[i][tw], tv);
		}
		for (int w = 1; w < N; w++) a[i][w] = max(a[i][w], a[i][w - 1]);
	}
	int q; cin >> q;
	while (q--) {
		int u, x; cin >> u >> x;
		if (u < (1 << T)) cout << a[u][x] << '\n';
		else {
			vector<int> v;
			int k = u;
			while (k >= (1 << T)) v.push_back(k), k >>= 1;
			int sz = v.size(), ans = 0;
			for (int mask = 0; mask < (1 << sz); mask++) {
				int tw = 0, tv = 0;
				for (int i = 0; i < sz; i++) if (mask >> i & 1) {
					tv += val[v[i]];
					tw += c[v[i]];
				}
				if (x >= tw) ans = max(ans, tv + a[k][x - tw]);
			}
			cout << ans << '\n';
		}
	}
    return 0;
}