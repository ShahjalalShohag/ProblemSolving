#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define inf 1<<28
#define pb push_back
#define fr(a,b,c) for(a=b;a<c;a++)
#define eqfr(a,b,c) for(a=b;a<=c;a++)
#define pii pair<int,int>
#define vi vector<int>
#define qi queue<int>
#define itfr(a,b) for(a=b.begin(),a!=b.end(),a++)
#define fill(a,x) memset(a,0,sizeof(a))
#define mpii map<int,int>
#define si set<int>
#define umpii unordered_map<int,int>
#define len(s) s.length()
#define vit vector<int>::iterator
#define szfr(a,b,c) for(a=b;a<c.size();a++)
#define mpit mapii::iterator
#define umpit umapii::iterator
#define sit si::iteartor
#define vs vector<string>
#define mpsi map<string,int>
#define popf pop_front
#define popb pop_back
#define pf push_front
#define di deque<int>
#define mp make_pair
vi g[2000];
int n,m,vis[2000];
void dfsutil(int i)
{
    int k;
    for(int j=0;j<g[i].size();j++){
        if(vis[g[i][j]]==0){
            vis[g[i][j]]=1;
            dfsutil(g[i][j]);
        }
    }
}
int dfs()
{
    int i,k=0;
    for(i=m+1;i<=n+m;i++){
        if(vis[i]==0){
                k++;
            dfsutil(i);
        }
    }
    return k;
}
int main()
{
    int i,j,ans,a,k,flag=0;
    cin>>n>>m;
    fill(vis,0);
    for(i=m+1;i<=n+m;i++){
        cin>>k;
        if(k!=0) flag=1;
        while(k--){
            cin>>a;
            g[i].pb(a);
            g[a].pb(i);
        }
    }
    ans=dfs();
    if(flag==0) cout<<n<<endl;
    else cout<<ans-1<<endl;
    return 0;
}
