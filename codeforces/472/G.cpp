#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

inline int popcount(int x){
    int counter = 0;
    __asm__ volatile ("POPCNT %1, %0;"
        :"=r"(counter)
        :"r"(x)
        :
    );
    return counter;
}
unsigned long long a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, B; cin >> A >> B;
	int M = 0;
	for (int i = 0; i < 31; i++) M |= 1 << i;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		if (i + 61 < n) {
			unsigned long long mask = 0;
			for (int j = i; j <= i + 61; j++) {
				mask = (mask << 1) + (A[j] - '0');
			}
			a[i] = mask;
		}
	}
	int m = B.size();
	for (int i = 0; i < m; i++) {
		if (i + 61 < m) {
			unsigned long long mask = 0;
			for (int j = i; j <= i + 61; j++) {
				mask = (mask << 1) + (B[j] - '0');
			}
			b[i] = mask;
		}
	}
	int q; cin >> q;
	while (q--) {
		int l1, l2, x; cin >> l1 >> l2 >> x;
		int ans = 0;
		while (x >= 62) {
			unsigned long long nw = a[l1] ^ b[l2];
			ans += popcount(nw & M) + popcount(nw >> 31);
			l1 += 62; l2 += 62; x -= 62;
		}
		for (int i = 0; i < x; i++) ans += A[l1 + i] != B[l2 + i];
		cout << ans << '\n';
	}
    return 0;
}