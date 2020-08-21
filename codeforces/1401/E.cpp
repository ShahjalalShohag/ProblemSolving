#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int M = 1e6;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<pair<int, int>> L, q[M + 9], RR;
int a[M + 9];
set<int> R;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int y, l, r; cin >> y >> l >> r;
		if (l == 0) L.push_back({r, y});
		else a[y] = l, RR.push_back({l, y});
	}	
	for (int i = 0; i < m; i++) {
		int x, l, r; cin >> x >> l >> r;
		q[x].push_back({l, r});
	}
	q[M].push_back({0, M});
	sort(L.rbegin(), L.rend());
	sort(RR.rbegin(), RR.rend());
	o_set<int> se;
	long long ans = 0;
	se.insert(0);
	se.insert(M);
	for (auto i: L) se.insert(i.second);
	for (int i = 1; i <= M; i++) {
		while (!L.empty() && L.back().first < i) {
			se.erase(L.back().second);
			L.pop_back();
		}	
		while (!RR.empty() && RR.back().first <= i) {
			R.insert(RR.back().second);
			RR.pop_back();
		}
		if (q[i].empty()) continue;
		assert(q[i].size() == 1);
		int l = q[i][0].first, r = q[i][0].second;
		ans += se.order_of_key(r + 1) - se.order_of_key(l) - 1;
		auto it = R.lower_bound(l);
		vector<int> v;
		while (it != R.end() && (*it) <= r) {
			se.insert(*it);
			v.push_back(*it);
			++it;
		}
		for (auto x: v) R.erase(x);
	}
	cout << ans << '\n';
    return 0;
}