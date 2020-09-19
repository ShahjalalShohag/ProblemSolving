#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> v;
	for (int i = n / 2, j = 0; i < n; i++, j++) {
		v.push_back(a[i]);
		if (j < n / 2) v.push_back(a[j]);
	}
	int ans = 0;
	for (int i = 1; i + 1 < n; i++) {
		ans += (v[i] < v[i - 1]) && (v[i] < v[i + 1]);
	}
	cout << ans << '\n';
	for (auto x: v) cout << x << ' ';
    return 0;
}