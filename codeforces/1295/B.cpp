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

int a[N][2];
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        string s; cin >> s;
        s = "0" + s;
        for(int i = 1; i <= n; i++){
            a[i][0] = a[i-1][0] + (s[i] == '0');
            a[i][1] = a[i-1][1] + (s[i] == '1');
        }
        int dif = a[n][0] - a[n][1];
        int ans = 0;
        if(dif == 0){
            bool ok = 1;
            for(int i = 0; i <= n; i++){
                if(x == a[i][0] - a[i][1]) ok = 0;
            }
            if(ok == 0) ans = -1;
            else ans = 0;
        }
        else{
            ans += x == 0;
            for(int i = 1; i <= n; i++){
                int nw = a[i][0] - a[i][1];
                if((x - nw) % dif == 0 && (x - nw) / dif >= 0) ans ++;
            }
        }
        cout << ans << nl;
    }
    return 0;
}
