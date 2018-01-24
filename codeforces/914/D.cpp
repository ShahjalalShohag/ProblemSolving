#include<bits/stdc++.h>
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
#define pip      pair< int,pii >
#define ppi      pair< pii,int >
#define sei      set<int>
#define usei     unordered_set<int>
#define ses      set<string>
#define sepii    set< pair<int,int> >
#define di       deque<int>
#define li       list<int>
#define sti      stack<int>
#define qi       queue<int>
#define pqi      priority_queue<int>
#define mpii      map<int,int>
#define mpll      map<ll,ll>
#define umii     unordered_map<int,int>
#define vit      vector<int>::iterator
#define mit      map<int,int>::iterator
#define sit      set<int>:: iterator
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
#define SQ(x)           ((x)*(x))
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
#define fast                ios_base::sync_with_stdio(false),cin.tie(NULL)
string  tostr(int n)        {stringstream rr;rr<<n;return rr.str();}
const int mod=1e9+7;
const int mxn=5e5+9;
const ld eps=1e-9;
ll qpow(ll n,ll k)          {ll ans=1;while(k){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}
ll ans,tree[mxn*4];
void update(ll node,ll b,ll e,ll i,ll val)
{
    if(i<b||i>e) return;
    if(b==e){
        tree[node]=val;
        return;
    }
    ll left=node*2,right=2*node+1,mid=(b+e)/2;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    tree[node]=__gcd(tree[left],tree[right]);
}
void query(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(j<b||i>e) return;
    ll mid=(b+e)/2;
    if(b>=i&&e<=j){
        if(b==e){
            ans+=!(tree[node]%x==0);
            return;
        }
        if(tree[node]%x==0) return;
        if(tree[2*node]%x!=0&&tree[2*node+1]%x!=0){
            ans+=2;
            return;
        }
        if(tree[2*node]%x!=0) query(2*node,b,mid,i,j,x);
        if(tree[2*node+1]%x!=0) query(2*node+1,mid+1,e,i,j,x);
        return;
    }
    if(ans<=1) query(2*node,b,mid,i,j,x);
    if(ans<=1) query(2*node+1,mid+1,e,i,j,x);
}
int main()
{
    fast;
    ll i,j,k,n,m,x,q,l,r,t;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        update(1,1,n,i,x);
    }
    cin>>q;
    while(q--){
        cin>>t;
        if(t==1){
            cin>>l>>r>>x;
            ans=0;
            query(1,1,n,l,r,x);
            ans<=1?cout<<"YES\n":cout<<"NO\n";
        }
        else{
            cin>>i>>x;
            update(1,1,n,i,x);
        }
    }
    return 0;
}
