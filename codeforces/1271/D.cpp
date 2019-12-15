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

int dp[N][N], c[N], add[N], profit[N], g[N], n;
vector<int> r[N];
int yo(int i, int k)
{
    if(i==n+1) return 0;
    int &ret=dp[i][k];
    if(ret!=-1) return ret;
    if(k<c[i]) return -1e9;
    int p=k+add[i];
    ret=yo(i+1, p);
    int nw=0;
    for(int j=0; j<(int)r[i].size(); j++){
        nw+=r[i][j];
        ret=max(ret, nw+yo(i+1, p-(j+1)));
    }
    return ret;
}
int32_t main()
{
    n=in();
    int m=in(), nw=in();
    for(int i=1; i<=n; i++) c[i]=in(), add[i]=in(), profit[i]=in();
    for(int i=1; i<=n; i++) g[i]=i;
    for(int i=1; i<=m; i++){
        int u=in(), v=in();
        g[v]=max(g[v], u);
    }
    for(int i=1; i<=n; i++) r[g[i]].eb(profit[i]);
    for(int i=1; i<=n; i++) sort(r[i].rbegin(), r[i]. rend());
    memset(dp, -1, sizeof dp);
    int ans=yo(1, nw);
    if(ans<0) ans=-1;
    cout<<ans<<nl;
    return 0;
}
