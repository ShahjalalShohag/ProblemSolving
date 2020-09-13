#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
int a[N], b[N];

long long ans;
vector<int> swa, swb;
inline void upd(vector<int> ta, vector<int> tb, long long x) {
	if (x < ans) {
		ans = x;
		swa = ta;
		swb = tb;
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	long long sa = 0, sb = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sa += a[i];
	}
	int m; cin >> m;	
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		sb += b[i];
	}
	ans = abs(sa - sb);
	vector<array<long long, 3>> two;
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			two.push_back({b[i] + b[j], i, j});
		}
	}
	sort(two.begin(), two.end());
	auto tmp = two;
	two.clear();
	if (tmp.size()) two.push_back(tmp[0]);
	for (int i = 1; i < tmp.size(); i++) {
		if (two.back()[0] != tmp[i][0]) {
			two.push_back(tmp[i]);
		}
	}
	long long p = sa - sb;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			upd({i}, {j}, abs(sa - sb - 2LL * (a[i] - b[j])));
		}
		for (int j = i + 1; j <= n; j++) {
			int x = lower_bound(two.begin(), two.end(), array<long long, 3>({a[i] + a[j] - p / 2, -1, -1})) - two.begin();
			for (int k = max(0, x - 5); k < min((int)two.size(), x + 5); k++) {
				upd({i, j}, {(int)two[k][1], (int)two[k][2]}, abs(sa - sb - 2LL * (a[i] + a[j] - two[k][0])));
			}
		}
	}
	cout << ans << '\n';
	cout << swa.size() << '\n';
	for (int i = 0; i < swa.size(); i++) {
		cout << swa[i] << ' ' << swb[i] << '\n';
	}
    return 0;
}