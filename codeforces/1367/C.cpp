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
		int ans = 0;
		for (int i = 0, j; i < n; i = j) {
			for (j = i + 1; j < n && s[i] == s[j]; j++);
			if (s[i] == '0') {
				if (i == 0 && j == n) ans += (j - i + k) / (k + 1);
				else if (i == 0 || j == n) ans += (j - i) / (k + 1);
				else ans += j - i >= k ? (j - i - k) / (k + 1) : 0;
			}
		}
		cout << ans << '\n';
	}
    return 0;
}