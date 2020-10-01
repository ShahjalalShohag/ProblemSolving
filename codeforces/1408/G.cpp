#include<bits/stdc++.h>
using namespace std;

const int N = 1505, mod = 998244353;

int par[N], sz[N], esz[N];
vector<int> dp[N];
int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n; cin >> n;
   vector<array<int, 3>> e;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         int k; cin >> k;
         if (i < j) {
            e.push_back({k, i, j});
         }
      }
   }
   sort(e.begin(), e.end());
   for (int i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
      esz[i] = 0;
      dp[i] = {0, 1};
   }
   function<int(int)> find = [&](int u) {
      return par[u] = (par[u] == u ? u : find(par[u]));
   };
   for (auto x: e) {
      int u = x[1], v = x[2];
      u = find(u); v = find(v);
      if (u != v) {
         par[v] = u;
         vector<int> tmp(sz[u] + sz[v] + 1, 0);
         for (int i = 0; i <= sz[u]; i++) {
            for (int j = 0; j <= sz[v]; j++) {
               tmp[i + j] += 1LL * dp[u][i] * dp[v][j] % mod;
               tmp[i + j] %= mod;
            }
         }
         dp[u] = tmp;
         esz[u] += esz[v];
         sz[u] += sz[v];
      }
      esz[u]++;
      if (sz[u] * (sz[u] - 1) / 2 == esz[u]) {
         dp[u][1] = (dp[u][1] + 1) % mod;
      }
   }
   int u = find(1);
   for (int i = 1; i <= n; i++) {
      cout << dp[u][i] << ' ';
   }
   return 0;
}