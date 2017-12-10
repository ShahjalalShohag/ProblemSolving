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
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
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

#define fr(i,a,b) for(int i=a;i<b;i++)
#define rfr(i,a,b) for(int i=b-1;i>=a;i--)
#define eqfr(i,a,b) for(int i=a;i<=b;i++)
#define reqfr(i,a,b) for(int i=b;i>=a;i--)
#define printa(a,L,R) fr(i,L,R)cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define pb push_back
#define pf push_front
#define popb pop_front
#define popf pop_front
#define mp make_pair
#define F first
#define S second
#define fill(a,x) memset(a,x,sizeof(a))
#define fill2d(a,x,n,m) memset(a,x,n*m*sizeof(a[0][0]))
#define inf 0x3f3f3f3f
#define mod 1e9+7
#define mxn 100100
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))

#define all(v) v.begin(),v.end()
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
int ans;
int solve(int a,int b)
{
    int i;
    if(a==0||b==0) return ans;
    if(a/b<2){
        ans++;
        solve(b,a-b);
    }
    else{
        i=(a/b)-1;
        ans+=i;
        solve(a-i*b,b);
    }
}
int main()
{
    fast;
    int n,a,b,i,j;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(b>a) swap(a,b);
        ans=0;
        cout<<solve(a,b)<<nl;
    }
    return 0;
}

