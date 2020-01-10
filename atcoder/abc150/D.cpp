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

int a[N];
int32_t main()
{
    int n=in(), m=in();
    ll lc=1, inf=2e9;
    for(int i=1; i<=n; i++){
        a[i]=in();
        a[i]/=2;
        lc=min(inf, lc*a[i]/__gcd(lc, 1LL*a[i]));
    }
    ll ans=((m/lc)+1)/2;
    int ok=1;
    for(int i=1; i<=n; i++) if((lc/a[i])%2==0) ok=0;
    if(!ok) ans=0;
    cout<<ans<<nl;
    return 0;
}
