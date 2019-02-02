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

const int mod=998244353-1;
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


struct matrix
{
	int n;
	vector<vector<int> > t;

	matrix() { }
	matrix(int _n, int val) {n = _n; t.assign(n, vector<int>(n, val)); }
	matrix(int _n) {n = _n; t.assign(n, vector<int>(n, 0)); }
	matrix(vector<vi> v){n=v.size();t=v;}
	matrix unit(int _n)
	{
	    matrix ans=matrix(_n,0);
	    for(int i=0;i<_n;i++) ans.t[i][i]=1;
	    return ans;
	}
	///make sure to erase mod if not needed
	matrix operator * (matrix b)
	{
		matrix c = matrix(n, 0);
		for(int i = 0; i < n; i++)
			for(int k = 0; k < n; k++)
				for(int j = 0; j < n; j++)
					c.t[i][j] = (c.t[i][j] + 1LL*t[i][k] * b.t[k][j]%mod) % mod;
		return c;
	}
	matrix operator | (matrix b)
	{
		matrix c = matrix(n, -inf);
		for(int i = 0; i < n; i++)
			for(int k = 0; k < n; k++)
				for(int j = 0; j < n; j++)
					c.t[i][j] = max(c.t[i][j], t[i][k] + b.t[k][j]);
		return c;
	}
	matrix pow(ll k)
	{
        if(k==0) return unit(n);
        k--;
        matrix a=*this,ans=a;
        while(k){
            if(k&1) ans=ans*a;
            a=a*a;
            k>>=1;
        }
        return ans;
	}
	matrix pow_max(ll k)
	{
        if(k==0) return unit(n);
        k--;
        matrix a=*this,ans=a;
        while(k){
            if(k&1) ans=ans|a;
            a=a|a;
            k>>=1;
        }
        return ans;
	}
	matrix operator + (matrix a)
	{
        matrix ans=matrix(n,n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            ans.t[i][j]=t[i][j]+a.t[i][j];
        return ans;
	}

	matrix operator - (matrix a)
	{
        matrix ans=matrix(n,n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            ans.t[i][j]=t[i][j]-a.t[i][j];
        return ans;
	}
    bool operator == (const matrix& a)
	{
	    return t==a.t;
	}
    bool operator != (const matrix& a)
	{
	    return t!=a.t;
	}
	void print()
	{
	    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cout<<t[i][j]<<" \n"[j==n-1];
	}
};

struct DiscreteLogarithm
{
    int powmod(int a, int b, int m)
    {
        int res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (1LL*res * a) % m;
            }
            a = (1LL*a * a) % m;
            b >>= 1;
        }
        return res;
    }

    ///returns the primitive root modulo p
    ///g  is a primitive root modulo p if and only if for any integer a such that
    ///gcd(a,p)=1, there exists an integer k such that: g^k = a(mod p).
    ///this code assumes p is prime
    int PrimitiveRoot(int p)
    {
        vector<int> fact;
        int phi = p-1,  n = phi;///Beware!!! if p is not prime calculate the value of phi
        for (int i=2; i*i<=n; ++i)
            if (n % i == 0) {
                fact.push_back (i);
                while (n % i == 0)
                    n /= i;
            }
        if (n > 1) fact.push_back (n);
        for (int res=2; res<=p; ++res) {
            bool ok = true;
            for (size_t i=0; i<fact.size() && ok; ++i)
                ok &= powmod (res, phi / fact[i], p) != 1;
            if (ok)  return res;
        }
        return -1;
    }
    /// baby step - giant step
    ///find any integer x such that a^x = b (mod m)
    ///where a and m are co-prime
    int DiscreteLog(int a, int b, int m)
    {
        int n = (int) sqrt (m + .0) + 1;
        int an = 1;
        for (int i = 0; i < n; ++i) an = (1LL*an * a) % m;
        map<int, int> vals;
        for (int p = 1, cur = an; p <= n; ++p) {
            if (!vals.count(cur)) vals[cur] = p;
            cur = (1LL*cur * an) % m;
        }
        for (int q = 0, cur = b; q <= n; ++q) {
            if (vals.count(cur)) {
                int ans = vals[cur] * n - q;
                return ans;
            }
            cur = (1LL*cur * a) % m;
        }
        return -1;
    }

    ///This program finds all numbers x such that x^k = a (mod n)
    int DiscreteRoot(int k, int a, int n) {
        if (a == 0) return 1;
        int g = PrimitiveRoot(n);
        int phi=n-1;///Beware!!! if n is not a prime calculate the value of phi
        ///run baby step-giant step
        int sq = (int) sqrt (n + .0) + 1;
        vector < pair<int,int> > dec (sq);
        for (int i=1; i<=sq; ++i) dec[i-1] = make_pair (powmod (g, 1LL*i * sq %phi * k % phi, n), i);
        sort (dec.begin(), dec.end());
        int any_ans = -1;
        for (int i=0; i<sq; ++i) {
            int my = powmod (g, 1LL* i * k % phi, n) * 1LL * a % n;
            auto  it =lower_bound (dec.begin(), dec.end(), make_pair (my, 0));
            if (it != dec.end() && it->first == my) {
                any_ans = it->second * sq - i;
                break;
            }
        }
        if(any_ans==-1) return -1;///no solution
        ///for any answer
        int delta = (n-1) / __gcd (k, n-1);
        for (int cur=any_ans%delta; cur<n-1; cur+=delta) return (powmod (g, cur, n));

        ///for all possible answers
        ///int delta = (n-1) / __gcd(k, n-1);
        ///vector<int> ans;
        ///for (int cur = any_ans % delta; cur < n-1; cur += delta) ans.push_back(powmod(g, cur, n));
        ///sort(ans.begin(), ans.end());
        ///return ans;
    }
}d;

int p[N];
int main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    cin>>k;
    for(i=0;i<k;i++) cin>>p[i];
    cin>>n>>m;
    matrix a(k);
    for(i=0;i<k;i++) a.t[0][i]=p[i];
    for(i=1;i<k;i++) a.t[i][i-1]=1;
    matrix ans=a.pow(n-k);
    int res=ans.t[0][0];
    int s=d.DiscreteRoot(res,m,mod+1);
    cout<<s<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
