#include<bits/stdc++.h>

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
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
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

const int mod=1e9+7;
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

vi d1,d2;
void manachers(string &s)
{
    int n=s.size();
    d1=vector<int>(n);  ///maximum odd length palindrome centered at i
                        ///here d1[i]=the palindrome has d1[i]-1 right characters from i
                        ///e.g. for aba, d1[1]=2;
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    d2=vector<int>(n);  ///maximum even length palindrome centered at i
                        ///here d2[i]=the palindrome has d2[i]-1 right characters from i
                        ///e.g. for abba, d2[2]=2;
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
}
const int MAXN = (int)5100;
const int MAXV = (int)5100;///maximum value of any element in array

///array values can be negative too, use appropriate minimum and maximum value
struct wavelet_tree
{
	int lo, hi;
	wavelet_tree *l, *r;
	int *b,*c, bsz,csz;/// c holds the prefix sum of elements

	wavelet_tree() { lo = 1; hi = 0; bsz = 0; csz=0, l = NULL; r = NULL; }

	void init(int *from, int *to, int x, int y)
	{
		lo = x, hi = y;
		if(from >= to) return;
		int mid = (lo + hi) >> 1; auto f = [mid](int x) { return x <= mid; };
		b = (int*)malloc((to - from + 2) * sizeof(int)); bsz = 0; b[bsz++] = 0;
		c = (int*)malloc((to - from + 2) * sizeof(int)); csz = 0; c[csz++] = 0;
		for(auto it = from; it != to; it++){
            b[bsz] = (b[bsz - 1] + f(*it));
            c[csz] = (c[csz - 1] + (*it));
            bsz++;
            csz++;
        }
        if(hi==lo) return;
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree();
		l->init(from, pivot, lo, mid);
		r = new wavelet_tree();
		r->init(pivot, to, mid+1, hi);
	}
	///kth smallest element in [l, r]
	///for array [1,2,1,3,5] 2nd smallest is 1 and 3rd smallest is 2
	int kth(int l, int r, int k)
	{
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l - 1], lb = b[l - 1], rb = b[r];
		if(k <= inLeft) return this->l->kth(lb + 1, rb, k);
		return this->r->kth(l - lb, r - rb, k - inLeft);
	}
	///count of numbers in [l, r] Less than or equal to k
	int LTE(int l, int r, int k)
	{
		if(l > r || k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l - 1], rb = b[r];
		return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
	}
	///count of numbers in [l, r] equal to k
	int count(int l, int r, int k)
	{
		if(l > r || k < lo || k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l - 1], rb = b[r];
		int mid = (lo + hi) >> 1;
		if(k <= mid) return this->l->count(lb + 1, rb, k);
		return this->r->count(l - lb, r - rb, k);
	}
    ///sum of numbers in [l ,r] less than or equal to k
	int sum(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return c[r] - c[l-1];
		int lb = b[l-1], rb = b[r];
		return this->l->sum(lb+1, rb, k) + this->r->sum(l-lb, r-rb, k);
	}
	~wavelet_tree()
	{
		delete l;
		delete r;
	}
};
int get(int l,int r)
{
    return r*(r+1)/2-(l-1)*l/2;
}
wavelet_tree oddl,oddr;
int odd(int l,int r)
{
    int m=(l+r)/2;
    int c=1-l;
    int less_=oddl.LTE(l,m,c);
    int ansl=get(l,m)+oddl.sum(l,m,c)+(m-l+1-less_)*c;
    c=1+r;
    less_=oddr.LTE(m+1,r,c);
    int ansr=-get(m+1,r)+oddr.sum(m+1,r,c)+(r-m-less_)*c;
    return ansl+ansr;
}
wavelet_tree evenl,evenr;
int even(int l,int r)
{
    int m=(l+r)/2;
    int c=-l;
    int less_=evenl.LTE(l,m,c);
    int ansl=get(l,m)+evenl.sum(l,m,c)+(m-l+1-less_)*c;
    c=1+r;
    less_=evenr.LTE(m+1,r,c);
    int ansr=-get(m+1,r)+evenr.sum(m+1,r,c)+(r-m-less_)*c;
    return ansl+ansr;
}
int a[N],b[N],c[N],d[N];
int sc()
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
int main()
{
    //BeatMeScanf;
    int i,j,k,n,m,q,l,r;
    string s;
    cin>>s;
    n=s.size();
    manachers(s);
    for(i=1;i<=n;i++) a[i]=d1[i-1]-i;
    oddl.init(a+1,a+n+1,-MAXV,MAXV);
    for(i=1;i<=n;i++) b[i]=d1[i-1]+i;
    oddr.init(b+1,b+n+1,-MAXV,MAXV);
    for(i=1;i<=n;i++) c[i]=d2[i-1]-i;
    evenl.init(c+1,c+n+1,-MAXV,MAXV);
    for(i=1;i<=n;i++) d[i]=d2[i-1]+i;
    evenr.init(d+1,d+n+1,-MAXV,MAXV);

    q=sc();
    for(i=0;i<q;i++){
        l=sc();
        r=sc();
        out(odd(l,r)+even(l,r));
    }
    return 0;
}