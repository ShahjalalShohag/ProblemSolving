#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[200][2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(a, 0, sizeof a);
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int k; cin >> k;
				a[i + j][k]++;
			}
		}
		int ans = 0;
		for (int i = 0, j = n + m - 2; i < j; i++, j--) {
			ans += min(a[i][0] + a[j][0], a[i][1] + a[j][1]);
		}
		cout << ans << '\n';
	}
    return 0;
}