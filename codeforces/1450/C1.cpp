#include<bits/stdc++.h>
using namespace std;

pair<vector<string>, int> yo(vector<string> s, int z) {
  int n = s.size();
  auto f = [&](int i, int j, int x, int d) {
    if (d) {
      for (int k = i - x; k <= i - x + 2; k++) {
        if (k < 0 || k >= n) return 0;
        if (s[k][j] != 'X') return 0;
      }
    }
    else {
      for (int k = j - x; k <= j - x + 2; k++) {
        if (k < 0 || k >= n) return 0;
        if (s[i][k] != 'X') return 0;
      }
    }
    return 1;
  };
  int tot = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i % 3 + z) % 3 == j % 3) {
        if (s[i][j] == 'X') {
          int cnt = 0;
          cnt += f(i, j, 2, 1);
          cnt += f(i, j, 1, 1);
          cnt += f(i, j, 0, 1);            
          cnt += f(i, j, 2, 0);
          cnt += f(i, j, 1, 0);
          cnt += f(i, j, 0, 0);
          if (cnt) {
            s[i][j] = 'O';
            ++tot;
          }
        }
      }
    }
  }
  return {s, tot};
}
pair<vector<string>, int> yo2(vector<string> s, int z) {
  int n = s.size();
  auto f = [&](int i, int j, int x, int d) {
    if (d) {
      for (int k = i - x; k <= i - x + 2; k++) {
        if (k < 0 || k >= n) return 0;
        if (s[k][j] != 'X') return 0;
      }
    }
    else {
      for (int k = j - x; k <= j - x + 2; k++) {
        if (k < 0 || k >= n) return 0;
        if (s[i][k] != 'X') return 0;
      }
    }
    return 1;
  };
  int tot = 0;
  for (int c = 6; c >= 1; c--) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i % 3 + z) % 3 == j % 3) {
          if (s[i][j] == 'X') {
            int cnt = 0;
            cnt += f(i, j, 2, 1);
            cnt += f(i, j, 1, 1);
            cnt += f(i, j, 0, 1);            
            cnt += f(i, j, 2, 0);
            cnt += f(i, j, 1, 0);
            cnt += f(i, j, 0, 0);
            if (cnt == c) {
              s[i][j] = 'O';
              ++tot;
            }
          }
        }
      }
    }
  }
  return {s, tot};
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<string> s(n), ans;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int cnt = n * n;
    for (int z = 0; z < 3; z++) {
      auto p = yo(s, z);
      if (p.second < cnt) {
        cnt = p.second;
        ans = p.first;
      }
    }     
    for (int z = 0; z < 3; z++) {
      auto p = yo2(s, z);
      if (p.second < cnt) {
        cnt = p.second;
        ans = p.first;
      }
    }    
    for (int i = 0; i < n; i++) {
      cout << ans[i] << '\n';
    }
  }
  return 0;
}