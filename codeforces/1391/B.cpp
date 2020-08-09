#include<bits/stdc++.h>
using namespace std;

string s[111];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> s[i];
		int ans = 0;
		for (int i = 0; i < n - 1; i++) ans += s[i][m - 1] != 'D';
		for (int i = 0; i < m - 1; i++) ans += s[n - 1][i] != 'R';
		cout << ans << '\n';
	}
    return 0;
}