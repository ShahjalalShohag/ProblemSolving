#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n + 1);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum % n != 0) {
			cout << -1 << '\n';
			continue;
		}
		int target = sum / n;
		vector<array<int, 3>> ans;
		for (int i = 2; i <= n; i++) {
			ans.push_back({1, i, (i - a[i] % i) % i});
			a[i] += (i - a[i] % i) % i;
			ans.push_back({i, 1, a[i] / i});
		}
		for (int i = 2; i <= n; i++) {
			ans.push_back({1, i, target});
		}
		cout << ans.size() << '\n';
		for (auto x: ans) cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
	}
    return 0;
}