#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

vector<int> g[N];
int a[N], dp[N], dp2[N];
void dfs(int u, int pre = 0)
{
    dp[u] = a[u];
    for(auto v: g[u]){
        if(v == pre) continue;
        dfs(v, u);
        dp[u] += max(0, dp[v]);
    }
}
void yo(int u,int pre = 0)
{
    int sum = 0;
    for(auto v: g[u]){
        if(v == pre) continue;
        sum += max(0, dp[v]);
    }
    for(auto v: g[u]){
        if(v == pre) continue;
        int nw = sum - max(0, dp[v]);
        dp2[v] = nw + max(0, dp2[u]) + a[u];
        yo(v, u);
    }
}
int32_t main()
{
    int n = in();
    for(int i = 1; i <= n; i++){
        a[i] = in();
        if(a[i] == 0) a[i] = -1;
    }
    for(int i = 1; i < n; i++){
        int u = in(), v = in();
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1);
    yo(1);
    for(int i = 1; i <= n; i++) printf("%d ", dp[i] + max(0, dp2[i]));
    puts("");
    return 0;
}
