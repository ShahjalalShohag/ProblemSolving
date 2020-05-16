#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
#define double long double
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
struct line {
    PT a, b; // goes through points a and b
    PT v; double c;  //line form: direction vec [cross] (x, y) = c 
    line() {}
    //direction vector v and offset c
    line(PT v, double c) : v(v), c(c) {
        auto p = get_points();
        a = p.first; b = p.second;
    }
    // equation ax + by = c
    line(double _a, double _b, double _c) : v({_b, -_a}), c(_c) {
        auto p = get_points();
        a = p.first; b = p.second;
    }
    // goes through points p and q
    line(PT p, PT q) : v(q - p), c(cross(v, p)), a(p), b(q) {}
    pair<PT, PT> get_points() { //extract any two points from this line
        PT p, q; double a = -v.y, b = v.x; // ax + by = -c
        if (sign(a) == 0) {
            p = PT(0, -c / b);
            q = PT(1, -c / b);
        }
        else if (sign(b) == 0) {
            p = PT(-c / a, 0);
            q = PT(-c / a, 1);
        }
        else {
            p = PT(0, -c / b);
            q = PT(1, (-c - a) / b);
        }
        return {p, q};
    }
    //ax + by + c = 0
    array<double, 3> get_abc() {
        double a = -v.y, b = v.x;
        return {a, b, c};
    }
    // 1 if on the left, -1 if on the right, 0 if on the line
    bool side(PT p) {
        return sign(cross(v, p) - c);
    }
    // translate the line by vector t i.e. shifting it by vector t
    line translate(PT t) { return {v, c + cross(v, t)}; }
    // compare two points by their orthogonal projection on this line
    // a projection point comes before another if it comes first according to vector v
    bool cmp_by_projection(PT p, PT q) {
        return dot(v, p) < dot(v, q);
    }
    line shift_left(double d) {return {v, c + d * v.norm()};}
};
// not necessarily convex, boundary is included in the intersection
// returns total intersected length
double polygon_line_intersection(vector<PT> &p, PT a, PT b) {
    int n = p.size();
    p.push_back(p[0]);
    line l = line(a, b);
    double ans = 0.0;
    vector< pair<double, int> > vec;
    for (int i = 0; i < n; i++) {
        int s1 = sign(cross(b - a, p[i] - a));
        int s2 = sign(cross(b - a, p[i+1] - a));
        if (s1 == s2) continue;
        line t = line(p[i], p[i + 1]);
        PT inter = (t.v * l.c - l.v * t.c) / cross(l.v, t.v);
        double tmp = dot(inter, l.v);
        int f;
        if (s1 > s2) f = s1 && s2 ? 2 : 1;
        else f = s1 && s2 ? -2 : -1;
        vec.push_back(make_pair(tmp, f));
    }
    sort(vec.begin(), vec.end());
    for (int i = 0, j = 0; i + 1 < (int)vec.size(); i++){
        j += vec[i].second;
        if (j) ans += vec[i + 1].first - vec[i].first;
    }
    ans = ans / sqrt(dot(l.v, l.v));
    p.pop_back();
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<PT> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    while (m--) {
        PT a, b; cin >> a.x >> a.y >> b.x >> b.y;
        auto ans = polygon_line_intersection(p, a, b);
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;
}