#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

set<int> g[30];
bool vis[30];
void add(int u, int v)
{
    g[u].insert(v);
    g[v].insert(u);
}
int cycle;
void dfs(int u, int pre = -1)
{
    vis[u] = 1;
    for(auto v: g[u]){
        if(v == pre) continue;
        if(vis[v]) cycle = 1;
        else dfs(v, u);
    }
}
string ans;
void dfs2(int u, int pre = -1)
{
    ans += char('a' + u);
    vis[u] = 1;
    for(auto v: g[u]){
        if(v == pre) continue;
        dfs2(v, u);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        for(int i = 1; s[i]; i++){
            add(s[i - 1] - 'a', s[i] - 'a');
        }
        memset(vis, 0, sizeof vis);
        int ok = 1;
        cycle = 0;
        for(int i = 0; i < 26; i++) if(!vis[i]) dfs(i);
        for(int i = 0; i < 26; i++) if(g[i].size() > 2 || cycle) ok = 0;
        if(!ok) cout <<"NO\n";
        else{
            memset(vis, 0, sizeof vis);
            ans = "";
            for(int i = 0; i < 26; i++) if(g[i].size() == 1 && !vis[i]) dfs2(i);
            for(int i = 0; i < 26; i++) if(!vis[i]) ans += char('a' + i);
            cout << "YES\n" << ans << nl;
        }
        for(int i = 0; i < 26; i++) g[i].clear();
    }
    return 0;
}
