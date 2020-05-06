#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<int> se;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			k %= n; k = (k + n) % n;
			se.insert((k + i) % n);
		}
		if (se.size() == n) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}