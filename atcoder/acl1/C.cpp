#include<bits/stdc++.h>
using namespace std;
 
const int N = 51 * 51;
// Complexity: O(n^3) but optimized
// It finds minimum cost maximum matching.
// For finding maximum cost maximum matching
// add -cost and return -matching()
// 1-indexed
struct Hungarian {
    int c[N][N], fx[N], fy[N], d[N];
    int l[N], r[N], arg[N], trace[N];
    queue<int> q;
    int start, finish, n;
    const int inf = 1e9;
    Hungarian() {}
    Hungarian(int n): n(n) {
        for (int i = 1; i <= n; ++i) {
            fy[i] = l[i] = r[i] = 0;
            for (int j = 1; j <= n; ++j) c[i][j] = inf;
        }
    }
    void add_edge(int u, int v, int cost) {
        c[u][v] = min(c[u][v], cost);
    }
    inline int getC(int u, int v) {
        return c[u][v] - fx[u] - fy[v];
    }
    void initBFS() {
        while (!q.empty()) q.pop();
        q.push(start);
        for (int i = 0; i <= n; ++i) trace[i] = 0;
        for (int v = 1; v <= n; ++v) {
            d[v] = getC(start, v);
            arg[v] = start;
        }
        finish = 0;
    }
    void findAugPath() {
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v = 1; v <= n; ++v) if (!trace[v]) {
                int w = getC(u, v);
                if (!w) {
                    trace[v] = u;
                    if (!r[v]) {
                        finish = v;
                        return;
                    }
                    q.push(r[v]);
                }
                if (d[v] > w) {
                    d[v] = w;
                    arg[v] = u;
                }
            }
        }
    }
    void subX_addY() {
        int delta = inf;
        for (int v = 1; v <= n; ++v) if (trace[v] == 0 && d[v] < delta) {
            delta = d[v];
        }
        // Rotate
        fx[start] += delta;
        for (int v = 1; v <= n; ++v) if(trace[v]) {
            int u = r[v];
            fy[v] -= delta;
            fx[u] += delta;
        } else d[v] -= delta;
        for (int v = 1; v <= n; ++v) if (!trace[v] && !d[v]) {
            trace[v] = arg[v];
            if (!r[v]) {
                finish = v; return;
            }
            q.push(r[v]);
        }
    }
    void Enlarge() {
        do {
            int u = trace[finish];
            int nxt = l[u];
            l[u] = finish;
            r[finish] = u;
            finish = nxt;
        } while (finish);
    }
    int maximum_matching() {
        for (int u = 1; u <= n; ++u) {
            fx[u] = c[u][1];
            for (int v = 1; v <= n; ++v) {
                fx[u] = min(fx[u], c[u][v]);
            }
        }
        for (int v = 1; v <= n; ++v) {
            fy[v] = c[1][v] - fx[1];
            for (int u = 1; u <= n; ++u) {
                fy[v] = min(fy[v], c[u][v] - fx[u]);
            }
        }
        for (int u = 1; u <= n; ++u) {
            start = u;
            initBFS();
            while (!finish) {
                findAugPath();
                if (!finish) subX_addY();
            }
            Enlarge();
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) if (l[i] != 0 && c[i][l[i]] != inf) ans += c[i][l[i]];
        return ans;
    }
};
string s[55];
bool vis[55][55];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    Hungarian M(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            function<void(int, int)> dfs = [&](int x, int y) {
                if (s[x][y] == '#') return;
                if (vis[x][y]) return;
                vis[x][y] = 1;
                M.add_edge(i * m + j + 1, x * m + y + 1, -(x - i + y - j));
                if (x + 1 < n) dfs(x + 1, y);
                if (y + 1 < m) dfs(x, y + 1);
            };
            if (s[i][j] == '#') continue;
            if (s[i][j] == 'o') {
                memset(vis, 0, sizeof vis);
                dfs(i, j);
            }
        }
    }
    cout << -M.maximum_matching() << '\n';
    return 0;
}