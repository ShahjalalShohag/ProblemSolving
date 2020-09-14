#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), id, v;
		for (auto &x: a) cin >> x;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			if (!k) id.push_back(i), v.push_back(a[i]);
		}
		sort(v.rbegin(), v.rend());
		for (int i = 0; i < id.size(); i++) a[id[i]] = v[i];
		for (auto i: a) cout << i << ' '; cout << '\n';
	}
    return 0;
}