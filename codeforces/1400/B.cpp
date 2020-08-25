#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long a, b; cin >> a >> b;
		int ca, cb; cin >> ca >> cb;
		long long wa, wb; cin >> wa >> wb;
		if (wa > wb) swap(wa, wb), swap(ca, cb);
		int ans = 0;
		for (int i = 0; i <= ca && wa * i <= a; i++) {
			int k = min(cb*1LL, (a - wa * i) / wb);
			long long la = ca - i, lb = cb - k;
			int cur = i + k;
			int z = min(la, b / wa);
			cur += z;
			cur += min(lb, (b - wa * z) / wb);
			ans = max(ans, cur);
		}
		cout << ans << '\n';
	}
    return 0;
}