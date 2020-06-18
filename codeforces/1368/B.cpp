#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long k; cin >> k;
	vector<int> cnt(10, 1);
	while (1) {
		long long nw = 1;
		int mn = 10000000;
		for (auto x: cnt) {
			nw *= x;
			mn = min(mn, x);
		}
		if (nw >= k) break;
		for (auto &x: cnt) {
			if (x == mn) {
				x++;
				break;
			}
		}
	}
	string s = "codeforces";
	for (int i = 0; i < 10; i++) {
		cout << string(cnt[i], s[i]);
	}
	cout << '\n';
    return 0;
}