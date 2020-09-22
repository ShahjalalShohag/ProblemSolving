#include<bits/stdc++.h>
using namespace std;

int a[100100];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	map<int, int> mp;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % k == 0 && mp[a[i] / k]) continue;
		ans++;
		mp[a[i]] = 1;
	}
	cout << ans << '\n';
    return 0;
}