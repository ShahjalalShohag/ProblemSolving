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

int32_t main()
{
    int t=in();
    while(t--){
        int k=in(), n=in();
        int p=n/k;
        int m=n%k;
        ll ans=0;
        for(int i=1; i<=k; i++){
            if(m) ans+=(p+1)*(p+1),m--;
            else ans+=p*p;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
