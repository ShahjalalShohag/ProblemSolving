#include<bits/stdc++.h>
using namespace std;

int a[100010];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (a[1] + a[2] <= a[n]) {
			cout << 1 << ' ' << 2 << ' ' << n << '\n';
		}
		else cout << -1 << '\n';
	}
    return 0;
}