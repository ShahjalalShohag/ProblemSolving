#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long a, b, n; cin >> a >> b >> n;
		int ans = 0;
		while (a <= n && b <= n) {
			if (a < b) a += b;
			else b += a;
			ans++;
		}
		cout << ans << '\n';
	}
    return 0;
}