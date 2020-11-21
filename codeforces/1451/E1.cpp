#include<bits/stdc++.h>
using namespace std;

int query(int i, int j, int f) {
  if (f == 0) {
    cout << "AND ";
  }
  else if (f == 1) {
    cout << "OR ";
  }
  else {
    cout << "XOR ";
  }
  cout << i << ' ' << j << '\n';
  cout.flush();
  int k; cin >> k;
  return k;
}
int a[1 << 17];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  set<vector<int>> se;
  map<vector<int>, vector<int>> mp;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        vector<int> v;
        v.push_back(i & j);
        v.push_back(i ^ j);
        v.push_back(j ^ k);
        v.push_back(j | k);
        v.push_back(i | k);
        se.insert(v);
        mp[v] = vector<int>({i, j, k});
      }
    }
  }
  //cout << se.size() << '\n';
  int n; cin >> n;
  vector<int> v;
  v.push_back(query(1, 2, 0));
  v.push_back(query(1, 2, 2));
  v.push_back(query(2, 3, 2));
  v.push_back(query(2, 3, 1));
  v.push_back(query(1, 3, 1));
  for (int k = 0; k < 17; k++) {
    vector<int> cur;
    for (int i = 0; i < 5; i++) {
      cur.push_back(v[i] >> k & 1);
    }
    for (int i = 0; i < 3; i++) {
      a[i + 1] |= mp[cur][i] << k;
    }
  }
  for (int i = 4; i <= n; i++) {
    int x = query(1, i, 2);
    a[i] = x ^ a[1];
  }
  cout << "!";
  for (int i = 1; i <= n; i++) {
    cout << ' ' << a[i];
  }
  cout << '\n';
  cout.flush();
  return 0;
}