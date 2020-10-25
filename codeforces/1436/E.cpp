#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, B = 320;

struct query {
  int l, r, id;
  bool operator < (const query &x) const {
    if(l / B == x.l / B) return r < x.r;
    return l / B < x.l / B;
  }
} Q[N];
int cnt[N], a[N], blk[N];
inline void add_left(int i) {
  int x = a[i];
  if (cnt[x] == 0) {
    ++blk[x / B];
  }
  ++cnt[x];
}
inline void add_right(int i) {
  int x = a[i];
  if (cnt[x] == 0) {
    ++blk[x / B];
  }
  ++cnt[x];
}
inline void rem_left(int i) {
  int x = a[i];
  --cnt[x];
  if (cnt[x] == 0) {
    --blk[x / B];
  }
}
inline void rem_right(int i) {
  int x = a[i];
  --cnt[x];
  if (cnt[x] == 0) {
    --blk[x / B];
  }
}
int mex() {
  for (int i = 0; ; ++i) if(blk[i] < B) {
    for (int j = i * B; ; ++j) {
      if (!cnt[j]) return j;
    }
  }
}
int ans[N], f[N];
vector<int> id[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i <= n; i++) {
    id[i].push_back(0);
  }
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    --a[i];
    id[a[i]].push_back(i);
  }
  int q = 0;
  for (int i = 0; i <= n; i++) {
    id[i].push_back(n + 1);
    for (int j = 1; j < id[i].size(); j++) {
      if (id[i][j - 1] + 1 < id[i][j]) {
        ++q;
        Q[q] = {id[i][j - 1] + 1, id[i][j] - 1, q};
      }
    }
  }
  ++q;
  Q[q] = {1, n, q};
  sort(Q + 1, Q + q + 1);
  int l = 1, r = 0;
  for(int i = 1; i <= q; i++) {
    int L = Q[i].l, R = Q[i].r;
    if(R < l) {
      while (l > L) add_left(--l);
      while (l < L) rem_left(l++);
      while (r < R) add_right(++r);
      while (r > R) rem_right(r--);
    } else {
      while (r < R) add_right(++r);
      while (r > R) rem_right(r--);
      while (l > L) add_left(--l);
      while (l < L) rem_left(l++);
    }
    ans[Q[i].id] = mex();
  }
  int cur = 0;
  for(int i = 1; i <= q; i++) {
    f[ans[i]] = 1;
    while (f[cur]) {
      ++cur;
    }
  }
  cout << cur + 1 << '\n';
  return 0;
}
