#include<bits/stdc++.h>
using namespace std;

int n, l1, r1, l2, r2;
long long yo(long long t) {
	long long ans = 0, extra = 0, already = 0, len = 0;
	if (r1 < l2) extra = l2 - r1;
	if (r2 < l1) extra = l1 - r2;
	already = max(0, min(r1, r2) - max(l1, l2));
	len = max(r1, r2) - min(l1, l2);
	ans = already * n;
	if (t <= extra) return ans;
	t -= extra;
	if (t <= len - already) return ans + t;
	ans += len - already;
	t -= len - already;
	for (int i = 1; i < n; i++) {
		if (t <= extra) break;
		long long moves = extra;
		moves += min(len - already, t - extra);
		long long profit = min(len - already, t - extra);
		if (profit * 2 < moves) break;
		ans += profit;
		t -= moves;
	}
	return ans + t / 2;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		long long k; cin >> n >> k;
		cin >> l1 >> r1 >> l2 >> r2;
		long long l = 0, r = 2e9 + 2, ans = 0;
		while (l <= r) {	
			long long mid = (l + r) / 2;
			if (yo(mid) >= k) {
				ans = mid; r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
    return 0;
}