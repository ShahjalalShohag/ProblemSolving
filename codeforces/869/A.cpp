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
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

#define MX (1 << 21)
#define OR 0
#define AND 1
#define XOR 2
int in=qpow(2,mod-2);
/// Fast Walsh-Hadamard Transformation in n log n
///Beware!!! after the convolution the arrays will not be the same again
///array sizes must be same and powers of 2
struct fwht{
    int P1[MX], P2[MX];

    void walsh_transform(int* ar, int n, int flag = AND){
        if (n == 0) return;

        int i, m = n/2;
        walsh_transform(ar, m, flag);
        walsh_transform(ar+m, m, flag);

        for (i = 0; i < m; i++){  /// Don't forget to remove modulo if not required
            int x = ar[i], y = ar[i + m];
            if (flag == OR) ar[i] = x, ar[i + m] = (x + y)%mod;
            if (flag == AND) ar[i] = (x + y)%mod, ar[i + m] = y;
            if (flag == XOR) ar[i] = (x + y)%mod, ar[i + m] = (x - y+mod)%mod;
        }
    }

    void inverse_walsh_transform(int* ar, int n, int flag = AND){
        if (n == 0) return;

        int i, m = n/2;
        inverse_walsh_transform(ar, m, flag);
        inverse_walsh_transform(ar+m, m, flag);

        for (i = 0; i < m; i++){  /// Don't forget to remove modulo if not required
            int x = ar[i], y = ar[i + m];
            if (flag == OR) ar[i] = x, ar[i + m] = (y - x+mod)%mod;
            if (flag == AND) ar[i] = (x - y+mod)%mod, ar[i + m] = y;
            if (flag == XOR) ar[i] = 1LL*(x + y)%mod *in%mod, ar[i + m] = 1LL*(x - y+mod)%mod *in%mod; /// replace modular inverse(in) by >>1 if not required
        }
    }

    /// For i = 0 to n - 1, j = 0 to n - 1
    /// v[i flag j] += A[i] * B[j]
   vi convolution(int n, int* A, int* B, int flag = AND){
        assert(__builtin_popcount(n) == 1); /// n must be a power of 2
        for (int i = 0; i < n; i++) P1[i] = A[i];
        for (int i = 0; i < n; i++) P2[i] = B[i];

        walsh_transform(P1, n, flag);
        walsh_transform(P2, n, flag);
        for (int i = 0; i < n; i++) P1[i] = 1LL*P1[i] * P2[i]%mod;
        inverse_walsh_transform(P1, n, flag);
        return vi(P1,P1+n);
    }

    ///compute A^k where A*A=A convolution A
    vi pow(int n,int* A,ll k,int flag=AND)
    {
        walsh_transform(A,n,flag);
        for(int i=0;i<n;i++) A[i]=qpow(A[i],k);
        inverse_walsh_transform(A,n,flag);
        return vi(A,A+n);
    }
}t;
int a[MX],b[MX],pos[MX];
int32_t main()
{
    BeatMeScanf;
    int i,j,k,n,m,cnt=0;
    cin>>n;
    for(i=0;i<n;i++) cin>>k,a[k]++,pos[k]=1;
    for(i=0;i<n;i++) cin>>k,b[k]++,pos[k]=1;
    vi ans=t.convolution(MX,a,b,XOR);
    for(i=0;i<MX;i++) if(pos[i]) cnt+=ans[i];
    if(cnt&1) cout<<"Fuck off! It is not possible\n";
    else cout<<"Karen\n";
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
