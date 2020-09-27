#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> cur;
	cur.push_back(a);
	int x = 0; 
	long long ans = 0;
	for (int k = 29; k >= 0; k--) {
		vector<long long> inv(2, 0);
		vector<vector<int>> nxt;
		for (auto v: cur) {
			vector<int> o, z;
			for (auto x: v) {
				int b = x >> k & 1;
				if (b) {
					inv[1] += z.size();
					o.push_back(x);
				}
				else {
					inv[0] += o.size();
					z.push_back(x);
				}
			}
			if (!o.empty()) nxt.push_back(o);
			if (!z.empty()) nxt.push_back(z);
		}
		cur = nxt;
		if (inv[0] <= inv[1]) {
			ans += inv[0];
		}
		else {
			ans += inv[1];
			x |= 1 << k;
		}
	}
	cout << ans << ' ' << x << '\n';
    return 0;
}