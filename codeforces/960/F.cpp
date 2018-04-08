#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
//#include<ext/pb_ds/detail/rb_tree_map_/rb_tree_.hpp>
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
#define vc vector<char>
#define vs vector<string>
#define vpii vector< pair<int,int> >
#define vpll vector< pair<ll,ll> >
#define ppll pair< ll,pll >
#define pllp pair< pll,ll >
#define stll stack<ll>
#define qll queue<ll>
#define pqll priority_queue<ll>
#define mppll map<pll,ll>
#define mpii map<int,int>
#define mpll map<ll,ll>
#define mpss map<string,string>
#define mpsll map<string,ll>
#define mplls map<ll,string>
#define umpii unordered_map<int,int>
#define umll unordered_map<ll,ll>
#define umpss unordered_map<string,string>
#define umpsll unordered_map<string,ll>
#define umplls unordered_map<ll,string>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define rep(i,n) for(i=0;i<n;i++)
#define itfor(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?’\n’:’ ‘)
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?’\n’:’ ‘)
#define pb push_back
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define inf 0x3f3f3f3f
#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
//#define sf(a) scanf(“%d”,&a)
//#define sfl(a) scanf(“%lld”,&a)
//#define sfc(a) scanf(“%c”,&a)
//#define sff(a,b) scanf(“%d %d”,&a,&b)
//#define sffl(a,b) scanf(“%lld %lld”,&a,&b)
//#define sfff(a,b,c) scanf(“%d %d %d”,&a,&b,&c)
//#define sfffl(a,b,c) scanf(“%lld %lld %lld”,&a,&b,&c)
#define pf printf
//#define pfi(a) pf(“%d\n”,&a)
//#define pfl(a) pf(“%lld\n”,&a)
#define _ccase printf("Case %d: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define debug(x) cout<<#x"="<<(x)<<nl

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) count(v.begin(),v.end(),a)
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod=1e9+7;
const int mxn=4e5+9;
const ld eps=1e-9;
//ll qpow(ll n,ll k) {ll ans=1;while(k){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}
struct sj
{
    ll x,y,z;
}a[mxn];
vll g[mxn],t[mxn];
void update(ll pos,ll n,ll s,ll e,ll i,ll val)
{
    if(s>i||e<i) return;
    if(s==e&&s==i){
        t[pos][n]=max(t[pos][n],val);
        return;
    }
    ll mid=(s+e)/2,l=2*n,r=l+1;
    update(pos,l,s,mid,i,val);
    update(pos,r,mid+1,e,i,val);
    t[pos][n]=max(t[pos][l],t[pos][r]);
}
ll query(ll pos,ll n,ll s,ll e,ll i,ll j)
{
    if(s>j||e<i) return 0;
    if(s>=i&&e<=j) return t[pos][n];
    ll mid=(s+e)/2,l=2*n,r=l+1;
    return max(query(pos,l,s,mid,i,j),query(pos,r,mid+1,e,i,j));
}
int main()
{
    //fast;
    ll i,j,k,n,m,u,v,w,mx,ans=0,st,l,r,mid;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[i].x=u;
        a[i].y=v;
        a[i].z=w;
        g[u].pb(w);
    }
    for(i=1;i<=n;i++){
        srt(g[i]);
        t[i].resize(g[i].size()*4);
    }
    for(i=m;i>=1;i--){
        u=a[i].x;
        v=a[i].y;
        w=a[i].z;
        auto it=UB(all(g[v]),w);
        st=it-g[v].begin();
        mx=query(v,1,0,(ll)g[v].size()-1,st,(ll)g[v].size()-1)+1;
        ans=max(ans,mx);
        l=0,r=g[u].size()-1;
        while(l<=r){
            mid=(l+r)/2;
            if(g[u][mid]>w) r=mid-1;
            else if(g[u][mid]<w) l=mid+1;
            else{
                k=mid;
                break;
            }
        }
        update(u,1,0,(ll)g[u].size()-1,k,mx);
    }
    cout<<ans<<nl;
    return 0;
}

