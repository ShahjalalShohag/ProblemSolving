#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
struct PT {
    int x, y;
    PT() {}
    PT(int x, int y) : x(x), y(y) {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const int a) const { return PT(x * a, y * a); }
    bool half(PT p) const {
    	return p.y > 0 || (p.y == 0 && p.x < 0);
	}
    bool operator < (PT a) const { return make_pair(half(*this), 0LL) < make_pair(half(a), 1LL * x * a.y - 1LL * a.x * y); }
};
long long cross(PT a, PT b) {
	return 1LL * a.x * b.y - 1LL * a.y * b. x;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<PT> p(n);
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		vector<PT> cur;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				PT w = p[j] - p[i];
				cur.push_back(w);
			}
		}
		sort(cur.begin(), cur.end());
		int cntl = 0, j  = 0;
		for (int i = 0; i < cur.size(); i++) {
			while (cntl < cur.size() && (i == j || cross(cur[i], cur[j]) > 0 && cross(cur[i] * -1, cur[j]) < 0)) j = (j + 1) % (cur.size()), cntl++;
			int cntr = n - 1 - cntl;
			ans += 1LL * (cntl - 1) * (cntl - 2) / 2 * cntr * (cntr - 1) / 2;
			cntl--;
		}
	}
	cout << ans / 2 << '\n';
    return 0;
}