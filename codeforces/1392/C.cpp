#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		long long ans = 0;
		for (int i = 1; i <= n; ) {
			int j = i + 1;
			while (j <= n && a[j] <= a[j - 1]) j++;
			ans += a[i] - a[j - 1];
			i = j;
		}
		cout << ans << '\n';
	}
    return 0;
}