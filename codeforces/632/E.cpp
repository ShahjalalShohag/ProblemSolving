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
#define inf 0x3f3f3f3f
#define PI (acos(-1.0))
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int mxn=1100;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

#define base complex<double> //to store complex numbers

//inv=0 means Converting from coefficient form to point value form
//inv=1 means Converting from point value  form to coefficient form i.e. inverse fft
void fft(vector<base> &a,bool inv)
{
    int n=(int)a.size();
    //rearranging the elements to the leaf nodes of the tree
    for(int i=1,j=0;i<n;i++){
        int bit=n>>1;
        for(;j>=bit;bit>>=1) j-=bit;
        j+=bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len*=2){
        ld ang=2*PI/len*(inv?-1:1);
        base wlen(cos(ang),sin(ang));
        //wlen=e^(2*PI*i/n)=cos(2*PI/n)+i*sin(2*PI/n)
        //bcz e^(i*theta)=cos(theta)+i*sin(theta)
        for(int i=0;i<n;i+=len){
            base w=1;
            for(int j=0;j<len/2;j++){
                base even=a[i+j],odd=a[i+j+len/2];
                a[i+j]=even+w*odd;
                a[i+j+len/2]=even-w*odd;
                w*=wlen;
            }
        }
    }
    if(inv) for(int i=0;i<n;i++) a[i]/=n;
}
void multiply(vi& a,vi& b,vi& res)
{
    vector<base>fa(all(a)),fb(all(b));
    int n=1;
    int mx=max((ll)a.size(),(ll)b.size());
    while(n<mx) n*=2;//making it power of 2
    n*=2;//making 2*n size
    fa.resize(n);
    fb.resize(n);
    //convolution
    fft(fa,0);
    fft(fb,0);
    for(int i=0;i<n;i++) fa[i]*=fb[i];
    fft(fa,1);//inverse fft
    res.resize(n);
    for(int i=0;i<n;i++) res[i]=int(fa[i].real()+0.5);
    for(int i=0;i<n;i++) if(res[i]>1) res[i]=1;
    while(res.size()>1&&res.back()==0) res.pop_back();
    return;
}
void getpow(vi &v,int k,vi &res)
{
    res.pb(1);
    while(k>0){
        if(k&1) multiply(res,v,res);
        multiply(v,v,v);
        k>>=1;
    }
}
int main()
{
    fast;
    ll i,j,k,n,m;
    cin>>n>>k;
    vi v(mxn,0);
    for(i=0;i<n;i++) cin>>m,v[m]=1;
    vi res;
    getpow(v,k,res);
    for(i=0;i<(int)res.size();i++) if(res[i]) cout<<i<<' ';
    return 0;
}

