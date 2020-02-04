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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int x = 0, y = 0, l = 0, r = 0, ans = n + 2;
        map<pii, int> last;
        last[pii(x, y)] = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L') x--;
            if(s[i] == 'R') x++;
            if(s[i] == 'U') y++;
            if(s[i] == 'D') y--;
            if(last.find(pii(x, y)) != last.end()){
                int le = last[pii(x, y)] + 1;
                int ri = i + 1;
                if(ri - le + 1 < ans){
                    ans = ri - le + 1;
                    l = le; r = ri;
                }
            }
            last[pii(x, y)] = i + 1;
        }
        if(ans == n + 2) cout << -1 << nl;
        else cout << l << ' ' << r << nl;
    }
    return 0;
}
