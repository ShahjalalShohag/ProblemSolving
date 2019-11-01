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
const int N=105;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


int dp[N][N][N],n;
char s[N];
int mov(char ch,int k)
{
    if(k==0) return ch=='S';
    else if(k==1) return ch=='R';
    else return ch=='P';
}
int yo(int i,int a,int b,int c)
{
    if(i==n) return 0;
    int &ret=dp[i][a][b];
    if(ret!=-1) return ret;
    ret=0;
    if(a) ret=max(ret,mov(s[i],0)+yo(i+1,a-1,b,c));
    if(b) ret=max(ret,mov(s[i],1)+yo(i+1,a,b-1,c));
    if(c) ret=max(ret,mov(s[i],2)+yo(i+1,a,b,c-1));
    return ret;
}
void print(int i,int a,int b,int c)
{
    if(i==n) return;
    int ret=yo(i,a,b,c);
    if(a&&mov(s[i],0)+yo(i+1,a-1,b,c)==ret){
        pf("%c",'R');
        print(i+1,a-1,b,c);
        return;
    }
    else if(b&&mov(s[i],1)+yo(i+1,a,b-1,c)==ret){
        pf("%c",'P');
        print(i+1,a,b-1,c);
        return;
    }
    else{
        pf("%c",'S');
        print(i+1,a,b,c-1);
    }
    return;
}
int32_t main()
{
    int t=in();
    while(t--){
        n=in();
        int a=in(),b=in(),c=in();
        sf("%s",s);
        mem(dp,-1);
        int ans=yo(0,a,b,c);
        if(ans>=(n+1)/2){
            puts("YES");
            print(0,a,b,c);
            puts("");
        }
        else puts("NO");
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

