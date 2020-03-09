#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 501;
const int mod = 1e9 + 7;

int n, a[N], dp[N][N], pp[N][N];
int pos(int l, int r)
{
    if(l == r) return a[l];
    int &ret= pp[l][r];
    if(ret != -1) return ret;
    for(int i = l; i < r; i++){
        int k = pos(l, i);
        if(k == pos(i + 1, r)) return ret = k + 1;
    }
    return ret = l * 520 + r + 10000000;
}
int yo(int l, int r)
{
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    if(pos(l, r) < 5000) return ret = 1;
    ret = 10000;
    for(int i = l; i < r; i++){
        ret = min(ret, yo(l, i) + yo(i + 1, r));
    }
    return ret;
}
int32_t main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    memset(pp, -1, sizeof pp);
    cout << yo(1, n) << nl;
    return 0;
}
