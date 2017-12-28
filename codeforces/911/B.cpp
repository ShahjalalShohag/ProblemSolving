#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsigned long long
#define ld       long double
#define pii      pair<int,int>
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
#define sepii    set<pair<int,int>>
#define di       deque<int>
#define li       list<int>
#define sti      stack<int>
#define qi       queue<int>
#define pqi      priority_queue<int>
#define mii      map<int,int>
#define mll      map<ll,ll>
#define umii     unordered_map<int,int>
#define vit      vector<int>::iterator
#define mit      map<int,int>::iterator
#define sit      set<int>:: iterator
#define uset     unordered_set
#define PQ       priority_queue

#define rep(i,n)        for(i=0;i<n;i++)
#define printa(a,L,R)   for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a)       printa(a,0,a.size())
#define print2d(a,r,c)  for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(i==j-1?'\n':' ')
#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second
#define mem(a,x)        memset(a,x,sizeof(a))
#define fill2d(a,x,n,m) memset(a,x,n*m*sizeof(a[0][0]))
#define inf             0x3f3f3f3f
#define mod             1000000007
#define mxn             100100
#define PI              3.14159265358979323846
#define E               2.71828182845904523536
#define gamma           0.5772156649
#define nl              "\n"
#define lg(r,n)         (int)(log2(n)/log2(r))
#define sint(a)         sin((PI*a)/180.0)
#define cost(a)         cos((PI*a)/180.0)
#define tant(a)         tan((PI*a)/180.0)
#define asint(a)        (asin(a)*180.0)/PI
#define acost(a)        (acos(a)*180.0)/PI
#define atant(a)        (atan(a)*180.0)/PI
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

#define rev(v)              reverse(v.begin(),v.end())
#define srt(v)              sort(v.begin(),v.end())
#define grtsrt(v)           sort(v.begin(),v.end(),greater<int>())
#define all(v)              v.begin(),v.end()
#define mnv(v)              *min_element(v.begin(),v.end())
#define mxv(v)              *max_element(v.begin(),v.end())
#define countv(v,a)         cout(v.begin(),v.end(),a)
#define len(s)              s.length()
#define strtoint(a)         atoi(a.c_str())
string  inttostr(int n)     {stringstream rr;rr<<n;return rr.str();}
#define fast                ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int main()
{
    fast;
    int i,j,k,n,a,b,ans=-inf;
    cin>>n>>a>>b;
    for(i=1;i<n;i++){
        k=min(a/i,b/(n-i));
        ans=max(ans,k);
    }
    cout<<ans<<nl;
    return 0;
}

