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
    int n=in();
    int ans=1;
    for(int i=1; i<=n; i++){
        int k=in();
        if(k==ans) ans++;
    }
    if(ans==1) ans=-1;
    else ans=n-ans+1;
    cout<<ans<<nl;
    return 0;
}
