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

int mod=1e9+7;
const int N=3e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

///transition-> for(i=0;i<x;i++) f[n]=tr[i]*f[n-i+1]
///S=starting recurrence
///k is 0 indexed
long long linearRec(vector<long long> S, vector<long long> tr, long long k) {
	long long n = S.size();
	if(n==0) return 0;
	auto combine = [&](vector<long long> a, vector<long long> b) {
		vector<long long> res(n * 2 + 1);
		for (long long i=0; i<n+1; i++) for (long long j=0; j<n+1; j++)
			res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
		for (long long i = 2 * n; i > n; --i) for (long long j=0; j<n; j++)
			res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % mod;
		res.resize(n + 1);
		return res;
	};

	vector<long long> pol(n + 1), e(pol);
	pol[0] = e[1] = 1;

	for (++k; k; k /= 2) {
		if (k % 2) pol = combine(pol, e);
		e = combine(e, e);
	}

	long long res = 0;
	for (long long i=0; i<n; i++) res = (res + pol[i + 1] * S[i]) % mod;
	return res;
}
/*
 * Description: Recovers any n-order linear recurrence relation from the first
 * 2n terms of the recurrence.
 * Useful for guessing linear recurrences after brute-forcing the first terms.
 * Should work on any field, but numerical stability for floats is not guaranteed.
 * Output will have size <=2*n.
*/
vector<ll> BerlekampMassey(vector<ll> s) {
	int n = SZ(s), L = 0, m = 0;
	vector<ll> C(n), B(n), T;
	C[0] = B[0] = 1;

	ll b = 1;
	for(int i=0;i<n;i++) {
        ++m;
		ll d = s[i] % mod;
		for(int j=1;j<=L;j++) d = (d + C[j] * s[i - j]) % mod;
		if (!d) continue;
		T = C; ll coef = d * qpow(b, mod-2) % mod;
		for(int j=m;j<n;j++) C[j] = (C[j] - coef * B[j - m]) % mod;
		if (2 * L > i) continue;
		L = i + 1 - L; B = T; b = d; m = 0;
	}

	C.resize(L + 1); C.erase(C.begin());
	for(auto& x:C)  x = (mod - x) % mod;
	return C;
}
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a / b;
        ll t = b; b = a%b; a = t;
        t = xx; xx = x - q*xx; x = t;
        t = yy; yy = y - q*yy; y = t;
    }
    return a;
}
ll mulmod(ll a,ll b,ll mod)
{
    a%=mod;
    ll ans=0;
    while(b){
        if(b&1) ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
pll CRT(ll x, ll a, ll y, ll b) {
	ll s, t;
	ll d = extended_euclid(x, y, s, t);
	if (a % d != b % d) return make_pair(0, -1);
	ll m=x*y;
	s%=m;
	t%=m;
	s=(s+m)%m;
	t=(t+m)%m;
	return make_pair( ((mulmod(mulmod(s , b,m) , x,m) + mulmod(mulmod(t , a,m) , y,m))%m)% m/d, m/ d);
}
pll CRT(const vll &x, const vll &a) {
	pll ret = make_pair(a[0], x[0]);
	for (ll i = 1; i < (int)x.size(); i++) {
		ret = CRT(ret.second, ret.first, x[i], a[i]);
		if (ret.second == -1) break;
	}
	return ret;
}

int32_t main()
{
    ///BeatMeScanf;
    int q=in();
    while(q--){
        ll n=LL(),m=LL();
        ll k=n/m;
        vll v;
        v.eb(0);
        for(int i=1;i<=min(30LL,k);i++) v.eb(v.back()+(1LL*i*m)%10);
        ll m1=1e9+7,m2=1e9+9;
        mod=m1;
        vll tr=BerlekampMassey(v);
        vll st=v;
        st.resize(SZ(tr));
        vll prime,rem;
        prime.eb(m1);rem.eb(linearRec(st,tr,k));
        mod=m2;
        tr=BerlekampMassey(v);
        st=v;
        st.resize(SZ(tr));
        prime.eb(m2);rem.eb(linearRec(st,tr,k));
        pll ans=CRT(prime,rem);
        pf1ll(ans.F);
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
