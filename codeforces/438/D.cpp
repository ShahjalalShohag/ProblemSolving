#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll       long long
#define ull      unsigned long long
#define ld       long double
#define pii      pair<int,int>
#define pll      pair<ll,ll>
#define vi       vector<int>
#define vll      vector<ll>
#define vc       vector<char>
#define vs       vector<string>
#define vpii     vector< pair<int,int> >
#define vpll     vector< pair<ll,ll> >
#define ppll     pair< ll,pll >
#define pllp     pair< pll,ll >
#define stll     stack<ll>
#define qll      queue<ll>
#define pqll     priority_queue<ll>
#define mppll    map<pll,ll>
#define mpii     map<int,int>
#define mpll     map<ll,ll>
#define mpss     map<string,string>
#define mpsll    map<string,ll>
#define mplls    map<ll,string>
#define umpii    unordered_map<int,int>
#define umll     unordered_map<ll,ll>
#define umpss    unordered_map<string,string>
#define umpsll   unordered_map<string,ll>
#define umplls   unordered_map<ll,string>
#define umap     unordered_map
#define uset     unordered_set
#define PQ       priority_queue

#define rep(i,n)        for(i=0;i<n;i++)
#define itfor(i, c)     for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define printa(a,L,R)   for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a)       printa(a,0,a.size())
#define print2d(a,r,c)  for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
#define pb              push_back
#define MP              make_pair
#define UB              upper_bound
#define LB              lower_bound
#define SQ(x)           ((x)*(x))
#define issq(x)         (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F               first
#define S               second
#define mem(a,x)        memset(a,x,sizeof(a))
#define inf             0x3f3f3f3f
#define PI              3.14159265358979323846
#define E               2.71828182845904523536
#define gamma           0.5772156649
#define nl              "\n"
#define lg(r,n)         (int)(log2(n)/log2(r))
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sfc(a)          scanf("%c",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define pf              printf
#define pfi(a)          pf("%d\n",&a)
#define pfl(a)          pf("%lld\n",&a)
#define _ccase          printf("Case %d: ",++cs)
#define _case           cout<<"Case "<<++cs<<": "
#define debug(x)        cout<<#x"="<<(x)<<nl

#define rev(v)              reverse(v.begin(),v.end())
#define srt(v)              sort(v.begin(),v.end())
#define grtsrt(v)           sort(v.begin(),v.end(),greater<int>())
#define all(v)              v.begin(),v.end()
#define mnv(v)              *min_element(v.begin(),v.end())
#define mxv(v)              *max_element(v.begin(),v.end())
#define countv(v,a)         count(v.begin(),v.end(),a)
#define toint(a)            atoi(a.c_str())
#define fast                ios_base::sync_with_stdio(false)
string  tostr(int n)        {stringstream rr;rr<<n;return rr.str();}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod=1e9+7;
const int N=1e5+9;
const ld eps=1e-9;
//ll qpow(ll n,ll k)          {ll ans=1;while(k){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}
struct st
{
    int mx;
    ll sum;
}t[4*N];
int a[N];
void build(int n,int b,int e)
{
    if(b==e){
        t[n].mx=a[b];
        t[n].sum=a[b];
        return;
    }
    int mid=(b+e)>>1,l=2*n,r=l+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n].mx=max(t[l].mx,t[r].mx);
    t[n].sum=t[l].sum+t[r].sum;
}
void upd(int n,int b,int e,int i,int val)
{
    if(b>i||e<i) return ;
    if(b>=i&&e<=i){
        t[n].mx=val;
        t[n].sum=val;
        return;
    }
    int mid=(b+e)>>1,l=2*n,r=l+1;
    upd(l,b,mid,i,val);
    upd(r,mid+1,e,i,val);
    t[n].mx=max(t[l].mx,t[r].mx);
    t[n].sum=t[l].sum+t[r].sum;
}
void updmod(int n,int b,int e,int i,int j,int x)
{
    if(b>j||e<i) return;
    if(b>=i&&e<=j&&b==e){
        t[n].mx=t[n].mx%x;
        t[n].sum=t[n].sum%x;
        return;
    }
    int mid=(b+e)>>1,l=2*n,r=l+1;
    if(t[l].mx>=x) updmod(l,b,mid,i,j,x);
    if(t[r].mx>=x) updmod(r,mid+1,e,i,j,x);
    t[n].mx=max(t[l].mx,t[r].mx);
    t[n].sum=t[l].sum+t[r].sum;
}
ll query(int n,int b,int e,int i,int j)
{
    if(b>j||e<i) return 0;
    if(b>=i&&e<=j) return t[n].sum;
    int mid=(b+e)>>1,l=2*n,r=l+1;
    return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);
}
int main()
{
    fast;
    int i,j,k,n,m,l,r,x,ty;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        cin>>ty>>l>>r;
        if(ty==1) cout<<query(1,1,n,l,r)<<nl;
        else if(ty==2){
            cin>>x;
            updmod(1,1,n,l,r,x);
        }
        else upd(1,1,n,l,r);
    }
    return 0;
}
