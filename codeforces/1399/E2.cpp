#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

inline long long profit(array<int, 3> &x) {
	return 1LL * (x[0] - x[0] / 2) * x[1];
}
struct cmp {
    bool operator()(array<int, 3> &a, array<int, 3> &b) {
        return profit(a) < profit(b);
    }
};
vector<array<int, 3>> g[N];
priority_queue<array<int, 3>, vector<array<int, 3>>, cmp> q[3];
long long sum;
int dfs(int u, int p = 0) {
	int leaf = 1, cnt = 0;
	for (auto e: g[u]) {
		int v = e[0], w = e[1], c = e[2];
		if (v == p) continue;
		int k = dfs(v, u);
		q[c].push({w, k, c});
		sum += 1LL * w * k;
		cnt += k;
		leaf = 0;
	}
	return cnt + leaf;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		long long s; cin >> s;
		for (int i = 1; i < n; i++) {
		    int u, v, w, k; cin >> u >> v >> w >> k;
		    g[u].push_back({v, w, k});
		    g[v].push_back({u, w, k});
		}
		sum = 0;
		for (int i = 1; i <= 2; i++) {
			while (!q[i].empty()) q[i].pop();
		}
		dfs(1);
		vector<long long> v;
		int ans = 1e9;
		if (sum - s <= 0) ans = 0;
		long long cur = 0;
		while (q[1].size()) {
			auto x = q[1].top();
			q[1].pop();
			cur += profit(x);
			if (profit(x) == 0) break;
			x[0] /= 2;
			q[1].push(x);
			v.push_back(cur);
		}
		long long p = cur;
		cur = 0;
		int cnt = 0, last = 0;
		while (1) {
			int k = 0;
			if (sum - cur > s && p >= sum - cur - s && v.size()) {
				k = lower_bound(v.begin(), v.end(), sum - cur - s) - v.begin() + 1;
			}
			if (p >= sum - cur - s) ans = min(ans, cnt * 2 + k);
			if (last || q[2].empty()) break;
			auto x = q[2].top();
			q[2].pop();
			cur += profit(x);
			if (profit(x) == 0) last = 1;
			x[0] /= 2;
			q[2].push(x);
			cnt++;
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) g[i].clear();
	}
    return 0;
}