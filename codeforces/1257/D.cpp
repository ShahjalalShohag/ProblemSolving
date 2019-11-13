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
const int N=2e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

int t[N][21],lg2[N];
int get(int l,int r)
{
    int k=lg2[r-l+1];
    return max(t[l][k],t[r-(1<<k)+1][k]);
}
int a[N],mx[N];
int32_t main()
{
    lg2[1]=0;
    for(int i=2;i<N;i++) lg2[i]=lg2[i/2]+1;
    int tc=in();
    while(tc--){
        int n=in();
        for(int i=1;i<=n;i++) a[i]=in();
        for(int i=1;i<=n;i++) t[i][0]=a[i];
        for(int j=1;j<=20;j++) for(int i=1;i+(1<<(j-1))<=n;i++) t[i][j]=max(t[i][j-1],t[i+(1<<(j-1))][j-1]);
        int m=in();
        for(int i=1;i<=m;i++){
            int p=in(),s=in();
            mx[s]=max(mx[s],p);
        }
        for(int i=n-1;i>=1;i--) mx[i]=max(mx[i+1],mx[i]);
        int ans=0;
        int nw=1;
        while(nw<=n){
            int l=nw,r=n,res=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(get(nw,mid)<=mx[mid-nw+1]) res=mid,l=mid+1;
                else r=mid-1;
            }
            if(res==-1){
                ans=-1;
                break;
            }
            nw=res+1;
            ans++;
        }
        pf1(ans);
        for(int i=1;i<=n+1;i++) mx[i]=0;
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

