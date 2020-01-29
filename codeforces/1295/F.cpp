#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 205;
const int mod = 998244353;

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

bool vis2[N][N];
mint dp2[N][N];
mint ncr(int n, int k, int pos)
{
    if(k > n) return 0;
    if(vis2[pos][k]) return dp2[pos][k];
    vis2[pos][k] = 1;
    mint ans = 1;
    for(int dwn = 1, up = n; dwn <= k; dwn++, up--) ans *= up, ans /= dwn;
    return dp2[pos][k] = ans;
}
bool vis[N][N];
mint dp[N][N];
int n, m, l[N], r[N];
vector<pii> seg;
mint yo(int i, int j)
{
    if(i == n) return 1;
    if(j == m) return 0;
    if(vis[i][j]) return dp[i][j];
    vis[i][j] = 1;
    mint ans = yo(i, j + 1);
    int L = seg[j].first, R = seg[j].second;
    for(int k = i; k < n; k++){
        if(l[k] <= L && R <= r[k]){
            ans += ncr(R - L + 1 + k - i, k - i + 1, j) * yo(k + 1, j + 1);
        }
        else break;
    }
    dp[i][j] = ans;
    return ans;
}
int32_t main()
{
    n = in();
    vector<int> v;
    for(int i = 0; i < n; i++){
        l[i] = in(), r[i] = in();
        v.eb(l[i]) , v.eb(r[i]);
    }
    reverse(l, l + n); reverse(r, r + n);
    sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); ++i){
        seg.eb(v[i], v[i]);
        if(i + 1 < v.size() && v[i] + 1 < v[i + 1]) seg.eb(v[i] + 1, v[i + 1] - 1);
    }
    m = seg.size();
    mint ans = yo(0, 0);
    for(int i = 0; i < n; i++) ans /= r[i] - l[i] + 1;
    cout << ans << nl;
    return 0;
}
