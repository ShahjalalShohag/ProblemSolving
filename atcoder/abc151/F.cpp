#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;


const double inf = 1e100;
const double eps = 1e-9;
const double PI = acos(-1.0);
int sign(double x) { return (x > eps) - (x < -eps); }
struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const double a) const { return PT(x * a, y * a); }
    friend PT operator * (const double &a, const PT &b) { return PT(a * b.x, a * b.y); }
    PT operator / (const double a) const { return PT(x / a, y / a); }
    bool operator == (PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (PT a) const { return !(*this == a); }
    bool operator < (PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    double arg() { return atan2(y, x); }
    PT truncate(double r) { // returns a vector with norm r and having same direction
        double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};
inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline double dist2(PT a, PT b) { return dot(a - b, a - b); }
inline double dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
PT perp(PT a) { return PT(-a.y, a.x); }
PT rotateccw90(PT a) { return PT(-a.y, a.x); }
PT rotatecw90(PT a) { return PT(a.y, -a.x); }
PT rotateccw(PT a, double t) { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t)); }
PT rotatecw(PT a, double t) { return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t)); }
double SQ(double x) { return x * x; }
double rad_to_deg(double r) { return (r * 180.0 / PI); }
double deg_to_rad(double d) { return (d * PI / 180.0); }

bool line_line_intersection(PT a, PT b, PT c, PT d, PT &ans) {
    double a1 = a.y - b.y, b1 = b.x - a.x, c1 = cross(a, b);
    double a2 = c.y - d.y, b2 = d.x - c.x, c2 = cross(c, d);
    double det = a1 * b2 - a2 * b1;
    if (det == 0) return 0;
    ans = PT((b1 * c2 - b2 * c1) / det, (c1 * a2 - a1 * c2) / det);
    return 1;
}
struct circle {
    PT p; double r;
    circle() {}
    circle(PT _p, double _r): p(_p), r(_r) {};
    // center (x, y) and radius r
    circle(double x, double y, double _r): p(PT(x, y)), r(_r) {};
    // compute circle given three points i.e. circumcircle of a triangle
    // the three points must be unique
    circle(PT a, PT b, PT c) {
        b = (a + b) * 0.5;
        c = (a + c) * 0.5;
        line_line_intersection(b, b + rotatecw90(a - b), c, c + rotatecw90(a - c), p);
        r = dist(a, p);
    }
};
double fix(double x) {
  if (x > PI) x -= PI * 2;
  if (x <= -PI) x += PI * 2;
  return x;
}
int maximum_circle_cover(vector<PT> p, double r) {
  int n = p.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
      vector<pair<double, int>> events = {{-PI, -1}, {PI, 1}};
      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        double dx = p[j].x - p[i].x, dy = p[j].y - p[i].y;
        if (hypot(dx, dy) > r * 2) continue;
        double dir = atan2(dy, dx);
        double ang = acos(hypot(dx, dy) / 2 / r);
        double st = fix(dir - ang), ed = fix(dir + ang);
        events.push_back({st, -1});
        events.push_back({ed, +1});
        if (st > ed) {
          events.push_back({+PI, +1});
          events.push_back({-PI, -1});
        }
      }
      sort(events.begin(), events.end());
      int cnt = 0;
      for (auto &&e: events) {
        cnt -= e.second;
        ans = max(ans, cnt);
      }
  }
  return ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<PT> p(n);
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	double l = 0, r = 2001; int it = 200;
    while (it--) {
        double mid = (l + r) * 0.5;
        if (maximum_circle_cover(p, mid) >= n) r = mid;
        else l = mid;
    }
	cout << fixed << setprecision(10) << r << '\n';
    return 0;
}