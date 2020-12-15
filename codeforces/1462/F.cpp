#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    o_set<pair<int, int>> en, st;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
      int l, r; cin >> l >> r;
      v.push_back({l, r});
      st.insert({l, i});
      en.insert({r, i});
    }
    int ans = n - 1;
    for (auto x: v) {
      int l = x.first, r = x.second;
      int cur = en.order_of_key(make_pair(l, -1));
      cur += st.size() - st.order_of_key(make_pair(r + 1, -1));
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}