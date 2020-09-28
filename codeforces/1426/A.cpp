#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		if (n <= 2) cout << 1 << '\n';
		else {
			for (int i = 1; ; i++) {
				if (n <= i * x + 2) {
					cout << i + 1 << '\n';
					break;
				}
			}
		}
	}
    return 0;
}