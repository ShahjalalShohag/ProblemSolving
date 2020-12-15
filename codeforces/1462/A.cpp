#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    deque<int> d;
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      d.push_back(k);
    }
    while (!d.empty()) {
      if (d.size() % 2 == n % 2) {
        cout << d.front() << ' ';
        d.pop_front();
      }
      else {
        cout << d.back() << ' ';
        d.pop_back();
      }
    }
    cout << '\n';
  }
  return 0;
}