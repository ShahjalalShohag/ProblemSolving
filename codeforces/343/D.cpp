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

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?�\n�:� �)
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?�\n�:� �)
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
#define inf 0x3f3f3f3f
#define PI (acos(-1.0))
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define dist(x1,y1,x2,y2) sqrt(SQ(x1-x2)+SQ(y1-y2))
#define one(x) __builtin_popcount(x)
#define stree ll l=(n<<1),r=(n<<1)|1,mid=b+(e-b)/2
#define Unique(v) v.erase(unique(all(v)),v.end())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int mxn=5e5+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}
ll par[mxn],tim,st[mxn],en[mxn];
vll g[mxn];
bool t[mxn*4];
//empty=1,fill=0;
void build(ll n,ll b,ll e)
{
    if(b==e){
        t[n]=1;
        return;
    }
    stree;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=t[l]|t[r];
}
void fill_them(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i) return;
    if(b==e){
        t[n]=0;
        return;
    }
    stree;
    if(t[l]) fill_them(l,b,mid,i,j);
    if(t[r]) fill_them(r,mid+1,e,i,j);
    t[n]=t[l]|t[r];
}
void make_empty(ll n,ll b,ll e,ll i)
{
    if(i<b||i>e) return;
    if(b==e&&b==i){
        t[n]=1;
        return;
    }
    stree;
    make_empty(l,b,mid,i);
    make_empty(r,mid+1,e,i);
    t[n]=t[l]|t[r];
}
bool query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i) return 0;
    if(b>=i&&e<=j) return t[n];
    stree;
    return query(l,b,mid,i,j)|query(r,mid+1,e,i,j);
}
void dfs(ll u,ll pre)
{
    par[u]=pre;
    st[u]=++tim;
    for(auto v:g[u]) if(v!=pre) dfs(v,u);
    en[u]=tim;
}
int main()
{
    fast;
    ll i,j,k,n,m,u,v,type,q;
    cin>>n;
    for(i=1;i<n;i++) cin>>u>>v,g[u].pb(v),g[v].pb(u);
    dfs(1,0);
    build(1,1,tim);
    cin>>q;
    while(q--){
        cin>>type>>u;
        if(type==1){
            bool chk=query(1,1,tim,st[u],en[u]);
            fill_them(1,1,tim,st[u],en[u]);
            if(chk&&par[u]) make_empty(1,1,tim,st[par[u]]);
        }
        else if(type==2) make_empty(1,1,tim,st[u]);
        else{
            if(query(1,1,tim,st[u],en[u])) cout<<0<<nl;
            else cout<<1<<nl;
        }
    }
    return 0;
}
