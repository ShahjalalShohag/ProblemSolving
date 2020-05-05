#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

vector<vector<int>> decompose(vector<int> &p) {
    int n = p.size();
    vector<vector<int>> cycles;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vector<int> v;
            while (!vis[i]) {
                v.push_back(i);
                vis[i] = 1;
                i = p[i];
            }
            cycles.push_back(v);
        }
    }
    return cycles;
}
vector<int> restore(int n, vector<vector<int>> &cycles) {
	vector<int> p(n);
	for (auto v: cycles) {
		int m = v.size();
		for (int i = 0; i < m; i++) p[v[i]] = v[(i + 1) % m];
	}
	return p;
}
vector<vector<int>> root(vector<int> &p, int k) {
    int n = p.size();
    vector<vector<int>> cycles[n + 1];
    auto d = decompose(p);
    for (auto v: d) cycles[(int)v.size()].push_back(v);
    vector<vector<int>> ans;
    for (int len = 1; len <= n; len++) {
        if (cycles[len].empty()) continue;
        int tmp = k, t = 1, x = __gcd(len, tmp);
        while (x != 1) {
            t *= x; tmp /= x;
            x = __gcd(len, tmp);
        }
        if ((int)cycles[len].size() % t != 0) {
        	ans.clear();
        	return ans; //no solution exists
        }
        int id = 0;
        for (int i = id; i < (int)cycles[len].size(); i += t) {
            int m = t * len;
            vector<int> cycle(m);
            for (int x = 0; x < t; x++) { //merging t cycles
                for (int y = 0; y < len; y++) {
                    cycle[(x + 1LL * y * k) % m] = cycles[len][i + x][y];
                }
            }
            ans.push_back(cycle);
        }
    }
    return ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> p(n);
	for (auto &x: p) cin >> x, --x;
	auto c = root(p, 2);
	if (c.empty()) return cout << - 1 << '\n', 0;
	auto ans = restore(n, c);
	for (auto x: ans) cout << x + 1 << ' '; cout << '\n';
    return 0;
}