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

ll yo(ll n)
{
    if(n <= 1) return n;
    return yo(n / 2)*2 + 1;
}
int32_t main()
{
    ll n; cin >> n;
    cout << yo(n) << nl;
    return 0;
}
