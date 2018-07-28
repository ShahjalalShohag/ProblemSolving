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
#define PI (acos(-1.0))
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
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
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
struct vect
{
    ld x,y;
    vect(){x=y=0;}
    vect(ld a,ld b){x=a,y=b;}
    vect operator + (const vect &a) const{
        return vect(x+a.x,y+a.y);
    }
    vect operator - (const vect &a) const{
        return vect(x-a.x,y-a.y);
    }
    vect operator * (const ld a) const{
        return vect(x*a,y*a);
    }
    vect operator / (const ld a) const{
        return vect(x/a,y/a);
    }
    bool operator == (const vect &a) const{
        return (x==a.x)&&(y==a.y);
    }
    bool operator != (const vect &a) const{
        return (x!=a.x)||(y!=a.y);
    }
    ld val()
    {
        return sqrt(x*x+y*y);
    }
};
istream& operator >> (istream& is,vect &a)
{
    return is>>a.x>>a.y;
}
ostream& operator << (ostream& os,const vect &a)
{
    return os<<fixed<<setprecision(6)<<a.x<<' '<<a.y<<nl;
}
struct line
{
    ld a,b,c;
    line(){a=b=c=0;}
    line(ld x,ld y,ld z){a=x,b=y,c=z;}
};
ld dist(vect a,vect b)
{
    return (a-b).val();
}
ld sqr_dist(vect a,vect b)
{
    a=a-b;
    return a.x*a.x+a.y*a.y;
}
ld dot(vect a,vect b)
{
    return a.x*b.x+a.y*b.y;
}
ld cross(vect a,vect b)
{
    return a.x*b.y-a.y*b.x;
}
line get_line(vect a,vect b)
{
    return line(a.y-b.y,a.x-b.x,cross(a,b));
}
bool is_on_segment(vect a,vect b,vect c)
{
    ld d1=dist(a,c)+dist(c,b);
    ld d2=dist(a,b);
    if(fabs(d1-d2)<eps) return 1;
    else return 0;
}
ld area_of_triangle(vect a,vect b,vect c)
{
    return fabs(cross(b-a,c-a)/2.0);
}
vect rotateccw90(vect a)
{
    return vect(-a.y,a.x);
}
vect rotatecw90(vect a)
{
    return vect(a.y,-a.x);
}
vect roteteccw(vect a,ld th)
{
    return vect(a.x*cos(th)-a.y*sin(th),a.x*sin(th)+a.y*cos(th));
}
vect rotatecw(vect a,ld th)
{
    return vect(a.x*cos(th)+a.y*sin(th),-a.x*sin(th)+a.y*cos(th));
}
//radian angle of <bac
ld angle(vect b,vect a,vect c)
{
    ld th=dot(b-a,c-a)/(b-a).val()/(c-a).val();
    if(th<-1) th=-1;
    if(th>1) th=1;
    return acos(th);
}
//radian angle between vector a and b
ld angle_between_vectors(vect a,vect b)
{
    ld th=dot(a,b)/a.val()/b.val();
    if(th<-1) th=-1;
    if(th>1) th=1;
    return acos(th);
}
//minimum distance from point c to line ab
ld dist_from_point_to_line(vect a,vect b,vect c)
{
    return fabs(cross(b-a,c-a)/(b-a).val());
}
//minimum distance point from point c to segment ab that lies on segment ab
vect project_from_point_to_segment(vect a, vect b, vect c)
{
    ld r = sqr_dist(a,b);
    if (fabs(r) < eps) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}
//minimum distance from point c to to segment ab
ld dist_from_point_to_segment(vect a, vect b, vect c)
{
    return dist(c, project_from_point_to_segment(a, b, c));
}
//orientation of point a,b,c
ld orient(vect a,vect b,vect c)
{
    return cross(b-a,c-a);
}
//is point p within angle <bac
bool point_in_angle(vect b,vect a,vect c,vect p)
{
    assert(fabs(orient(a,b,c)-0.0)>0);
    if(orient(a,c,b)<0) swap(b,c);
    return orient(a,c,p)>=0&&orient(a,b,p)<=0;
}
//equation of bisector line of <bac
line bisector(vect b,vect a,vect c)
{
    vect unit_ab=(b-a)/(b-a).val();
    vect unit_ac=(c-a)/(c-a).val();
    vect l=unit_ab+unit_ac;
    return line(l.y,-l.x,l.x*a.y-l.y*a.x);
}
//sort in counterclockwise;
bool half(vect p)
{
    return p.y>0||(p.y==0&&p.x<0);
}
void polar_sort(vector<vect>&v)
{
    sort(all(v),[](vect a,vect b){return make_tuple(half(a),0)<make_tuple(half(b),cross(a,b));});
}
//intersection point between ab and cd
vect line_intersection(vect a,vect b,vect c,vect d)
{
    ld a1=a.y-b.y;
    ld b1=b.x-a.x;
    ld c1=cross(a,b);
    ld a2=c.y-d.y;
    ld b2=d.x-c.x;
    ld c2=cross(c,d);
    ld det=a1*b2-a2*b1;
    if(det==0) return {1e18,1e18};
    return vect((b1*c2-b2*c1)/det,(c1*a2-a1*c2)/det);
}
vect a[1200];
int main()
{
    fast;
    ll i,j,k,n,m,t;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    ld ans=1e18;
    for(i=0;i<2*n;i++){
        ans=fmin(ans,dist_from_point_to_segment(a[i%n],a[(i+2)%n],a[(i+1)%n]));
    }
    cout<<fout(10)<<ans/2.0<<nl;
    return 0;
}
