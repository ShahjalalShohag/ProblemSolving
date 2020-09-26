#include<bits/stdc++.h>
using namespace std;

const int N = 6e5 + 9;

struct ST {
    int t[4 * N];
    ST() {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e) {
        if(b == e) {
            t[n] = 0;
            return;
        }
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = max(t[l], t[r]);
    }
    void upd(int n, int b, int e, int i, int x) {
        if(b > i || e < i) return;
        if(b == e && b == i) {
            t[n] = max(t[n], x);
            return;
        }
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = max(t[l], t[r]);
    }
    int query(int n, int b, int e, int i, int j) {
        if(b > j || e < i) return -1e9;
        if(b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return max(L, R);
    }
} t;

int dp[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	t.build(1, 1, N - 1);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		dp[x] = t.query(1, 1, N - 1, max(0, x - k) + 1, x + k + 1) + 1;
		t.upd(1, 1, N - 1, x + 1, dp[x]);
		ans = max(ans, dp[x]);
	}
	cout << ans << '\n';
    return 0;
}