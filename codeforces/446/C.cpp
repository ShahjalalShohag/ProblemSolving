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
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
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

const int mod=1e9+9;
const int mxn=3e5+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
struct seg
{
    ll fi,se;
}lazy[mxn*4];
ll t[mxn*4],f[mxn],a[mxn];
//get k-th fibonacci number where first and second fibonacci is a and b
ll get_kth(ll a,ll b,ll k)
{
    a%=mod;
    b%=mod;
    if(k==1) return a;
    if(k==2) return b;
    return ((a*f[k-2])%mod+(b*f[k-1])%mod)%mod;
}
void propagate(ll n,ll b,ll e)
{
    if(lazy[n].fi==0&&lazy[n].se==0) return;
    if(b==e) t[n]=(t[n]+lazy[n].fi)%mod;
    else{
        ll len=e-b+1;
        //sum of fib[1]+fib[2]+...+fib[len]=fib[len+2]-fib[2];
        t[n]=(t[n]+((get_kth(lazy[n].fi,lazy[n].se,len+2)-lazy[n].se)%mod+mod)%mod)%mod;
        lazy[2*n].fi=(lazy[2*n].fi+lazy[n].fi%mod)%mod;
        lazy[2*n].se=(lazy[2*n].se+lazy[n].se%mod)%mod;
        ll mid=(b+e)/2;
        lazy[2*n+1].fi=(lazy[2*n+1].fi+get_kth(lazy[n].fi,lazy[n].se,mid-b+1+1))%mod;
        lazy[2*n+1].se=(lazy[2*n+1].se+get_kth(lazy[n].fi,lazy[n].se,mid-b+1+2))%mod;
    }
    lazy[n].fi=lazy[n].se=0;
}
void build(ll n,ll b,ll e)
{
    if(b==e){
        t[n]=a[b]%mod;
        return;
    }
    stree;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=(t[l]+t[r])%mod;
}
void upd(ll n,ll b,ll e,ll i,ll j)
{
    propagate(n,b,e);
    if(i>e||j<b) return;
    if(b>=i&&e<=j){
        lazy[n].fi=(lazy[n].fi+f[b-i+1])%mod;
        lazy[n].se=(lazy[n].se+f[b-i+2])%mod;
        propagate(n,b,e);
        return;
    }
    stree;
    upd(l,b,mid,i,j);
    upd(r,mid+1,e,i,j);
    t[n]=(t[l]+t[r])%mod;
}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    propagate(n,b,e);
    if(i>e||j<b) return 0;
    if(b>=i&&e<=j) return t[n]%mod;
    stree;
    return (query(l,b,mid,i,j)+query(r,mid+1,e,i,j))%mod;
}
int main()
{
    fast;
    ll i,j,k,n,m,t,l,r;
    f[1]=f[2]=1;
    for(i=3;i<mxn;i++) f[i]=(f[i-1]+f[i-2])%mod;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        cin>>t>>l>>r;
        if(t==1) upd(1,1,n,l,r);
        else cout<<(query(1,1,n,l,r)+mod)%mod<<nl;
    }
    return 0;
}
