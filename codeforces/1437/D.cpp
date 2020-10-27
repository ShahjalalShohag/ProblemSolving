#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int dep[N], a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    queue<int> q;
    q.push(1);
    dep[1] = 0;
    int ans = 0;
    for (int i = 2; i <= n; ) {
      int j = i + 1;
      while (a[j - 1] < a[j]) ++j;
      int u = q.front(); q.pop();
      for (int k = i; k < j; k++){
        q.push(a[k]);
        dep[a[k]] = dep[u] + 1;
        ans = dep[u] + 1;
      }
      i = j;
    }
    cout << ans << '\n';
  }
  return 0;
}