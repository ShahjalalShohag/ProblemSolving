#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;

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

mint C[6][6], pw[6][N];
///1-indexed
template<typename T>
struct segtree {
    #define lc (n<<1)
    #define rc ((n<<1)|1)
    vector<T>t[6];
    vector<int> lazy,a;
    int x;
    segtree() {}
    segtree(int n)
    {
        x=n;
        for(int i = 0; i <= 5; i++) t[i].assign(4*n,mint(0));                    ///initialization
        lazy.assign(4*n, - 1);
        a.assign(n+1,0);
    }
    void push(int n, int b, int e) {
        if (lazy[n]== - 1) return;
        for(int k = 0; k <= 5; k++) t[k][n] = (pw[k][e] - pw[k][b - 1]) * lazy[n];            ///process the operation here
        if (b!=e){
            lazy[lc]=lazy[n];          ///carry the lazy to the lower nodes
            lazy[rc]=lazy[n];
        }
        lazy[n] = -1;
    }
    void pull(int n) {
        for(int k = 0; k <= 5; k++) t[k][n] = t[k][lc]+t[k][rc];                     ///merge lower nodes of the tree to get the parent node
    }
    void build(int n,int b,int e)
    {
        if(b>e) return;
        if(b==e){
            for(int k = 0; k <= 5; k++) t[k][n]= (pw[k][b] - pw[k][b - 1]) * a[b-1];
            return;
        }
        int mid=(b+e)>>1;
        build(lc,b,mid);
        build(rc,mid+1,e);
        pull(n);
    }
    void upd(int n,int b,int e,int i,int j,int v)
    {
        push(n,b,e);
        if (j<b||e<i) return;
        if (i<=b&&e<=j) {
            lazy[n]=v;
            push(n,b,e);
            return;
        }
        int mid=(b+e)>>1;
        upd(lc,b,mid,i,j,v);
        upd(rc,mid+1,e,i,j,v);
        pull(n);
    }
    mint sum[6];
    void query(int n,int b,int e,int i,int j)
    {
        push(n,b,e);
        if(i>e||b>j) return;                 ///return null type
        if(i<=b&&e<=j){
            for(int k = 0; k <= 5; k++) sum[k] += t[k][n];
            return;
        }
        int mid=(b+e)>>1;
        query(lc,b,mid,i,j);
        query(rc,mid+1,e,i,j);
    }
    void build(vector<int>& v)                    ///normally vector a is 0 based but tree is formed 1-based
    {
        a=v;
        build(1,1,x);
    }
    void upd(int i,int j,int v)
    {
        upd(1,1,x,i,j,v);
    }
    T query(int i,int j, int k)
    {
        for(int k = 0; k < 6; k++) sum[k] = 0;
        query(1,1,x,i,j);
        mint y = mint(1) - i;
        mint ans = 0;
        for(int j = 0; j <= k; j++){
            ans += C[k][j] * (y.pow(j)) * sum[k - j];
        }
        return ans;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 6; i++) C[i][0] = 1;
    for(int i = 1; i < 6; i++) for(int j = 1; j < 6; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    for(int k = 0; k <= 5; k++){
        for(int i = 0; i < N; i++){
            pw[k][i] = mint(i).pow(k);
            if(i) pw[k][i] += pw[k][i - 1];
        }
    }
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    segtree<mint> t(n);
    t.build(a);
    while(q--){
        char ch; int l, r, k; cin >> ch >> l >> r >> k;
        if(ch == '='){
            t.upd(l, r, k);
        }
        else cout << t.query(l, r, k) << '\n';
    }
    return 0;
}
