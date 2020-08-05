#include<bits/stdc++.h>
using namespace std;

int a[55], b[55];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int mna = 2e9, mnb = 2e9;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			mna = min(mna, a[i]);
		}		
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			mnb = min(mnb, b[i]);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += max(a[i] - mna, b[i] - mnb);
		}
		cout << ans << '\n';
	}
    return 0;
}