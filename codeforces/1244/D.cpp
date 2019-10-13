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

int mx,L,T,a[N];
vi g[N];
void dfs(int u,int pre,int dep)
{
    if(dep>mx) mx=dep,L=u;
    for(auto v:g[u]) if(v!=pre) dfs(v,u,dep+1);
}
void dfs2(int u,int pre)
{
    a[++T]=u;
    for(auto v:g[u]) if(v!=pre) dfs2(v,u);
}
ll dp[N][5][5];
int n;
ll c[N][4];
ll yo(int i,int mask,int pre)
{
    if(i==n+1)return 0;
    ll &ret=dp[i][mask][pre];
    if(ret!=-1) return ret;
    ll ans=1e18;
    for(int k=0;k<3;k++) if(!((mask>>k)&1)){
        int nw=1<<k;
        if(pre!=3) nw|=1<<pre;
        ans=min(ans,1LL*c[a[i]][k]+yo(i+1,nw,k));
    }
    return ret=ans;
}
int res[N];
void path(int i,int mask,int pre)
{
    if(i==n+1)return;
    ll ans=yo(i,mask,pre);
    for(int k=0;k<3;k++) if(!((mask>>k)&1)){
        int nw=1<<k;
        if(pre!=3) nw|=1<<pre;
        if(ans==1LL*c[a[i]][k]+yo(i+1,nw,k)){
            res[a[i]]=k+1;
            path(i+1,nw,k);
            return;
        }
    }
}

int32_t main()
{
    n=in();
    for(int k=0;k<3;k++){
        for(int i=1;i<=n;i++) c[i][k]=in();
    }
    for(int i=0;i<n-1;i++){
        int u=in(),v=in();
        g[u].eb(v);
        g[v].eb(u);
    }
    for(int i=1;i<=n;i++) if(SZ(g[i])>2) return cout<<-1<<nl,0;
    dfs(1,0,1);
    dfs2(L,0);
    assert(T==n);
    mem(dp,-1);
    pf1ll(yo(1,0,3));
    path(1,0,3);
    for(int i=1;i<=n;i++) cout<<res[i]<<' ';
    cout<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

