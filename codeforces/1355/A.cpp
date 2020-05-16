#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long a, k; cin >> a >> k;
		k--;
		while (k--) {
			int mn = 9, mx = 0;
			long long p = a;
			while (p) {
				int x = p % 10;
				mn = min(mn, x); mx = max(mx, x);
				p /= 10;
			}
			if (mn * mx == 0) break;
			a += mn * mx;
		}
		cout << a << '\n';
	}
    return 0;
}