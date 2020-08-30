#include<bits/stdc++.h>
using namespace std;

const int N = 5005, mod = 1e9 + 7;
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

vector<int> g[N];
mint dp[N][N];
int sz[N];
void dfs(int u, int p = 0) {
	sz[u] = 1;
	for (auto v: g[u]) {
		if (v ^ p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
	    int u, v; cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	int u = 1;
	dfs(u);
	while (1) {
		int tmp = -1;
		for (auto v: g[u]) {
			if (sz[v] > sz[u]) continue;
			if (2 * sz[v] >= n) tmp = v;
		}
		if (tmp == -1) break;
		u = tmp;
	}
	dfs(u);
	vector<int> a;
	a.push_back(0);
	for (auto v: g[u]) {
		if (2 * sz[v] == n) {
			cout << C.fact(n / 2) * C.fact(n / 2) << '\n';
			return 0;
		}
		a.push_back(sz[v]);
	}
	dp[0][0] = 1;
	int p = a.size();
	for (int i = 1; i < p; i++) {
		for (int k = 0; k <= n; k++) {
			if (dp[i - 1][k] == 0) continue;
			for (int z = 0; z <= a[i]; z++) {
				dp[i][k + z] += dp[i - 1][k] * C.ncr(a[i], z) * C.ncr(a[i], z) * C.fact(z);
			}
		}
	}
	mint ans = 0;
	for (int k = 0; k <= n; k++) {
		ans += dp[p - 1][k] * C.fact(n - k) * (k & 1 ? -1 : 1);
	}
	cout << ans << '\n';
    return 0;
}