#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
const int mxn=2e5+9;
set<int>g[mxn];
int k;
set<int>se;
void can_now(int u)
{
    if(g[u].size()<k&&se.find(u)!=se.end()){
        se.erase(u);
        for(auto &v:g[u]){
            g[v].erase(u);
            can_now(v);
        }
    }
}
int res[mxn];
pair<int,int> e[mxn];
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int i,j,n,m,t,u,v;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++){
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        e[i]={u,v};
    }
    for(i=1;i<=n;i++) se.insert(i);
    for(i=1;i<=n;i++) can_now(i);
    for(i=m;i>=1;i--){
        res[i]=se.size();
        u=e[i].first,v=e[i].second;
        g[u].erase(v);
        g[v].erase(u);
        can_now(u);
        can_now(v);
    }
    for(i=1;i<=m;i++) cout<<res[i]<<endl;
    return 0;
}

