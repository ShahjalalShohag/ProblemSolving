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
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define sz(v) (int)v.size()
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
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 rnd(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

vi g[N];
int par[N][20],dep[N],sz[N],st[N],en[N],T;
void dfs(int u,int pre)
{
    par[u][0]=pre;
    dep[u]=dep[pre]+1;
    sz[u]=1;
    st[u]=++T;
    for(int i=1;i<=18;i++) par[u][i]=par[par[u][i-1]][i-1];
    for(auto v:g[u]){
        if(v==pre) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    en[u]=T;
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=18;k>=0;k--) if(dep[par[u][k]]>=dep[v]) u=par[u][k];
    if(u==v) return u;
    for(int k=18;k>=0;k--) if(par[u][k]!=par[v][k]) u=par[u][k],v=par[v][k];
    return par[u][0];
}
int kth(int u,int k)
{
    for(int i=0;i<=18;i++) if(k&(1<<i)) u=par[u][i];
    return u;
}
int dist(int u,int v)
{
    int lc=lca(u,v);
    return dep[u]+dep[v]-2*dep[lc];
}
int isanc(int u, int v) {
    return (st[u]<=st[v]) && (en[v]<=en[u]);
}
vi t[N];
///given specific nodes, construct a compressed directed tree with these vertices(if needed some other nodes included)
///returns the nodes of the tree
///t[] is the specific tree
vi buildtree(vi v)
{
    ///sort by entry time
    sort(all(v), [](int x, int y){
		return st[x]<st[y];
	});
	///finding all the ancestors, there are few of them
	int s=sz(v);
	for(int i=0;i<s-1;i++){
        int lc=lca(v[i],v[i+1]);
        v.eb(lc);
	}
	/// removing duplicated nodes
	sort(all(v));
	v.erase(unique(all(v)),v.end());
    ///again sort by entry time
    sort(all(v), [](int x, int y){
		return st[x]<st[y];
	});
	stack<int> st;
	st.push(v[0]);
	for(int i=1;i<sz(v);i++){
		while(!isanc(st.top(),v[i])) st.pop();
		t[st.top()].pb(v[i]);
		st.push(v[i]);
	}
	return v;
}
int ans;
int imp[N];
int yo(int u)
{
    vi nw;
    for(auto v:t[u]) nw.eb(yo(v));
    if(imp[u]){
        for(auto x:nw) if(x) ans++;
        return 1;
    }
    else{
        int cnt=0;
        for(auto x:nw) cnt+=x>0;
        if(cnt>1){
            ans++;
            return 0;
        }
        return cnt;
    }
}
int32_t main()
{
    BeatMeScanf;
    cin.tie(0);
    int i,j,k,n,m,q,u,v;
    cin>>n;
    for(i=1;i<n;i++) cin>>u>>v,g[u].eb(v),g[v].eb(u);
    dfs(1,0);
    cin>>q;
    while(q--){
        cin>>k;
        vi v;
        for(i=0;i<k;i++) cin>>m,v.eb(m),imp[m]=1;
        int fl=1;
        for(auto x:v) if(imp[par[x][0]]) fl=0;
        ans=0;
        vi nodes;
        if(fl) nodes=buildtree(v);
        if(fl) yo(nodes.front());
        if(!fl) ans=-1;
        cout<<ans<<nl;
        ///clear the tree
        for(auto x:nodes) t[x].clear();
        for(auto x:v) imp[x]=0;
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1


