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
#define valid(tx,ty) (tx>=1&&tx<=n&&ty>=1&&ty<=n)
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
const int N=220;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


///Complexity; min(3^k*n*m,2^k*(n*m)^2)
///must be in 0-indexed
const int M=8;///max number of terminal nodes
int ter[M][2];///terminal nodes
int a[N][N],dp[N][1<<M],n,m;
pii par[N][1<<M];
char s[N][N];

///tracking the steiner tree
void backtrack(int i,int mask)
{
    if(i<0||mask<0) return;
    s[i/m][i%m]='X';
    backtrack(par[i][mask].F,par[i][mask].S);
    if(i==par[i][mask].F) backtrack(i,mask^par[i][mask].S);
}
int main()
{
    BeatMeScanf;
    int i,j,k,t;
    cin>>n>>m>>k;
    for (i=0; i<n; i++) for (int j=0; j<m; j++) cin>>a[i][j];
    for (i=0; i<k; i++)
    {
        int x,y;
        cin>>x>>y;
        ter[i][0]=x-1;
        ter[i][1]=y-1;
    }
    for (int i=0; i<n*m; i++) for (int j=0; j<(1<<k); j++) dp[i][j]=1e9,par[i][j]=MP(-1,-1);
    /// base case
    for (int i=0; i<k; i++)
    {
        int x=ter[i][0];
        int y=ter[i][1];
        dp[x*m+y][1<<i]=a[x][y];
    }
    for (int mask=1; mask<(1<<k); mask++)
    {
        for (int i=0; i<n*m; i++)
        {
            for (int sub=((mask-1)&mask); sub>0 ; sub=((sub-1)&mask) )
            {
                int num1=dp[i][sub];///cost of having nodes of sub
                int num2=dp[i][sub^mask];///cost for tree without sub nodes
                int num3=a[i/m][i%m];///remove cost for common node i
                if (num1+num2-num3<dp[i][mask]){
                    dp[i][mask]=num1+num2-num3;
                    par[i][mask]=MP(i,sub);
                }
            }
        }
        ///run spfa
        queue<int> q;
        vector<bool> inque(N*N,0);
        for (int i=0; i<n*m; i++)
        {
            inque[i]=true;
            q.push(i);
        }
        while (!q.empty())
        {
            int node=q.front();
            q.pop();
            inque[node]=false;
            for (int i=0; i<4; i++)
            {
                int x=node/m;
                int y=node%m;
                int nx=x+dx[i];
                int ny=y+dy[i];
                if (nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    int num=dp[x*m+y][mask]+a[nx][ny];///add cost for adjacent transitions
                    if (num<dp[nx*m+ny][mask])
                    {
                        dp[nx*m+ny][mask]=num;
                        par[nx*m+ny][mask]=MP(node,mask);
                        if (inque[nx*m+ny]==false)
                        {
                            inque[nx*m+ny]=true;
                            q.push(nx*m+ny);
                        }
                    }
                }
            }
        }
    }
    int ans=1e9,last=0;
    for(int i=0;i<n*m;i++){
        if(dp[i][(1<<k)-1]<ans){
            ans=dp[i][(1<<k)-1];
            last=i;
        }
    }
    cout<<ans<<nl;
    backtrack(last,(1<<k)-1);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(s[i][j]!='X') s[i][j]='.';
            cout<<s[i][j];
        }
        cout<<nl;
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

