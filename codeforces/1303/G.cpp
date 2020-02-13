#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 1.5e5 + 9;
const int mod = 1e9 + 7;
/// Keeps upper hull for maximums.
/// add lines with -m and -b and return -ans to
/// make this code working for minimums.(not -x)
const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
///Dynamic Convex Hull Trick
struct CHT : public multiset<line> { /// will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return 1.0*(x->b - y->b)*(z->m - y->m) >= 1.0*(y->b - z->b)*(y->m - x->m);
    }
    void add(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll query(ll x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
}*cht;
vector<int> g[N];
int cenpar[N],sz[N],subtree_sz,dep[N], a[N];
bool done[N];
void dfs(int u,int pre)
{
    dep[u]=dep[pre]+1;
    for(auto v:g[u]){
        if(v==pre) continue;
        dfs(v,u);
    }
}
void set_subtree_size(int u,int pre)
{
    subtree_sz++;
    sz[u]=1;
    for(auto v:g[u]){
        if(v==pre||done[v]) continue;
        set_subtree_size(v,u);
        sz[u]+=sz[v];
    }
}
int get_centroid(int u,int pre)
{
    for(auto v:g[u]){
        if(v==pre||done[v]) continue;
        else if(sz[v]>subtree_sz/2) return get_centroid(v,u);
    }
    return u;
}

ll nsum[N], isum[N], ans;
void add(int u, int pre, ll s, int dep)
{
    s += a[u];
    isum[u] = 1LL * a[u] * dep + isum[pre];
    ans = max(ans, isum[u]);
    cht -> add(s, isum[u]);
    for(auto v: g[u]){
        if(v == pre || done[v]) continue;
        add(v, u, s, dep + 1);
    }
}
int nw;
void yo(int u, int pre, ll s, int dep)
{
    s += a[u];
    nsum[u] = nsum[pre] + s;
    ans = max(ans, nsum[u]);
    ans = max(ans, nsum[u] + cht -> query(dep));
    for(auto v: g[u]){
        if(v == pre || done[v]) continue;
        yo(v, u, s, dep + 1);
        if(u == nw) add(v, u, 0, 1);
    }
}
void decompose(int u,int pre)
{
    subtree_sz=0;
    set_subtree_size(u,pre);
    int cen=get_centroid(u,pre);
    cenpar[cen]=pre;
    done[cen]=1;
    nw = cen;
    cht = new CHT();
    cht -> add(0, 0);
    nsum[0] = nsum[cen] = 0;
    isum[0] = isum[cen] = 0;
    yo(cen, 0, 0, 1);
    cht = new CHT();
    cht -> add(0, 0);
    nsum[0] = nsum[cen] = 0;
    isum[0] = isum[cen] = 0;
    reverse(g[cen].begin(), g[cen].end());
    yo(cen, 0, 0, 1);
    for(auto v:g[cen]){
        if(v==pre||done[v]) continue;
        decompose(v,cen);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    int n ; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0);
    decompose(1, 0);
    cout << ans << nl;
    return 0;
}
