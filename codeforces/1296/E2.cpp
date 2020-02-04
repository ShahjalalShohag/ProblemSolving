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

int cnt[300], oc[300][300], dp[300], col[N], used[300];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    int n ; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        int vis = 0;
        for(char ch = s[i] + 1; ch <= 'z'; ch++){
            if(cnt[ch]){
                dp[s[i]] = max(dp[s[i]], dp[ch] + 1);
                vis |= used[ch];
            }
        }
        int mex = 0;
        for(int i = 0; i < 26; i++) if(vis>> i == 0){
            mex = i; break;
        }
        col[i] = mex;
        used[s[i]] |= 1 << mex;
        cnt[s[i]] = 1;
    }
    int ans = 0;
    for(char ch = 'a'; ch <= 'z'; ch++) ans= max(ans, dp[ch]);
    cout << ans + 1 << nl;
    for(int i = 0; i < n; i++) cout << col[i] + 1 << ' ';
    cout << nl;
    return 0;
}
