#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		if (k >= n) cout << k - n << '\n';
		else cout << (n - k) % 2 << '\n';
	}
    return 0;
}