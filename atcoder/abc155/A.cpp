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
    int a, b, c; cin >> a >> b >> c;
    int ok = 0;
    if(a == b && b != c) ok = 1;
    if(a == c && a != b) ok = 1;
    if(b == c && a != b) ok = 1;
    if(ok) puts("Yes");
    else puts("No");
    return 0;
}
