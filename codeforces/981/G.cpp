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
#define dist(x1,y1,x2,y2) sqrt(SQ(x1-x2)+SQ(y1-y2))
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=(n<<1)+1,mid=b+(e-b)/2
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

const ll mod=998244353;
const int mxn=2e5+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}
struct seg
{
    ll sz=0,mul=1,add=0;
};
seg t[mxn*4];
map<ll,ll>oc[mxn];
void propagate(ll n,ll l,ll r)
{
    if(t[n].add==0&&t[n].mul==1) return;

    t[n].sz=(t[n].sz*t[n].mul)%mod;
    t[n].sz=(t[n].sz+((r-l+1)*t[n].add)%mod)%mod;

    if(l!=r){
        t[2*n].mul=(t[2*n].mul*t[n].mul)%mod;
        t[2*n].add=(t[2*n].add*t[n].mul)%mod;
        t[2*n].add=(t[2*n].add+t[n].add)%mod;

        t[2*n+1].mul=(t[2*n+1].mul*t[n].mul)%mod;
        t[2*n+1].add=(t[2*n+1].add*t[n].mul)%mod;
        t[2*n+1].add=(t[2*n+1].add+t[n].add)%mod;
    }

    t[n].add=0;
    t[n].mul=1;
}
void sumupd(ll n,ll b,ll e,ll i,ll j)
{
    propagate(n,b,e);
    if(b>j||i>e) return;
    if(b>=i&&e<=j){
        t[n].add=(t[n].add+1)%mod;
        propagate(n,b,e);
        return;
    }
    stree;
    sumupd(l,b,mid,i,j);
    sumupd(r,mid+1,e,i,j);
    t[n].sz=(t[l].sz+t[r].sz)%mod;
}
void mulupd(ll n,ll b,ll e,ll i,ll j)
{
    propagate(n,b,e);
    if(b>j||i>e) return;
    if(b>=i&&e<=j){
        t[n].mul=(t[n].mul*2)%mod;
        t[n].add=(t[n].add*2)%mod;
        propagate(n,b,e);
        return;
    }
    stree;
    mulupd(l,b,mid,i,j);
    mulupd(r,mid+1,e,i,j);
    t[n].sz=(t[l].sz+t[r].sz)%mod;
}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    propagate(n,b,e);
    if(b>j||i>e) return 0;
    if(b>=i&&e<=j) return t[n].sz;
    stree;
    return (query(l,b,mid,i,j)+query(r,mid+1,e,i,j))%mod;
}
int main()
{
    fast;
    ll i,j,k,n,m,q,tt,l,r,x;
    cin>>n>>q;
    while(q--){
        cin>>tt;
        if(tt==1){
            cin>>l>>r>>x;
            vpll rmv;
            while(1){
                auto it=oc[x].LB(l);
                if(it==oc[x].end()) break;
                ll _l=it->S;
                ll _r=it->F;
                if(r<_l) break;
                rmv.eb(_l,_r);
                oc[x].erase(it);
            }
            if((ll)rmv.size()){
                ll sz=rmv.size();
                for(i=0;i<sz;i++){
                    mulupd(1,1,n,max(l,rmv[i].F),min(r,rmv[i].S));
                    if(i==0){
                        if(rmv[0].F>l){
                            sumupd(1,1,n,l,rmv[0].F-1);
                        }
                    }
                    else{
                        if(rmv[i].F-rmv[i-1].S>1){
                            sumupd(1,1,n,rmv[i-1].S+1,rmv[i].F-1);
                        }
                    }
                    if(i==sz-1){
                        if(rmv[i].S<r){
                            sumupd(1,1,n,rmv[i].S+1,r);
                        }
                    }
                }
                r=max(rmv.back().S,r);
                l=min(rmv.front().F,l);
                oc[x][r]=l;
            }
            else{
                sumupd(1,1,n,l,r);
                oc[x][r]=l;
            }
        }
        else{
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<nl;
        }
    }
    return 0;
}
