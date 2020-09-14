#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long x, y, k; cin >> x >> y >> k;
		long long p = y * k + k, ans = 0, cur = 1;
		for (long long i = 1; i <= p / x;) {
			i *= x;
			ans += i / x;
			cur = i;
		}
		ans += (p - cur + x - 2) / (x - 1) + k;
		cout << ans << '\n';
	}
    return 0;
}