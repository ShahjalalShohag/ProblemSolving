#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 998244353, P = 37;
template <const int32_t MOD>
struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
  inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
  inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
  inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
  inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
  modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
  inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
  inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
  inline bool operator == (modint<MOD> other) const { return value == other.value; }
  inline bool operator != (modint<MOD> other) const { return value != other.value; }
  inline bool operator < (modint<MOD> other) const { return value < other.value; }
  inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

int par[N][20], dep[N];
char a[N];
mint h[N], pw[N];
int Kth(int u, int k) {
  for (int i = 0; i < 20; i++) {
    if (k >> i & 1) {
      u = par[u][i];
    }
  }
  return u;
}
void add_edge(int u, int p, char c) { // p --c--> u
  a[u] = c;
  dep[u] = dep[p] + 1;
  par[u][0] = p;
  h[u] = h[p] * P + c;
  for (int i = 1; i < 20; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
}
mint get_hash(int u, int v) { // v is a parent of u
  return h[u] - h[v] * pw[dep[u] - dep[v]];
}
bool cmp(int u, int v) { // string from u to 1 < string from v to 1 ?
  int d = min(dep[u], dep[v]);
  if (get_hash(u, Kth(u, d)) == get_hash(v, Kth(v, d))) {
    return dep[u] < dep[v];
  }
  int l = 1, r = d, cur = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (get_hash(u, Kth(u, mid)) == get_hash(v, Kth(v, mid))) {
      l = mid + 1;
      cur = mid;
    }
    else {
      r = mid - 1;
    }
  }
  return a[Kth(u, cur)] < a[Kth(v, cur)];
}
int best[N];
int ans[N];
string p[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = pw[i - 1] * P;
  }
  string s; cin >> s;
  int n = s.size();
  s += '.';
  int T = 1;
  best[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == s[i + 1]) {
      best[i] = ++T;
      add_edge(T, best[i + 1], s[i]);      
      if (cmp(best[i + 2], best[i])) {
        best[i] = best[i + 2];
      }
    }
    else {
      best[i] = ++T;
      add_edge(T, best[i + 1], s[i]);
    }
    int cur = best[i];
    ans[i] = dep[cur];
    p[i] = "";
    if (ans[i] > 10) {
      for (int k = 0; k < 5; k++) {
        p[i] += a[Kth(cur, k)];
      }
      p[i] += "...";
      for (int k = dep[cur] - 2; k < dep[cur]; k++) {
        p[i] += a[Kth(cur, k)];
      }
    }
    else {
      for (int k = 0; k < dep[cur]; k++) {
        p[i] += a[Kth(cur, k)];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ' << p[i] << '\n';
  }
  return 0;
}