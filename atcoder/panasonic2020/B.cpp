#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;


int32_t main()
{
    ll n, m; cin >> n >> m; cout << ((n == 1 || m == 1) ? 1 : (n * m + 1) / 2) << nl;
    return 0;
}
