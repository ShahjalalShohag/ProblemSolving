#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 2e5 + 9;
const int mod = 1e9 + 7;

unsigned char a[N];
int32_t main()
{
    int n=in();
    for(int i=1; i<=n; i++) scanf("%hhu", &a[i]);
    int q=in();
    while(q--){
        int l=in(), r=in();
        unsigned char x, y; scanf("%hhu%hhu", &x, &y);
        for(int i=l; i<=r; i++) a[i]=a[i]==x?y:a[i];
    }
    for(int i=1; i<=n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}
