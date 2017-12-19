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

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) cout(v.begin(),v.end(),a)

#define fast ios_base::sync_with_stdio(false)
int res[100100];
int main()
{
    fast;
    int n,i,j,p,q,x,a,b;
    mii ind;
    si f,s;
    sit it;
    vi c;
    cin>>n>>a>>b;
    for(i=0;i<n;i++){
        cin>>x;
        f.insert(x);
        ind[x]=i;
    }
    for(it=f.begin();it!=f.end();++it){
            x=*it;
        if(f.find(a-x)==f.end()){
            c.pb(x);
        }
    }
    for(i=0;i<c.size();++i){
        f.erase(c[i]);s.insert(c[i]);
    }
    c.clear();
    while(!s.empty()){
        it=s.begin();
        x=*it;
        if(s.find(b-x)!=s.end()){
            res[ind[x]]=1;
            res[ind[b-x]]=1;
            s.erase(x);
            if(2*x!=b) s.erase(b-x);
        }
        else if(f.find(b-x)!=f.end()){
            res[ind[x]]=1;
            res[ind[b-x]]=1;
            f.erase(b-x);
            if(2*(b-x)!=a){
                    f.erase(a-(b-x));
                    s.insert(a-(b-x));
            }
            s.erase(x);

        }
        else{
            cout<<"NO"<<nl;
            return 0;
        }
    }
    cout<<"YES"<<nl;
    for(i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<nl;
    return 0;
}