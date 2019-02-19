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
//#define rev(v) reverse(v.begin(),v.end())
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
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 random(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int N=2e5+9;
const ld eps=1e-9;
const double PI = acos(-1);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k,ll mod) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


///only works for ntt friendly primes
const int MT=18,T=(1<<MT)|1;///maximum size of array,always make it a power of 2
const int root=3;///primitive root of K
const int K=998244353;///prime modulo
int inv[T], w[T];
namespace NTT{
    int power(int a,int b)
    {
        int t=1;
        for (; b>0; b>>=1,a=1ll*a*a%K)
            b&1? t=1ll*t*a%K:0;
        return t;
    }

    void initNTT(){
        w[0]=1,w[1]=power(root,K>>MT);
        for(int i=2;i<=T-1;i++) w[i]=1ll*w[i-1]*w[1]%K;
        inv[1]=1;
        for(int i=2;i<=T-1;i++) inv[i]=(K-K/i)*1ll*inv[K%i]%K;
    }

    int getmx(int n)
    {
        int mx=1;
        for (; mx<n; mx<<=1);
        return mx;
    }

    vector<int> ntt(vector<int> &a, int mx)
    {
        vector<int> b=a;
        static int rev[T];
        b.resize(mx);
        for(int i=0;i<=mx-1;i++)
            rev[i]=rev[i>>1]>>1|(i&1)*(mx>>1),rev[i]>i? swap(b[i],b[rev[i]]):void();
        for (int k=1,_=T/2; k<mx; k<<=1,_>>=1)
            for (int j=0; j<mx; j+=k<<1)
                for (int t,i=j,p=0; i<j+k; ++i,p+=_)
                    t=1ll*b[i+k]*w[p]%K,b[i+k]=(b[i]-t+K)%K,b[i]=(b[i]+t)%K;

        return b;
    }

    vector<int> trans(vector<int> &a, int n){
        const int mx=a.size();
        if(mx<=n) n=mx-1;
        vector<int> b=a;
        vector<int>rev (mx);
        for(int i=0;i<=mx-1;i++)
            rev[i]=rev[i>>1]>>1|(i&1)*(mx>>1),rev[i]>i? swap(b[i],b[rev[i]]):void();
        for (int k=1,_=-T/2; k<mx; k<<=1,_>>=1)
        for (int j=0; j<mx; j+=k<<1)
            for (int t,i=j,p=T-1; i<j+k; ++i,p+=_)
                t=1ll*b[i+k]*w[p]%K,b[i+k]=(b[i]-t+K)%K,b[i]=(b[i]+t)%K;
        int t=power(mx,K-2);
        vector<int> c;
        int te=1;
        for(int i=n;i>=0;i--)  if (b[i]) {c.pb(b[i]*1ll*t%K);te=i; break;}
        for(int i=te-1;i>=0;i--) c.pb(b[i]*1ll*t%K);
        reverse(all(c));
        return c;
    }

