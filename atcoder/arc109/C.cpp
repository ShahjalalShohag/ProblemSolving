#include<bits/stdc++.h>
using namespace std;

char f(char a, char b) {
  if (a == b) return a;
  if (a == 'R' && b == 'S') return a;
  if (a == 'S' && b == 'R') return b;  
  if (a == 'P' && b == 'R') return a;
  if (a == 'R' && b == 'P') return b;  
  if (a == 'S' && b == 'P') return a;
  return b;
}
string yo(string s, int k) {
  int n = s.size();
  if (k <= 7 && (1 << k) <= n) {
    s.resize(1 << k);
    n = 1 << k;
  }
  if (k == 0) return s;
  string p = "";
  for (int i = 0; i < n; i += 2) {
    p += f(s[i], s[i + 1]);
  }
  p += p;
  return yo(p, k - 1);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s += s;
  cout << yo(s, k) << '\n';
  return 0;
}