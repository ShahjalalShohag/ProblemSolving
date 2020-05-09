#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long n, k; cin >> n >> k;
		long long l = 1, r = 1e12, ans;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (mid - mid / n < k) l = mid + 1;
			else ans = mid, r = mid - 1;
		}
		cout << ans << '\n';
	}
    return 0;
}