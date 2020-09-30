#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

 #define lc (n << 1)
 #define rc ((n << 1) | 1)
 int t[4 * N], id[N];
 void upd(int n, int b, int e, int i, int j, int v) {
     if (j < b || e < i) return;
     if (i <= b && e <= j) {
         t[n] = max(t[n], v);
         return;
     }
     int mid = (b + e) >> 1;
     upd(lc, b, mid, i, j, v);
     upd(rc, mid + 1, e, i, j, v);
}
void dfs(int n, int b, int e, int p = 0) {
	t[n] = max(t[n], p);
	if (b == e) {
		id[b] = n;
		return;
	}
	int mid = b + e >> 1;
	dfs(lc, b, mid, t[n]);
	dfs(rc, mid + 1, e, t[n]);
}
int a[N * 2], nxt[N * 2];
pair<int, int> p[N];
int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, m; cin >> n >> m;
   int mn = N;
   for (int i = 0; i < n; i++) {
   	cin >> p[i].first >> p[i].second;
   	mn = min(mn, p[i].first);
   }
   memset(a, -1, sizeof a);
   for (int i = 0; i < m; i++) {
   	int x, y; cin >> x >> y;
   	a[x] = max(a[x], y);
   }
   nxt[N - 1] = N;
   for (int i = N - 2; i >= 0; i--) {
   	a[i] = max(a[i], a[i + 1]);
   	if (a[i] == a[i + 1]) nxt[i] = nxt[i + 1];
   	else nxt[i] = i + 1;
   }
   for (int i = 0; i < n; i++) {
   	for (int j = p[i].first; j < N; j = nxt[j]) {
   		upd(1, 1, N - 1, j - p[i].first + 1, nxt[j] - p[i].first, a[j] != -1 ? a[j] - p[i].second + 1 : 0);
   	}
   }
   dfs(1, 1, N - 1);
   int ans = 1e9;
   for (int x = mn; x < N; x++) {
   	int r = (x - mn), u = t[id[r + 1]];
   	ans = min(ans, u + r);
   }
   cout << ans << '\n';
   return 0;
}