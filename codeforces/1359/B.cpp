#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, x, y; cin >> n >> m >> x >> y;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int i = 0, j; i < m; i = j) {
				for (j = i + 1; j < m && s[i] == s[j]; j++) ;
				if (s[i] == '.') v.push_back(j - i);
			}
		}
		long long ans = 0;
		for (auto z: v) {
			if (2 * x <= y) ans += z * x;
			else ans += (z / 2) * y + (z % 2) * x;
		}
		cout << ans << '\n';
	}
    return 0;
}