#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector< pair<int,int> >
#define vpll vector< pair<ll,ll> >
#define pip pair< int,pii >
#define ppi pair< pii,int >
#define sei set<int>
#define usei unordered_set<int>
#define ses set<string>
#define sepii set<pair<int,int>>
#define di deque<int>
#define li list<int>
#define sti stack<int>
#define qi queue<int>
#define pqi priority_queue<int>
#define mii map<int,int>
#define mll map<ll,ll>
#define umii unordered_map<int,int>
#define vit vector<int>::iterator
#define mit map<int,int>::iterator
#define sit set<int>:: iterator

#define fr(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define rfr(i,a,b) for(i=b-1;i>=a;i--)
#define eqfr(i,a,b) for( i=a;i<=b;i++)
#define reqfr(i,a,b) for(i=b;i>=a;i--)
#define printa(a,L,R) fr(i,L,R)cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define pb push_back
#define pf push_front
#define popb pop_front
#define popf pop_front
#define mp make_pair
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define fill2d(a,x,n,m) memset(a,x,n*m*sizeof(a[0][0]))
#define inf 0x3f3f3f3f
#define mod 1000000007
#define mxn 100100
#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define _ccase      printf("Case %d: ",++cs)
#define _case      cout<<"Case "<<++cs<<": "
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) cout(v.begin(),v.end(),a)
#define len(s) s.length()
#define strtoint(a) atoi(a.c_str())
string inttostr(int n){stringstream rr;rr<<n;return rr.str();}

#define fast ios_base::sync_with_stdio(false)
ll presum(ll n,ll m)
{
    //sum of (n/i)*i from i=1 to n;
    ll ans,sum,high,low,sq,t2,t1,u,v,cnt,i;
    sq=sqrt(n);
    ans=0;
    for(i=1;i<=sq;i++){
        if(i>m) return ans;
        ans=(ans+(n/i)*i)%mod;
    }
    for(i=n/sq-1;i>=1;i--){
        low=n/(i+1);
        high=n/i;
        if(high>=m){
            u=m%mod;
            v=(m+1)%mod;
            t2=((u*v)/2)%mod;
            u=low%mod;
            v=(low+1)%mod;
            t1=((u*v)/2)%mod;
            sum=(t2-t1+mod)%mod;
            ans=(ans+(sum*i)%mod)%mod;
            return ans;
        }
        u=high%mod;
        v=(high+1)%mod;
        t2=((u*v)/2)%mod;
        u=low%mod;
        v=(low+1)%mod;
        t1=((u*v)/2)%mod;
        sum=(t2-t1+mod)%mod;
        ans=(ans+(sum*i)%mod)%mod;
    }
    return ans;
}
int main()
{
    ll n,i,j,t,m,ans,k1,k2,cs=0;
        cin>>n>>m;
        ans=presum(n,min(n,m));
        k1=m%mod;
        k2=n%mod;
        ans=(k1*k2-ans+mod)%mod;
        cout<<ans<<nl;
    return 0;
}



