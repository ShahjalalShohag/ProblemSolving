#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fbo find_by_order
#define ook order_of_key
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define inf 1e18
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%I64d %I64d\n",a,b)
#define pf3ll(a,b,c)          printf("%I64d %I64d %I64d\n",a,b,c)
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int mxn=3e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
const int mxp=2100;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
int sign(double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
inline double sqr(double x){return x*x;}
struct PT
{
    double x,y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    void in() {
        sf("%lf %lf",&x,&y);
    }
    void out() {
        pf("%.10f %.10f\n",x,y);
    }
    PT operator + (const PT &a) const{
        return PT(x+a.x,y+a.y);
    }
    PT operator - (const PT &a) const{
        return PT(x-a.x,y-a.y);
    }
    PT operator * (const double a) const{
        return PT(x*a,y*a);
    }
    friend PT operator * (const double &a, const PT &b)
    {
        return PT(a * b.x, a * b.y);
    }
    PT operator / (const double a) const{
        return PT(x/a,y/a);
    }
    bool operator==(PT a)const
    {
        return sign(a.x-x)==0&&sign(a.y-y)==0;
    }
    bool operator<(PT a)const
    {
        return sign(a.x-x)==0?sign(y-a.y)<0:x<a.x;
    }
    bool operator>(PT a)const
    {
        return sign(a.x-x)==0?sign(y-a.y)>0:x>a.x;
    }
    double val()
    {
        return sqrt(x*x+y*y);
    }
    double val2()
    {
        return (x*x+y*y);
    }
    double arg()
    {
        return atan2(y,x);
    }
    //return point that is truncated the distance from center to r
    PT trunc(double r){
        double l=val();
        if (!sign(l)) return *this;
        r/=l;
        return PT(x*r,y*r);
    }
};
istream& operator >> (istream& is,PT &a)
{
    return is>>a.x>>a.y;
}
ostream& operator << (ostream& os,const PT &a)
{
    return os<<fixed<<setprecision(10)<<a.x<<' '<<a.y;
}
double dist(PT a,PT b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
double dist2(PT a,PT b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
double dot(PT a,PT b)
{
    return a.x*b.x+a.y*b.y;
}
double cross(PT a,PT b)
{
    return a.x*b.y-a.y*b.x;
}
PT rotateccw90(PT a)
{
    return PT(-a.y,a.x);
}
PT rotatecw90(PT a)
{
    return PT(a.y,-a.x);
}
PT rotateccw(PT a,double th)
{
    return PT(a.x*cos(th)-a.y*sin(th),a.x*sin(th)+a.y*cos(th));
}
PT rotatecw(PT a,double th)
{
    return PT(a.x*cos(th)+a.y*sin(th),-a.x*sin(th)+a.y*cos(th));
}
double angle_between_vectors(PT a, PT b)
{
    double costheta=dot(a,b)/a.val()/b.val();
    return acos(fmax(-1.0,fmin(1.0,costheta)));
}
double rad_to_deg(double r) {
  return (r * 180.0 / PI);
}

double deg_to_rad(double d) {
  return (d * PI / 180.0);
}



// a line is defined by two points
struct line
{
    PT a,b;
    line(){}
    line(PT _a,PT _b)
    {
        a=_a;
        b=_b;
    }
    //ax+by+c=0
    line(double _a,double _b,double _c)
    {
        if (sign(_a)==0)
        {
            a=PT(0,-_c/_b);
            b=PT(1,-_c/_b);
        }
        else if (sign(_b)==0)
        {
            a=PT(-_c/_a,0);
            b=PT(-_c/_a,1);
        }
        else
        {
            a=PT(0,-_c/_b);
            b=PT(1,(-_c-_a)/_b);
        }
    }
    void in()
    {
        a.in();
        b.in();
    }
    PT vec() const
    {
        return (b-a);
    }
    bool operator==(line v)
    {
        return (a==v.a)&&(b==v.b);
    }
    PT cross_point(line v){
        double a1=cross(v.b-v.a,a-v.a);
        double a2=cross(v.b-v.a,b-v.a);
        return PT((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
};
istream &operator>>(istream &is, line &a) {
    return is >> a.a >> a.b;
}
ostream &operator<<(ostream &os, line &p) {
    return os << p.a << " to " << p.b;
}


// find a point from 'a' through 'b' with distance d
PT point_along_line(PT a,PT b,double d) {
    return a + (((b-a) / (b-a).val()) * d);
}
// projection point c onto line through a and b  assuming a != b
PT project_from_point_to_line(PT a, PT b, PT c) {
    return a + (b-a)*dot(c-a, b-a)/(b-a).val2();
}
// reflection point c onto line through a and b  assuming a != b
PT reflection_from_point_to_line(PT a, PT b, PT c) {
    PT p=project_from_point_to_line(a,b,c);
    return point_along_line(c,p,2*dist(c,p));
}

//minimum distance from point c to line through a and b
double dist_from_point_to_line(PT a,PT b,PT c)
{
    return fabs(cross(b-a,c-a)/(b-a).val());
}
//return 1 if  point c is on line segment ab
bool is_point_on_seg(PT a,PT b,PT c)
{
    double d1=dist(a,c)+dist(c,b);
    double d2=dist(a,b);
    if(fabs(d1-d2)<eps) return 1;
    else return 0;
}
//minimum distance point from point c to segment ab that lies on segment ab
PT project_from_point_to_seg(PT a, PT b, PT c)
{
    double r = dist2(a,b);
    if (fabs(r) < eps) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}
//minimum distance from point c to to segment ab
double dist_from_point_to_seg(PT a, PT b, PT c)
{
    return dist(c, project_from_point_to_seg(a, b, c));
}
//returns a parallel line of line ab in counterclockwise direction with d distance from ab
line get_parallel_line(PT a,PT b,double d)
{
    return line(point_along_line(a,rotateccw90(b-a)+a,d),point_along_line(b,rotatecw90(a-b)+b,d));
}
//Return a tangent line of line ab which intersects
//with it at point c in counterclockwise direction
line get_perpendicular_line(PT a,PT b,PT c)
{
    return line(c+rotateccw90(a-c),c+rotateccw90(b-c));
}
//relation of point p with line ab
//return
//1 if point is ccw with line
//2 if point is cw with line
//3 if point is on the line
int point_line_relation(PT a,PT b,PT p){
        int c=sign(cross(p-a,b-a));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
}
//return
//0 if not parallel
//1 if parallel
//2 if collinear
bool is_parallel(PT a,PT b,PT c,PT d)
{
    double k=fabs(cross(b-a,d-c));
    if(k<eps){
        if(fabs(cross(a-b,a-c))<eps&&fabs(cross(c-d,c-a))<eps) return 2;
        else return 1;
    }
    else return 0;
}
double area_of_triangle(PT a,PT b,PT c)
{
    return fabs(cross(b-a,c-a)/2.0);
}
//radian angle of <bac
double angle(PT b,PT a,PT c)
{
    return angle_between_vectors(b-a,c-a);
}

//orientation of point a,b,c
double orient(PT a,PT b,PT c)
{
    return cross(b-a,c-a);
}
//is point p within angle <bac
bool is_point_in_angle(PT b,PT a,PT c,PT p)
{
    assert(fabs(orient(a,b,c)-0.0)>0);
    if(orient(a,c,b)<0) swap(b,c);
    return orient(a,c,p)>=0&&orient(a,b,p)<=0;
}
//equation of bisector line of <bac
line bisector(PT b,PT a,PT c)
{
    PT unit_ab=(b-a)/(b-a).val();
    PT unit_ac=(c-a)/(c-a).val();
    PT l=unit_ab+unit_ac;
    return line(l.y,-l.x,l.x*a.y-l.y*a.x);
}
//sort points in counterclockwise;
bool half(PT p)
{
    return p.y>0.0||(p.y==0.0&&p.x<0.0);
}
void polar_sort(vector<PT>&v)
{
    sort(all(v),[](PT a,PT b){return make_tuple(half(a),0.0)<make_tuple(half(b),cross(a,b));});
}
//intersection point between ab and cd
//assuming unique intersection exists
bool line_line_intersection(PT a,PT b,PT c,PT d,PT &out)
{
    double a1=a.y-b.y;
    double b1=b.x-a.x;
    double c1=cross(a,b);
    double a2=c.y-d.y;
    double b2=d.x-c.x;
    double c2=cross(c,d);
    double det=a1*b2-a2*b1;
    if(det==0) return 0;
    out=PT((b1*c2-b2*c1)/det,(c1*a2-a1*c2)/det);
    return 1;
}
//intersection point between segment ab and segment cd
//assuming unique intersection exists
bool seg_seg_intersection(PT a,PT b,PT c,PT d,PT &out)
{
    double oa=orient(c,d,a);
    double ob=orient(c,d,b);
    double oc=orient(a,b,c);
    double od=orient(a,b,d);
    //proper intersection exists iff opposite tmps
    if(oa*ob<0&&oc*od<0){
        out=(a*ob-b*oa)/(ob-oa);
        return 1;
    }
    else return 0;
}
//intersection point between segment ab and segment cd
//assuming unique intersection may not exists
//se.size()==0 means no intersection
//se.size()==1 means one intersection
//se.size()==2 means range intersection
set<PT> seg_seg_intersection_inside(PT a, PT b, PT c, PT d)
{
    PT out;
    if (seg_seg_intersection(a,b,c,d,out)) return {out};
    set<PT> se;
    if (is_point_on_seg(c,d,a)) se.insert(a);
    if (is_point_on_seg(c,d,b)) se.insert(b);
    if (is_point_on_seg(a,b,c)) se.insert(c);
    if (is_point_on_seg(a,b,d)) se.insert(d);
    return se;
}
//intersection  between segment ab and line cd
//return
//0 if do not intersect
//1 if proper intersect
//2 if segment intersect
int seg_line_relation(PT a,PT b,PT c,PT d)
{
    double p=orient(c,d,a);
    double q=orient(c,d,b);
    if(sign(p)==0&&sign(q)==0) return 2;
    //proper intersection exists iff opposite tmps
    else if(p*q<0) return 1;
    else return 0;
}
//minimum distance from segment ab to segment cd
double dist_from_seg_to_seg(PT a,PT b,PT c,PT d)
{
    PT dummy;
    if(seg_seg_intersection(a,b,c,d,dummy)) return 0.0;
    else return min({dist_from_point_to_seg(a,b,c),
                     dist_from_point_to_seg(a,b,d),
                     dist_from_point_to_seg(c,d,a),
                     dist_from_point_to_seg(c,d,b)});
}



//a circle is defined by a center and radius
struct circle
{
    PT p;
    double r;
    circle(){}
    circle(PT _p,double _r): p(_p),r(_r){};
    //center (x,y) and radius r
    circle(double x,double y,double _r): p(PT(x,y)),r(_r){};
    //compute circle given three points i.e. circumcircle of a triangle
    circle(PT a,PT b,PT c){
        b=(a+b)/2.0;
        c=(a+c)/2.0;
        line_line_intersection(b,b+rotatecw90(a-b),c,c+rotatecw90(a-c),p);
        r=dist(a,p);
    }
    circle(PT a,PT b,PT c,bool t){
        line u,v;
        double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
        u.a=a;
        u.b=u.a+(PT(cos((n+m)/2.0),sin((n+m)/2.0)));
        v.a=b;
        m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
        v.b=v.a+(PT(cos((n+m)/2.0),sin((n+m)/2.0)));
        line_line_intersection(u.a,u.b,v.a,v.b,p);
        r=dist_from_point_to_seg(a,b,p);
    }
    void in(){
        p.in();scanf("%lf",&r);
    }
    void out(){
        printf("%.10f %.10f %.10f\n",p.x,p.y,r);
    }
    bool operator==(circle v){
        return ((p==v.p)&&sign(r-v.r)==0);
    }
    bool operator<(circle v)const{
        return ((p<v.p)||(p==v.p)&&sign(r-v.r)<0);
    }
    double area(){return PI*sqr(r);}
    double circumference(){return 2.0*PI*r;}
};
istream &operator>>(istream &is, circle &a) {
    return is >> a.p >> a.r;
}
ostream &operator<<(ostream &os, circle &a) {
    return os << a.p <<" "<< a.r;
}
//if point is inside circle
//return
//0 outside
//1 on circumference
//2 inside circle
int circle_point_relation(PT p,double r,PT b)
{
    double dst=dist(p,b);
    if (sign(dst-r)<0)return 2;
    if (sign(dst-r)==0)return 1;
    return 0;
}
//if segment is inside circle
//return
//0 outside
//1 on circumference
//2 inside circle
int circle_seg_relation(PT p,double r,PT a,PT b)
{
    double dst=dist_from_point_to_seg(a,b,p);
    if (sign(dst-r)<0)return 2;
    if (sign(dst-r)==0)return 1;
    return 0;
}
//if line cross circle
//return
//0 outside
//1 on circumference
//2 inside circle
int circle_line_relation(PT p,double r,PT a,PT b)
{
    double dst=dist_from_point_to_line(a,b,p);
    if (sign(dst-r)<0)return 2;
    if (sign(dst-r)==0)return 1;
    return 0;
}
//compute intersection of line through points a and b with
//circle centered at c with radius r > 0
vector<PT> circle_line_intersection(PT c, double r ,PT a, PT b)
{
    vector<PT> ret;
    b = b-a;
    a = a-c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    if (D < -eps) return ret;
    ret.pb(c+a+b*(-B+sqrt(D+eps))/A);
    if (D > eps) ret.pb(c+a+b*(-B-sqrt(D))/A);
    return ret;
}
//return
//5 - outside and do not intersect
//4 - intersect outside in one point
//3 - intersect in 2 points
//2 - intersect inside in one point
//1 - inside and do not intersect
int circle_circle_relation(PT a,double r,PT b,double R)
{
    double d=dist(a,b);
    if (sign(d-r-R)>0)  return 5;
    if (sign(d-r-R)==0) return 4;
    double l=fabs(r-R);
    if (sign(d-r-R)<0&&sign(d-l)>0) return 3;
    if (sign(d-l)==0) return 2;
    if (sign(d-l)<0) return 1;
}
// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> circle_circle_intersection(PT a,double r,PT b,double R)
{
    if(a==b&&sign(r-R)==0) return {PT(1e18,1e18)};
    vector<PT> ret;
    double d = sqrt(dist2(a, b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.pb(a+v*x + rotateccw90(v)*y);
    if (y > 0) ret.pb(a+v*x - rotateccw90(v)*y);
    return ret;
}
// returns two circle c1,c2 through points a,b of radius r
// returns 0 if there is no such circle
// 1 if one circle
// 2 if two circle
int getcircle(PT a,PT b,double r,circle &c1,circle &c2)
{
    vector<PT> v=circle_circle_intersection(a,r,b,r);
    int t=v.size();
    if(!t) return 0;
    c1.p=v[0],c1.r=r;
    if(t==2) c2.p=v[1],c2.r=r;
    return t;
}
// returns two circle c1,c2 which is tangent to line u, goes through
// point q and has radius r1
// returns 0 for no circle ,1 if c1=c2 ,2 if c1!=c2
int getcircle(line u,PT q,double r1,circle &c1,circle &c2)
{
    double dis=dist_from_point_to_line(u.a,u.b,q);
    if (sign(dis-r1*2)>0) return 0;
    if (sign(dis)==0)
    {
        c1.p=(q+rotateccw90(u.vec())).trunc(r1);
        c2.p=(q+rotatecw90(u.vec())).trunc(r1);
        c1.r=c2.r=r1;
        return 2;
    }
    line u1=line((u.a+rotateccw90(u.vec())).trunc(r1),(u.b+rotateccw90(u.vec())).trunc(r1));
    line u2=line((u.a+rotatecw90(u.vec())).trunc(r1),(u.b+rotatecw90(u.vec())).trunc(r1));
    circle cc=circle(q,r1);
    PT p1,p2;
    vector<PT>v;
    v=circle_line_intersection(q,r1,u1.a,u1.b);
    if (!v.size()) v=circle_line_intersection(q,r1,u2.a,u2.b);
    v.eb(v[0]);
    p1=v[0],p2=v[1];
    c1=circle(p1,r1);
    if (p1==p2)
    {
        c2=c1;
        return 1;
    }
    c2=circle(p2,r1);
    return 2;
}
//returns area of intersection between two circles
double circle_circle_area(PT a,double r1,PT b,double r2)
{
    circle u(a,r1),v(b,r2);
    int rel=circle_circle_relation(a,r1,b,r2);
    if (rel>=4) return 0.0;
    if (rel<=2) return min(u.area(),v.area());
    double d=dist(u.p,v.p);
    double hf=(u.r+v.r+d)/2.0;
    double ss=2*sqrt(hf*(hf-u.r)*(hf-v.r)*(hf-d));
    double a1=acos((u.r*u.r+d*d-v.r*v.r)/(2.0*u.r*d));
    a1=a1*u.r*u.r;
    double a2=acos((v.r*v.r+d*d-u.r*u.r)/(2.0*v.r*d));
    a2=a2*v.r*v.r;
    return a1+a2-ss;
}
//tangent lines i.e. sporshoks  from point q to circle with center p and radius r
int tangent_lines_from_point(PT p,double r,PT q,line &u,line &v)
{
    int x=circle_point_relation(p,r,q);
    if (x==2) return 0;
    if (x==1)
    {
        u=line(q,q+rotateccw90(q-p));
        v=u;
        return 1;
    }
    double d=dist(p,q);
    double l=sqr(r)/d;
    double h=sqrt(sqr(r)-sqr(l));
    u=line(q,p+((q-p).trunc(l)+(rotateccw90(q-p).trunc(h))));
    v=line(q,p+((q-p).trunc(l)+(rotatecw90(q-p).trunc(h))));
    return 2;
}
//returns outer tangents line of two circles
// if inner==1 it returns inner tangent lines
int tangents_lines_from_circle(PT c1, double r1, PT c2, double r2, bool inner, line &u,line &v)
{
    if (inner)
        r2 = -r2;
    PT d = c2-c1;
    double dr = r1-r2, d2 = d.val(), h2 = d2-dr*dr;
    if (d2 == 0 || h2 < 0)
    {
        assert(h2 != 0);
        return 0;
    }
    vector<pair<PT,PT>>out;
    for (int tmp :{-1,1}){
        PT v = (d*dr + rotateccw90(d)*sqrt(h2)*tmp)/d2;
        out.pb({c1 + v*r1, c2 + v*r2});
    }
    u=line(out[0].F,out[0].S);
    if(out.size()==2) v=line(out[1].F,out[1].S);
    return 1 + (h2 > 0);
}


//a polygon is defined by n points
//here l[] array stores lines of the polygon
struct polygon
{
    int n;
    PT p[mxp];
    line l[mxp];
    void in(int _n){
        n=_n;
        for (int i=0;i<n;i++)   p[i].in();
    }
    void add(PT q){p[n++]=q;}
    void getline(){
        for (int i=0;i<n;i++)
            l[i]=line(p[i],p[(i+1)%n]);
    }
    double getcircumference()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=dist(p[i],p[(i+1)%n]);
        }
        return sum;
    }
    double getarea()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=cross(p[i],p[(i+1)%n]);
        }
        return fabs(sum)/2;
    }
    //returns 0 for cw, 1 for ccw
    bool getdir()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=cross(p[i],p[(i+1)%n]);
        }
        if (sign(sum)>0)return 1;
        return 0;
    }
    struct cmp{
        PT p;
        cmp(const PT &p0){p=p0;}
        bool operator()(const PT &aa,const PT &bb){
            PT a=aa,b=bb;
            int d=sign(cross(a-p,b-p));
            if (d==0) return sign(dist(a,p)-dist(b,p))<0;
            return d>0;
        }
    };
    //sorting in convex_hull order
    void norm(){
        PT mi=p[0];
        for (int i=1;i<n;i++)mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    //returns convex hull in convex (monotone chain)
    void getconvex(polygon &convex)
    {
        int i,j,k;
        sort(p,p+n);
        convex.n=n;
        for (i=0;i<min(n,2);i++)
        {
            convex.p[i]=p[i];
        }
        if (n<=2)return;
        int &top=convex.n;
        top=1;
        for (i=2;i<n;i++)
        {
            while (top&&cross(convex.p[top]-p[i],convex.p[top-1]-p[i])<=0)
                top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for (i=n-3;i>=0;i--)
        {
            while (top!=temp&&cross(convex.p[top]-p[i],convex.p[top-1]-p[i])<=0)
                top--;
            convex.p[++top]=p[i];
        }
    }
    //checks if convex
    bool isconvex()
    {
        bool s[3];
        memset(s,0,sizeof(s));
        int i,j,k;
        for (i=0;i<n;i++)
        {
            j=(i+1)%n;
            k=(j+1)%n;
            s[sign(cross(p[j]-p[i],p[k]-p[i]))+1]=1;
            if (s[0]&&s[2])return 0;
        }
        return 1;
    }
    //used for later function
    double xmult(PT a, PT b, PT c)
    {
        return cross(b - a,c - a);
    }
    // returns
    // 3 - if q is a vertex
	// 2 - if on a side
	// 1 - if inside
	// 0 - if outside
    int relation_point(PT q){
        int i,j;
        for (i=0;i<n;i++){
            if (p[i]==q)return 3;
        }
        getline();
        for (i=0;i<n;i++){
            if (is_point_on_seg(l[i].a,l[i].b,q))return 2;
        }
        int cnt=0;
        for (i=0;i<n;i++){
            j=(i+1)%n;
            int k=sign(cross(q-p[j],p[i]-p[j]));
            int u=sign(p[i].y-q.y);
            int v=sign(p[j].y-q.y);
            if (k>0&&u<0&&v>=0)cnt++;
            if (k<0&&v<0&&u>=0)cnt--;
        }
        return cnt!=0;
    }
    //returns minimum enclosing circle
    void find_(int st,PT tri[],circle &c){
        if (!st) c=circle(PT(0,0),-2);
        if (st==1) c=circle(tri[0],0);
        if (st==2) c=circle((tri[0]+tri[1])/2.0,dist(tri[0],tri[1])/2.0);
        if (st==3) c=circle(tri[0],tri[1],tri[2]);
    }
    void solve(int cur,int st,PT tri[],circle &c){
        find_(st,tri,c);
        if (st==3)return;
        int i;
        for (i=0;i<cur;i++){
            if (sign(dist(p[i],c.p)-c.r)>0){
                tri[st]=p[i];
                solve(i,st+1,tri,c);
            }
        }
    }
    circle minimum_enclosing_circle(){
        random_shuffle(p,p+n);
        PT tri[4];
        circle c;
        solve(n,0,tri,c);
        return c;
    }
};


//stores some polygons
struct polygons
{
    vector<polygon>p;
    polygons(){p.clear();}
    void clear(){p.clear();}
    void push(polygon q){if (sign(q.getarea()))p.pb(q);}
    vector<pair<double,int> >e;
    //used for later use
    void ins(PT s,PT t,PT X,int i){
        double r=fabs(t.x-s.x)>eps?(X.x-s.x)/(t.x-s.x):(X.y-s.y)/(t.y-s.y);
        r=fmin(r,1.0);r=fmax(r,0.0);
        e.pb(MP(r,i));
    }
    double polyareaunion(){
        double ans=0.0;
        int c0,c1,c2,i,j,k,w;
        for (i=0;i<p.size();i++)
            if (p[i].getdir()==0)reverse(p[i].p,p[i].p+p[i].n);
        for (i=0;i<p.size();i++){
            for (k=0;k<p[i].n;k++){
                PT &s=p[i].p[k],&t=p[i].p[(k+1)%p[i].n];
                if (!sign(cross(s,t)))continue;
                e.clear();
                e.pb(MP(0.0,1));
                e.pb(MP(1.0,-1));
                for (j=0;j<p.size();j++)if (i!=j){
                    for (w=0;w<p[j].n;w++){
                        PT a=p[j].p[w],b=p[j].p[(w+1)%p[j].n],c=p[j].p[(w-1+p[j].n)%p[j].n];
                        c0=sign(cross(t-s,c-s));
                        c1=sign(cross(t-s,a-s));
                        c2=sign(cross(t-s,b-s));
                        if (c1*c2<0)ins(s,t,line(s,t).cross_point(line(a,b)),-c2);
                        else if (!c1&&c0*c2<0)ins(s,t,a,-c2);
                        else if (!c1&&!c2){
                            int c3=sign(cross(t-s,p[j].p[(w+2)%p[j].n]-s));
                            int dp=sign(dot(t-s,b-a));
                            if (dp&&c0)ins(s,t,a,dp>0?c0*((j>i)^(c0<0)):-(c0<0));
                            if (dp&&c3)ins(s,t,b,dp>0?-c3*((j>i)^(c3<0)):c3<0);
                        }
                    }
                }
                sort(e.begin(),e.end());
                int ct=0;
                double tot=0.0,last;
                for (j=0;j<e.size();j++){
                    if (ct==2)tot+=e[j].first-last;
                    ct+=e[j].second;
                    last=e[j].first;
                }
                ans+=cross(s,t)*tot;
            }
        }
        return fabs(ans)*0.5;
    }
};
int main()
{
    fast;
    ll i,j,k,n,m,d,x,y;
    polygon p;
    PT a;
    cin>>n>>d;
    p.add(PT(d*1.0,0));
    p.add(PT(n*1.0,n*1.0-d*1.0));
    p.add(PT(n*1.0-d*1.0,n*1.0));
    p.add(PT(0,d*1.0));
    cin>>m;
    while(m--){
        cin>>x>>y;
        a=PT(x*1.0,y*1.0);
        int k=p.relation_point(a);
        if(k) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
