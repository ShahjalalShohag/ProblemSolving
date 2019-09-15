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

int a[12][12],dp[12][1<<12],n,m,b[12][1<<12];
int yo(int mask,int c)
{
    if(c==m) return 0;
    int &ret=dp[c][mask];
    if(ret!=-1) return ret;
    int nw=((1<<n)-1)^mask;
    int ans=0;
    for(int sub=nw;;sub=(sub-1)&nw){
        ans=max(ans,b[c][sub]+yo(mask|sub,c+1));
        if(sub==0) break;
    }
    return ret=ans;
}
int get_max(vi &a)
{
    int ans=0;
    for(auto x:a) ans=max(ans,x);
    return ans;
}
int32_t main()
{
    ///BeatMeScanf;
    int t=in();
    while(t--){
        n=in(),m=in();
        vector<vi> col(m,vi(n,0));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) col[j][i]=in();
        sort(all(col),[](vi &a,vi &b){
             return get_max(a)>get_max(b);});
        m=min(n,m);
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) a[j][i]=col[i][j];
        mem(b,0);
        for(int mask=0;mask<(1<<n);mask++){
            for(int c=0;c<m;c++){
                for(int shift=0;shift<n;shift++){
                    int nw=0;
                    for(int i=0;i<n;i++) if((mask>>i)&1) nw+=a[(i+shift)%n][c];
                    b[c][mask]=max(b[c][mask],nw);
                }
            }
        }
        mem(dp,-1);
        pf1(yo(0,0));
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
