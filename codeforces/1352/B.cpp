#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> ans;
		if (n >= k && n % 2 == k % 2) {
			for (int i = 1; i < k; i++) ans.push_back(1);
			ans.push_back(n - k + 1);
		}
		else if (n >= k * 2 && n % 2 == 0) {
			for (int i = 1; i < k; i++) ans.push_back(2);
			ans.push_back(n - 2 * k + 2);
		}
		if (ans.size()) {
			cout << "YES\n";
			for (auto x: ans) cout << x << ' '; cout << '\n';
		}
		else cout << "NO\n";
	}
    return 0;
}