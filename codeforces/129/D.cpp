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
#define fast ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
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
const int mxn=1e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

//number of states or nodes  in a suffix automaton is equal to the
// number of equivalence classes i.e. endpos-equivalent classes among all substrings
struct node
{
    int len;            //largest string length of the corresponding endpos-equivalent class
    int link;           //leads to the state that corresponds to the longest suffix of w
                        //that is another endpos-equivalent class.
    int firstpos;       //1-indexed end position of the first occurrence of the largest string length of the
                        //corresponding endpos-equivalent class
    map<char,int>nxt;
};
//all suffix links of the last node are terminal nodes including the last node
const int MX=mxn*2;
node t[MX];
int sz,last;
void init()
{
    sz=last=0;
    t[0].len=0;
    t[0].firstpos=0;
    t[0].link=-1;
    sz++;
}
ll cnt[MX];
vpii v;
set<pii>nodes;
void add_letter(char ch)
{
    int cur=sz++;
    t[cur].len=t[last].len+1;
    t[cur].firstpos=t[cur].len;
    cnt[cur]=1;
    nodes.insert({t[cur].len,cur});
    int p;
    for(p=last;p!=-1&&!t[p].nxt.count(ch);p=t[p].link) t[p].nxt[ch]=cur;
    if(p==-1) t[cur].link=0;
    else{
        int q=t[p].nxt[ch];
        if(t[p].len+1==t[q].len) t[cur].link=q;
        else{
            int clone=sz++;
            t[clone].len=t[p].len+1;
            t[clone].nxt=t[q].nxt;
            t[clone].link=t[q].link;
            t[clone].firstpos=t[q].firstpos;
            cnt[clone]=0;
            nodes.insert({t[clone].len,clone});
            for(;p!=-1&&t[p].nxt[ch]==q;p=t[p].link) t[p].nxt[ch]=clone;
            t[q].link=t[cur].link=clone;
        }
    }
    last=cur;
}
ll dcnt[MX];            //number of distinct substrings in the subtree of node i
ll dist_sub(int u)      //number of distinct substrings of the string
{
    ll ans=1;
    if(dcnt[u]) return dcnt[u];
    for(auto x:t[u].nxt){
        char ch=x.F;
        ans+=1LL*dist_sub(t[u].nxt[ch]);
    }
    return dcnt[u]=ans;
}
string ans;
ll k;
void kth(int i)
{
    if(k<=0) return;
    for(auto x:t[i].nxt){
        k-=cnt[x.S];
        kth(x.S);
        if(k<=0){
            ans.pb(x.F);
            return;
        }
    }
}
int main()
{
    fast;
    int i,j,n,m,q;
    string s;
    cin>>s>>k;
    n=s.size();
    init();
    for(i=0;i<n;i++) add_letter(s[i]);
    for(auto it=nodes.rbegin();it!=nodes.rend();++it) cnt[t[(*it).S].link]+=cnt[(*it).S];
    if(1LL*n*(1LL*n+1)/2<k) cout<<"No such line.\n";
    else{
        ans="";
        kth(0);
        rev(ans);
        cout<<ans<<nl;
    }
    return 0;
}
