#include<bits/stdc++.h>
using namespace std;

long long a[30][30], s[30][30], mn[30][30];

int n;
set<long long> se;
void dfs(int i, int j, long long sum = 0) {
	if (i > n || j > n) return;
	if (i == n && j == n) { 
		if (se.find(sum + a[i][j]) != se.end()) {
			cout << "NO\n";
			exit(0);
		}
		se.insert(sum + a[i][j]);
		return;
	}
	dfs(i + 1, j, sum + a[i][j]);
	dfs(i, j + 1, sum + a[i][j]);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = s[i - 1][j] + 1;
			if (j == 1) s[i][j] = s[i - 1][j] + a[i][j];
			else s[i][j] = s[i][j - 1] + a[i][j];
			//cout << a[i][j] << ' ';
			mn[i][j] = mn[i - 1][j] + a[i][j];
		}
		//cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j > 1) cout << ' ';
			cout << a[i][j];
		}
		cout << '\n';
		cout.flush();
	}
	int q; cin >> q;
	while (q--) {
		long long sum; cin >> sum;
		vector<pair<int, int>> v;
		int i = n, j = n;
		while (i >= 1 && j >= 1) {
			sum -= a[i][j];
			v.push_back({i, j});
			if (j == 1) i--;
			else if (i == 1) j--;
			else if (sum >= mn[i][j - 1]) j--;
			else i--;
		}
		reverse(v.begin(), v.end());
		for (auto x: v) {
			cout << x.first << ' ' << x.second << '\n';
			cout.flush();
		}
	}
    return 0;
}