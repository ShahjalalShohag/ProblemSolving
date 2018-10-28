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
#define fast ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
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
const int N=1e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

const int kinds = 128;///maximum ASCII value of any character of the string
char str[N];
int K, buc[N], r[N], sa[N], X[N], Y[N], high[N];
bool cmp(int *r, int a, int b, int x)
{
    return (r[a] == r[b] && r[a+x] == r[b+x]);
}

void suffix_array_DA(int n, int m)
{
    int *x = X, *y = Y, i, j, k = 0, l;
    memset(buc, 0, sizeof(buc));
    for(i = 0; i < n; i++) buc[ x[i]=str[i] ]++;
    for(i = 1; i < m; i++) buc[i] += buc[i-1];
    for(i = n-1; i >= 0; i--) sa[--buc[x[i]]] = i;
    for(l = 1, j = 1; j < n; m = j, l <<= 1)
    {
        j = 0;
        for(i = n-l; i < n; i++) y[j++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= l) y[j++] = sa[i]-l;
        for(i = 0; i < m; i++) buc[i] = 0;
        for(i = 0; i < n; i++) buc[ x[y[i]] ]++;
        for(i = 1; i < m; i++) buc[i] += buc[i-1];
        for(i = n-1; i >= 0; i--) sa[ --buc[ x[y[i]] ]] = y[i];
        for(swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? j-1 : j++;
    }
    for(i = 1; i < n; i++) r[sa[i]] = i;
    for(i = 0; i < n-1; high[r[i++]] = k)
        for(k ? k--: 0, j = sa[r[i]-1]; str[i+k] == str[j+k]; k++);
}
vector<int> suffix_array_construction(string s)
{
    int n=s.size();
    for(int i=0;i<n;i++) str[i]=s[i];
    str[n]='\0';
    suffix_array_DA(n+1,kinds);
    vector<int>saa;
    for(int i=1;i<=n;i++) saa.eb(sa[i]);
    return saa;
}
vector<int> lcp_construction(string const& s, vector<int> const& p)
{
    int n = s.size();
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++) rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);

    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])  k++;
        lcp[rank[i]] = k;
        if (k)  k--;
    }
    return lcp;
}
const int MX = 18;
int st[N][MX];
int lg[N];

void pre()
{
    lg[1] = 0;
    for (int i=2; i<N; i++)
        lg[i] = lg[i/2]+1;
}

void build(vector<int> &lcp)
{
    int n = lcp.size();
    for (int i=0; i<n; i++)
        st[i][0] = lcp[i];

    for (int k=1; k<MX; k++)
        for (int i=0; i<n; i++)
        {
            st[i][k] = st[i][k-1];
            int nxt = i + (1<<(k-1));
            if (nxt >= n)    continue;
            st[i][k] = min(st[i][k], st[nxt][k-1]);
        }
}
///minimum of lcp[l.......r]
int get(int l, int r)
{
    int k = lg[r-l+1];
    return min(st[l][k], st[r-(1<<k)+1][k]);
}
int ra[N],sz;
///lcp of suffix starting from i and j
int lcp_(int i,int j)
{
    if(i==j) return sz-i;
    int l=ra[i];
    int r=ra[j];
    if(l>r) swap(l,r);
    return get(l,r-1);
}
string ss;
///lower bound of string t
int lb(string &t,vi &sa){
    int l=0,r=sz-1;
    int k=t.size();
    int ans=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(ss.substr(sa[mid],min(sz-sa[mid],k)) >= t) ans=mid,r=mid-1;
        else l = mid+1;
    }
    return ans;
}
///upper bound of string t
int ub(string &t,vi &sa){
    int l=0,r=sz-1;
    int k=t.size();
    int ans=sz;
    while(l<=r){
        int mid = (l+r)/2;
        if(ss.substr(sa[mid],min(sz-sa[mid],k)) > t) ans=mid,r=mid-1;
        else l = mid+1;
    }
    return ans;
}
int main()
{
    fast;
    int i,j,k,n,m,q;
    string s;
    cin>>s;
    n = s.size();
    vector<int> sa = suffix_array_construction(s);
    //vector<int> lcp = lcp_construction(s, sa);
    sz=n;
    ss=s;
    cin>>q;
    while(q--){
        string t;
        cin>>k>>t;
        int l=lb(t,sa);
        int r=ub(t,sa);
        vi oc;
        for(i=l;i<r;i++) oc.eb(sa[i]);
        srt(oc);
        if(k>oc.size()) cout<<-1<<nl;
        else{
            int ans=n;
            for(i=0;i+k-1<oc.size();i++) ans=min(ans,oc[i+k-1]-oc[i]+(int)t.size());
            cout<<ans<<nl;
        }
    }
    return 0;
}
