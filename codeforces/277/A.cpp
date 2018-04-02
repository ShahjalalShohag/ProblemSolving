#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> g[210];
bool vis[210];
void dfs(ll u)
{
    vis[u]=1;
    for(auto v:g[u]) if(!vis[v]) dfs(v);
}
int main()
{
    ll i,j,k,n,m,cnt=0,flag=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>k;
        if(k!=0) flag=1;
        for(j=0;j<k;j++) cin>>m,g[i].push_back(m+n),g[m+n].push_back(i);
    }
    for(i=1;i<=n;i++) if(!vis[i]) dfs(i),cnt++;
    flag==0?cout<<n<<endl:cout<<cnt-1<<endl;
}
