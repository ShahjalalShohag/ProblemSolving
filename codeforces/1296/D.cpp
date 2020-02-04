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
    ios_base::sync_with_stdio(0);
    int n, a, b, k; cin >> n >> a >> b >> k;
    int ans = 0;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        int left = x % (a + b);
        if(left == 0) v.eb((b + a - 1) / a);
        else if(left <= a) ans++;
        else v.eb((left - a + a - 1) / a);
    }
    sort(v.begin(), v.end());
    for(auto x: v){
        if(k >= x) ans ++ , k -= x;
    }
    cout << ans << nl;
    return 0;
}
