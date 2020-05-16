#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		int ans = 0, cur = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] <= cur + 1) {
				ans ++; cur = 0;
			}
			else cur++;
		}
		cout << ans << '\n';
	}
    return 0;
}