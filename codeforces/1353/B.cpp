#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
int a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		for (int i = 0, j = n - 1; k && i < n; i++, j--, k--) {
			if (a[i] < b[j]) swap(a[i], b[j]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) ans += a[i];
		cout << ans << '\n';
	}
    return 0;
}