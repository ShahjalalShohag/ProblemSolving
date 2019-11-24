#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;

int ans[N],res;
vector<pii> g[N];
void dfs(int u,int pre=0,int c=0)
{
    int nw=1;
    for(auto x:g[u]){
        int v=x.first,id=x.second;
        if(v==pre) continue;
        if(nw==c) nw++;
        ans[id]=nw;
        res=max(res,nw);
        dfs(v,u,nw);
        nw++;
    }
}
int32_t main()
{
    int n=in();
    for(int i=1;i<n;i++){
        int u=in(),v=in();
        g[u].eb(v,i);
        g[v].eb(u,i);
    }
    dfs(1);
    printf("%d\n",res);
    for(int i=1;i<n;i++) printf("%d\n",ans[i]);
    return 0;
}
