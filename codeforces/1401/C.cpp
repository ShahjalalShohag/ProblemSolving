#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> u, v, id, a(n);
		for (auto &x: a) cin >> x;
		int k = *min_element(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			if (a[i] % k != 0) {
				v.push_back(a[i]);
				id.push_back(i);
			}
			else u.push_back(a[i]);
		}
		sort(u.begin(), u.end());
		vector<int> cur(n, 0);
		for (int i = 0; i < v.size(); i++) {
			cur[id[i]] = v[i];
		}
		for (int i = 0, x = 0; i < n; i++) {
			if (cur[i] == 0) cur[i] = u[x++];
		}
		auto p = cur;
		sort(p.begin(), p.end());
		if (cur == p) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}