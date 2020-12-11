#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9;
// len -> largest string length of the corresponding endpos-equivalent class
// link -> longest suffix that is another endpos-equivalent class.
// firstpos -> 1 indexed end position of the first occurrence of the largest string of that node
// minlen(v) -> smallest string of node v = len(link(v)) + 1
// terminal nodes -> store the suffixes
struct SuffixAutomaton {
  struct node {
    int len, link, firstpos;
    map<char, int> nxt;
  };
  int sz, last;
  vector<node> t;
  vector<int> terminal;
  vector<int> dp;
  vector<vector<int>> g;
  SuffixAutomaton() {}
  SuffixAutomaton(int n) {
    t.resize(2 * n); terminal.resize(2 * n, 0);
    dp.resize(2 * n, -1); sz = 1; last = 0;
    g.resize(2 * n);
    t[0].len = 0; t[0].link = -1; t[0].firstpos = 0;
  }
  void extend(char c) {
    int p = last;
    if (t[p].nxt.count(c)) {
      int q = t[p].nxt[c];
      if (t[q].len == t[p].len + 1) {
        last = q;
        return;
      }
      int clone = sz++;
      t[clone] = t[q];
      t[clone].len = t[p].len + 1;
      t[q].link = clone;
      last = clone;
      while (p != -1 && t[p].nxt[c] == q) {
        t[p].nxt[c] = clone;
        p = t[p].link;
      }
      return;
    }
    int cur = sz++;
    t[cur].len = t[last].len + 1;
    t[cur].firstpos = t[cur].len;
    p = last;
    while (p != -1 && !t[p].nxt.count(c)) {
      t[p].nxt[c] = cur;
      p = t[p].link;
    }
    if (p == -1) t[cur].link = 0;
    else {
      int q = t[p].nxt[c];
      if (t[p].len + 1 == t[q].len) t[cur].link = q;
      else {
        int clone = sz++;
        t[clone] = t[q];
        t[clone].len = t[p].len + 1;
        while (p != -1 && t[p].nxt[c] == q) {
          t[p].nxt[c] = clone;
          p = t[p].link;
        }
        t[q].link = t[cur].link = clone;
      }
    }
    last = cur;
  }
  void build(string &s) {
    for (auto x: s) {
      extend(x);
      terminal[last] = 1;
    }
  }
};

struct ST {
  int t[4 * N];
  ST() {
    memset(t, 0, sizeof t);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = max(t[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = max(t[l], t[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
}t;

int st[N], en[N], par[N][20], T;
vector<int> g[N], oc[N];
void dfs(int u, int p = 0) {
  st[u] = ++T;
  par[u][0] = p;
  for (int k = 1; k < 20; k++) {
    par[u][k] = par[par[u][k - 1]][k - 1];
  }
  for (auto v: g[u]) {
    if (v ^ p) {
      dfs(v, u);
    }
  }
  en[u] = T;
}
int dp[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  SuffixAutomaton sa(n);
  sa.build(s);
  for (int i = 1; i < sa.sz; i++) {
    g[sa.t[i].link].push_back(i);
    oc[sa.t[i].firstpos].push_back(i);
  }
  dfs(0);
  for (int i = 1; i <= n; i++) {
    for (auto u: oc[i]) {
      int v = u;
      // find the maximum length of a suffix which occurs at least twice in this node
      for (int k = 19; k >= 0; k--) {
        int cur = par[v][k];
        int last = t.query(1, 1, T, st[cur], en[cur]) - sa.t[cur].len + 1;
        int nw = i - sa.t[u].len + 1;
        if (last < nw) {
          v = par[v][k];
        }
      }
      int cur = par[v][0];
      int last = t.query(1, 1, T, st[cur], en[cur]) - sa.t[cur].len + 1;
      int nw = i - sa.t[u].len + 1;
      if (last >= nw) {
        v = par[v][0];
      }
      dp[u] = max(dp[par[u][0]], dp[v] + 1);
    }
    for (auto u: oc[i]) {
      t.upd(1, 1, T, st[u], i);
    }
  }
  int ans = 0;
  for (int i = 1; i < sa.sz; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}