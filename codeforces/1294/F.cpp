#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

vector<int> g[N];
int par[N][20],dep[N],sz[N];
void dfs(int u,int pre=0)
{
    par[u][0]=pre;
    dep[u]=dep[pre]+1;
    sz[u]=1;
    for(int i=1;i<=18;i++) par[u][i]=par[par[u][i-1]][i-1];
    for(auto v:g[u]){
        if(v==pre) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=18;k>=0;k--) if(dep[par[u][k]]>=dep[v]) u=par[u][k];
    if(u==v) return u;
    for(int k=18;k>=0;k--) if(par[u][k]!=par[v][k]) u=par[u][k],v=par[v][k];
    return par[u][0];
}
int dist(int u,int v)
{
    int lc=lca(u,v);
    return dep[u]+dep[v]-2*dep[lc];
}
int mx, l, r;
void dfs1(int u, int pre=0, int dis=0)
{
    if(dis>mx) mx=dis, l=u;
    for(auto v: g[u]) if(v!=pre){
        dfs1(v, u, dis+1);
    }
}
void dfs2(int u, int pre=0, int dis=0)
{
    if(dis>mx) mx=dis, r=u;
    for(auto v: g[u]) if(v!=pre){
        dfs2(v, u, dis+1);
    }
}
int dis[N];
int32_t main()
{
    int n=in();
    for(int i=1; i<n; i++){
        int u=in(), v=in();
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1);
    mx=-1;
    dfs1(1);
    mx=-1;
    dfs2(l);
    int ans=mx;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(dist(l, i)+dist(i, r)==ans) q.push(i), dis[i]=0;
        else dis[i]=1e9;
    }
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto v: g[u]) if(dis[u]+1<dis[v]) dis[v]=dis[u]+1, q.push(v);
    }
    int third=-1, d=0;
    for(int i=1; i<=n; i++){
        if(dis[i]>d) d=dis[i], third=i;
    }
    if(third==-1){
        for(int i=1; i<=n; i++) if(i!=l&&i!=r){
            third=i;
            break;
        }
    }
    ans+=d;
    cout<<ans<<nl<<l<<' '<<r<<' '<<third<<nl;
    return 0;
}
