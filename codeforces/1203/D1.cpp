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
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define one(x) __builtin_popcount(x)
#define fout(x) fixed<<setprecision(x)
#define BeatMeScanf ios_base::sync_with_stdio(false)
//int dx[]={1,0,-1,0,1,-1,-1,1};
//int dy[]={0,1,0,-1,1,1,-1,-1};
random_device RD;
mt19937 rnd(RD());
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
    #define pf1(a) printf("%d\n",a);
    #define pf1ll(a) printf("%lld\n",a);
}
using namespace IO;

const int mod=1e9+7;
const int N=2e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

int l[N],r[N],nxt[N][26],pre[N][26];
int32_t main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    string a,b;
    cin>>a>>b;
    n=sz(a);
    m=sz(b);
    for(i=0;i<26;i++) nxt[n][i]=n,pre[0][i]=0;
    for(i=n-1;i>=0;i--){
        for(j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
        nxt[i][a[i]-'a']=i;
    }
    for(i=1;i<n;i++){
        for(j=0;j<26;j++) pre[i][j]=pre[i-1][j];
        pre[i][a[i]-'a']=i;
    }
    int nw=-1;
    for(i=0;i<m;i++){
        nw=nxt[nw+1][b[i]-'a'];
        l[i]=nw;
       // debug(l[i]);
    }
    nw=n;
    for(i=m-1;i>=0;i--){
        nw=pre[nw-1][b[i]-'a'];
        r[i]=nw;
       // debug(r[i]);
    }
    int ans=max({l[0],n-l[m-1]-1,r[0],n-r[m-1]-1});
    for(i=0;i+1<m;i++){
        assert(r[i+1]>l[i]);
        ans=max(ans,r[i+1]-l[i]-1);
    }
    cout<<ans<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
