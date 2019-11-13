//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MP make_pair
#define fs first
#define sc second
#define F first
#define S second
#define nl "\n"
#define asche cerr<<"Ekhane asche\n";
#define pf printf
#define sf scanf
#define mem(a,x) memset(a,x,sizeof(a))
#define SZ(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define one(x) __builtin_popcount(x)
#define fout(x) fixed<<setprecision(x)
#define BeatMeScanf ios_base::sync_with_stdio(false)
//int dx[]={1,0,-1,0,1,-1,-1,1};
//int dy[]={0,1,0,-1,1,1,-1,-1};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
namespace IO
{
    #define in() ( { int a ; scanf("%d",&a); a; } )
    #define LL() ( { ll a ; scanf("%lld",&a); a; } )
    #define ULL() ( { ull a ; scanf("%llu",&a); a; } )
    #define DD() ({ double a; scanf("%lf", &a); a;})
    #define CC() ( { char a ; scanf("%c",&a); a; } )
    #define pf1(a) printf("%d\n",a)
    #define pf1ll(a) printf("%lld\n",a)
}
using namespace IO;

const int N = 3e6+9;
const int mod = 998244353;
const int root=3;
int lim, rev[N], w[N], wn[N],inv_lim;
void reduce(int &x) { x=(x+mod)%mod;}
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

vi g[N];
vi mul(int l,int r)
{
    if(l>r) return vi(1,1);
    if(l==r) return g[l];
    int mid=(l+r)/2;
    vi ansl=mul(l,mid);
    vi ansr=mul(mid+1,r);
    return multiply(ansl,ansr);
}
int a[N];
int32_t main()
{
    int n=in();
    for(int i=0;i<n;i++){
        int k=in();
        a[k]++;
    }
    int T=0;
    for(int i=1;i<N;i++) if(a[i]) g[++T]=vi(a[i]+1,1);
    vi ans=mul(1,T);
    pf1(ans[n/2]);
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
