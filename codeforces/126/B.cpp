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
const int mxn=1e6+9;
const ld eps=1e-9;
ll qpow(ll n,ll k)          {ll ans=1;while(k){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans;}
ll hs[mxn],pw[mxn],pr=31,len;
string s;
vll v;
bool can(ll n)
{
    ll i,j,k,curhs;
    for(i=n;i<len-1;i++){
        curhs=hs[i]-hs[i-n];
        if(curhs==hs[n-1]*pw[i-n+1]) return 1;
    }
    return 0;
}
int main()
{
    fast;
    ll i,j,k,n,m,mid,l,r,revhs;
    pw[0]=1;
    for(i=1;i<mxn;i++) pw[i]=pw[i-1]*pr;
    cin>>s;
    len=s.size();
    for(i=0;i<len;i++) i?hs[i]=hs[i-1]+(s[i]-'a'+1)*pw[i]:hs[i]=s[i]-'a'+1;
    for(i=0;i<len-1;i++){
        revhs=hs[len-1]-hs[len-1-i-1];
        if(hs[i]*pw[len-1-i]==revhs) v.pb(i+1);
    }
    if(v.size()==0) return cout<<"Just a legend\n",0;

    srt(v);
    l=0,r=v.size()-1;
    if(can(v[l])==0) return cout<<"Just a legend\n",0;
    if(can(v[r])==1){
        for(i=0;i<v[r];i++) cout<<s[i];
        return 0;
    }
    while(1){
        mid=(r+l)>>1;
        if(mid==l){
            for(i=0;i<v[mid];i++)  cout<<s[i];
            return 0;
        }
        if(can(v[mid])) l=mid;
        else r=mid;
    }
    return 0;
}

