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
const int N=4e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


vi g[N],gr[N];
bool vis[N];
int T,low[N],dis[N],par[N],rnk[N];
ll w[N];
set<pii>bridge;
void dfs(int u,int pre)
{
    low[u]=dis[u]=++T;
    vis[u]=1;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dis[u]) bridge.insert({min(u,v),max(u,v)});
        }
        else{
            if(v!=pre) low[u]=min(low[u],dis[v]);
        }
    }
}
int find_(int x)
{
    if(par[x]==x) return x;
    return find_(par[x]);
}
void merge_(int x,int y)
{
    int u=find_(x);
    int v=find_(y);
    if(u!=v){
        if(rnk[u]<rnk[v]) par[u]=v,w[v]+=w[u],rnk[v]+=rnk[u];
        else par[v]=u,w[u]+=w[v],rnk[u]+=rnk[v];
    }
}
ll dp[N][2],ok[N],ans;
void yo(int u,int pre=0)
{
    dp[u][1]=w[u];
    ok[u]=rnk[u]>1;
    ll nw=0;
    for(auto v:gr[u]){
        if(v==pre) continue;
        yo(v,u);
        nw+=dp[v][0];
        ok[u]|=ok[v];
    }
    ll p=0;
    for(auto v:gr[u]){
        if(v==pre) continue;
        p=max(p,dp[v][1]+nw-dp[v][0]);
    }
    if(ok[u]) dp[u][0]=nw+w[u];
    dp[u][1]+=p;
}
int main()
{
    BeatMeScanf;
    int i,j,k,n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(i=1;i<=m;i++) cin>>u>>v,g[u].eb(v),g[v].eb(u);
    int s;
    cin>>s;
    dfs(1,0);
    for(i=1;i<=n;i++) par[i]=i,rnk[i]=1;
    for(u=1;u<=n;u++){
        for(auto v:g[u]){
            if(bridge.find({min(u,v),max(u,v)})==bridge.end()) merge_(u,v);
        }
    }
    for(auto p:bridge){
        u=p.F;
        v=p.S;
        int x=find_(u);
        int y=find_(v);
        gr[x].eb(y);
        gr[y].eb(x);
    }
    s=find_(s);
    yo(s);
    ans=max(dp[s][0],dp[s][1]);
    cout<<ans<<nl;
    return 0;
}
