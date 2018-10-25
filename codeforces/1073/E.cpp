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
#define dist(x1,y1,x2,y2) sqrt(SQ(x1-x2)+SQ(y1-y2))
#define one(x) __builtin_popcountll(x)
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

const int mod=998244353;
const int mxn=1e5+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
vll digit;
bool vis[20][1111][2];
ll sz;
pll dp[20][1111][2];
ll cnt[1111],pw[30],k;
pll yo(ll idx,ll mask,bool badha)
{
    if(idx==-1){
        if(cnt[mask]<=k) return MP(0,1);
        else return MP(0,0);
    }
    pll &ret=dp[idx][mask][badha];
    bool &x=vis[idx][mask][badha];
    if(x==1&&badha!=1) return ret;
    pll ans={0,0};
    ll mxhere=badha?digit[idx]:9;
    for(ll i=0;i<=mxhere;i++){
        bool next_badha=(i==digit[idx]?badha:0);
        pll p=yo(idx-1,(mask==0&&i==0)?mask:mask|(1LL<<i),next_badha);
        if(p.S==0) continue;
        ans.F+=(p.F+pw[idx]*i%mod*p.S%mod)%mod;
        ans.F%=mod;
        ans.S+=p.S;
        ans.S%=mod;
    }
    if(badha==0) x=1,ret=ans;
    return ans;
}
ll get(ll n)
{
    if(n<0) return 0;
    digit.clear();
    while(n) digit.pb(n%10),n/=10;
    sz=digit.size();
    return yo(sz-1,0,1).F%mod;
}
int main()
{
    fast;
    ll i,j,n,m,l,r,t;
    pw[0]=1;
    for(i=1;i<30;i++) pw[i]=10LL*pw[i-1]%mod;
    cnt[0]=1;
    for(i=0;i<1111;i++){
        for(j=0;j<=10;j++) if(i&(1<<j)) cnt[i]++;
    }
    t=1;
    while(t--){
        cin>>l>>r>>k;
        cout<<((get(r)-get(l-1))%mod+mod)%mod<<nl;
    }
    return 0;
}