    vector<int> multiply(vector<int> &a, vector<int> &b, int n){
        int N=a.size(); if (N<b.size()) N=b.size();
        int mx=getmx((N<<1));
        vector<int> c=ntt(a,mx);
        vector<int> d=ntt(b,mx);
        for(int i=0;i<=mx-1;i++) c[i]=c[i]*1ll*d[i]%K;
        int u=a.size()+b.size()-2 ;
        if (n>u) n=u;
        c=trans(c,n);
        return c;
    }
    ///return f(x)*g(x) modulo K
    inline vector<int> multiply(vector<int> &a, vector<int> &b){
        return multiply(a,b,T-1);
    }
    ///returns 1/f(x) modulo K
    vector<int> inverse(vector<int> &a, int n){
        if (n==0){
            vector<int> b; b.pb(power(a[0],K-2)); return b;
        }
        vector<int> b=inverse(a,n>>1);
        n++;
        vector<int> t;
        if (a.size()>=n) t=vector<int> (a.begin(),a.begin()+n);
        else t=a;
        int mx=getmx(n<<1);
        t=ntt(t,mx);
        b=ntt(b,mx);
        for(int i=0;i<=mx-1;i++)
            b[i]=b[i]*(2ll-t[i]*1ll*b[i]%K+K)%K;
        n--;
        vector<int> C=trans(b,n);
        return trans(b,n);
    }
    ///returns d/dx(f(x)) modulo K
    inline vector<int> derivative(vector<int> &a, int m){
        vector<int> b;
        for (int i=0; i+1<a.size(); i++){
            b.pb(a[i+1]*1ll*(i+1)%K);
        }
        return b;
    }
    ///returns integration of f(x)dx modulo K
    inline vector<int> integrate(vector<int> &a, int m){
        vector<int> b;
        b.pb(0);
        for (int i=1; i-1<a.size() && i<=m; i++){
            b.pb(a[i-1]*1ll*inv[i]%K);
        }
        return b;
    }
    ///returns log(e)(f(x)) modulo K
    ///it uses this formula-> ln(f(x))=integration(d/dx(f(x))/f(x))
    vector<int> ln(vector<int> &a, int n){
        int mx=getmx((n+1)<<1);
        vector<int> u=derivative(a,n);
        u=ntt(u,mx);
        vector<int> d=inverse(a,n);
        d=ntt(d,mx);
        vector<int> b(mx);
        for(int i=0;i<=mx-1;i++) b[i]=u[i]*1ll*d[i]%K;
        b=trans(b,n);
        return integrate(b,n);
    }
    ///returns e^f(x) modulo K
    vector<int> exp(vector<int> &a, int n){
        if (!n){
            vector<int> b; b.pb(1); return b;
        }
        vector<int> b=exp(a,n>>1);
        n++;
        vector<int> l,t;
        int mx=getmx(n<<1);
        if (a.size()>=n) t=vector<int> (a.begin(),a.begin()+n);
        else t=a;
        t=ntt(t,mx);
        l=ln(b,n-1); l=ntt(l,mx);
        b=ntt(b,mx);
        for(int i=0;i<=mx-1;i++)
            b[i]=b[i]*1ll*(1ll-l[i]+t[i]+K)%K;
        n--;
        return trans(b,n);
    }
    ///returns sqrt(f(x)) modulo K
    vector<int> sqrt(vector<int>&a, int n){
        /// this only works with a[0]=0,1
        if (n==0){
            vector<int> b; b.pb(a[0]); return b;
        }
        int i2=inv[2];
        vector<int> b=sqrt(a,n>>1);
        n++;
        vector<int> ib,t;
        int mx=getmx(n<<1);
        if (a.size()>=n) t=vector<int> (a.begin(),a.begin()+n);
        else t=a;
        t=ntt(t,mx);
        ib=inverse(b,n-1);
        ib=ntt(ib,mx);
        b=ntt(b,mx);
        for(int i=0;i<=mx-1;i++)
            b[i]=(b[i]*1ll*b[i]+t[i])%K*1ll*i2%K*ib[i]%K;
        n--;
        return trans(b,n);
    }
    ///returns f(x)^n modulo K
    vector<int> pw(vector<int> &a, int n, int m){
        vector<int> res;
        if (n==0){
            res.pb(1);
            return res;
        }
        int A0=power(a[0],n);
        res=ln(a,m);
        for (int i=0; i<res.size(); i++) res[i]=res[i]*1ll* n%K;
        res=exp(res,m);
        for (int i=0; i<res.size(); i++) res[i]=res[i]*1ll*A0%K;
        return res;
    }
}
using namespace NTT;
vector<int> a,b;
int main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    initNTT();

    cin>>n>>m;
    a.resize(m+1);
    a[0]=1;
    for(i=1;i<=n;i++) {
        int x;
        cin>>x;
        if (x<=m) a[x]=K-4;
    }
    b=sqrt(a,m);
    if (b.size()==1) {
        for(i=1;i<=m;i++) cout<<0<<endl;
        return 0;
    }
    b[0]++;
    a=inverse(b,m);
    a.resize(m+1);
    for(i=1;i<=m;i++) cout<<a[i]*2ll%K<<endl;
    return 0;
}

