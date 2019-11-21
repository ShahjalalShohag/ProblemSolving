#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=1.5e5+9;
const int mod=998244353;


int qpow(int n,int k)
{
    int ans=1;
    while(k){
        if(k&1) ans=1LL*ans*n%mod;
        n=1LL*n*n%mod;
        k>>=1;
    }
    return ans;
}
int t[N];
inline void add(int &a,int &b)
{
    if((a+=b)>=mod) a-=mod;
}
const int B=316;
int A[N],blsum[N];
void upd(int i,int x)
{
    add(A[i],x);
    add(blsum[i/B],x);
}
void upd(int l,int r,int x)
{
    upd(l,x);
    upd(r+1,mod-x);
}
int query(int x)
{
    int ans=0;
    for(int i=0;i<x/B;i++) add(ans,blsum[i]);
    for(int i=x/B*B;i<=x;i++) add(ans,A[i]);
    return ans;
}
int T,st[N],en[N],sz[N],sum[N];
vector<int> g[N];
void dfs(int u,int pre=0)
{
    if(pre) g[u].erase(find(g[u].begin(),g[u].end(),pre));
    sz[u]=1;
    for(auto v:g[u]){
        dfs(v,u);
        sz[u]+=sz[v];
    }
    sort(g[u].begin(),g[u].end(),[](int i,int j){return sz[i]<sz[j];});
}
vector<pair<int,pii>> G[N];
void yo(int u)
{
    st[u]=++T;
    for(auto v:g[u]) yo(v);
    en[u]=T;
    for(int i=0,j;i<(int)g[u].size();i=j){
        for(j=i+1;j<(int)g[u].size()&&sz[g[u][i]]==sz[g[u][j]]; j++);
        G[u].eb(sz[g[u][i]],make_pair(st[g[u][i]],en[g[u][j-1]]));
    }
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int32_t main()
{
    int n=in(),q=in();
    for(int i=1;i<n;i++){
        int u=in(),v=in();
        g[u].eb(v);
        g[v].eb(u);
    }
    int root=rnd()%n+1;
    dfs(root);
    yo(root);
    int inv=qpow(n,mod-2);
    while(q--){
        int ty=in();
        if(ty==1){
            int u=in(),k=in();
            int p=1LL*sz[u]*k%mod;
            upd(1,T,p);
            upd(st[u],en[u],mod-p);
            for(auto x:G[u]){
                int s=x.first;
                auto p=x.second;
                upd(p.first,p.second,1LL*(n-s)*k%mod);
            }
            add(sum[u],k);
        }
        else{
            int u=in();
            int ans=query(st[u]);
            ans=1LL*ans*inv%mod;
            add(ans,sum[u]);
            printf("%d\n",ans);
        }
    }
    return 0;
}
