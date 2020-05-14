#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long ans = 0;
		int n; cin >> n;
		int k = n / 2;
		for (int i = 1; i <= k; i++) ans += 1LL * (2 * i - 1) * i;
		ans += 1LL * k * (k + 1) / 2;
		cout << ans * 4 << '\n';
	}
    return 0;
}