//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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
const int N=1e6+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

int A[N],a[N];
ll yo(vpll &v)
{
    //for(auto x:v) cout<<x.F<<' '<<x.S<<nl;
    //cout<<nl;
    ll sum=0;
    for(auto x:v) sum+=x.S;
    ll nw=0;
    for(auto x:v){
        nw+=x.S;
        if(nw*2>=sum){
            //debug(x.F);
            ll ans=0;
            for(auto y:v) ans+=y.S*abs(x.F-y.F);
            //debug(ans);
            return ans;
        }
    }
}
int32_t main()
{
    int n=in();
    ll sum=0;
    for(int i=1;i<=n;i++){
        A[i]=in();
        sum+=A[i];
    }
    vll v;
    for(ll k=2;k*k<=sum;k++){
        if(sum%k==0){
            while(sum%k==0) sum/=k;
            v.eb(k);
        }
    }
    if(sum>1) v.eb(sum);
    assert(SZ(v)<=20);
    ll res=1e18;
    for(auto x:v){
        //debug(x);
        ll ans=0;
        for(int i=1;i<=n;i++) a[i]=A[i]%x;
        ll nw=0;
        vpll p;
        for(int i=1;i<=n;i++){
            nw+=a[i];
            if(nw>=x){
                p.eb(i,a[i]-(nw-x));
                ans+=yo(p);
                p.clear();
                nw%=x;
                if(nw) p.eb(i,nw);
            }
            else if(a[i]) p.eb(i,a[i]);
        }
        res=min(res,ans);
    }
    if(res==1e18) res=-1;
    cout<<res<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

