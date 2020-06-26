#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
const long long inf = 1e16;
long long a[N];
struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    long long t[4 * N], lazy[4 * N];
    ST() {
        for (int i = 0; i < 4 * N; i++) t[i] = inf;
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int n, int b, int e) {
        if (lazy[n] == 0) return;
        t[n] = t[n] + lazy[n];
        if (b != e) {
            lazy[lc] = lazy[lc] + lazy[n];
            lazy[rc] = lazy[rc] + lazy[n];
        }
        lazy[n] = 0;
    }
    inline long long combine(long long a,long long b) {
        return min(a, b);
    }
    inline void pull(int n) {
        t[n] = min(t[lc], t[rc]);
    }
    void build(int n, int b, int e, int k) {
        lazy[n] = 0;
        if (b == e) {
            t[n] = a[b] + k * b;
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid, k);
        build(rc, mid + 1, e, k);
        pull(n);
    }
    void upd(int n, int b, int e, int i, int j, long long v) {
        push(n, b, e);
        if (j < b || e < i) return;
        if (i <= b && e <= j) {
            lazy[n] = v;
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }    
    void set(int n, int b, int e, int i, int j, long long v) {
        push(n, b, e);
        if (j < b || e < i) return;
        if (i <= b && e <= j) {
            t[n] = v;
            return;
        }
        int mid = (b + e) >> 1;
        set(lc, b, mid, i, j, v);
        set(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    long long query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if (i > e || b > j) return inf + inf;
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
}t1, t2;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q, x, y; cin >> n >> q >> x >> y;
	int last = y;
	for (int i = 1; i <= n; i++) a[i] = inf;
	a[x] = 0;
	t1.build(1, 1, n, 1);
	t2.build(1, 1, n, -1);
	while (q--) {
		int x; cin >> x;
		long long z = min(t2.query(1, 1, n, 1, x) + x, 
			t1.query(1, 1, n, x, n) - x);
		long long p1 = t1.query(1, 1, n, last, last) - last;
		long long p2 = t2.query(1, 1, n, last, last) + last;
		if (last > 1) t1.upd(1, 1, n, 1, last - 1, abs(x - last));
		if (last < n) t1.upd(1, 1, n, last + 1, n, abs(x - last));
		if (last > 1) t2.upd(1, 1, n, 1, last - 1, abs(x - last));
		if (last < n) t2.upd(1, 1, n, last + 1, n, abs(x - last));
		t1.set(1, 1, n, last, last, min(z, p1 + abs(x - last)) + last);
		t2.set(1, 1, n, last, last, min(z, p2 + abs(x - last)) - last);
		last = x;
	}
	long long ans = inf;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, t1.query(1, 1, n, i, i) - i);
		ans = min(ans, t2.query(1, 1, n, i, i) + i);
	}
	cout << ans << '\n';
    return 0;
}