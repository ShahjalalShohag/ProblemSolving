#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;

int a[N], ans[N];
bitset<N> bs[101], nw, t;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int k; cin >> k; bs[k][i] = true;
    }
    int q; cin >> q;
    while(q--){
        int l, r, x, y; cin >> l >> r >> x >> y;
        if(x == y) continue;
        nw.set();
        nw <<= N - (r - l + 1);
        nw >>= N - r - 1;
        t = bs[x] & nw;
        bs[x] &= ~t;
        bs[y] |= t;
    }
    for(int i = 1; i <= 100; i++){
        int p = bs[i]._Find_first();
        while(p < N){
            ans[p] = i;
            p = bs[i]._Find_next(p);
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}