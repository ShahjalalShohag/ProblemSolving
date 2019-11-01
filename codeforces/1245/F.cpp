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

const int mod=1e9+7;
const int N=3e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

vi l,r;
ll dp[32][2][2][2][2];
ll yo(int i,int f1,int f2,int g1,int g2)
{
    if(i<0) return 1;
    ll &ret=dp[i][f1][f2][g1][g2];
    if(ret!=-1) return ret;
    int l1=f1?0:l[i];
    int r1=f2?1:r[i];
    int l2=g1?0:l[i];
    int r2=g2?1:r[i];
    ret=0;
    for(int a=l1;a<=r1;a++){
        for(int b=l2;b<=r2;b++){
            if(a&b) continue;
            int nf1=a==l[i]?f1:1;
            int nf2=a==r[i]?f2:1;
            int ng1=b==l[i]?g1:1;
            int ng2=b==r[i]?g2:1;
            ret+=yo(i-1,nf1,nf2,ng1,ng2);
        }
    }
    return ret;
}
int32_t main()
{
    int t=in();
    while(t--){
        int a=in(),b=in();
        for(int i=0;i<30;i++) l.eb((a>>i)&1);
        for(int i=0;i<30;i++) r.eb((b>>i)&1);
        mem(dp,-1);
        pf1ll(yo(29,0,0,0,0));
        l.clear();
        r.clear();
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
