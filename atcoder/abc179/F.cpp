#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	set<pair<int, int>> se[2];
	se[0].insert({n, n});
	se[1].insert({n, n});
	long long ans = 1LL * (n - 2) * (n - 2);
	while (q--) {
		int ty, i; cin >> ty >> i;
		ty--;
		auto it = se[ty].lower_bound({i, -1});
		int k = (*it).second;
		ans -= k - 2;
		se[ty ^ 1].insert({(k - 1), i});
	}
	cout << ans << '\n';
    return 0;
}