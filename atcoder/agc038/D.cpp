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

int u[N],v[N],c[N],sz[N],par[N];
int find_(int u)
{
    if(par[u]==u) return u;
    return par[u]=find_(par[u]);
}
void add(int u,int v)
{
    u=find_(u);
    v=find_(v);
    if(u!=v){
        if(sz[u]<sz[v]) par[u]=v,sz[v]+=sz[u];
        else par[v]=u,sz[u]+=sz[v];
    }
}
int vis[N];
int32_t main()
{
    int n=in(),m=in(),q=in();
    for(int i=1;i<=n;i++) par[i]=i,sz[i]=1;
    int z=0;
    for(int i=1;i<=q;i++){
        u[i]=in(),v[i]=in(),c[i]=in();
        u[i]++;
        v[i]++;
        if(c[i]==0) add(u[i],v[i]);
        if(c[i]==1) z++;
    }
    ///check for no c[i]=0
    for(int i=1;i<=q;i++){
        if(c[i]==0) continue;
        if(find_(u[i])==find_(v[i])) return cout<<"No\n",0;
        else vis[find_(u[i])]=1,vis[find_(v[i])]=1;
    }
    set<int>se;
    for(int i=1;i<=n;i++) se.insert(find_(i));
    int p=0;
    ll mn=SZ(se)-1,mx=SZ(se)-1;
    for(auto x:se){
        mn+=sz[x]-1;
        mx+=sz[x]-1;
        if(sz[x]==1) p++;
    }
    if(z) mn++;
    if(p==0&&z) return cout<<"No\n",0;
    int cnt=SZ(se);
    mx+=1LL*cnt*(cnt-1)/2-(cnt-1);
    if(1LL*m>=mn&&1LL*m<=mx) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

