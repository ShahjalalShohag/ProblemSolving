#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, mod = 998244353;

int a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	if (m > n) return cout << 0 << '\n', 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	long long ans = 1;
	for (int i = m, cur = n; i >= 1; i--) {
		int way = 0; int found = 0;
		while (cur >= 1 && a[cur] >= b[i]) {
			if (a[cur] == b[i]) found = 1;
			if (found) way++;
			cur--;
		}
		if (i == 1) {
			if (cur == 0 && found) way = 1;
			else way = 0;
		}
		if (found) ans = ans * way % mod;
		else {
			ans = 0;
			break;
		}
	}
	cout << ans << '\n';
    return 0;
}