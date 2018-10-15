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
const int N=1e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

struct node
{
    node *left,*right;
    int val,suf,pref,mx;
    node(){left=NULL,right=NULL,val=suf=pref=mx=0;}
}*root[N];
struct st
{
    int val,suf,pref,mx;
    st(){val=suf=pref=mx=0;}
    st(int a,int b,int c,int d){val=a,suf=b,pref=c,mx=d;}
};
void build(node* cur,int b,int e)
{
    if(b==e){
        cur->val=0;
        return ;
    }
    int mid=(b+e)/2;
    cur->left=new node();
    cur->right=new node();
    build(cur->left,b,mid);
    build(cur->right,mid+1,e);
}
void upd(node* pre,node*  cur,int b,int e,int i,int v)
{
    if(i<b||i>e) return;
    if(b==e){
        cur->val=v;
        cur->mx=v;
        cur->pref=v;
        cur->suf=v;
        return;
    }
    int mid=(b+e)/2;
    if(i<=mid){
        cur->right=pre->right;
        cur->left=new node();
        upd(pre->left,cur->left,b,mid,i,v);
    }
    else{
        cur->left=pre->left;
        cur->right=new node();
        upd(pre->right,cur->right,mid+1,e,i,v);
    }
    cur->val=cur->left->val+cur->right->val;
    cur->mx=max({cur->left->mx,cur->right->mx,cur->left->suf+cur->right->pref});
    cur->pref=cur->left->pref;
    if(mid-b+1==cur->left->pref) cur->pref+=cur->right->pref;
    cur->suf=cur->right->suf;
    if(e-mid==cur->right->suf) cur->suf+=cur->left->suf;
}
st query(node* cur,int b,int e,int i,int j)
{
    if(b>j||e<i){
        return st();
    }
    if(b>=i&&e<=j) return st(cur->val,cur->suf,cur->pref,cur->mx);
    int mid=(b+e)/2;
    st l=query(cur->left,b,mid,i,j);
    st r=query(cur->right,mid+1,e,i,j);
    st ret=st();
    ret.val=l.val+r.val;
    ret.mx=max({l.mx,r.mx,l.suf+r.pref});
    ret.pref=l.pref;
    if(mid-b+1==l.pref) ret.pref+=r.pref;
    ret.suf=r.suf;
    if(e-mid==r.suf) ret.suf+=l.suf;
    return ret;
}
pii a[N];
int main()
{
    BeatMeScanf;
    int i,j,k,n,m,q,t,x,l,r,w;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i].F;
        a[i].S=i;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    root[0]=new node();
    build(root[0],1,n);
    for(i=1;i<=n;i++){
        root[i]=new node();
        upd(root[i-1],root[i],1,n,a[i].S,1);
    }
    cin>>q;
    while(q--){
        cin>>l>>r>>w;
        int le=1,ri=n;
        int ans=1;
        while(le<=ri){
            int mid=(le+ri)/2;
            if(query(root[mid],1,n,l,r).mx>=w) ans=mid,ri=mid-1;
            else le=mid+1;
        }
        cout<<a[ans].F<<nl;
    }
    return 0;
}

