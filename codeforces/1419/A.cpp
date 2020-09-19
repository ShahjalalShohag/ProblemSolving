#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int cnt[2][2];
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i++) {
			cnt[i % 2][(s[i] - '0') % 2]++;
		}
		int ans;
		if (n & 1) {
			if (cnt[0][1]) ans = 1;
			else ans = 2;
		}
		else {
			if (cnt[1][0]) ans = 2;
			else ans = 1;
		}
		cout << ans << '\n';
	}
    return 0;
}