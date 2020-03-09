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
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        set<int> se; int cnt = 0;
        for(int i = 1; i <= n; i++){
            ll x; cin >> x;
            int id = 0;
            while(x){
                if(x % k == 1) se.insert(id), cnt ++;
                else if(x % k > 1) cnt += 1000;
                x /= k;
                ++id;
            }
        }
        if(se.size() == cnt) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
