#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 998244353;

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

struct Combi{
  int n; vector<mint> facts, finvs, invs;
  Combi(int _n): n(_n), facts(_n), finvs(_n), invs(_n){
    facts[0] = finvs[0] = 1;
    invs[1] = 1;
      for (int i = 2; i < n; i++) invs[i] =  invs[mod % i] * (-mod / i);
    for(int i = 1; i < n; i++){
      facts[i] = facts[i - 1] * i;
      finvs[i] = finvs[i - 1] * invs[i];
    }
  }
  inline mint fact(int n) { return facts[n]; }
  inline mint finv(int n) { return finvs[n]; }
  inline mint inv(int n) { return invs[n]; }
  inline mint ncr(int n, int k) { return n < k ? 0 : facts[n] * finvs[k] * finvs[n-k]; }
};
Combi C(N);

int mob[N];
void mobius() {
    for(int i = 1; i < N; i++) mob[i] = 3;
    mob[1] = 1;
    for (int i = 2; i < N; i++) {
        if (mob[i] == 3) {
            mob[i] = -1;
            for (int j = 2 * i; j < N; j += i) mob[j] = mob[j] == 3 ? -1 : mob[j] * (-1);
            if(i <= (N - 1) / i) {
              for (int j = i * i; j < N; j += i * i) mob[j] = 0;
            }
        }
    }
}
mint f(long long n) {
  return mint(2).pow(n - 1) * (n % mod);
}
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mobius();
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, k; cin >> x >> k;
    a[x] += k;
  }
  mint ans = 0;
  for (int i = 1; i < N; i++) {
    if (mob[i] == 0) continue;
    long long tot = 0;
    mint cur = 0, sum = 0, sq = 0;
    for (int j = i; j < N; j += i) {
      tot += a[j];
      sq += mint(j) * j * a[j];
      sum += mint(j) * a[j];
    }
    sum *= sum;
    sum -= sq;
    if (tot > 1) {
      mint nw = f(tot - 2) + (mint(2).pow(tot - 2));
      cur += nw * sum;
    }  
    if (tot) {
      mint nw = f(tot - 1);
      cur += nw * sq;
    }
    ans += cur * mob[i];
  }
  cout << ans << '\n';
  return 0;
}