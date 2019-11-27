#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 1e5 + 9;
const int mod = 1e9 + 7;

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

struct BIT {
    modint<mod> dataMul[N],dataAdd[N];
    void init()
    {
        memset(dataMul,0, sizeof dataMul);
        memset(dataAdd,0, sizeof dataAdd);
    }
    void internalUpdate(int at, modint<mod> mul, modint<mod> add) {
        while (at < N) {
            dataMul[at] += mul;
            dataAdd[at] += add;
            at |= (at + 1);
        }
    }
    void update(int left, int right, modint<mod> by) {
        internalUpdate(left, by, -by * (left - 1));
        internalUpdate(right, -by, by * right);
    }
    modint<mod> query(int at) {
        modint<mod> mul = 0;
        modint<mod> add = 0;
        int start = at;
        while (at >= 0) {
            mul += dataMul[at];
            add += dataAdd[at];
            at = (at & (at + 1)) - 1;
        }
        return (mul * start + add);
    }
    modint<mod> query(int l,int r)
    {
        return query(r)-query(l-1);
    }
}up, down;

vector<int> g[N];
int total_chain,T,node[N],pos[N], par[N];
int son[N],chain_head[N],sz[N],dep[N],chain_no[N];
void dfs(int u,int pre)
{
    dep[u]=dep[pre]+1;
    par[u]=pre;
    int mx=-1;
    sz[u]=1;
    for(auto v:g[u]){
        if(v==pre) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>mx) mx=sz[v],son[u]=v;
    }
}
void hld(int u,int pre)
{
    if(chain_head[total_chain]==-1) chain_head[total_chain]=u;
    pos[u]=++T;
    node[T]=u;
    chain_no[u]=total_chain;
    if(son[u]==-1) return;
    hld(son[u],u);
    for(auto v:g[u]){
        if(v==pre||v==son[u]) continue;
        total_chain++;
        hld(v,u);
    }
}
modint<mod> ans, res;
void upd(int l, int r, modint<mod> val, int ty)
{
    if(ty==0){
        ans+=val* down.query(l, r);
        up.update(l, r, val);
    }
    else{
        ans+=val*up.query(l, r);
        down.update(l, r, val);
    }
}
///v is an ancestor of u
int upd_up(int u,modint<mod>val, int ty)
{
    int chain1=chain_no[u];
    int chain2=chain_no[1];
    int chd_u=chain_head[chain1];
    int chd_v=chain_head[chain2];
    while(chd_u!=chd_v){
        upd(pos[chd_u],pos[u],val, ty);///queries should be from low depth node to high depth node
        u=par[chd_u];
        chain1=chain_no[u];
        chd_u=chain_head[chain1];
    }
    upd(pos[1],pos[u],val, ty);
}
vector<int> q[N];
modint<mod> a[N];
int32_t main()
{
    int n=in();
    modint<mod> tot=1;
    for(int i=1; i<=n; i++){
        int l=in(), r=in();
        a[i]=modint<mod>(r-l+1).inv();
        q[l].eb(i);
        q[r+1].eb(-i);
        tot*=(r-l+1);
    }
    for(int i=1; i<n; i++){
        int u=in(), v=in();
        g[u].eb(v);
        g[v].eb(u);
    }
    memset(son, -1, sizeof son);
    memset(chain_head, -1, sizeof chain_head);
    dfs(1,0);
    hld(1,0);
    up.init();
    down.init();
    for(int i=1; i<N; i++){
        for(auto u: q[i]){
            if(u<0){
                u=-u;
                upd_up(u, -a[u], 0);
                upd(1, T, -a[u], 1);
                upd_up(u, a[u], 1);
            }
            else{
                upd_up(u, a[u], 0);
                upd(1, T, a[u], 1);
                upd_up(u, -a[u], 1);
            }
        }
        res+=ans;
    }
    res*=tot;
    printf("%d\n", res);
    return 0;
}
