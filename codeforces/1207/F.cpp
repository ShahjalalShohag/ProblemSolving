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
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define one(x) __builtin_popcount(x)
#define fout(x) fixed<<setprecision(x)
#define BeatMeScanf ios_base::sync_with_stdio(false)
//int dx[]={1,0,-1,0,1,-1,-1,1};
//int dy[]={0,1,0,-1,1,1,-1,-1};
random_device RD;
mt19937 rnd(RD());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const int mod=1e9+7;
const int N=5e5+1;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
int in()
{
    register int c = getchar();
    register int x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = getchar());
    if(c=='-') {neg=1;c=getchar();}
    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
    return x;
}
inline void out(int n)
{
    int N = n<0?-n:n, rev, cnt = 0;
    rev = N;
    if (N == 0) { putchar('0'); putchar('\n'); return ;}
    while ((rev % 10) == 0) { cnt++; rev /= 10;}
    if(n<0) putchar('-');
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
    while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10;}
    while (cnt--) putchar('0');
    putchar('\n');
    return;
}
int ans[1010][1010],a[N],bl=700;
int32_t main()
{
    ///BeatMeScanf;
    int q=in();
    while(q--){
        int t=in(),x=in(),y=in();
        if(t==1){
            a[x]+=y;
            for(int i=1;i<=bl;i++) ans[i][x%i]+=y;
        }
        else{
            if(x<=bl) out(ans[x][y]);
            else{
                int res=0;
                for(int i=y;i<N;i+=x) res+=a[i];
                out(res);
            }
        }
    }
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
