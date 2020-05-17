#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

vector<int> a[N];
int last[N];
int t[N];
inline void upd(int i, int k) {
	while (i < N) t[i] += k, i += i & -i;
}
inline int query(int i) {
	int ans = 0;
	while (i) ans += t[i], i -= i & -i;
	return ans;
}
vector<pair<int, int>> Q[N];
int ans[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	map<pair<int, int>, int> mp;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		vector<pair<int, int>> p(k);
		for (int j = 0; j < k; j++) cin >> p[j].first >> p[j].second;
		for (int j = 0; j < k; j++) {
			pair<int, int> x = {p[(j + 1) % k].first - p[j].first, p[(j + 1) % k].second - p[j].second};
			int g = __gcd(abs(x.first), abs(x.second));
			x.first /= g; x.second /= g;
			if (mp.find(x) == mp.end()) mp[x], mp[x] = mp.size();
			a[i].push_back(mp[x]);
		}
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;
		Q[r].push_back({l, i});
	}
	for (int i = 1; i <= n; i++) {
		for (auto x: a[i]) {
			if (last[x]) upd(last[x], -1);
			last[x] = i;
			upd(last[x], +1);
		}
		for (auto x: Q[i]) ans[x.second] = query(N - 1) - query(x.first - 1);
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}