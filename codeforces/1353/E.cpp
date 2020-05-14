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
		int one = 0;
		for (auto x: s) one += x == '1';
		int ans = max(0, one - 1);
		for (int st = 0; st < k; st++) {
			int nw = n;
			int cnt1 = 0, cnt0 = 0, mn = 0;
			vector<int> v; v.push_back(0);
			for (int i = st; i < n; i += k) {
				cnt1 += s[i] == '1';
				cnt0 += s[i] == '0';
				nw = min(nw, cnt0 - cnt1 + mn);
				mn = min(mn, cnt1 - cnt0);
			}
			ans = min(ans, nw + cnt1 + one - cnt1);
		}
		cout << ans << '\n';
	}
    return 0;
}