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
#define vpll vector< pair<ll,ll> >
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
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
#define fast ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define dist(x1,y1,x2,y2) sqrt(SQ(x1-x2)+SQ(y1-y2))
#define one(x) __builtin_popcount(x)
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
const int N=2e5+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k,ll mod) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
const ll MOD1=127657753LL,MOD2=987654319LL;
const ll p1=137,p2=277;
ll invp1,invp2;
pll pw[N],invpw[N];
void pre()
{
    pw[0]={1,1};
    for(int i=1;i<N;i++){
        pw[i].F=pw[i-1].F*p1%MOD1;
        pw[i].S=pw[i-1].S*p2%MOD2;
    }
    invp1=qpow(p1,MOD1-2,MOD1);
    invp2=qpow(p2,MOD2-2,MOD2);
    invpw[0]={1,1};
    for(int i=1;i<N;i++){
        invpw[i].F=invpw[i-1].F*invp1%MOD1;
        invpw[i].S=invpw[i-1].S*invp2%MOD2;
    }

}
///returns hash of string s
pll get_hash(string s)
{
    int n=s.size();
    pll ans={0,0};
    for(int i=0;i<n;i++){
        ans.F=(s[i]+ans.F*p1%MOD1)%MOD1;
        ans.S=(s[i]+ans.S*p2%MOD2)%MOD2;
    }
    return ans;
}
struct RollingHash
{
    int n;
    vi s;
    vector<pll>hs;///1-indexed
    void init(vi _s)
    {
        n=_s.size();
        s=_s;
        hs.eb(0,0);
        for(int i=0;i<n;i++){
            pll p;
            p.F=(hs[i].F+pw[i].F*s[i]%MOD1)%MOD1;
            p.S=(hs[i].S+pw[i].S*s[i]%MOD2)%MOD2;
            hs.pb(p);
        }
    }
    ///returns hash of substring [l....r],1-indexed
    pll get_hash(int l,int r)
    {
        pll ans;
        ans.F=(hs[r].F-hs[l-1].F+MOD1)%MOD1*invpw[l-1].F%MOD1;
        ans.S=(hs[r].S-hs[l-1].S+MOD2)%MOD2*invpw[l-1].S%MOD2;
        return ans;
    }
    ///returns hash of total string
    pll get()
    {
        return get_hash(1,n);
    }
};
RollingHash h[26];
vi pos[26];
int main()
{
    fast;
    int i,j,k,m,x,y,n,l,q;
    string s;
    cin>>n>>q>>s;
    pre();
    for(i=0;i<26;i++) pos[i]=vi(n,0);
    for(i=0;i<n;i++) pos[s[i]-'a'][i]=1;
    for(i=0;i<26;i++) h[i].init(pos[i]);
    vpll a,b;
    while(q--){
        cin>>x>>y>>l;
        for(i=0;i<26;i++){
            a.pb(h[i].get_hash(x,x+l-1));
            b.pb(h[i].get_hash(y,y+l-1));
        }
        srt(a);
        srt(b);
        if(a==b) cout<<"YES\n";
        else cout<<"NO\n";
        a.clear();
        b.clear();
    }
    return 0;
}
