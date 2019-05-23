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
ll gc(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lc(ll a,ll b){return a/gc(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

///Zero Indexed
///F=(x_0 or y_0) and (x_1 or y_1) and ... (x_{vars-1} or y_{vars-1})
///here y_i belongs to x_i
///is there any assignment of x_i such that F=true
///for (x_0 xor y_0) and (x_1 xor y_1)...
///replace (x_i xor y_i) by (x_i or y_i) and (not x_i or not y_i)
struct twosat {
	int n;	/// total size combining +, -. must be even.
	vector< vector<int> > g, gt;	/// graph, transpose graph
	vector<bool> vis, res;	/// visited and resulting assignment
	vector<int> comp;	/// component number
	stack<int> ts;	/// topsort

	twosat(int vars=0) {
		n = (vars << 1);
		g.resize(n);
		gt.resize(n);
	}

	/// zero indexed, be careful
	/// (x_a or (not x_b))-> af=1,bf=0
	void add(int a, bool af, int b, bool bf) {
		a += a+(af^1);
		b += b+(bf^1);
		g[a^1].push_back(b);	/// !a => b
		g[b^1].push_back(a);	/// !b => a
		gt[b].push_back(a^1);
		gt[a].push_back(b^1);
	}

	void dfs1(int u) {
		vis[u] = true;
		for(int v : g[u]) if(!vis[v]) dfs1(v);
		ts.push(u);
	}

	void dfs2(int u, int c) {
		comp[u] = c;
		for(int v : gt[u]) if(comp[v] == -1) dfs2(v, c);
	}
	bool ok() {
		vis.resize(n, false);
		for(int i=0; i<n; ++i) if(!vis[i]) dfs1(i);

		int scc = 0;
		comp.resize(n, -1);
		while(!ts.empty()) {
			int u = ts.top();
			ts.pop();
			if(comp[u] == -1) dfs2(u, scc++);
		}

		res.resize(n/2);
		for(int i=0; i<n; i+=2) {
			if(comp[i] == comp[i+1]) return false;
			res[i/2] = (comp[i] > comp[i+1]);
		}
		return true;
	}
};

int p[N];
map<int, int> pos;
int main() {
	BeatMeScanf;
	int i,j,k,n,m,a,b,u,v;
	cin>>n>>m;
	twosat ts(n);
	for(i=0;i<m;i++){
        cin>>u>>v>>k;
        --u;
        --v;
        if(k) ts.add(u,0,v,1),ts.add(u,1,v,0);
        else ts.add(u,1,v,1),ts.add(u,0,v,0);
	}
	k=ts.ok();
	if(!k) cout<<"Impossible\n";
	else{
        vi v;
        for(i=0;i<n;i++) if(ts.res[i]) v.eb(i);
        cout<<sz(v)<<nl;
        for(auto x:v) cout<<x+1<<' ';
        cout<<nl;
	}
	return 0;
}
