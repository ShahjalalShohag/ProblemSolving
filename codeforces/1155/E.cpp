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
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define sz(v) (int)v.size()
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
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 rnd(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e6+3;
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

int global, pos, neg,inv[mod];
void shift()
{

    pos++;
    global = (1LL*global * pos) % mod;
    int d = inv[(neg + mod)%mod];
    global = (1LL*global * d) % mod;
    neg++;
}
struct point
{
    int x, y;
    int hor;
    point() {}
    point(int x, int y): x(x), y(y) {}
    int get_val(int val)
    {
        int d = (val - x);
        if( d < 0 ) d += mod;
        int now = ( 1LL*global * inv[d] ) % mod;
        return ( 1LL*now * hor ) % mod;
    }
};
///this is useful when the degree n is constant but you
///ought to bruteforce over x to find f(x).
///In that case bruteforce all x's upto n and find f(x) in O(n) for big values of x
struct lagrange
{
    ///polynomial degree n
    ///there must be n+1 relation points (xi,yi) for each xi from 0 to n in the vector v
    ///careful about the 0-degree polynomials
    int n;
    vector <point> v;
    lagrange() {}
    lagrange(int n, vector <point> v): n(n), v(v) {}
    ///O(nlog(mod))
    void init()
    {
        assert( v.size() == n + 1 );
        int ret = 1;
        for(int i = 1; i <= n; i++)
        {
            int now = (-i + mod);
            ret = ( 1LL*ret * now ) % mod;
        }
        global = ret;
        pos = 0;
        neg = -n;
        for(int i = 0; i <= n; i++)
        {
            v[i].hor = qpow( global,mod-2 );
            shift();
        }
    }
    ///O(nlog(mod))
    int get_val(int val)
    {
        if( val <= n ) return v[val].y;
        global = 1;
        for(int i = 0; i <= n; i++) global = ( 1LL*global * (val - v[i].x) ) % mod;
        if( global < 0 ) global += mod;

        int ret = 0;
        for(int i = 0; i <= n; i++)
        {
            int now = v[i].get_val(val);
            ret = ( ret + 1LL*now * v[i].y%mod ) % mod;
        }
        return ret;
    }
};
lagrange I;

int32_t main()
{
    BeatMeScanf;
    int i,j,n=10,k,m;
    inv[1] = 1;
    for (i = 2; i <mod; i++ ) {
        inv[i] = (-(1LL*mod/i) * inv[mod%i] ) % mod;
        inv[i] = (inv[i] + mod)%mod;
    }
    vector <point> v;
    for(int i = 0; i <= n + 1; i++)
    {
        cout<<'?'<<' '<<i<<nl;
        cout.flush();
        cin>>k;
        if(k==0){
            cout<<'!'<<' '<<i<<nl;
            cout.flush();
            return 0;
        }
        v.pb( point(i, k) );///relation points
    }
    I = lagrange(n + 1, v);
    I.init();
    for(i=n+2;i<mod;i++){
        k=I.get_val(i);
        if(k==0){
            cout<<'!'<<' '<<i<<nl;
            cout.flush();
            return 0;
        }
    }
    cout<<'!'<<' '<<-1<<nl;
    cout.flush();
    return 0;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1


