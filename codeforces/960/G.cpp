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

const int mod=998244353;
const int N=4e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = N;

inline void addmod(int& x, int y, int mod) { (x += y) >= mod && (x -= mod); }
inline int mulmod(int x, int y, int mod) { return x * 1ll * y % mod; }

struct complex_base
{
	double x, y;
	complex_base(double _x = 0, double _y = 0) { x = _x; y = _y; }
	friend complex_base operator-(const complex_base &a, const complex_base &b) { return complex_base(a.x - b.x, a.y - b.y); }
	friend complex_base operator+(const complex_base &a, const complex_base &b) { return complex_base(a.x + b.x, a.y + b.y); }
	friend complex_base operator*(const complex_base &a, const complex_base &b) { return complex_base(a.x * b.x - a.y * b.y, a.y * b.x + b.y * a.x); }
	friend void operator/=(complex_base &a, const double &P) { a.x /= P; a.y /= P; }
};

int bit_rev[MAXN];
int last_n_fft = -1, ilast_n_fft = -1;
complex_base root[MAXN], iroot[MAXN];

void fft(complex_base *a, int lg)
{
	int n = (1 << lg);
	if(last_n_fft != n)
	{
		double ang = 2 * PI / n;
		for(int i = 0; i < (n >> 1); i++)
			root[i] = complex_base(cos(ang * i), sin(ang * i));

		last_n_fft = n;
	}

	for(int i = 1; i < n; i++)
	{
		bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
		if(bit_rev[i] < i) swap(a[i], a[bit_rev[i]]);
	}

	for(int len = 2; len <= n; len <<= 1)
	{
		int step = (n / len);
		for(int j = 0; j < (len >> 1); j++)
			for(int i = 0; i < n; i += len)
			{
				complex_base u = a[i + j], v = root[step * j] * a[i + j + (len >> 1)];
				a[i + j] = u + v;
				a[i + j + (len >> 1)] = u - v;
			}
	}
}

void inv_fft(complex_base *a, int lg)
{
	int n = (1 << lg);
	if(ilast_n_fft != n)
	{
		double ang = -2 * PI / n;
		for(int i = 0; i < (n >> 1); i++)
			iroot[i] = complex_base(cos(ang * i), sin(ang * i));

		ilast_n_fft = n;
	}

	for(int i = 1; i < n; i++)
	{
		bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
		if(bit_rev[i] < i) swap(a[i], a[bit_rev[i]]);
	}

	for(int len = 2; len <= n; len <<= 1)
	{
		int step = (n / len);
		for(int j = 0; j < (len >> 1); j++)
			for(int i = 0; i < n; i += len)
			{
				complex_base u = a[i + j], v = iroot[step * j] * a[i + j + (len >> 1)];
				a[i + j] = u + v;
				a[i + j + (len >> 1)] = u - v;
			}
	}

	for(int i = 0; i < n; i++)
		a[i] /= n;
}

complex_base A[MAXN], B[MAXN];

vector<int> mult(const vector<int> &a, const vector<int> &b)
{
	if(a.size() * b.size() <= 128)
	{
		vector<int> ans(a.size() + b.size(), 0);
		for(int i = 0; i < (int)a.size(); i++)
			for(int j = 0; j < (int)b.size(); j++)
				ans[i + j] = (ans[i + j] + a[i] * 1ll * b[j]) % mod;

		return ans;
	}

	int lg = 0; while((1 << lg) < (int)(a.size() + b.size())) ++lg;
	for(int i = 0; i < (1 << lg); i++) A[i] = B[i] = complex_base(0, 0);
	for(int i = 0; i < (int)a.size(); i++) A[i] = complex_base(a[i], 0);
	for(int i = 0; i < (int)b.size(); i++) B[i] = complex_base(b[i], 0);

	fft(A, lg); fft(B, lg);
	for(int i = 0; i < (1 << lg); i++)
		A[i] = A[i] * B[i];
	inv_fft(A, lg);

	vector<int> ans(a.size() + b.size(), 0);
	for(int i = 0; i < (int)ans.size(); i++)
		ans[i] = (int64_t)(A[i].x + 0.5) % mod;

	return ans;
}

vector<int> mult_mod(const vector<int> &a, const vector<int> &b)
{
	// a = a0 + sqrt(MOD) * a1
	// a = a0 + base * a1
	int base = (int)sqrtl(mod);

	vector<int> a0(a.size()), a1(a.size());
	for(int i = 0; i < (int)a.size(); i++)
	{
		a0[i] = a[i] % base;
		a1[i] = a[i] / base;
	}

	vector<int> b0(b.size()), b1(b.size());
	for(int i = 0; i < (int)b.size(); i++)
	{
		b0[i] = b[i] % base;
		b1[i] = b[i] / base;
	}

	vector<int> a01 = a0;
	for(int i = 0; i < (int)a.size(); i++)
		addmod(a01[i], a1[i], mod);

	vector<int> b01 = b0;
	for(int i = 0; i < (int)b.size(); i++)
		addmod(b01[i], b1[i], mod);

	vector<int> C = mult(a01, b01);  // 1

	vector<int> a0b0 = mult(a0, b0); // 2
	vector<int> a1b1 = mult(a1, b1); // 3

	vector<int> mid = C;
	for(int i = 0; i < (int)mid.size(); i++)
	{
		addmod(mid[i], -a0b0[i] + mod, mod);
		addmod(mid[i], -a1b1[i] + mod, mod);
	}

	vector<int> res = a0b0;
	for(int i = 0; i < (int)res.size(); i++)
		addmod(res[i], mulmod(base, mid[i], mod), mod);

	base = mulmod(base, base, mod);
	for(int i = 0; i < (int)res.size(); i++)
		addmod(res[i], mulmod(base, a1b1[i], mod), mod);

	return res;
}

vi vec[N];
int stirling(int n,int k)
{
    if(n==0&&k==0) return 1;
    if(n<=0||k<=0) return 0;
    int mx=1;
    while(mx<n) mx<<=1;
    for(int i=0;i<n;i++){
        vec[i].eb(i);
        vec[i].eb(1);
    }
    for(int i=n;i<mx;i++) vec[i].eb(1);
    for(int j=mx;j>1;j>>=1){
        int d=j>>1;
        for(int i=0;i<d;i++) vec[i]=mult_mod(vec[i],vec[i+d]);
    }
    if(k>=vec[0].size()) return 0;
    return vec[0][k];
}
int ncr(int n,int r)
{
    if(r<0||n<r) return 0;
    vi f(N,1),ifac(N,1),inv(N,1);
    for (int i = 2; i <N; i++ ) {
        inv[i] = (-(1LL*mod/i) * inv[mod%i] ) % mod;
        inv[i] = (inv[i] + mod)%mod;
    }
    for(int i=1;i<N;i++){
        f[i]=1LL*f[i-1]*i%mod;
        ifac[i]=1LL*ifac[i-1]*inv[i]%mod;
    }
    return 1LL*f[n]*ifac[r]%mod*ifac[n-r]%mod;
}
int main()
{
    BeatMeScanf;
    int i,j,k,n,m,a,b;
    cin>>n>>a>>b;
    cout<<1LL*stirling(n-1,a+b-2)*ncr(a+b-2,a-1)%mod<<nl;
    return 0;
}
/*
Before submit=>
    *check for integer overflow
    *check for n=1
*/
