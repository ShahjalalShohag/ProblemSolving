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
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 rnd(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

const int N = 1<<18;
const int mod = 998244353;
const int root=3;
int lim, rev[N], w[N], wn[N],inv_lim;
void reduce(int &x) { x=(x%mod+mod)%mod;}
int pow(int x, int y, int ans = 1)
{
	for (; y; y >>= 1, x = (ll) x * x % mod)
		if (y & 1) ans = (ll) ans * x % mod;
	return ans;
}
void nttinit(int len)
{
	lim = wn[0] = 1;
	int s = -1;
    while (lim < len) lim <<= 1, ++s;
	for (int i = 0; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
	const int g = pow(root, (mod - 1) / lim);
	inv_lim=pow(lim, mod - 2);
	for (int i = 1; i < lim; ++i) wn[i] = (ll) wn[i - 1] * g % mod;
}
void ntt(vi &a, int typ)
{
	for (int i = 0; i < lim; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		for (int j = 0, t = lim / i / 2; j < i; ++j) w[j] = wn[j * t];
		for (int j = 0; j < lim; j += i << 1)
			for (int k = 0; k < i; ++k) {
				const int x = a[k + j], y = (ll) a[k + j + i] * w[k] % mod;
				reduce(a[k + j] += y - mod), reduce(a[k + j + i] = x - y);
			}
	}
	if (!typ) {
        reverse(a.begin() + 1, a.begin() + lim);
		for (int i = 0; i < lim; ++i) a[i] = (ll) a[i] * inv_lim % mod;
	}
}
vi multiply(vi &f, vi &g)
{
    int n=(int)f.size()+(int)g.size()-1;
    nttinit(n);
    vi a=f,b=g;
    a.resize(lim);
    b.resize(lim);
    ntt(a, 1), ntt(b, 1);
    for (int i = 0; i < lim; ++i) a[i] = (ll) a[i] * b[i] % mod;
    ntt(a, 0);
    while((int)a.size()&&a.back()==0) a.pop_back();
    return a;
}
int factor[N], ifactor[N];
///return f(x+c)
vi shift(vi &f,int c)
{
    int n=(int)f.size();
    nttinit(n+n-1);
    vi a=f;
    a.resize(lim);
    for (int i = 0; i < n; ++i) a[i] = (ll) a[i] * factor[i] % mod;
    reverse(a.begin(), a.begin()+n);
    vi b;
    b.resize(lim);
    b[0] = 1;
    for (int i = 1; i < n; ++i) b[i] = (ll) b[i - 1] * c % mod;
    for (int i = 0; i < n; ++i) b[i] = (ll) b[i] * ifactor[i] % mod;
    ntt(a, 1), ntt(b, 1);
    for (int i = 0; i < lim; ++i) a[i] = (ll) a[i] * b[i] % mod;
    ntt(a, 0), reverse(a.begin(), a.begin() + n);
    vi g;
    g.resize(n);
    for (int i = 0; i < n; ++i) g[i] = (ll) a[i] * ifactor[i] % mod;
    return g;
}
///returns (x+1)*(x+2)*(x+3)...(x+n)
///O(nlogn)
vi range_mul(int n) {
	if (n == 0) return vi({1});
	if (n & 1) {
		vi f=range_mul(n - 1);
		f.push_back(0);
		for (int i = (int)f.size()-1; i; --i) f[i] = (f[i - 1] + (ll) n * f[i]) % mod;
		f[0] = (ll) f[0] * n % mod;
		return f;
	} else {
		int n_ = n >> 1;
		vi f=range_mul(n_);
		vi tmp=shift(f,n_);
		return multiply(f, tmp);
	}
}
int stirling(int n,int k)
{
    if(n==0&&k==0) return 1;
    if(n<=0||k<=0) return 0;
    vi x=vi({0,1});
    vi y=range_mul(n-1);
    vi ans=multiply(x,y);
    if(k>=(int)ans.size()) return 0;
    return ans[k];
}
int ncr(int n,int r)
{
    if(r<0||n<r) return 0;
    return 1LL*factor[n]*ifactor[r]%mod*ifactor[n-r]%mod;
}
int main()
{
    BeatMeScanf;
    int i,j,k,n,m,a,b;
    factor[0] = 1;
	for (int i = 1; i < N; ++i) factor[i] = (ll) factor[i - 1] * i % mod;
	ifactor[N - 1] = pow(factor[N - 1], mod - 2);
	for (int i = N - 1; i; --i) ifactor[i - 1] = (ll) ifactor[i] * i % mod;
    cin>>n>>a>>b;
    cout<<1LL*stirling(n-1,a+b-2)*ncr(a+b-2,a-1)%mod<<nl;
    return 0;
}
