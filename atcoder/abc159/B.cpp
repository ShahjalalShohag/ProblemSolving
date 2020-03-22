#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

bool pal(string s)
{
    string p = s;
    reverse(s.begin(), s.end());
    return p == s;
}
int32_t main()
{
    string s; cin >> s;
    int n = s.size();
    if(pal(s) && pal(s.substr(0, n / 2)) && pal(s.substr(n / 2 + 1))) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
