#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int h, c, t;
long double val(long long x) {
	return 1.L * (x * h + (x - 1) * c) / (2 * x - 1);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		cin >> h >> c >> t;
		int l = 1, r = 1e9, opt = 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (val(mid) >= 1.L * t) opt = mid, l = mid + 1;
			else r = mid - 1;
		}
		long double q = (h + c) * 0.5;
		int ans = 2; long double dif = fabs(q - t);
		long double nw = fabs(val(opt) - t);
		if (nw < dif || fabs(nw - dif) < 1e-12 && 2 * opt - 1 < ans) {
			dif = nw;
			ans = 2 * opt - 1;
		}
		opt++;
		nw = fabs(val(opt) - t);
		if (nw < dif || fabs(nw - dif) < 1e-12 && 2 * opt - 1 < ans) {
			dif = nw;
			ans = 2 * opt - 1;
		}
		cout << ans << '\n';
	}
    return 0;
}