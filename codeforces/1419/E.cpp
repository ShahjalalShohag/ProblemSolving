#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> p;
		int z = n;
		map<int, int> mp;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				p.push_back(i);
				while (n % i == 0) {
					n /= i;
					mp[i]++;
				}
			}
		}
		if (n > 1) p.push_back(n), mp[n]++;
		n = z;
		sort(p.begin(), p.end());
		vector<int> ans; int cnt = 0;
		if (p.size() == 2 && p[0] != p[1] && mp[p[0]] == 1 && mp[p[1]] == 1) {
			cnt = 1;
		}
		for (int i = 0; i < p.size(); i++) {
			function<void(int, int)> dfs = [&](int id, int cur) {
				if (id > i && cur % p[i] != 0) return;
				if (id == p.size()) {
					if (cur == n) return;
					if (i + 1 < p.size() && cur == p[i] * p[i + 1]) return;
					ans.push_back(cur);
					return;
				}
				dfs(id + 1, cur);
				for (int k = 1; k <= mp[p[id]]; k++) {
					cur *= p[id];
					dfs(id + 1, cur);
				}
				return;
			};
			dfs(i, 1);
			if (i + 1 < p.size() && p[i] * p[i + 1] != n) {
				ans.push_back(p[i] * p[i + 1]);
			}
		}
		ans.push_back(n);
		for (auto x: ans) cout << x << ' '; cout << '\n';
		cout << cnt << '\n';
	}
    return 0;
}