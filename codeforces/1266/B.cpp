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
        ll n; cin>>n;
        if(n>=13&&n%14>=1&&n%14<=6) puts("YES");
        else puts("NO");
    }
    return 0;
}
