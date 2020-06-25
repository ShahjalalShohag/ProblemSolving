#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
int a[N];
bitset<N> pref[N], suf[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum < k) return cout << n << '\n', 0;
	pref[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1];
		if (a[i] <= k) {
			 pref[i]|= pref[i - 1] << a[i];
		}
	}
	suf[n + 1][0] = 1;
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1];
		if (a[i] <= k) {
			suf[i] |= suf[i + 1] << a[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		auto cur = pref[i - 1];
		for (int j = i + 1; j <= n; j++) {
			cur |= cur << a[j];
		}
		bool ok = false;
		for (int j = max(0, k - a[i]); j < k; j++) {
			ok |= cur[j];
		}
		ans += ok;
	}
	cout << n - ans << '\n';
    return 0;
}