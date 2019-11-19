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

struct edge
{
    int u,v;
    ll w;
    edge(int _u,int _v,ll _w): u(_u),v(_v),w(_w){}
    bool operator < (const edge& x) const{return w>x.w;}
};
vpii g[N];
ll d[N];
bool vis[N];
vpii query[N];
int par[N];
vi nodes[N];
ll ans[N];
int32_t main()
{
    int n=in(),m=in(),k=in(),Q=in();
    for(int i=1;i<=m;i++){
        int u=in(),v=in(),w=in();
        g[u].eb(v,w);
        g[v].eb(u,w);
    }
    priority_queue<edge>q;
    for(int i=1;i<=n;i++) d[i]=1e18;
    for(int i=1;i<=k;i++){
        d[i]=0;
        q.push(edge(i,i,0));
    }
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        int u=x.u;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto x:g[u]){
            int v=x.F,w=x.S;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push(edge(v,v,d[v]));
            }
        }
    }
    //for(int i=1;i<=n;i++) cout<<i<<' '<<d[i]<<nl;
    vector<edge> e;
    for(int u=1;u<=n;u++) for(auto &x:g[u]){
        e.eb(edge(u,x.F,d[u]+d[x.F]+x.S));
    }
    sort(all(e));
    reverse(all(e));
    for(int i=1;i<=Q;i++){
        int u=in(),v=in();
        query[u].eb(v,i);
        query[v].eb(u,i);
    }
    for(int i=1;i<=n;i++) par[i]=i,nodes[i].eb(i);
    for(auto x:e){
        int u=x.u,v=x.v;
        ll w=x.w;
        if(par[u]==par[v]) continue;
        if(SZ(nodes[par[u]])>SZ(nodes[par[v]])) swap(u,v);
        int pp=par[u];
        for(auto x:nodes[pp]){
            for(auto y:query[x]){
                int id=y.S;
                if(par[y.F]==par[v]) ans[id]=w;
            }
        }
        for(auto x:nodes[pp]){
            par[x]=par[v];
            nodes[par[v]].eb(x);
        }
        nodes[pp].clear();
    }
    for(int i=1;i<=Q;i++) pf1ll(ans[i]);
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

