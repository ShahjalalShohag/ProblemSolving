//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
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
    #define LL() ( { ll a ; scanf("%I64d",&a); a; } )
    #define ULL() ( { ull a ; scanf("%llu",&a); a; } )
    #define DD() ({ double a; scanf("%lf", &a); a;})
    #define CC() ( { char a ; scanf("%c",&a); a; } )
    #define pf1(a) printf("%d\n",a)
    #define pf1ll(a) printf("%lld\n",a)
}
using namespace IO;

const int mod=1e9+7;
const int N=1e6+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

ll mul_mod(ll a,ll b,ll mod)
{
    ll ans=0;
    a%=mod;
    while(b){
        if(b&1LL) ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
ll pow_mod(ll n,ll k,ll mod)
{
    ll ans=1;
    n=n%mod;
    while(k){
        if(k&1) ans=mul_mod(ans,n,mod);
        n=mul_mod(n,n,mod);
        k>>=1;
    }
    return ans;
}
bool test(ll n,ll d)
{
    ll i,j,k,a,x;
    a=2LL+rnd()%(n-4);
    x=pow_mod(a,d,n);
    if(x==1||x==n-1) return 1;
    while(d!=n-1){
        x=mul_mod(x,x,n);
        d*=2;
        if(x==1) return 0;
        if(x==n-1) return 1;
    }
    return 0;
}
bool millerrobin(ll n)
{
    if(n<=1||n==4) return 0;
    if(n<=3) return 1;
    ll i,d=n-1;
    while(d%2==0) d/=2;
    for(i=1;i<=10;i++) if(test(n,d)==0) return 0;
    return 1;
}
ll f(ll n,ll x)
{
    return (mul_mod(x, x, n) + 1) % n;
}
///returns any prime factor of n
ll pollard(ll n) {
	if (!(n & 1)) return 2;
	for (ll i = 2;; i++) {
		ll x = i, y = f(n,x), p;
		while ((p = __gcd(n + y - x, n)) == 1)
			x = f(n,x), y = f(n,f(n,y));
		if (p != n) return p;
	}
}
///Complexity O(n^1/4*logn)
vector<ll> factorize(ll n) {
	if (n == 1) return {};
	if (millerrobin(n)) return {n};
	ll x = pollard(n);
	auto l = factorize(x), r = factorize(n / x);
	l.insert(l.end(), all(r));
	return l;
}

ll a[N];
vpll vec;
vll di;
void gen(int i,ll nw)
{
    if(i==SZ(vec)){
        di.eb(nw);
        return;
    }
    gen(i+1,nw);
    for(int k=1;k<=vec[i].S;k++){
        nw*=vec[i].F;
        gen(i+1,nw);
    }
}
unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(ll x) const { return hash_f(x); }
};
gp_hash_table<ll, int, chash> id,mp;
int cnt[N];
int32_t main()
{
    ///BeatMeScanf;
    int n=in();
    for(int i=1;i<=n;i++) a[i]=LL();
    int it=10;
    ll ans=1;
    while(it--){
        int k=rnd()%n+1;
        //debug(k);
        //debug(a[k]);
        auto v=factorize(a[k]);
        mp.clear();
        for(auto x:v) mp[x]++;
        vec.clear();
        for(auto x:mp) vec.eb(x.F,x.S);
        di.clear();
        gen(0,1);
        //debug(k,a[k]);
        //debug(SZ(di));

        sort(all(di));
        // debug(a[k]);
        //for(auto x:di) cout<<x<<' ';
        //cout<<nl;
        int d=SZ(di);
        id.clear();
        for(int i=0;i<d;i++) id[di[i]]=i;
        mem(cnt,0);
        for(int i=1;i<=n;i++) cnt[id[__gcd(a[i],a[k])]]++;
        for(auto x:vec){
            for(int i=d-1;i>=0;i--){
                if(di[i]%x.F==0){
                    cnt[id[di[i]/x.F]]+=cnt[i];
                    //assert(id[di[i]/x.F]<i);
                }
            }
        }
        for(int i=0;i<d;i++){
            if(2*cnt[i]>=n){
                ans=max(ans,di[i]);
            }
        }
    }
    pf1ll(ans);
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

