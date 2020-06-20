#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a[2];
		for (int i = 1; i <= 2 * n; i++) {
			int k; cin >> k;
			a[k % 2].push_back(i);
		}
		vector<pair<int, int>> ans;
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i + 1 < a[k].size(); i += 2) ans.emplace_back(a[k][i], a[k][i + 1]);
		}
		ans.resize(n - 1);
		for (auto x: ans) cout << x.first << ' ' << x.second << '\n';
	}
    return 0;
}