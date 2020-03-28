#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, mod = 1e9 + 7;

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
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

struct combi{
	int N;
	vector<mint>facts,finvs,invs;
	combi(int n):N(n),facts(n),finvs(n),invs(n){
		facts[0]=finvs[0]=1;
		for(int i=1;i<N;i++){
			facts[i]=facts[i-1]*i;
			invs[i]=mint(i).inv();
			finvs[i]=finvs[i-1]*invs[i];
		}
	}
	inline mint fact(int n){return facts[n];}
	inline mint finv(int n){return finvs[n];}
	inline mint inv(int n){return invs[n];}
	inline mint ncr(int n,int k){return facts[n]*finvs[k]*finvs[n-k];}
};
combi C(N);

vector<int> g[N];
int sz[N];
void dum(int u, int pre = 0)
{
    sz[u] = 1;
    for(auto v: g[u]){
        if(v == pre) continue;
        dum(v, u);
        sz[u] += sz[v];
    }
}

mint dp[N], pdp[N], mul[N], ans[N], up[N];
void dfs(int u, int pre = 0)
{
    dp[u] = C.fact(sz[u] - 1); pdp[u] = 1;
    mul[u] = 1;
    for(auto v: g[u]){
        if(v == pre) continue;
        dfs(v, u);
        dp[u] *= dp[v]; mul[u] *= C.fact(sz[v]);
        pdp[u] *= dp[v];
    }
    dp[u] *= mul[u].inv();
}
int n, usz[N];
void yo(int u, int pre = 0)
{
    ans[u] = C.fact(n - 1) * pdp[u] * up[u] * mul[u].inv() * C.fact(usz[u]).inv();
    for(auto v: g[u]){
        if(v == pre) continue;
        up[v] = C.fact(n - sz[v] - 1) * pdp[u] * dp[v].inv() * mul[u].inv() * C.fact(sz[v]) * up[u] * C.fact(usz[u]).inv();
        usz[v] = n - sz[v];
        yo(v, u);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dum(1);
    dfs(1);
    up[1] = 1;
    yo(1);
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}
