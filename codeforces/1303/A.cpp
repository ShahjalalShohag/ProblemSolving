#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int32_t main()
{
    int t = in();
    while(t--){
        string s; cin >> s;
        int one = 0, mn = -1, mx = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                one ++;
                if(mn == -1) mn = i;
                mx = i;
            }
        }
        int ans = 0;
        if(one) ans = mx - mn + 1 - one;
        cout << ans << nl;
    }
    return 0;
}
