#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			ans |= b == c;
		}
		if (m % 2 == 0 && ans) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}