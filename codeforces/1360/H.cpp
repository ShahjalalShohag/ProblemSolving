#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

long long a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			long long k = 0;
			for (auto x: s) k = k * 2 + (x == '1');
			a[i] = k;
		}
		long long len = (1LL << m) - n;
		long long l = 0, r = (1LL << m) - 1, ans = 0;
		while (l <= r) {
			long long mid = l + (r - l) / 2;
			long long p = mid + 1;
			for (int i = 0; i < n; i++) {
				if (a[i] <= mid) p--;
			}
			if (p >= (len + 1) / 2) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		for (int i = m - 1; i >= 0; i--) {
			if (ans >> i & 1) cout << '1';
			else cout << '0';
		}
		cout << '\n';
	}
    return 0;
}