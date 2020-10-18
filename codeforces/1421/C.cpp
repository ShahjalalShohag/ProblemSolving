#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  cout << 3 << '\n';
  cout << "L 2\n";
  cout << "R 2\n";
  cout << "R " << 2 * n - 1 << '\n';
  return 0;
}