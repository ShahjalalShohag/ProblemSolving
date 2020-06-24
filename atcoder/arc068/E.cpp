#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

template <class T>
struct BIT { //1-indexed
    int n; vector<T> t;
    BIT(int _n) {
        n = _n; t.assign(n,0);
    }
    T query(int i) {
        T ans = 0;
        for (; i >= 1; i -= (i & -i)) ans += t[i];
        return ans;
    }
    void upd(int i, T val) {
        if (i <= 0) return;
        for (; i < n; i += (i & -i)) t[i] += val;
    }
    void upd(int l, int r, T val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
vector<int> line[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		line[r - l + 1].push_back(l);
	}
	BIT<int> t(N);
	int dead = n;
	for (int d = 1; d <= m; d++) {
		int ans = dead;
		for (int i = d; i <= m; i += d) ans += t.query(i);
		cout << ans << '\n';
		for (auto l: line[d]) {
			int r = l + d - 1;
			t.upd(l, r, 1);
			dead--;
		}
	}
    return 0;
}