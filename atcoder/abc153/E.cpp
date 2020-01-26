#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 1e4 + 9;
const int mod = 1e9 + 7, inf = 1e9;

int dp[N][1010], w[N], c[N];
int yo (int h, int n)
{
    if(h <= 0) return 0;
    if(n == -1) return inf;
    int &ret = dp[h][n];
    if(ret != -1) return ret;
    ret = yo(h, n - 1);
    ret = min(ret, yo(h - w[n], n - 1) + c[n]);
    ret = min(ret, yo(h - w[n], n) + c[n]);
    return ret;
}
int32_t main()
{
    int h = in(), n = in();
    for(int i = 0; i < n; i++) w[i] = in(), c[i]= in();
    memset(dp, -1, sizeof dp);
    cout << yo(h, n-1) << nl;
    return 0;
}
