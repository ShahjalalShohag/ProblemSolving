#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fbo find_by_order
#define ook order_of_key
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define sz(v) (int)v.size()
#define pf printf
#define sf scanf
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%I64d %I64d\n",a,b)
#define pf3ll(a,b,c)          printf("%I64d %I64d %I64d\n",a,b,c)
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 rnd(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+7;
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

using F = ll; using W = ll; /// types for flow and weight/cost
struct S{
	const int v;			/// neighbour
	const int r;	/// index of the reverse edge
	F f;			/// current flow
	const F cap;	/// capacity
	const W cost;	/// unit cost
	S(int v, int ri, F c, W cost = 0) :
		v(v), r(ri), f(0), cap(c), cost(cost) {}
	inline F res() const { return cap - f; }
};
struct FlowGraph : vector<vector<S>> {
	FlowGraph(size_t n) : vector<vector<S>>(n) {}
	void add_arc(int u, int v, F c, W cost = 0){ auto &t = *this;
		t[u].emplace_back(v, t[v].size(), c, cost);
		t[v].emplace_back(u, t[u].size()-1, 0, -cost);
	}
	void add_edge(int u, int v, F c, W cost = 0) { auto &t = *this;
		t[u].emplace_back(v, t[v].size(), c, cost);
		t[v].emplace_back(u, t[u].size()-1, c, -cost);
	}
	void clear() { for (auto &ed : *this) for (auto &e : ed) e.f = 0LL; }
};

///0-indexed
struct Dinic{
	FlowGraph &edges; int V,s,t;
	vi l; vector<vector<S>::iterator> its; // levels and iterators
	Dinic(FlowGraph &edges, int s, int t) :
		edges(edges), V(edges.size()), s(s), t(t), l(V,-1), its(V) {}
	ll augment(int u, F c) { // we reuse the same iterators
		if (u == t) return c;
		for(auto &i = its[u]; i != edges[u].end(); i++){
			auto &e = *i;
			if (e.cap > e.f && l[u] < l[e.v]) {
				auto d = augment(e.v, min(c, e.cap - e.f));
				if (d > 0) { e.f += d; edges[e.v][e.r].f -= d; return d; }
			}	}
		return 0;
	}
	ll run() {
		ll flow = 0, f;
		while(true) {
			fill(l.begin(), l.end(),-1); l[s]=0; // recalculate the layers
			queue<int> q; q.push(s);
			while(!q.empty()){
				auto u = q.front(); q.pop();
				for(auto &&e : edges[u]) if(e.cap > e.f && l[e.v]<0)
					l[e.v] = l[u]+1, q.push(e.v);
			}
			if (l[t] < 0) return flow;
			for (int u = 0; u < V; ++u) its[u] = edges[u].begin();
			while ((f = augment(s, 2e9)) > 0) flow += f;///take care of inf
		}
    }
};

///For a given weighted graph the Gomory-Hu tree has the following properties:
///The vertex set of the tree and the graph is the same.
///The maximum flow between vertices u and v in the tree(i.e. minimum edge from u to v)
///is equal to the maximum flow in the graph.
///0-indexed
///O(n*maxflow+n^2)
struct edge { int u, v; ll w; };
struct GomoryHuTree {
	int V;
	vi p, w, c;
	vector<edge> tree;
	void dfs(int u, const FlowGraph &fg) {
		c[u] = 1;
		for (const auto &e : fg[u])
			if (!c[e.v] && e.res())
				dfs(e.v, fg);
	}
	GomoryHuTree(int n, const vector<edge> &ed) : V(n), p(V), w(V), c(V) {
		FlowGraph fg(V);
		for (const edge &e : ed) fg.add_edge(e.u, e.v, e.w);
		p[0] = -1, std::fill(p.begin() + 1, p.end(), 0);
		for (int i = 1; i < V; ++i) {
			w[i] = Dinic(fg, i, p[i]).run();
			std::fill(c.begin(), c.end(), 0);
			dfs(i, fg);
			for (int j = i+1; j < V; ++j)
				if (c[j] && p[j] == p[i]) p[j] = i;
			if (p[p[i]] >= 0 && c[p[p[i]]]) { // Is this needed? :-)))))
				int pi = p[i];
				swap(w[i], w[pi]);
				p[i] = p[pi];
				p[pi] = i;
			}
			fg.clear();
		}
	}
	const vector<edge> &get_tree() {
		if (tree.empty())
			for (int i = 0; i < V; ++i) {
				if (p[i] >= 0)
					tree.push_back(edge{i, (int)p[i], w[i]});
			}
		return tree;
	}
};

struct dsu {
	vi par, rank, size; int c;
	dsu(int n) : par(n), rank(n,0), size(n,1), c(n) {
		for (int i = 0; i < n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1; else --c;
		if (rank[i] > rank[j]) swap(i, j);
		par[i] = j; size[j] += size[i];
		if (rank[i] == rank[j]) rank[j]++;
		return j;
	}
};

int32_t main()
{
    BeatMeScanf;
    int i,j,k,n,m;
	cin >> n >> m;

	vector<edge> ed(m);
	for (edge &e : ed) cin >> e.u >> e.v >> e.w, --e.u, --e.v;

	GomoryHuTree gt(n, ed);
	vector<edge> t = gt.get_tree();

	sort(t.begin(), t.end(), [](const edge &l, const edge &r) {
		return l.w > r.w;
	});

	dsu d(n);
	vector<vi> perm(n);
	ll ans = 0LL;
	for (int i = 0; i < n; ++i) perm[i].push_back(i);
	for (const auto &e : t) {
		int l = d.find(e.u), r = d.find(e.v);
		if (l != d.merge(l, r)) swap(l, r);
		ans += e.w;
		for (int j : perm[r]) perm[l].push_back(j);
		perm[r].clear();
	}

	cout << ans << endl;
	for (int i = 0; i < n; ++i)
		cout << perm[d.find(0)][i]+1 << " \n"[i+1==n];
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

