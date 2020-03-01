#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

int s[10], id[10], a[10];
int32_t main()
{
    int n, m; cin >> n >> m;
    map<int, int > mp;
    for(int i = 0; i < m; i++){
        cin >> id[i] >> a[i];
        --id[i];
        s[id[i]] = a[i];
        mp[id[i]] = a[i];
    }
    if(mp.find(0) == mp.end() && n != 1) s[0] = 1;
    for(int i = 0; i < m; i++) if(s[id[i]] != a[i]) return cout << -1 << nl, 0;
    if(s[0] == 0 && n != 1) return cout << -1 << nl, 0;
    for(int i = 0; i < n; i++) cout << s[i];
    cout << nl;
    return 0;
}
