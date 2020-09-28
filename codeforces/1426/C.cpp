#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 1e9;
		for (int i = 1; i <= 50000; i++) {
			ans = min(ans, i - 2 + (n + i - 1) / i);
		}
		cout << ans << '\n';
	}
    return 0;
}