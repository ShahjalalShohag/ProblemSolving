#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int ans = n;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				if (i <= k) ans = min(ans, n / i);
				if (n / i <= k) ans = min(ans, n / (n / i));
			}
		}
		cout << ans << '\n';
	}
    return 0;
}