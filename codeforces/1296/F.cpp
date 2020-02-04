#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 5005;
const int mod = 1e9 + 7;

vector<int> g[N];
int u[N], v[N];
int par[N][20], dep[N], sz[N];
void dfs(int u,int pre)
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
struct constraint
{
    int u, v, w;
    bool operator < (const constraint &oth) const
    {
        return w > oth.w;
    }
}e[N];
int ans[N][N];
int32_t main()
{
    int n = in();
    for(int i = 1; i < n; i++){
        u[i] = in(), v[i] = in();
        g[u[i]].eb(v[i]);
        g[v[i]].eb(u[i]);
    }
    dfs(1, 0);
    int m = in();
    for(int i = 1; i <= m; i++){
        e[i].u = in(), e[i].v = in(), e[i].w = in();
    }
    sort(e + 1, e + m + 1);
    for(int i = 1; i <= m; i++){
        int u = e[i].u, v= e[i].v, w = e[i].w;
        int lc = lca(u, v);
        int got = 0;
        vector<pii> left;
        for(int nw = u; nw != lc; nw = par[nw][0]){
            int assigned = ans[nw][par[nw][0]];
            got |= assigned == w;
            if(assigned == 0){
                left.eb(nw, par[nw][0]);
            }
        }
        for(int nw = v; nw != lc; nw = par[nw][0]){
            int assigned = ans[nw][par[nw][0]];
            got |= assigned == w;
            if(assigned == 0){
                left.eb(nw, par[nw][0]);
            }
        }

        if(got || (int)left.size() > 0){
            for(auto x: left) ans[x.first][x.second] = ans[x.second][x.first] = w;
        }
        else return cout <<-1 << nl, 0;
    }
    for(int i = 1; i < n; i++) printf("%d ", (ans[u[i]][v[i]] == 0? 1000000 : ans[u[i]][v[i]]));
    return 0;
}
