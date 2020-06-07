#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")


#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

unsigned long long a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, B; cin >> A >> B;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		if (i + 63 < n) {
			unsigned long long mask = 0;
			for (int j = i; j <= i + 63; j++) {
				mask = (mask << 1) + (A[j] - '0');
			}
			a[i] = mask;
		}
	}
	int m = B.size();
	for (int i = 0; i < m; i++) {
		if (i + 63 < m) {
			unsigned long long mask = 0;
			for (int j = i; j <= i + 63; j++) {
				mask = (mask << 1) + (B[j] - '0');
			}
			b[i] = mask;
		}
	}
	int q; cin >> q;
	while (q--) {
		int l1, l2, x; cin >> l1 >> l2 >> x;
		int ans = 0;
		while (x >= 64) {
			ans += __builtin_popcountll(a[l1] ^ b[l2]);
			l1 += 64; l2 += 64; x -= 64;
		}
		for (int i = 0; i < x; i++) ans += A[l1 + i] != B[l2 + i];
		cout << ans << '\n';
	}
    return 0;
}