#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9;

int n, x[N], y[N], a[N][2], sid[N];
vector<int> g[N], gt[N];
int get_id(int i, int j, int k) {
	int z = a[i][j];
	if (k == 0) return z;
	else return z + 2 * n;
}
int get_segtree_id(int x) {
	return sid[x];
}
void add_edge(int u, int v) {
	g[u].push_back(v);
	gt[v].push_back(u);
}
void build(int cur, int b, int e) {
	if (b == e) {
		sid[cur] = b;
		return;
	}
	sid[cur] = 4 * n + cur;
	build(cur << 1, b, b + e >> 1);
	add_edge(sid[cur], sid[cur << 1]);
	if ((b + e >> 1) + 1 <= e) {
		build(cur << 1 | 1, (b + e >> 1) + 1, e);
		add_edge(sid[cur], sid[cur << 1 | 1]);
	}
}
void add(int n, int b, int e, int l, int r, int u) {
	if (b > r || e < l) return;
	if (b >= l && e <= r) {
		add_edge(u, get_segtree_id(n));
		return;
	}
	add(n << 1, b, b + e >> 1, l, r, u);
	add(n << 1 | 1, (b + e >> 1) + 1, e, l, r, u);
}
stack<int> ts;
bool vis[N];
int comp[N];
void dfs1(int u) {
	vis[u] = true;
	for (int v : g[u]) if (!vis[v]) dfs1(v);
	ts.push(u);
}
void dfs2(int u, int c) {
	comp[u] = c;
	for (int v : gt[u]) if (comp[v] == -1) dfs2(v, c);
}
vector<pair<int, int>> v;
bool yo(int d) {
	for (int i = 1; i < N; i++) {
		g[i].clear();
		gt[i].clear();
	}
	build(1, 1, 2 * n);
	for (int i = 1; i <= n; i++) {
		add_edge(get_id(i, 0, 0), get_id(i, 1, 1));
		add_edge(get_id(i, 1, 0), get_id(i, 0, 1));

		int l = upper_bound(v.begin(), v.end(), make_pair(x[i] - d, N)) - v.begin() + 1;
		int cur = get_id(i, 0, 0);
		if (l < cur) add(1, 1, 2 * n, l, cur - 1, get_id(i, 0, 1));	
		int r = upper_bound(v.begin(), v.end(), make_pair(x[i] + d, -1)) - v.begin() + 1;
		r--;
		if (cur < r) add(1, 1, 2 * n, cur + 1, r, get_id(i, 0, 1));	

		l = upper_bound(v.begin(), v.end(), make_pair(y[i] - d, N)) - v.begin() + 1;
		cur = get_id(i, 1, 0);
		if (l < cur) add(1, 1, 2 * n, l, cur - 1, get_id(i, 1, 1));	
		r = upper_bound(v.begin(), v.end(), make_pair(y[i] + d, -1)) - v.begin() + 1;
		r--;
		if (cur < r) add(1, 1, 2 * n, cur + 1, r, get_id(i, 1, 1));
	}
	memset(vis, 0, sizeof vis);
	ts = stack<int>();
	for (int i = 1; i < N; i++) if(!vis[i]) dfs1(i);
	int scc = 0;
	memset(comp, -1, sizeof comp);
	while (!ts.empty()) {
		int u = ts.top();
		ts.pop();
		if (comp[u] == -1) dfs2(u, scc++);
	}
	for (int i = 1; i <= 2 * n; i ++) {
		if (comp[i] == comp[i + 2 * n]) return false;
	}
	return true;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		v.push_back({x[i], i});
		v.push_back({y[i], i + n});
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= 2 * n; i++) {
		auto x = v[i - 1];
		if (x.second <= n) {
			a[x.second][0] = i;
		}
		else {
			a[x.second - n][1] = i;
		}
	}
	int l = 1, r = 1e9, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (yo(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
    return 0;
}