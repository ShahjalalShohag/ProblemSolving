#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

// add lines with -m and -b and return -ans to
// make this code work for minimums.(not -x)
const long long inf = -(1LL<<62);
struct line {
    long long m, b;
    mutable function<const line*() > succ;
    bool operator < (const line& rhs) const {
        if (rhs.b != inf) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        long long x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct CHT : public multiset<line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y -> m == z -> m && y -> b <= z -> b;
        }
        auto x = prev(y);
        if (z == end()) return y -> m == x -> m && y -> b <= x -> b;
        return ((__int128_t) (x -> b - y -> b))*(z -> m - y -> m) >= ((__int128_t) (y -> b - z -> b))*(y -> m - x -> m);
    }
    void add(long long m, long long b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    long long query(long long x) {
        auto l = *lower_bound((line) { x, inf });
        return l.m * x + l.b;
    }
} *cht;
int n, a[N];
long long psum[N], ssum[N], pref[N], suf[N], must_use[N];
void yo(int l, int r) {
	if (l == r) {
		must_use[l] = max(must_use[l], 1LL - a[l] + pref[l - 1] + suf[l + 1]);
		return;
	}
	int mid = l + r >> 1;
	cht = new CHT();
	for (int i = l; i <= mid; i++) {
		cht -> add(-i, (1LL * i * i - 3 * i) / 2 + pref[i - 1] + psum[i - 1]);
	}
	long long cur = -1e18;
	for (int i = r; i >= mid + 1; i--) {
		cur = max(cur, suf[i + 1] + cht -> query(i) + (1LL * i * i + 3 * i) / 2 - psum[i] + 1);
		must_use[i] = max(must_use[i], cur);
	}
	cht = new CHT();
	for (int i = mid + 1; i <= r; i++) {
		int id = n - i + 1;
		cht -> add(-id, (1LL * id * id - 3 * id) / 2 + suf[i + 1] + ssum[i + 1]);
	}
	cur = -1e18;
	for (int i = l; i <= mid; i++) {
		int id = n - i + 1;
		cur = max(cur, pref[i - 1] + cht -> query(id) + (1LL * id * id + 3 * id) / 2 - ssum[i] + 1);
		must_use[i] = max(must_use[i], cur);
	}
	yo(l, mid);
	yo(mid + 1, r);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i--) {
		ssum[i] = ssum[i + 1] + a[i];
	}
	cht = new CHT();
	for (int i = 1; i <= n; i++) {
		cht -> add(-i, (1LL * i * i - 3 * i) / 2 + pref[i - 1] + psum[i - 1]);
		pref[i] = cht -> query(i) + (1LL * i * i + 3 * i) / 2 - psum[i] + 1;
		pref[i] = max(pref[i], pref[i - 1]);
	}
	cht = new CHT();
	for (int i = n; i >= 1; i--) {
		int id = n - i + 1;
		cht -> add(-id, (1LL * id * id - 3 * id) / 2 + suf[i + 1] + ssum[i + 1]);
		suf[i] = cht -> query(id) + (1LL * id * id + 3 * id) / 2 - ssum[i] + 1;
		suf[i] = max(suf[i], suf[i + 1]);
	}
	for (int i = 1; i <= n; i++) must_use[i] = -1e18;
	yo(1, n);
	int q; cin >> q;
	while (q--) {
		int i, x; cin >> i >> x;
		long long not_use = pref[i - 1] + suf[i + 1];
		long long ans = max(not_use, must_use[i] + a[i] - x);
		cout << ans << '\n';
	}
    return 0;
}