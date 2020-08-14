#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		map<int, int> mp;
		int n; cin >> n;
		string s; cin >> s;
		mp[0] = 1;
		long long ans = 0;
		int cur = 0;
		for (auto x: s) {
			cur += x - '0' - 1;
			ans += mp[cur];
			mp[cur]++;
		}
		cout << ans << '\n';
	}
    return 0;
}