#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> cnt(2, 0);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			cnt[k % 2]++;
			tot += k % 2 != i % 2;
		}
		if (cnt[1] != n / 2) cout << - 1 << '\n';
		else cout << (tot + 1) / 2 << '\n';
	}
    return 0;
}