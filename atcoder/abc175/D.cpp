#include<bits/stdc++.h>
using namespace std;

int a[5050], p[5050], vis[5050];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	long long ans = -2e18;
	for (int x = 1; x <= n; x++) {
		if (vis[x]) continue;
		vector<int> v;
		long long sum = 0;
		while (!vis[x]) {
			vis[x] = 1;
			v.push_back(a[x]);
			sum += a[x];
			x = p[x];
		}
		auto t = v;
		for (auto x: t) v.push_back(x);
		int sz = t.size();
		for (int i = 0; i < sz; i++) {
			long long cur = 0;
			for (int j = i; j < i + sz; j++) {
				cur += v[j];
				if (j - i + 1 <= k) {
					ans = max(ans, cur);
					ans = max(ans, cur + (k - (j - i + 1)) / sz * sum);
				}
			}
		}
	}
	cout << ans << '\n';
    return 0;
}