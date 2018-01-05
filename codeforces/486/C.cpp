#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define vpii vector<pair<int,int>>
#define si set<int>
#define usi unordered_set<int>
#define ss set<string>
#define spii set<pair<int,int>>
#define di deque<int>
#define li list<int>
#define sti stack<int>
#define qi queue<int>
#define pq priority_queue<int>
#define mii map<int,int>
#define mll map<ll,ll>
#define umii unordered_map<int,int>
#define vit vector<int>::iterator
#define mit map<int,int>::iterator
#define sit set<int>:: iterator

#define fr(i,a,b) for(int i=a;i<b;i++)
#define rfr(i,a,b) for(int i=b-1;i>=a;i--)
#define eqfr(i,a,b) for(int i=a;i<=b;i++)
#define reqfr(i,a,b) for(int i=b;i>=a;i--)
#define printa(a,L,R) fr(i,L,R)cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fill(a,x) memset(a,x,sizeof(a))
#define fill2d(a,x,n,m) memset(a,x,n*m*sizeof(a[0][0]))
#define inf 0x3f3f3f3f
#define mod 1e9+7
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) cout(v.begin(),v.end(),a)
#define strtoint(a) atoi(a.c_str())
string inttostr(int n){stringstream rr;rr<<n;return rr.str();}

#define fast ios_base::sync_with_stdio(false)

int main()
{
    fast;
    int n,i,j,p,left,right,ans=0,d;
    string s;
    cin>>n>>p>>s;
    p--;
    n--;
    if(p>n/2) p=n-p;
    left=-1;
    for(i=0;i<=n/2;i++){
        if(s[i]!=s[n-i]){
            d=abs(s[i]-s[n-i]);
            d=min(d,26-d);
            ans+=d;
            if(left==-1) left=i;
            right=i;
        }
    }
    if(ans==0){
        cout<<0<<nl;
        return 0;
    }
    if(p<=left) ans+=right-p;
    else if(p>left&&p<right){
        if(p-left<=right-p) ans+=p-left+right-left;
        else ans+=right-p+right-left;
    }
    else if(p>=right) ans+=p-left;
    cout<<ans<<nl;
    return 0;
}
