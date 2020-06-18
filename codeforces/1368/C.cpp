#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	set<pair<int, int>> ans;
	int x = 0, y = 0;
	for (int k = 0; k <= n; k++) {
		if (k % 2 == 0) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) continue;
					ans.insert({x + i, y + j});
				}
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) continue;
					ans.insert({x + i, y - j});
				}
			}
		}
		x += 2;
	}
	cout << ans.size() << '\n';
	for (auto x: ans) cout << x.first << ' ' << x.second << '\n';
    return 0;
}