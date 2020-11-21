#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    vector<int> ca(26, 0), cb(26, 0);
    for (auto x: a) {
      ca[x - 'a']++;
    }    
    for (auto x: b) {
      cb[x - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      if (cb[i]) {
        for (int j = 0; j < i; j++) {
          if (ca[j] % k != 0) {
            ok = false;
            break;
          }
          ca[j + 1] += ca[j];
          ca[j] = 0;
        }
        if (ca[i] < cb[i]) {
          ok = false;
          break;
        }
        ca[i] -= cb[i];
      }
    }
    if (ok) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
  return 0;
}