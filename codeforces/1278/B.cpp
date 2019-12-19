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
        int a=in(), b=in();
        if(a>b) swap(a, b);
        int ans=0;
        int x=b-a;
        for(int i=1; x; i++){
            ll nw=1LL*i*(i+1)/2;
            if(nw>=x&&(nw-x)%2==0){
                ans=i;
                break;
            }
        }
        cout<<ans<<nl;
    }
    return 0;
}
