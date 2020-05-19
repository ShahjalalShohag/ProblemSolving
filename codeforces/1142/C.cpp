#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int sign(long long x) { return (x > 0) - (x < 0); }
struct PT {
    long long x, y;
    PT() {}
    PT(long long x, long long y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    bool operator < (PT a) const { return x == a.x ? y < a.y : x < a.x; }
};
inline long long cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<PT> p(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		p[i] = {x, y - 1LL * x * x};
	}
	sort(p.begin(), p.end());
    vector<PT> up;
    for (auto& w : p) {
        while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), w) >= 0) {
            up.pop_back();
        }
        up.push_back(w);
    }
    int ans = up.size() - 1;
    if (up.size() > 1) ans -= up[0].x == up[1].x;
    cout << ans << '\n';
    return 0;
}