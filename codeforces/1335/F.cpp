#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

bool vis[N], a[N];
int id[N], cnt[N], g[N], T;
stack<int> st;
map<int, int> b[N];
int dis[N], rep[N];
void dfs(int u) {
	if(id[u]) return;
	int v = g[u];
	vis[u] = 1;
	if(id[v]) {
		id[u] = id[v];
		dis[u] = dis[v] + 1;
		return;
	}
	st.push(u);
	if (vis[v]) {
		++T;
		vector<int> vec;
		while (!st.empty() && st.top() != v) {
			id[st.top()] = T; vec.push_back(st.top());
			cnt[T]++;
			st.pop();
		}
		cnt[T]++; id[v] = T;
		rep[T] = u;
		for(int i = 0; i < vec.size(); i++) dis[vec[i]] = i;
		dis[v] = vec.size();
		reverse(vec.begin(), vec.end());
		for (auto x: vec) st.push(x);
	}
	else {
		dfs(v);
		id[u] = id[v];
		dis[u] = dis[v] + 1;
	}
	st.pop();
	return;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
    	int n, m; cin >> n >> m;
    	#define f(i, j) (i - 1) * m + j
    	for (int i = 1; i <= n; i++) {
    		string s; cin >> s;
    		for (int j = 1; j <= m; j++) {
    			if(s[j - 1] == '0') a[f(i, j)] = 1;
    		}
    	}
    	for (int i = 1; i <= n; i++) {
    		string s; cin >> s; s = "." + s;
    		for (int j = 1; j <= m; j++) {
    			if(s[j] == 'R') g[f(i, j)] = (f(i, j + 1));
    			if(s[j] == 'L') g[f(i, j)] = (f(i, j - 1));
    			if(s[j] == 'U') g[f(i, j)] = (f(i - 1, j));
    			if(s[j] == 'D') g[f(i, j)] = (f(i + 1, j));
    		}
    	}
    	int ans = 0, black = 0;
    	for (int i = 1; i <= n * m; i++) {
    		dfs(i);
    		int k = id[i];
    		if(a[i]) b[k][dis[i] % cnt[k]]++;
    		//cout << a[i] << ": ";
    		//cout << k << ' ';
    	}
    	//cout << '\n';
    	for (int i = 1; i <= T; i++) {
    		ans += cnt[i];
    		int nw = 0;
    		for (auto x: b[i]) nw += x.second > 0;
    		black += min(cnt[i], nw);
    	}
    	cout << ans << ' ' << black << '\n';
    	for (int i = 0; i <= n * m; i++) {
    		g[i] = id[i] = rep[i] = dis[i] = a[i] = cnt[i] = vis[i] = 0;
    		b[i].clear();
    	}
    	T = 0;
    	st = stack<int>();
    }
    return 0;
}