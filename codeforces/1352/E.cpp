#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<bool> ok(n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			int sum = a[i];
			for (int j = i + 1; j <= n; j++) {
				sum += a[j];
				if (sum <= n) ok[sum] = 1;
				else break;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += ok[a[i]];
		cout << ans << '\n';
	}
    return 0;
}