#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		if (n / k >= m) cout << m << '\n';
		else {
			int r = m - n / k;
			cout << n / k - (r + k - 2) / (k - 1) << '\n';
		}
	}
    return 0;
}