#include<bits/stdc++.h>
using namespace std;

int a[10][10];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> v;
  for (int i = 2; i <= n; i++) {
    v.push_back(i);
  }
  int ans = 0;
  do {
    int cur = a[1][v[0]] + a[v.back()][1];
    for (int i = 0; i + 1 < v.size(); i++) {
      cur += a[v[i]][v[i + 1]];
    }
    ans += cur == k;
  } while(next_permutation(v.begin(), v.end()));
  cout << ans << '\n';
  return 0;
}