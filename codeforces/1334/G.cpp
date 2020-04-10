#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

bitset<N> bs[26], ans; int p[26];
int32_t main()
{
    for(int i = 0; i < 26; i++) cin >> p[i], p[i]--;
    string s, t; cin >> s >> t;
    for(int i = 0; t[i]; i++) bs[t[i] - 'a'][i] = 1;
    ans.set();
    for(int i = 0; s[i]; i++) ans &= (bs[s[i] - 'a'] | bs[p[s[i] - 'a']]) >> i;
    for(int i = 0; i <= t.size() - s.size(); i++) cout << ans[i];
    return 0;
}
