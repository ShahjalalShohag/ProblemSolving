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
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define one(x) __builtin_popcount(x)
#define fout(x) fixed<<setprecision(x)
#define BeatMeScanf ios_base::sync_with_stdio(false)
//int dx[]={1,0,-1,0,1,-1,-1,1};
//int dy[]={0,1,0,-1,1,1,-1,-1};
random_device RD;
mt19937 rnd(RD());
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

const int mod=1e9+7;
const int N=3e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

struct minxor {
	int best[32], msb;
	minxor() { memset(best, -1, sizeof best); }
	void add(int x) {
		while(x > 0) {
			msb = 31 - __builtin_clz(x);
			if(best[msb] == -1) {
				best[msb] = x;
				break;
			}
			else x = x ^ best[msb];
		}
	}
	int get(int ret = 0) {
		for(int i = 31; i >= 0; i--) {
			if(best[i] != -1) ret = min(ret, ret ^ best[i]);
		}
        return ret;
	}
} XOR;

vpii g[N];
bool vis[N];
int d[N];
void dfs(int u)
{
    vis[u]=1;
    for(auto x:g[u]){
        int v=x.F,w=x.S;
        if(vis[v]) XOR.add(d[u]^d[v]^w);
        else d[v]=d[u]^w,dfs(v);
    }
}
int32_t main()
{
    ///BeatMeScanf;
    int n=in(),m=in();
    for(int i=1;i<=m;i++){
        int u=in(),v=in(),w=in();
        g[u].eb(v,w);
        g[v].eb(u,w);
    }
    dfs(1);
    pf1(XOR.get(d[1]^d[n]));
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
