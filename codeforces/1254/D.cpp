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
    while(i<N){
        (t[i]+=x)%=mod;
        i+=i&-i;
    }
}
void upd(int l,int r,int x)
{
    upd(l,x);
    upd(r+1,(-x+mod)%mod);
}
int query(int i)
{
    int ans=0;
    while(i){
        (ans+=t[i])%=mod;
        i-=i&-i;
    }
    return ans;
}
int T,st[N],en[N],par[N],hld[N],sz[N],big[N],sum[N];
vector<int> g[N];
void dfs(int u,int pre=0)
{
    int mx=0;
    st[u]=++T;
    par[u]=pre;
    sz[u]=1;
    for(auto v:g[u]){
        if(v==pre) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>mx) mx=sz[v],big[u]=v;
    }
    en[u]=T;
}
void yo(int u,int pre=0)
{
    for(auto v:g[u]){
        if(v==pre) continue;
        if(v==big[u]) hld[v]=hld[u];
        else hld[v]=v;
        yo(v,u);
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
    hld[1]=1;
    yo(1);
    int inv=qpow(n,mod-2);
    while(q--){
        int ty=in();
        if(ty==1){
            int u=in(),k=in();
            int p=1LL*sz[u]*k%mod;
            upd(1,T,p);
            upd(st[u],en[u],(-p+mod)%mod);
            if(big[u]){
                int p=1LL*(n-sz[big[u]])*k%mod;
                upd(st[big[u]],en[big[u]],p);
            }
            (sum[u]+=k)%=mod;
        }
        else{
            int u=in();
            int ans=query(st[u]);
            int extra=sum[u];
            while(hld[u]>1){
                u=hld[u];
                int p=1LL*(n-sz[u])*sum[par[u]]%mod;
                (ans+=p)%=mod;
                u=par[u];
            }
            ans=1LL*ans*inv%mod;
            (ans+=extra)%=mod;
            printf("%d\n",ans);
        }
    }
    return 0;
}
