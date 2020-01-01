#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int a[N], cnt[16], dp[1<<16], pos[1<<16];
int32_t main()
{
    int n=in();
    for(int i=1; i<n; i++){
        int u=in(), v=in(), k=in();
        u++; v++;
        a[u]^=k; a[v]^=k;
    }
    int ans=0;
    for(int i=1; i<=n; i++) cnt[a[i]]++;
    ans+=cnt[0];
    for(int i=1; i<16; i++) ans+=cnt[i]>>1, cnt[i]%=2;
    cnt[0]=0;
    dp[0]=0;
    vector<int> v;
    for(int i=0; i<16; i++) if(cnt[i]) v.eb(i);
    int m=v.size();
    for(int mask=1; mask<(1<<m); mask++){
        int nw=0;
        for(int i=0; i<m; i++) if((mask>>i)&1) nw^=v[i];
        if(nw==0) pos[mask]=1;
    }
    for(int mask=1; mask<(1<<m); mask++){
        for(int sub=mask; sub; sub=(sub-1)&mask){
            if(pos[sub]) dp[mask]=max(dp[mask], dp[mask^sub]+1);
        }
    }
    ans+=dp[(1<<m)-1];
    cout<<n-ans<<nl;
    return 0;
}
