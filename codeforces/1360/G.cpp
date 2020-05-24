#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

const int inf = 1 << 20;
struct Dinic {
    struct edge {int to, rev; int flow, w; int id;};
	int n, s, t, mxid;
	vector<int> d, flow_through; vector<int> done;
	vector<vector<edge>> g;
	Dinic() {}
	Dinic(int _n) {
		n = _n + 10; mxid = 0;
		g.resize(n);
	}
	void add_edge(int u, int v, int w, int id = -1) {
		edge a = {v, (int)g[v].size(), 0, w, id};
		edge b = {u, (int)g[u].size(), 0, 0, -1};//for bidirectional edges cap(b) = w
		g[u].emplace_back(a);
		g[v].emplace_back(b);
		mxid = max(mxid, id);
	}
	bool bfs() {
		d.assign(n, -1); d[s] = 0;
		queue<int> q; q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto &e: g[u]) {
				int v = e.to;
				if (d[v] == -1 && e.flow < e.w) d[v] = d[u] + 1, q.push(v);
			}
		}
		return d[t] != -1;
	}
	int dfs(int u, int flow) {
		if (u == t) return flow;
		for (int &i = done[u]; i < (int)g[u].size(); i++) {
			edge &e = g[u][i];
			if (e.w <= e.flow) continue;
			int v = e.to;
			if (d[v] == d[u] + 1) {
				int nw = dfs(v, min(flow, e.w - e.flow));
				if (nw > 0) {
					e.flow += nw;
					g[v][e.rev].flow -= nw;
					return nw;
				}
			}
		}
		return 0;
	}
	int max_flow(int _s, int _t) {
		s = _s; t = _t;
		int flow = 0;
		while (bfs()) {
			done.assign(n, 0);
			while (int nw = dfs(s, inf)) flow += nw;
		}
		flow_through.assign(mxid + 10, 0);
        for(int i = 0; i < n; i++) for(auto e: g[i]) if(e.id >= 0) {
        	flow_through[e.id] = e.flow;
        }
		return flow;
	}
};
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int n, m, a, b; cin >> n >> m >> a >> b;
		int sum = 0, s = n + m, t = s + 1;
		Dinic F(t);
		for (int i = 0; i < n; i++) {
			F.add_edge(s, i, a);
		}	
		for (int i = 0; i < m; i++) {
			F.add_edge(i + n, t, b);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) F.add_edge(i, j + n, 1, i * m + j);
		}
		int ans = F.max_flow(s, t);
		if (ans != n * a || ans != m * b) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					int nw = F.flow_through[i * m + j];
					cout << char('0' + nw);
				}
				cout << '\n';
			}
		}
	}
    return 0;
}