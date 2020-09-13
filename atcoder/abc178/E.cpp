#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	long long mx1 = -2e9, mx2 = -2e9, mn1 = 2e9, mn2 = 2e9;
	for (int i = 0; i < n; i++) {
		long long x, y; cin >> x >> y;
		mx1 = max(mx1, x + y);
		mn1 = min(mn1, x + y);		
		mx2 = max(mx2, x - y);
		mn2 = min(mn2, x - y);
	}
	cout << max(mx1 - mn1, mx2 - mn2) << '\n';
    return 0;
}