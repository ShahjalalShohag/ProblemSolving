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
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define sz(v) (int)v.size()
#define BeatMeScanf ios_base::sync_with_stdio(false)

int mod=1e9+7;
const int N=300,M=4e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

struct BIT {
    ll dataMul[M],dataAdd[M];
    void internalUpdate(int at, long long mul, long long add) {
        while (at < M) {
            dataMul[at] += mul;
            dataAdd[at] += add;
            at |= (at + 1);
        }
    }
    void update(int left, int right, long long by) {
        internalUpdate(left, by, -by * (left - 1));
        internalUpdate(right, -by, by * right);
    }
    long long query(int at) {
        long long mul = 0;
        long long add = 0;
        int start = at;
        while (at >= 0) {
            mul += dataMul[at];
            add += dataAdd[at];
            at = (at & (at + 1)) - 1;
        }
        return (mul * start + add);
    }
    ll query(int l,int r)
    {
        return query(r)-query(l-1);
    }
    void clear()
    {
        mem(dataMul,0);
        mem(dataAdd,0);
    }
}t;

int spf[N];///smallest prime factor
vi prime;
void linear_sieve()
{
    for(int i=2;i<N;i++){
        if(spf[i]==0) spf[i]=i,prime.eb(i);
        int sz=prime.size();
        for(int j=0;j<sz&&i*prime[j]<N&&prime[j]<=spf[i];j++) spf[i*prime[j]]=prime[j];
    }
}
int l[M],r[M],x[M],a[M];
ll ans[M];
int32_t main()
{
    BeatMeScanf;
    cin.tie(0);
    int i,j,k,n,m,q,p;
    linear_sieve();
    cin>>n>>q;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=q;i++){
        string s;
        cin>>s>>l[i]>>r[i];
        if(s[0]=='M') cin>>x[i];
    }
    for(i=1;i<=q;i++) ans[i]=1;
    for(auto p:prime){
        t.clear();
        int in=qpow(p,mod-2);
        in=(1LL-in+mod)%mod;
        for(i=1;i<=n;i++){
            int cnt=0;
            int k=a[i];
            while(k%p==0) k/=p,cnt++;
            t.update(i,i,cnt);
        }
        for(i=1;i<=q;i++){
            if(x[i]>0){
                int cnt=0;
                int k=x[i];
                while(k%p==0) k/=p,cnt++;
                t.update(l[i],r[i],cnt);
            }
            else{
                ll nw=t.query(l[i],r[i]);
                if(!nw) continue;
                nw%=(mod-1);
                ans[i]*=qpow(p,nw);
                ans[i]%=mod;
                ans[i]*=in;
                ans[i]%=mod;
            }
        }
    }
    for(i=1;i<=q;i++) if(x[i]==0) cout<<(ans[i]+mod)%mod<<nl;
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

