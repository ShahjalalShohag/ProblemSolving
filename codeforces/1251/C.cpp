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
const int N=3e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

char s[N];
int vis[N];
int32_t main()
{
    int t=in();
    while(t--){
        sf("%s",s);
        int n=strlen(s);
        string ans="";
        for(int i=0,j=0,nw=0;nw<n;){
            if(vis[nw]){
                nw++;
                continue;
            }
            while(vis[j]||j<n&&(s[j]-'0')%2==0) j++;
            while(vis[i]||i<n&&(s[i]-'0')%2==1) i++;
            if(i==n){
                ans+=s[j];
                j++;
                nw++;
            }
            else if(j==n) ans+=s[i],i++,nw++;
            else{
                if((s[nw]-'0')%2==0){
                    if(s[i]>s[j]){
                        vis[j]=1;
                        ans+=s[j];
                        j++;
                    }
                    else vis[i]=1,ans+=s[i],i++,nw++;
                }
                else{
                    if(s[j]>s[i]){
                        vis[i]=1;
                        ans+=s[i];
                        i++;
                    }
                    else vis[j]=1,ans+=s[j],j++,nw++;
                }
            }
        }
        puts(ans.c_str());
        for(int i=0;i<=n;i++) vis[i]=0;
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

