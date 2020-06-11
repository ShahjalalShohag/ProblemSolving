#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x, q; cin >> n >> x >> q;
		int L = x, R = x;
		while (q--) {
			int l, r; cin >> l >> r;
			if (l > R || r < L) ;
			else L = min(L, l), R = max(R, r);
		}
		cout << R - L + 1 << '\n';
	}
    return 0;
}