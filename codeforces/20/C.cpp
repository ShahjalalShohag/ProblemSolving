#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vs vector<string>
#define vpii vector<pair<int,int>>
#define vpll vector< pair<ll,ll> >
#define si set<int>
#define usi unordered_set<int>
#define ss set<string>
#define spii set<pair<int,int>>
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
#define fi first
#define se second
#define fill(a,x) memset(a,x,sizeof(a))
#define fill2d(a,x,n,m) memset(a,x,n*m*sizeof(a[0][0]))
#define inf INT_MAX
#define mod 1e9+7
#define mxn 100100
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) cout(v.begin(),v.end(),a)
#define len(s) s.length()
#define strtoint(a) atoi(a.c_str())
vpii g[mxn];
int dis[mxn],par[mxn],done[mxn];
int n;
void solve()
{
    int i,j,x,y,v;
    for(i=0;i<mxn;i++) dis[i]=inf;
    priority_queue< pii >pq;
    pq.push(mp(0,1));
    dis[1]=0;
    while(!pq.empty()){
        pii tmp=pq.top();
        pq.pop();
        v=tmp.se;
        if(v==n) return;
        done[v]=1;
        for(i=0;i<g[v].size();i++){
            x=g[v][i].fi;
            y=g[v][i].se;
            if(!done[x]&&(dis[v]+y<dis[x])){
                par[x]=v;
                dis[x]=dis[v]+y;
                pq.push(mp(-dis[x],x));
            }
        }
    }
}
int print_path(int x)
{
    if(x==1){
        printf("%d ",1);
    }
    else if(par[x]==0){
        printf("-1\n");
    }
    else{
        print_path(par[x]);
        printf("%d ",x);
    }
}
int main()
{
    int i,j,cs,t,e,u,s,v,w;
        scanf("%d%d",&n,&e);
        for(j=0;j<e;j++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
        }
        solve();
        print_path(n);
    return 0;
}

