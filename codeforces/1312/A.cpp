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
    int t; cin >> t;
    while(t--){
        int n, m; cin  >> n >> m;
        if(n % m ==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
