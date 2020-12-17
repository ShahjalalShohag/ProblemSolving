#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9;

int a[N], tmp[N];
vector<int> v;
int yo1(int n, int x) {
  auto free = v;
  for (int i = x; i >= 1; i--) {
    int cur = free.back();
    if (cur < a[i]) return 0;
    free.pop_back();
  }
  return 1;
}
int yo2(int n, int x) {
  auto free = v;
  reverse(free.begin(), free.end());
  for (int i = x + 1; i <= n; i++) {
    int cur = free.back();
    if (cur > a[i]) return 0;
    free.pop_back();
  }
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
      tmp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      tmp[a[i]] = 0;
    }
    v.clear();
    for (int i = 1; i <= 2 * n; i++) {
      if (tmp[i]) {
        v.push_back(i);
      }
    }
    int l = 0, r = n, L = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (yo1(n, mid)) {
        L = mid; l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    l = 0, r = n; int R = n + 1;    
    while (l <= r) {
      int mid = l + r >> 1;
      if (yo2(n, n - mid)) {
        R = n - mid; l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    cout << max(0, L - R + 1) << '\n';
  }
  return 0;
}