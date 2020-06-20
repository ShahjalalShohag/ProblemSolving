#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int b[N], dp[N], a[N];
int get(int n) {
	for (int i = 1; i <= n; i++) {
		dp[i] = b[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	return dp[n];
}
int yo(int n, int k) {
	if (k % 2 == 0) {
		if (get(n - 1) >= k / 2) return 1;
		reverse(b + 1, b + n + 1);
		if (get(n - 1) >= k / 2) return 1;
		return 0;
	}
	if (get(n) >= (k + 1) / 2) return 1;
	for (int i = 2; i < n; i++) b[i - 1] = b[i];
	if (n > 2 && get(n - 2) >= k / 2) return 1;
	return 0;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e9, ans = 1e9;
	if (k == 1) {
		for (int i = 1; i <= n; i++) ans = min(ans, a[i]);
		cout << ans << '\n';
		return 0;
	}
	while (l <= r) {
		int mid = l + r >> 1;
		for (int i = 1; i <= n; i++) b[i] = a[i] <= mid;
		if (yo(n, k)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
    return 0;
}