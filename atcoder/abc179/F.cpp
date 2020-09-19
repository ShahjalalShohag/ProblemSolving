#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	set<pair<int, int>> r, c;
	r.insert({n, n});
	c.insert({n, n});
	while (q--) {
		int ty, i; cin >> ty >> i;
		if (ty == 1) {
			auto it = r.lower_bound({i, -1});
			int k = (*it).second;
			c.insert({(k - 1), i});
		}
		else {
			auto it = c.lower_bound({i, -1});
			int k = (*it).second;
			r.insert({(k - 1), i});
		}
	}
	long long ans = 1LL * (n - 2) * (n - 2);
	for (auto x: r) {
		if (x.second != n) ans -= x.first - 1;
	}	
	for (auto x: c) {
		if (x.second != n) ans -= x.first - 1;
	}
	cout << ans << '\n';
    return 0;
}