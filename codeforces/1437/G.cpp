#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int ind[N];
struct aho_corasick {
  bool is_end[N];
  int link[N]; //link to the longest proper suffix
  int sz;
  map<char, int> to[N], dp[N];
  void clear() {
      for(int i = 0; i < sz; i++)
          is_end[i] = 0,ind[i]=0,link[i] = 0, to[i].clear(), dp[i].clear();
      sz = 1;
      is_end[0] = 1;
  }
  aho_corasick() {
      sz = N - 2;
      clear();
  }
  void add_word(string &s, int idx) {
      int u = 0;
      for(char c: s) {
          if(!to[u].count(c)) to[u][c] = sz++;
          u = to[u][c];
      }
      is_end[u] = 1;
      ind[idx] = u;
  }
  void push_links() {
      queue<int> q;
      int u, v, j;
      char c;
      q.push(0);///root
      link[0] = -1;
      while(!q.empty()) {
          u = q.front();
          q.pop();
          for(auto it: to[u]) {
              v = it.second;
              c = it.first;
              j = link[u];
              while(j != -1 && !to[j].count(c)) j = link[j];
              if(j != -1) link[v] = to[j][c];
              else link[v] = 0;
              q.push(v);
          }
      }
  }
  //go to the state if we add the character ch
  int go(int v, char ch) {
      if (!dp[v].count(ch)) {
          if (to[v].count(ch)) return dp[v][ch] = to[v][ch];
          return dp[v][ch] = (v == 0 ? 0 : go(link[v], ch));
      }
      return dp[v][ch];
  }
}aho;

multiset<int> t[N * 4];
void add(int n, int b, int e, int i, int j, int x) {
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    t[n].insert(x);
    return;
  }
  int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
  add(l, b, mid, i, j, x);
  add(r, mid + 1, e, i, j, x);
}
void del(int n, int b, int e, int i, int j, int x) {
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    t[n].erase(t[n].find(x));
    return;
  }
  int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
  del(l, b, mid, i, j, x);
  del(r, mid + 1, e, i, j, x);
}
int res;
void query(int n, int b, int e, int i) {
  res = max(res, t[n].empty() ? -1 : *(t[n].rbegin()));
  if (b == e) return;
  int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
  if (i <= mid) {
    query(l, b, mid, i);
  }
  else query(r, mid + 1, e, i);
}

int T = 0, st[N], en[N];
vector<int> g[N];
void dfs(int u, int p = -1) {
  st[u] = ++T;
  for (auto v: g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  en[u] = T;
}
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    aho.add_word(s, i);
  }
  aho.push_links();
  for(int i = 1; i < aho.sz; i++) g[aho.link[i]].push_back(i);
  dfs(0);
  for (int i = 1; i <= n; i++) {
    int id = ind[i];
    add(1, 1, T, st[id], en[id], 0);
  }
  while (q--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int i, x; cin >> i >> x;
      int id = ind[i];
      del(1, 1, T, st[id], en[id], a[i]);
      a[i] = x;
      add(1, 1, T, st[id], en[id], a[i]);
    }
    else {
      string s; cin >> s;
      int cur = 0, ans = -1;
      for (auto x: s) {
        cur = aho.go(cur, x);
        res = -1;
        query(1, 1, T, st[cur]);
        ans = max(ans, res);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}