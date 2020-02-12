#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int cnt[100];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    map<int, int > pw;
    for(int i = 1, p = 0; i < 1000000000; i*=2, p++) pw[i] = p;
    int t; cin >> t;
    while(t--){
        ll n; int m; cin >> n >> m;
        while(m--){
            int k ; cin >> k;
            cnt[pw[k]]++;
        }
        int ans = 0, ok = 1;
        for(int i = 0; i < 60; i++){
            if(i) cnt[i] += cnt[i - 1] / 2;
            if((n >> i) & 1){
                if(cnt[i]) cnt[i]--;
                else{
                    for(int j = i + 1; j < 60; j++) if(cnt[j]){
                        cnt[j] --;
                        for(int k = j - 1; k >= i; k--){
                            cnt[k] ++;
                            ans++;
                        }
                        break;
                    }
                    if(!cnt[i]){
                        ok = 0;
                        break;
                    }
                    //cnt[i]++;
                }
            }
        }
        if(!ok) ans = -1;
        cout << ans << nl;
        memset(cnt, 0, sizeof cnt);
    }
    return 0;
}
