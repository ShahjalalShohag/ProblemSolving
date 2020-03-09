#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 998244353 ;

int f[N],inv[N],finv[N];
void pre()
{
    f[0]=1;
    for(int i=1;i<N;i++) f[i]=1LL*i*f[i-1]%mod;
    inv[1] = 1;
    for (int i = 2; i <N; i++ ) {
        inv[i] = (-(1LL*mod/i) * inv[mod%i] ) % mod;
        inv[i] = (inv[i] + mod)%mod;
    }
    finv[0]=1;
    for(int i=1;i<N;i++) finv[i]=1LL*inv[i]*finv[i-1]%mod;
}
int ncr(int n,int r)
{
    if(n<r||n<0||r<0) return 0;
    return 1LL*f[n]*finv[n-r]%mod*finv[r]%mod;
}
int32_t main()
{
    pre();
    int n, m; cin >> n >> m;
    int ans = 1LL * m * ncr(m - 1, n - 2) % mod;
    for(int i = 1; i <= m; i++){
        ans -= ncr(i - 1, n - 2);
        if(ans < 0) ans += mod;
    }
    int sum = 0;
    for(int i = 2; i < n; i++) (sum += ncr(n - 3, i - 2)) %= mod;
    ans = 1LL * ans * sum % mod;
    cout << ans << nl;
    return 0;
}
