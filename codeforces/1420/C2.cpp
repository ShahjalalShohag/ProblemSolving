#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
struct node {
	long long a[2][2];
	node() {
		memset(a, 0, sizeof a);
	}
};
int c[N];
struct ST {
    node t[N * 4];
    node merge(node l, node r) {
    	node ans = node();
    	for (int i = 0; i < 2; i++) {
    		for (int j = 0; j < 2; j++) {
    			ans.a[i][j] = max(l.a[i][j], r.a[i][j]);
    			for (int k = 0; k < 2; k++) {
    				ans.a[i][j] = max(ans.a[i][j], l.a[i][k] + r.a[k ^ 1][j]);
    			}
    		}
    	}
    	return ans;
    }
    void build(int n, int b, int e) {
        if(b == e) {
            t[n].a[0][0] = c[b];
            t[n].a[1][1] = -c[b];
            t[n].a[0][1] = -1e12;
            t[n].a[1][0] = -1e12;
            return;
        }
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = merge(t[l], t[r]);
    }
    void upd(int n, int b, int e, int i, int x) {
        if(b > i || e < i) return;
        if(b == e && b == i) {
            t[n].a[0][0] = x;
            t[n].a[1][1] = -x;
            t[n].a[0][1] = -1e12;
            t[n].a[1][0] = -1e12;
            return;
        }
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = merge(t[l], t[r]);
    }
} t;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n, q; cin >> n >> q;
		for (int i = 1; i <= n; i++) cin >> c[i];
		t.build(1, 1, n);
		cout << max({t.t[1].a[0][0], t.t[1].a[0][1], t.t[1].a[1][0], t.t[1].a[1][1]}) << '\n';
		while (q--) {
			int l, r; cin >> l >> r;
			t.upd(1, 1, n, l, c[r]);
			t.upd(1, 1, n, r, c[l]);
			swap(c[l], c[r]);
			cout << max({t.t[1].a[0][0], t.t[1].a[0][1], t.t[1].a[1][0], t.t[1].a[1][1]}) << '\n';
		}
	}
    return 0;
}