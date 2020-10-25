#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

char ch[N];
int k[N], a[N], ans[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  set<int> se;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> ch[i];
    if (ch[i] == '+') {
      se.insert(i);
    }
    else {
      cin >> k[i];
      a[k[i]] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    auto it = se.lower_bound(a[i]);
    if (it == se.begin()) {
      cout << "NO\n";
      return 0;
    }
    --it;
    ans[*it] = i;
    se.erase(it);
  }
  if (!se.empty()) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (ch[i] == '+') {
      assert(ans[i]);
      se.insert(ans[i]);
    }
    else {
      if (se.empty() || (*se.begin()) != k[i]) {
        cout << "NO\n";
        return 0;
      }
      se.erase(se.begin());
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= 2 * n; i++) {
    if (ch[i] == '+') {
      cout << ans[i] << ' ';
    }
  }
  return 0;
}