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
    int n = in();
    map<string , int > mp; int m = 0;
    while(n--){
        string s; cin >> s; mp[s]++; m =max(m , mp[s]);
    }
    for(auto x: mp) if(x.second == m) cout << x.first << nl;
    return 0;
}
