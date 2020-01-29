#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 2e5 + 9;
const int mod = 1e9 + 7;

int nxt[N][26];
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string a, b; cin >> a >> b;
        int n = a.size();
        for(int j = 0; j < 26; j++) nxt[n][j] = n;
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i+1][j];
            nxt[i][a[i] - 'a'] = i;
        }
        int ans = 0, ok = 1;
        int m = b.size();
        for(int i = 0, j; i < m; i = j){
            if(nxt[0][b[i] - 'a'] == n){
                ok = 0;
                break;
            }
            int nw = -1;
            for(j = i; nw < n && j < m && nxt[nw + 1][b[j] - 'a'] < n; j++) nw = nxt[nw + 1][b[j] - 'a'];
            ans ++;
        }
        if(!ok) ans = -1;
        cout << ans << nl;
    }
    return 0;
}
