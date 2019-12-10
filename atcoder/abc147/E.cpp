#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 80+2;
const int mod = 1e9 + 7;

bitset<N*N*4> dp[N][N];
int a[N][N], b[N][N];
int32_t main()
{
    int n = in(), m = in();
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) a[i][j]=in();
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) b[i][j]=in();
    dp[1][1][N*N*2]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int k=abs(a[i][j]-b[i][j]);
            dp[i][j]=(dp[i][j]<<k)|(dp[i][j]>>k);
            dp[i+1][j]|=dp[i][j];
            dp[i][j+1]|=dp[i][j];
        }
    }
    int ans=1e9;
    for(int i=0; i<N*N*4; i++) if(dp[n][m][i]) ans=min(ans, abs(i-N*N*2));
    cout<<ans<<nl;
    return 0;
}
