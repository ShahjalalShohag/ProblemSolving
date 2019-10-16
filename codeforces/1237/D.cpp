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

struct segtree
{
    #define stree l=2*n,r=l+1,mid=(b+e)>>1
    int t[4*N];
    void build(int n,int b,int e)
    {
        if(b==e){
            t[n]=1e9;
            return;
        }
        int stree;
        build(l,b,mid);
        build(r,mid+1,e);
        t[n]=min(t[l],t[r]);
    }
    void upd(int n,int b,int e,int i,int x)
    {
        if(b>i||e<i) return;
        if(b==e&&b==i){
            t[n]=x;
            return;
        }
        int stree;
        upd(l,b,mid,i,x);
        upd(r,mid+1,e,i,x);
        t[n]=min(t[l],t[r]);
    }
    int query(int n,int b,int e,int i,int j)
    {
        if(b>j||e<i) return 1e9;
        if(b>=i&&e<=j) return t[n];
        int stree;
        int a=query(l,b,mid,i,j);
        int p=query(r,mid+1,e,i,j);
        return min(a,p);
    }
}t;
struct segtree2
{
    #define stree l=2*n,r=l+1,mid=(b+e)>>1
    int t[4*N];
    void build(int n,int b,int e)
    {
        if(b==e){
            t[n]=1e9;
            return;
        }
        int stree;
        build(l,b,mid);
        build(r,mid+1,e);
        t[n]=min(t[l],t[r]);
    }
    void upd(int n,int b,int e,int i,int x)
    {
        if(b>i||e<i) return;
        if(b==e&&b==i){
            t[n]=x;
            return;
        }
        int stree;
        upd(l,b,mid,i,x);
        upd(r,mid+1,e,i,x);
        t[n]=min(t[l],t[r]);
    }
    int query(int n,int b,int e,int i,int j)
    {
        if(b>j||e<i) return 1e9;
        if(b>=i&&e<=j) return t[n];
        int stree;
        int a=query(l,b,mid,i,j);
        int p=query(r,mid+1,e,i,j);
        return min(a,p);
    }
}tmin;
int ans[N];
int32_t main()
{
    int n=in();
    vi b(n+1);
    for(int i=1;i<=n;i++) b[i]=in();
    vi a(1,0);
    int k=3;
    while(k--) for(int i=1;i<=n;i++) a.eb(b[i]);
    n*=3;
    t.build(1,1,n);
    tmin.build(1,1,n);
    for(int i=n;i>=1;i--){
        int p=(a[i]+1)/2;
        int k=n,l=i,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(tmin.query(1,1,n,i,mid)<p) k=mid,r=mid-1;
            else l=mid+1;
        }
        t.upd(1,1,n,i,k);
        ans[i]=t.query(1,1,n,i,k);
        t.upd(1,1,n,i,ans[i]);
        tmin.upd(1,1,n,i,a[i]);
    }
    for(int i=1;i<=n/3;i++){
        if(i>1) putchar(' ');
        pf("%d",ans[i]==n?-1:ans[i]-i);
    }
    puts("");
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

