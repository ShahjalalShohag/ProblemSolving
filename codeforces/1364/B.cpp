#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<int> ans({a[1], a[2]});
		for (int i = 3; i <= n; i++) {
			int u = ans[ans.size() - 2], v = ans.back();
			if (u < v && v < a[i]) ans.pop_back();
			else if (u > v && v > a[i]) ans.pop_back();
			ans.push_back(a[i]);
		}
		cout << ans.size() << '\n';
		for (auto x: ans) cout << x << ' '; cout << '\n';
	}
    return 0;
}