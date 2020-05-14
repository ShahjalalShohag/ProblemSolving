#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int n, m; cin >> n >> m;
		if (n == 1) cout << 0 << '\n';
		else if (n == 2) cout << m << '\n';
		else cout << m * 2 << '\n';
	}
    return 0;
}