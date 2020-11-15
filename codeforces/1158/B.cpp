#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  string s = "";
  k = (n - k) >> 1;
  while (s.size() < n) {
    s += string(k, '0') + "1";
  }
  while (s.size() > n) s.pop_back();
  cout << s << '\n';
  return 0;
}