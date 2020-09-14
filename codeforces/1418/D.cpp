#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	set<int> se;
	multiset<int> diff;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		se.insert(k);
	}
	for (auto it = next(se.begin()); it != se.end(); ++it) {
		diff.insert(*it - *prev(it));
	}
	auto query = [&]() {
		if (se.size() <= 2) return 0;
		return *se.rbegin() - *se.begin() - *diff.rbegin();
	};
	cout << query() << '\n';
	while (q--) {
		int ty, k; cin >> ty >> k;
		if (ty == 1) {
			auto it = se.lower_bound(k);
			int r = it == se.end() ? -1 : *it;
			int l = it == se.begin() ? -1 : *prev(it);
			if (l != -1 && r != -1) {
				diff.erase(diff.find(r - l));
			}
			if (l != -1) diff.insert(k - l);
			if (r != -1) diff.insert(r - k);
			se.insert(k);
		}		
		else {
			auto it = se.lower_bound(k);
			int r = next(it) == se.end() ? -1 : *next(it);
			int l = it == se.begin() ? -1 : *prev(it);
			if (l != -1) diff.erase(diff.find(k - l));
			if (r != -1) diff.erase(diff.find(r - k));
			if (l != -1 && r != -1) {
				diff.insert(r - l);
			}
			se.erase(k);
		}
		cout << query() << '\n';
	}
    return 0;
}