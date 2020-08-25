#include<bits/stdc++.h>
using namespace std;

const int N = 3030;
int a[N], cnt[N][N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) ans += cnt[a[i]][a[j]];
			for (int j = i - 1; j >= 1; j--) cnt[a[j]][a[i]]++;
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cnt[i][j] = 0;
			}
		}
	}
    return 0;
}