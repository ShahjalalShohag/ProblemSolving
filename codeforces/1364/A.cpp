#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> v; int sum = 0;
		for (int i = 1; i <= n; i++) {
			int k; cin >> k;
			sum += k; sum %= x;
			if (k % x != 0) v.push_back(i);
		}
		int ans = -1;
		if (sum != 0) ans = n;
		else {
			for (auto z: v) ans = max({ans, z - 1, n - z});
		}
		cout << ans << '\n';
	}
    return 0;
}