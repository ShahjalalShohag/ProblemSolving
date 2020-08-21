#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		vector<int> a(3), b(3);
		for (int i = 0; i < 3; i++) cin >> a[i];
		for (int i = 0; i < 3; i++) cin >> b[i];
		int n = a[0] + a[1] + a[2], k = min(a[2], b[1]);
		int ans = 2 * k;
		a[2] -= k;
		b[1] -= k;
		n -= k;
		b[2] = max(0, b[2] - (n - a[1]));
		ans -= 2 * min(a[1], b[2]);
		cout << ans << '\n';
	}
    return 0;
}