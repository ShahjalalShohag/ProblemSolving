#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int ans[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 1;
		int k = n;
		while (k % 2 == 0) k /= 2;
		if (k == 1) ans = 0;
		bool is_prime = 1;
		for (int i = 2; i * i <= k; i++) {
			if (k % i == 0) {
				is_prime = 0;
				break;
			}
		}
		if (n % 2 == 0 && n % 4 != 0 && is_prime) ans = 0;
		if (n == 2) ans = 1;
		if (ans) cout << "Ashishgup\n";
		else cout << "FastestFinger\n";
	}
    return 0;
}