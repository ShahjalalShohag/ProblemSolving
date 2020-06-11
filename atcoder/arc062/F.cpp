#include<bits/stdc++.h>
using namespace std;

const int N = 205, mod = 1e9 + 7;

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

int dis[N], low[N];
int T, n;
vector<int> g[N];
stack<pair<int, int>>st;
vector<set<pair<int, int>>> e; //biconnected components
void calc_bcc(int u, int v) {
    int i, j, uu, vv, cur;
    pair<int, int> now;
    set<pair<int, int>>se;
    while (!st.empty()) {
        now = st.top();
        st.pop();
        uu = now.first, vv = now.second;
        se.insert({uu, vv});
        if (u == uu && v == vv) break;
        if (u == vv && v == uu) break;
    }
    e.push_back(se);
    return;
}
void bcc(int u, int pre) { 
    dis[u] = low[u] = ++T;
    for(int i = 0 ; i<g[u].size() ; i++) {
        int v = g[u][i];
        if (v == pre) continue;
        if (dis[v] == 0) {
            st.push(make_pair(u, v));
            bcc(v,u);
            low[u] = min(low[u], low[v]);
            if (low[v]>=dis[u]) {
                calc_bcc(u, v);
            }
        } else if (dis[v] < dis[u]) {
            low[u] = min(low[u],dis[v]);
            st.push(make_pair(u, v));
        }

    }
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dis, 0, sizeof dis);
    for(int i = 1; i <= n; i++) if (!dis[i]) bcc(i, -1);
    mint ans = 1;
    for (auto comp: e) {
    	set<int> cur;
    	for (auto edge: comp) {
    		cur.insert(edge.first);
    		cur.insert(edge.second);
    	}
    	int sz = comp.size();
    	if (cur.size() == sz) {
    		// simple cycle
    		mint res = 0;
    		for (int i = 1; i <= sz; i++) {
    			res += mint(k).pow(__gcd(i, sz));
    		}
    		res /= sz;
    		ans *= res;
    	}
    	else ans *= C.ncr(k + sz - 1, sz); // any permutation of colors are considered same
    }
    cout << ans << '\n';
    return 0;
}
