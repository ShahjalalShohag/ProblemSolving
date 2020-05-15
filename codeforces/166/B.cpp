#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
const double inf = 1e100;
const double eps = 1e-9;
const double PI = acos(-1.0);

int sign(double x) {
    return (x > eps) - (x < -eps);
}
struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const {
        return PT(x + a.x, y + a.y);
    }
    PT operator - (const PT &a) const {
        return PT(x - a.x, y - a.y);
    }
    PT operator * (const double a) const {
        return PT(x * a, y * a);
    }
    friend PT operator * (const double &a, const PT &b) {
        return PT(a * b.x, a * b.y);
    }
    PT operator / (const double a) const {
        return PT(x / a, y / a);
    }
    bool operator == (PT a) const {
        return sign(a.x - x) == 0 && sign(a.y - y) == 0;
    }
    bool operator < (PT a) const {
        return sign(a.x - x) == 0 ? y < a.y : x < a.x;
    }
    bool operator > (PT a) const {
        return sign(a.x - x) == 0 ? y > a.y : x > a.x;
    }
    double norm() {
        return sqrt(x * x + y * y);
    }
    double norm2() {
        return x * x + y * y;
    }
    double arg() {
        return atan2(y, x);
    }
    PT truncate(double r) { // returns a point with norm r and having same direction
        double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};
double dot(PT a, PT b) {
    return a.x * b.x + a.y * b.y;
}
double dist2(PT a, PT b) {
    return dot(a - b, a - b);
}
double dist(PT a, PT b) {
    return sqrt(dot(a - b, a - b));
}
double cross(PT a, PT b) {
    return a.x * b.y - a.y * b.x;
}
int orientation(PT a, PT b, PT c) {
    return sign(cross(b - a, c - a));
}
struct polygon {
    vector<PT> p;
    polygon() {}
    polygon(int _n) { p.resize(_n); }
    polygon(vector<PT> _p) { p = _p; }
    void add(PT q) { p.push_back(q); }
    double circumference() {
        double ans=0; int n = p.size();
        for (int i = 0; i < n; i++) ans += dist(p[i], p[(i + 1) % n]);
        return ans;
    }
    double area() {
        double ans = 0; int n = p.size();
        for (int i = 0; i < n; i++) ans += cross(p[i], p[(i + 1) % n]);
        return fabs(ans) * 0.5;
    }
    // 0 if cw, 1 if ccw
    bool get_direction() {
        double ans = 0; int n = p.size();
        for (int i = 0; i < n; i++) ans += cross(p[i], p[(i + 1) % n]);
        if (sign(ans) > 0) return 1;
        return 0;
    }
    polygon convex_hull() {
        vector<PT> v = p;
        sort(v.begin(), v.end());
        vector<PT> up, dn;
        for (auto& p : v) {
            while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), p) >= 0) {
                up.pop_back();
            }
            while (dn.size() > 1 && orientation(dn[dn.size() - 2], dn.back(), p) <= 0) {
                dn.pop_back();
            }
            up.push_back(p);
            dn.push_back(p);
        }
        v = dn;
        v.pop_back();
        reverse(up.begin(), up.end());
        up.pop_back();
        for (auto& p : up) {
            v.push_back(p);
        }
        if (v.size() == 2 && v[0] == v[1]) v.pop_back();
        return polygon(v);
    }
     //checks if convex or not
    bool is_convex() {
        bool s[3]; s[0] = s[1] = s[2] = 0;
        int n = p.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            s[sign(cross(p[j] - p[i], p[k] - p[i])) + 1] = 1;
            if (s[0] && s[2]) return 0;
        }
        return 1;
    }
    // -1 if strictly inside, 0 if on the polygon, 1 if strictly outside
    int point_inside_convex(const PT& x) {
        int n = p.size(), a, b, c;
        assert(n >= 3);
        PT g = (p[0] + p[n / 3] + p[n * 2 / 3]) / 3.0;
        double ag, cg;
        for (a = 0, b = n; a + 1 < b; ) {
            c = (a + b) / 2;
            ag = cross(p[a] - g, x - g);
            cg = cross(p[c] - g, x - g);
            if (cross(p[a] - g, p[c] - g) > 0) {
                if (ag > 0 and cg < 0) b = c; else a = c;
            } 
            else {
                if (ag < 0 and cg > 0) a = c; else b = c;
            }
        }
        b %= n;
        ag = cross(p[a] - x, p[b] - x);
        if (ag < 0) return 1;
        if (ag > 0) return -1;
        return 0;
    }
};
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    polygon p(n);
    for (int i = 0; i < n; i++) cin >> p.p[i].x >> p.p[i].y;
    reverse(p.p.begin(), p.p.end());
    int ans = 1;
    int q; cin >> q;
    while (q--) {
        PT x; cin >> x.x >> x.y;
        ans &= p.point_inside_convex(x) == -1;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;   
}