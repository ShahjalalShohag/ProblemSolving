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
#define len(s)              s.length()
#define toint(a)            atoi(a.c_str())
#define fast                ios_base::sync_with_stdio(false),cin.tie(NULL)
string  tostr(int n)        {stringstream rr;rr<<n;return rr.str();}
ll qpow(ll n,ll k)          {ll ans=1;while(k){if(k&1) ans=ans*n;n=n*n;k>>=1;}return ans;}
const int mod=1e9+7;
const int mxn=1e5+9;
const int eps=1e-9;
struct sj
{
    string str;
    int g,t,p;
};
vector<sj>v;
void prnt(vs a)
{
    int i;
    for( i=0;i<a.size()-1;i++){
        cout<<a[i]<<", ";
    }
    cout<<a[i]<<'.'<<nl;
}
int main()
{
    fast;
    int i,j,k,q,mxt,mxp,mxg,taxi,pizza,girl,a,b,c,n;
    vs anst,ansp,ansg;
    char ch;
    string s;
    cin>>n;
    mxt=mxp=mxg=-inf;
    for(i=0;i<n;i++){
        cin>>q>>s;
        taxi=pizza=girl=0;
        while(q--){
            cin>>a>>ch>>b>>ch>>c;
            if(a==b&&b==c&&a%10==a/10) taxi++;
            else if(a/10>a%10&&a%10>b/10&&b/10>b%10&&b%10>c/10&&c/10>c%10) pizza++;
            else girl++;
        }
        mxt=max(mxt,taxi),mxp=max(mxp,pizza),mxg=max(mxg,girl);
        sj tmp;
        tmp.str=s,tmp.g=girl,tmp.t=taxi,tmp.p=pizza;
        v.pb(tmp);
    }
    for(auto x:v){
        if(x.t==mxt) anst.pb(x.str);
        if(x.p==mxp) ansp.pb(x.str);
        if(x.g==mxg) ansg.pb(x.str);
    }
    cout<<"If you want to call a taxi, you should call: ";prnt(anst);
    cout<<"If you want to order a pizza, you should call: ";prnt(ansp);
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";prnt(ansg);
    return 0;
}

