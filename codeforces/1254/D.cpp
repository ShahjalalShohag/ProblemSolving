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
void upd(int i,int x)
{
    while(i<N)(t[i]+=x)%=mod,i+=i&-i;
}
void upd(int l,int r,int x)
{
    upd(l,x);
    upd(r+1,mod-x);
}
int query(int i)
{
    int ans=0;
    while(i) (ans+=t[i])%=mod,i-=i&-i;
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
int32_t main()
{
    int n=in(),q=in();
    for(int i=1;i<n;i++){
        int u=in(),v=in();
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1);
    yo(1);
    int inv=qpow(n,mod-2);
    while(q--){
        int ty=in();
        if(ty==1){
            int u=in(),k=in();
            int p=1LL*sz[u]*k%mod;
            upd(1,T,p);
            upd(st[u],en[u],(-p+mod)%mod);
            for(auto x:G[u]){
                int s=x.first;
                auto p=x.second;
                upd(p.first,p.second,1LL*(n-s)*k%mod);
            }
            (sum[u]+=k)%=mod;
        }
        else{
            int u=in();
            int ans=query(st[u]);
            ans=1LL*ans*inv%mod;
            (ans+=sum[u])%=mod;
            printf("%d\n",ans);
        }
    }
    return 0;
}
