#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
struct ST {
  pair<int, int> t[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = {a[b], b};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = max(t[l], t[r]);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {-inf, -1};
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
}t;

int s[N], n, k;
vector<int> id[N * 10];
int f(int l, int r, int p) {
  return upper_bound(id[p].begin(), id[p].end(), r) - 
    lower_bound(id[p].begin(), id[p].end(), l);
}
long long yo(int l, int r) {
  if (l > r) return 0;
  if (l == r) return 1;
  auto p = t.query(1, 1, n, l, r);
  int x = p.second;
  long long ans = 0;
  if (x - l <= r - x) {
    for (int i = x; i >= l; i--) {
      ans += f(x, r, (s[i - 1] + p.first) % k);
    }
  }  
  else {
    for (int i = x; i <= r; i++) {
      ans += f(l - 1, x - 1, ((s[i] - p.first) % k + k) % k);
    }
  }
  return ans + yo(l, x - 1) + yo(x + 1, r);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  id[0].push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = (s[i - 1] + a[i]) % k;
    id[s[i]].push_back(i);
  }
  t.build(1, 1, n);
  cout << yo(1, n) - n << '\n';
  return 0;
}