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
#define sz(v) (int)v.size()
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
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 rnd(rd());
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
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

struct cline {
    ll M, C;
    cline() {}
    cline(ll m, ll c): M(m), C(c) {}
};
int last=0,pointer=0;

//pointer=0,last=0 should be made initially
cline line[N]; //y=mx+c we need only m(slope) and c(constant)

//Returns true if either line l1 or line l3 is always better than line l2
bool bad(const cline & l1,const cline & l2,const cline & l3) {
    /*
    intersection(l1,l2) has x-coordinate (c1-c2)/(m2-m1)
    intersection(l1,l3) has x-coordinate (c1-c3)/(m3-m1)
    set the former greater than the latter, and cross-multiply to
    eliminate division
    */
    //if the query x values is non-decreasing (reverse(> sign) for vice verse)
    return (double)(l3.C-l1.C)*(double)(l1.M-l2.M)<=(double)(l2.C-l1.C)*(double)(l1.M-l3.M);
}

//Adding should be done serially
//If we want minimum y coordinate(value) then maximum valued m should be inserted first
//If we want maximum y coordinate(value) then minimum valued m should be inserted first
void add(cline l) {
    //First, let's add it to the end
    line[last++]=l;
    //If the penultimate is now made irrelevant between the antepenultimate
    //and the ultimate, remove it. Repeat as many times as necessary
    //in short convex hull main convex hull tecnique is applied here
    while(last>=3&&bad(line[last-3],line[last-2],line[last-1])) {
        line[last-2]=line[last-1];
        last--;
    }
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//line(x) and the lower/upper envelope(pointer)
//This can only be applied if the query of vertical line(x) is already sorted
//works better if number of query is huge
long long query(long long x) {
    //If we removed what was the best line for the previous query, then the
    //newly inserted line is now the best for that query
    if (pointer>=last)
        pointer=last-1;
    //Any better line must be to the right, since query values are
    //non-decreasing
    // Min Value wanted... (reverse(> sign) for max value)
    while (pointer<last-1 && line[pointer+1].M*x+line[pointer+1].C<=line[pointer].M*x+line[pointer].C)
        pointer++;
    return line[pointer].M*x+line[pointer].C;
}

//for any kind of query(sorted or not) it can be used
//it works because of the hill property
//works better if number of query is few
long long bs(int st,int end,long long x,int last) {
    int mid=(st+end)/2;
    // Min Value wanted... (reverse(> sign) for max value)
    if(mid+1<last && line[mid+1].M*x+line[mid+1].C<line[mid].M*x+line[mid].C) return bs(mid+1,end,x,last);
    // Min Value wanted... (reverse(> sign) for max value)
    if(mid-1>=0 && line[mid-1].M*x+line[mid-1].C<line[mid].M*x+line[mid].C) return bs(st,mid-1,x,last);
    return line[mid].M*x+line[mid].C;
}


ll dp[110][N];///dp[i][j]=minimum cost for dividing [1...j] into i parts
ll a[N],d[N],h[N],ti[N],s[N];
ll cost(int i,int j)
{
    return a[j]*(j-i+1)-(s[j]-s[i-1]);
}
int main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    cin>>n>>m>>k;
    for(i=2;i<=n;i++) cin>>d[i],d[i]+=d[i-1];
    for(i=1;i<=m;i++) cin>>h[i]>>ti[i];
    for(i=1;i<=m;i++) a[i]=ti[i]-d[h[i]],s[i]=s[i-1]+a[i];
    sort(a+1,a+m+1);
    ///dp[k][j]=min(dp[k-1][i]+a[j]*(j-i)-(s[j]-s[i]))
    ///i.e dp[k][j]=min(dp[k-1][i]+cost(i+1,j))
    for(i=1;i<=m;i++) dp[1][i]=cost(1,i);
    ///solution for at most k partition
    for(int kk=2;kk<=k;kk++){
        last=0;
        pointer=0;
        for(int i=1;i<=m;i++){
            cline nw;
            nw.M=-i;
            nw.C=dp[kk-1][i]+s[i];
            add(nw); ///add line as dp[kk-1][i] is a constant now
            dp[kk][i]=query(a[i])+i*a[i]-s[i];
        }
    }
    cout<<dp[k][m]<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

