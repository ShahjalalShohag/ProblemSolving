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
#define inf 1e18
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
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
inline void nopenot(){cout<<"YES\n";exit(0);}
inline void nope(){cout<<"NO\n";exit(0);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 random(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int N=1e6+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k,ll mod) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
const int MOD1=127657753,MOD2=987654319;
const int p1=137,p2=277;
int invp1,invp2;
pii pw[N],invpw[N];
void pre()
{
    pw[0]={1,1};
    for(int i=1;i<N;i++){
        pw[i].F=1LL*pw[i-1].F*p1%MOD1;
        pw[i].S=1LL*pw[i-1].S*p2%MOD2;
    }
    invp1=qpow(p1,MOD1-2,MOD1);
    invp2=qpow(p2,MOD2-2,MOD2);
    invpw[0]={1,1};
    for(int i=1;i<N;i++){
        invpw[i].F=1LL*invpw[i-1].F*invp1%MOD1;
        invpw[i].S=1LL*invpw[i-1].S*invp2%MOD2;
    }

}
///returns hash of string s
pii get_hash(string s)
{
    int n=s.size();
    pii ans={0,0};
    for(int i=0;i<n;i++){
        ans.F=(ans.F+1LL*pw[i].F*s[i]%MOD1)%MOD1;
        ans.S=(ans.S+1LL*pw[i].S*s[i]%MOD2)%MOD2;
    }
    return ans;
}
struct RollingHash
{
    int n;
    string s;///0-indexed
    vector<pii>hs;///1-indexed
    void init(string _s)
    {
        n=_s.size();
        s=_s;
        hs.eb(0,0);
        for(int i=0;i<n;i++){
            pii p;
            p.F=(hs[i].F+1LL*pw[i].F*s[i]%MOD1)%MOD1;
            p.S=(hs[i].S+1LL*pw[i].S*s[i]%MOD2)%MOD2;
            hs.pb(p);
        }
    }
    ///returns hash of substring [l....r],1-indexed
    pii get_hash(int l,int r)
    {
        pii ans;
        ans.F=(hs[r].F-hs[l-1].F+MOD1)%MOD1*1LL*invpw[l-1].F%MOD1;
        ans.S=(hs[r].S-hs[l-1].S+MOD2)%MOD2*1LL*invpw[l-1].S%MOD2;
        return ans;
    }
    ///returns hash of total string
    pii get()
    {
        return get_hash(1,n);
    }
    pii get(int l,int r)
    {
        return get_hash(l+1,r+1);
    }
};
RollingHash h;
int main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    ///never forget to initialize pre()
    pre();
    string s,p;
    cin>>p>>s;
    int szp=p.size();
    n=s.size();
    int o=0;
    for(i=szp-1;i>=0;i--){
        o+=(p[i]==p[0]);
    }
    h.init(s);
    int cnt=0;
    for(i=0;i<szp;i++){
        if(p[i]==p[0]) cnt++;
        else break;
    }
    int ans=0;
    for(i=0;i<n;i++){
        if(1LL*(i+1)*cnt>=1LL*n) continue;
        bool ok=1;
        pii a=h.get(0,i);
        for(j=1,k=i+1;j<cnt&&k+i<n;j++,k+=i+1){
            if(a!=h.get(k,k+i)){
                ok=0;
                break;
            }
        }
        if(!ok) continue;
        int nx=o-cnt;
        ll baki=1LL*n-1LL*o*(i+1);
        int u=szp-o;
        if(baki<=0||baki%u!=0) continue;
        int len=baki/u;
        int idx=(i+1)*cnt;
        pii b=h.get(idx,idx+len-1);
        if(a==b) continue;
        ok=1;
        for(k=cnt;k<szp&&idx<n;k++){
            if(p[k]==p[0]){
                if(a!=h.get(idx,idx+i)){
                    ok=0;
                    break;
                }
                idx+=i+1;
            }
            else{
                if(b!=h.get(idx,idx+len-1)){
                    ok=0;
                    break;
                }
                idx+=len;
            }
        }
        if(ok) ans++;
    }
    cout<<ans<<nl;
    return 0;
}
