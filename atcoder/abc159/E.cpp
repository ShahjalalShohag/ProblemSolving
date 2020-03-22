#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 1010;
const int mod = 1e9 + 7;

string s[N];
int32_t main()
{
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] = "#" + s[i];
    }
    int ans = 1e9;
    for(int mask = 0; mask < (1 << (n - 1)); mask++){
        int cnt = __builtin_popcount(mask);
        vector<int> cur(cnt + 1, 0);
        int p = mask | (1 << (n - 1));
        int ultimate = 1;
        //deb(mask);
        for(int j = 1; j <= m; j++){
            //for(auto x: cur) cout << x << ' ';
        //cout << nl;
            int ok = 1;
            vector<int> extra;
            int pp = 0;
            for(int i = 1; i <= n; i++){
                pp += s[i][j] == '1';
                if((p >> (i - 1))&1) extra.eb(pp), pp = 0;
            }
            for(auto x: extra){
                //cout << x << ' ';
                if(x > k){
                    ultimate = 0;
                    break;
                }
            }
            //cout << nl;
            if(ultimate == 0) break;
            for(int i = 0; i < extra.size(); i++){
                cur[i] += extra[i];
                if(cur[i] > k){
                    ok = 0; break;
                }
            }
            if(!ok){
                cnt++;
                cur = extra;
            }
        }
        if(ultimate){
            ans = min(ans, cnt);
            //cout << mask <<  ' ' << cnt << nl;
        }
    }
    cout << ans << nl;
    return 0;
}
