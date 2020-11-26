#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int n, a[N];
int yo(int x) {
  long long cur = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > x) return 0;
    cur += x - a[i];
  }
  return cur >= x;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = 2e9, ans = 0;
  while (l <= r) {
    int mid = l + ((r - l) >> 1);
    if (yo(mid)) {
      ans = mid; r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << ans << '\n';
  return 0;
}