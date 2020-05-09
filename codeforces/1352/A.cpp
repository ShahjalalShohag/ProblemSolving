#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> ans;
		int p = 1;
		while (n) {
			if (n % 10) ans.push_back(p * (n % 10));
			n /= 10;
			p *= 10;
		}
		cout << ans.size() << '\n';
		for (auto x: ans) cout << x << ' '; cout << '\n';
	}
    return 0;
}