#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		int sum = 0, f = 0;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			sum += x - k;
			f += k == x;
		}
		if (f == n) cout << 0 << '\n';
		else if (sum == 0) cout << 1 << '\n';
		else cout << 2 - (f > 0) << '\n';
	}
    return 0;
}