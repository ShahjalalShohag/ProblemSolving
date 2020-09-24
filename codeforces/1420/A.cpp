#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int ok = 1;
		for (int i = 1; i < n; i++) {
			ok &= a[i] < a[i - 1];
		}
		if (ok) cout << "NO\n";
		else cout << "YES\n";
	}
    return 0;
}