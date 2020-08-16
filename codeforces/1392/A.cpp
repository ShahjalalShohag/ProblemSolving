#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<int> se;
		for (int i = 1; i <= n; i++) {
			int k; cin >> k;
			se.insert(k);
		}
		if (se.size() == 1) cout << n << '\n';
		else cout << 1 << '\n';
	}
    return 0;
}