#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long n; cin >> n;
		int ans = 0;
		__int128 c = 0;
		for (long long i = 1; i <= n; i *= 2) {
			c += i;
			__int128 p = c * (c + 1) / 2;
			if (p <= n) ans++;
			else break;
			n -= p;
		}
		cout << ans << '\n';
	}
    return 0;
}