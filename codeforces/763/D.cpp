#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, mod = 1e9 + 97;
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
const mint P = 998244353, Q = 1e9 + 33 , R = 99999989;
mint dp[N];
vector<int> g[N];
void dfs1(int u, int pre = 0)
{
    dp[u] = 0;
    for(auto v: g[u]) if(v != pre){
        dfs1(v, u);
        dp[u] += P.pow(dp[v].value);
    }
    dp[u] = dp[u] * Q + R;
}
mint up[N], rp[N];
void dfs2(int u, int pre = 0)
{
    mint sum = 0;
    if(pre) sum += P.pow(up[u].value);
    for(auto v: g[u]) if(v != pre){
        sum += P.pow(dp[v].value);
    }
    rp[u] = sum * Q + R;
    for(auto v: g[u]) if(v != pre){
        up[v] = sum - P.pow(dp[v].value);
        up[v] = up[v] * Q + R;
        dfs2(v, u);
    }
}
map<mint, int> mp;
inline void add(mint x)
{
    mp[x]++;
}
inline void del(mint x)
{
    auto it = mp.find(x);
    if(it != mp.end()){
        (*it).second --;
        if((*it).second == 0) mp.erase(it);
    }
}
int ans, id;
void dfs3(int u, int pre = 0)
{
    del(dp[u]); if(pre) del(rp[pre]);
    if(pre) add(up[u]); add(rp[u]);
    if((int)mp.size() > ans) ans = mp.size(), id = u;
    for(auto v: g[u]) if(v != pre){
        dfs3(v, u);
    }
    add(dp[u]); if(pre) add(rp[pre]);
    if(pre) del(up[u]); del(rp[u]);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1);
    dfs2(1);
    for(int i = 1; i <= n; i++) mp[dp[i]]++;
    ans = -1;
    dfs3(1);
    cout << id << '\n';
    return 0;
}
