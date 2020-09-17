#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
bool dp[N][N];
string s;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	int n = s.size(), LG = 0;
	while ((1 << LG) <= n) {
		LG++;
	}
	LG--;
	int len = n;
	for (int i = 0; i < LG; i++) {
		len -= 1 << i;
	}
	vector<array<int, 2>> cd, ncd;
	cd.push_back({0, 0});
	while (len --) {
		char ans = 'z';
		for (int z = 0; z < cd.size(); z++) {
			auto x = cd[z];
			int i = x[0], mask = x[1];
			ans = min(ans, s[i]);
			for (int k = 0; k < LG; k++) {
				if (~mask >> k & 1) {
					bool &f = dp[i + (1 << k)][mask | (1 << k)];
					if (!f) {
						f = 1;
						cd.push_back({i + (1 << k), mask | (1 << k)});
					}
				}
			}
		}
		cout << ans;
		ncd.clear();
		for (auto x: cd) {
			if (s[x[0]] == ans) {
				dp[x[0] + 1][x[1]] = 1;
				ncd.push_back({x[0] + 1, x[1]});
			}
		}
		cd = ncd;
	}
    return 0;
}