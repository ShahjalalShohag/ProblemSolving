#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
int deg[N];
vector<int> g[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	int cur = m;
	for (int i = 0; i < n; i++) {
		vector<array<int, 2>> a(m);
		for (int j = 0; j < m; j++) {
			cin >> a[j][0];
			a[j][1] = j;
		}
		sort(a.begin(), a.end());
		int st = 0;
		cur++;
		for (int j = 0; j < m; ) {
			if (a[j][0] == -1) {
				j++;
				continue;
			}
			int k = j;
			while (k < m && a[j][0] == a[k][0]) {
				if (st) {
					g[cur].push_back(a[k][1]);
					deg[a[k][1]]++;
				}
				g[a[k][1]].push_back(cur + 1);
				deg[cur + 1]++;
				++k;
			}
			cur++;
			j = k;
			st = 1;
		}
	}
	queue<int> q;
	for (int i = 0; i < m; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	vector<int> ans;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u < m) ans.push_back(u + 1);
		for (auto v: g[u]) {
			--deg[v];
			if (deg[v] == 0) q.push(v);
		}
	}
	if (ans.size() < m) cout << -1 << '\n';
	else {
		for (auto i: ans) cout << i << ' ';
	}
    return 0;
}