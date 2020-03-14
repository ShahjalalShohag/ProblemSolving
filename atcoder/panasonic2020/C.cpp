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
    ll a, b, c; cin >> a >> b >> c;
    long double sa = sqrtl(1.0 * a), sb = sqrtl(1.0 * b), sc = sqrtl(1.0 * c);
    if(sa + sb < sc && a * b * 4LL < (c - a - b) * (c - a - b)) puts("Yes");
    else puts("No");
    return 0;
}
