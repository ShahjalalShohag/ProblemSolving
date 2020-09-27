#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
vector<int> a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			a[i] = vector<int>(1, 0);
		}
		for (int i = 1; i <= n; i++) {
			int k; cin >> k;
			a[k].push_back(i);
		}
		vector<int> ans(n + 2, n + 1);
		for (int i = 1; i <= n; i++) {
			a[i].push_back(n + 1);
			int mx = 0;
			for (int k = 1; k < a[i].size(); k++) {
				mx = max(mx, a[i][k] - a[i][k - 1]);
			}
			ans[mx] = min(ans[mx], i);
		}
		for (int i = 1; i <= n; i++) {
			ans[i] = min(ans[i], ans[i - 1]);
			if (ans[i] == n + 1) cout << -1 << ' ';
			else cout << ans[i] << ' ';
		}
		cout << '\n';
	}
    return 0;
}