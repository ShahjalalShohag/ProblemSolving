#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> cnt(26, 0);
		for (auto c: s) cnt[c - 'a']++;
		int ans = 1;
		for (int d = 1; d <= n; d++) {
			if (k % d != 0) continue;
			for (int i = 1; i * d <= n; i++) {
				int sum = 0;
				for (int c = 0; c < 26; c++) {
					sum += cnt[c] / i;
				}
				if (sum >= d) ans = max(ans, i * d);
			}
		}
		cout << ans << '\n';
	}
    return 0;
}