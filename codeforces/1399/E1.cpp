#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

inline long long profit(pair<int, int> &x) {
	return 1LL * (x.first - x.first / 2) * x.second;
}
struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return profit(a) < profit(b);
    }
};
vector<pair<int, int>> g[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
long long sum;
int dfs(int u, int p = 0) {
	int leaf = 1, cnt = 0;
	for (auto e: g[u]) {
		int v = e.first, w = e.second;
		if (v == p) continue;
		int k = dfs(v, u);
		q.push({w, k});
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
		    int u, v, w; cin >> u >> v >> w;
		    g[u].push_back({v, w});
		    g[v].push_back({u, w});
		}
		sum = 0;
		while (!q.empty()) q.pop();
		dfs(1);
		int ans = 0;
		while (sum > s) {
			auto x = q.top();
			q.pop();
			sum -= profit(x);
			x.first /= 2;
			q.push(x);
			ans++;
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) g[i].clear();
	}
    return 0;
}