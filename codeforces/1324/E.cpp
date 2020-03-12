#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 2005;
const int mod = 1e9 + 7;

int a[N], dp[N][N], n, h, l, r;
int yo(int i, int nw)
{
    if(i == n + 1) return 0;
    int &ret = dp[i][nw];
    if(ret != -1) return ret;
    int p = (nw + a[i]) % h;
    ret = yo(i + 1, p) + (l <= p && p <= r);
    p = (p - 1 + h) % h;
    ret = max(ret, yo(i + 1, p) + (l <= p && p <= r));
    return ret;
}
int32_t main()
{
    cin >> n >> h >> l >> r;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << yo(1, 0) << nl;
    return 0;
}
