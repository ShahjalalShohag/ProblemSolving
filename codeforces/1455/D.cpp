#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int yo(int n, vector<int> a, int x) {
  vector<int> b = a;
  sort(b.begin(), b.end());
  if (a == b) return 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > x) {
      swap(a[i], x);
      return 1 + yo(n, a, x);
    }
  }
  return -inf;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << max(yo(n, a, x), -1) << '\n';
  }
  return 0;
}