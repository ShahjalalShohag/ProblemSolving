#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

string a, b;
int dp[401][401][401], n, m;
int yo(int i, int j, int k)
{
    if(i == n){
        if(k == m) return 0;
        else return - 500;
    }
    if(j == m && k == m) return 0;
    if(j >= k) return - 500;
    int &ret = dp[i][j][k];
    if(ret != -1000) return ret;
    ret = yo(i + 1, j, k);
    if(j < m && a[i] == b[j]) ret = max(ret, 1 + yo(i + 1, j + 1, k));
    if(k < m && a[i] == b[k]) ret = max(ret, 1 + yo(i + 1, j, k + 1));
    return ret;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        cin >> a >> b;
        n = a.size(), m = b.size();
        int ans = 0;
        for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) for(int k = 0; k <= n; k++) dp[i][j][k] = -1000;
        for(int i = 0; i <= m; i++){
            if(yo(0, 0, i) >= m){
                ans = 1;
                break;
            }
        }
        if(ans) cout <<"YES\n";
        else cout << "NO\n";
    }
    return 0;
}
