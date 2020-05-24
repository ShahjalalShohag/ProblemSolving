#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto &x: a) cin >> x;
		sort(a.begin(), a.end());
		int ans = 100000;
		for (int i = 1; i < n; i++) ans = min(ans, a[i] - a[i - 1]);
		cout << ans << '\n';
	}
    return 0;
}