#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		long long ans = 0;
		vector<int> cnt(32, 0);
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			int msb = 31 - __builtin_clz(k);
			ans += cnt[msb];
			cnt[msb]++;
		}
		cout << ans << '\n';
	}
    return 0;
}