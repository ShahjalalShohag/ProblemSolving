#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> odd, even;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			if (k & 1) odd.push_back(k);
			else even.push_back(k);
		}
		if (odd.size() % 2 == 0) cout << "YES\n";
		else {
			int ok = 0;
			for (auto x: odd) {
				for (auto y: even) {
					ok |= abs(x - y) == 1;
				}
			}
			if (ok) cout << "YES\n";
			else cout << "NO\n";
		}
	}
    return 0;
}