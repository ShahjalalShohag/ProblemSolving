#include<bits/stdc++.h>
using namespace std;

const int N = 305, mod = 1e9 + 7;

template <int32_t MOD>
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
    modint<MOD> pow(uint64_t k) const {
        modint<MOD> x = *this, y = 1;
        for (; k; k >>= 1) {
            if (k & 1) y *= x;
            x *= x;
        }
        return y;
    }
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
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

int d[N], n;
mint dp[2][N][N * 2];
mint f[N];
int32_t main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
   	f[0] = 1; for (int i = 1; i < N; i++) f[i] = f[i - 1] * i;
    int ok = 1;
	for (int i = 1; i <= n; i++) ok &= d[i] == 2;
	if (ok) {
		cout << f[n - 1] / 2 << '\n';
		return 0;
	}
	dp[(n + 1) & 1][0][0] = 1;
	for (int i = n; i >= 1; i--) {
		for (int k = 0; k <= n; k++) {
			for (int sum = 0; sum <= 2 * n; sum++) {
				mint ans = dp[(i + 1) & 1][k][sum];
				if (k && d[i] > 1 && sum >= d[i] - 2) ans += dp[(i + 1) & 1][k - 1][sum - d[i] + 2] * (d[i] - 1);
				dp[i & 1][k][sum] = ans;
			}
		}
	}
   	mint ans = 0;
   	for (int k = 3; k <= n; k++) {
   		for (int sum = 0; sum <= 2 * n; sum++) {
   			mint mul = dp[1][k][sum];
   			ans += sum * f[k - 1] * mul * f[n - k - 1];
   		}
   	}
   	ans /= 2; for (int i = 1; i <= n; i++) ans /= f[d[i] - 1];
   	cout << ans << '\n';
    return 0;
}