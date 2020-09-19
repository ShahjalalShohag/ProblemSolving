#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	set<pair<int, int>> se[2];
	se[0].insert({n, n});
	se[1].insert({n, n});
	while (q--) {
		int ty, i; cin >> ty >> i;
		ty--;
		auto it = se[ty].lower_bound({i, -1});
		int k = (*it).second;
		se[ty ^ 1].insert({(k - 1), i});
	}
	long long ans = 1LL * (n - 2) * (n - 2);
	for (int i = 0; i < 2; i++) {
		for (auto x: se[i]) {
			if (x.second != n) ans -= x.first - 1;
		}
	}	
	cout << ans << '\n';
    return 0;
}