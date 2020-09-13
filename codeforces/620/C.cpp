#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> v;
	int last = 1;
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		if (mp[k]) {
			v.push_back({last, i});
			mp.clear();
			last = i + 1;
		}
		else mp[k] = 1;
	}
	if (v.empty()) cout << -1 << '\n';
	else {
		cout << v.size() << '\n';
		if (v.back().second != n) v.back().second = n;
		for (auto i: v) cout << i.first << ' ' << i.second << '\n';
	}
    return 0;
}