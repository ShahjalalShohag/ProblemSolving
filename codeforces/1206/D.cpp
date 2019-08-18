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
const int N=3e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

ll a[N];
int cnt[N],dis[N];
set<int> g[N];
int32_t main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        for(k=62;k>=0;k--) if((a[i]>>k)&1LL) cnt[k]++;
    }
    for(i=0;i<=62;i++) if(cnt[i]>2) return cout<<3<<nl,0;
    sort(a+1,a+n+1,greater<ll>());
    for(i=1;i<=n;i++) if(a[i]==0){
        n=i-1;
        break;
    }
    int ans=1e9;
    for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) if(a[i]&a[j]) g[i].insert(j),g[j].insert(i);
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(a[i]&a[j]){
                g[i].erase(j);
                g[j].erase(i);
                queue<int>q;
                q.push(i);
                for(k=1;k<=n;k++) dis[k]=1e9;
                dis[i]=0;
                while(!q.empty()){
                    int u=q.front();
                    q.pop();
                    for(auto v:g[u]) if(dis[v]>dis[u]+1) dis[v]=1+dis[u],q.push(v);
                }
                ans=min(ans,dis[j]+1);
                g[i].insert(j);
                g[j].insert(i);
            }
        }
    }
    if(ans==1e9) ans=-1;
    cout<<ans<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
