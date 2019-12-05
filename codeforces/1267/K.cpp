#include <bits/stdc++.h>
 
using namespace std;
 
namespace IO
{
    #define II() ( { int a ; read(a) ; a; } )
    #define LL() ( { Long a ; read(a) ; a; } )
    #define DD() ({double a; scanf("%lf", &a); a;})
    #define FI freopen ("input.txt", "r", stdin)
    #define FO freopen ("output.txt", "w", stdout)
    template<class T>inline bool read(T &x){
        int c=getchar();int sgn=1;
        while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
        for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; 
        x*=sgn; return ~c;
    }
}
namespace Utility
{
    template< typename T > T gcd(T a, T b) { return a ? gcd(b%a,a) : b; }
    template< typename T > T lcm(T a, T b) { return (a / gcd(a, b) * b); }
    template< typename T >inline T addmod(T a, T b, T mod) { T c = a+b; return c>mod? c-mod : c; }
    template< typename T >inline T submod(T a, T b, T mod) { T c = a-b; return c<mod? c+mod : c; }
    template< typename T >inline T mulmod(T a, T b, T mod) { return a*1LL*b%mod; }
    template< typename T> T exEuclid(T a, T b, T &x, T &y) {
        x = 0, y = 1;
        if (a == 0) return b;
        T x1, y1;
        T d = exEuclid(b%a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }
    template< typename T > T modInv(T a, T mod){
        T x, y; exEuclid(a,mod,x,y);
        return x < 0? x + mod : x;
    }
    template<typename T> T bigmod(T b, T p, T mod){
        T ret = b>0;
        while(p){
            if (p&1) ret = mulmod(ret, b, mod);
            p >>= 1 , b = mulmod(b, b, mod);
        }
        return ret;
    }
}
using namespace IO;
using namespace Utility;
 
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define DB if(0) 
#define D(x) cerr << #x " is " << x << endl
 
typedef long long Long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<string> VS;
 
const int INF = 2000000009;
const int MX = 1000005;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1e9+7;
 
/******************************************************************/

int cnt[30],high;


void calc(Long n){
    Long x = 2;
    while (n){
        cnt[n%x]++;
        n/=x;
        x++;
    }
    high=x-1;
}
#define ll long long
Long  dp[22][22][22];
int vis[22][22][22],casio;
ll fact[22];

ll dp_func(int pos,int all,int zero)
{
    if(pos==high)
    {
       return all==1&&zero==0;
    }
    if(vis[pos][all][zero]==casio)return dp[pos][all][zero];
    ll ret=0;
    if(all)ret+=dp_func(pos+1,all-1+cnt[pos],zero)*all;
    if(zero)ret+=dp_func(pos+1,all+cnt[pos],zero-1)*zero;
    vis[pos][all][zero]=casio;
    return dp[pos][all][zero]=ret;
}


int main()
{
    //std::ios_base::sync_with_stdio(false);
    
    int ts;
    cin>>ts;
    fact[0]=1;
    for(int i=1;i<=19;i++)
    {
          fact[i]=fact[i-1]*i;

    }
    while(ts--){
     casio++;
     memset(cnt,0,sizeof cnt);
     ll x;
     scanf("%lld",&x);
     calc(x);
     ll ans=dp_func(2,cnt[1],cnt[0]);
     for(int i=0;i<=19;i++)
     {
        ans/=fact[cnt[i]];

     }
     printf("%lld\n",ans-1);


    }

 
    return 0;
}