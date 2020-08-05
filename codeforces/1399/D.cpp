#include<bits/stdc++.h>
using namespace std;

set<int> id[2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < n; i++) {
			id[s[i] - '0'].insert(i);
		}
		vector<int> ans(n);
		int cnt = 0;
		while (id[0].size() || id[1].size()) {
			cnt++;
			if (id[0].empty()) {
				ans[*id[1].begin()] = cnt;
				id[1].erase(id[1].begin());
				continue;
			}			
			if (id[1].empty()) {
				ans[*id[0].begin()] = cnt;
				id[0].erase(id[0].begin());
				continue;
			}
			int cur = 0;
			if ((*id[1].begin()) < (*id[0].begin())) cur = 1;
			int last = *id[cur].begin();
			while (1) {
				auto it = id[cur].lower_bound(last);
				if (it == id[cur].end()) break;
				ans[*it] = cnt;
				last = *it;
				id[cur].erase(it);
				cur ^= 1;
			}
		}
		cout << cnt << '\n';
		for (auto i: ans) cout << i << ' '; cout << '\n';
	}
    return 0;
}