#include<bits/stdc++.h>
using namespace std;

const int N = 42;

int g[N][N];
int res;
long long edges[51];
//3 ^ (n / 3)
void BronKerbosch(int n, long long R, long long P, long long X)
{
    if (P == 0LL && X == 0LL) {
        int t = __builtin_popcountll(R);
        res = max(res, t);
        return;
    }
    long long u = 0;
    while (!((1LL<<u) & (P|X))) u ++;
    for (int v = 0; v < n; v++) {
        if (((1LL << v) & P) && !((1LL << v) & edges[u])) {
            BronKerbosch(n, R | (1LL << v), P & edges[v], X & edges[v]);
            P -= (1LL << v);
            X |= (1LL << v);
        }
    }
}

int max_clique (int n)
{
    res = 0;
    for (int i = 1; i <= n; i++) {
        edges[i] = 0;
        for (int j = 1; j <= n; j++)  if (g[i][j]) edges[i - 1] |= ( 1LL << (j - 1) );
    }
    BronKerbosch(n, 0, (1LL << n) - 1, 0);
    return res;
}

int32_t main()
{
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) for(int j = 1;  j <= n; j++) cin >> g[i][j];
    int m = max_clique(n); double x = 1.0 * k / m;
    double ans = (1.0 * k * k - x * x * m) / 2.0;
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
