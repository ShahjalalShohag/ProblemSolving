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
#define inf 1e18
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
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
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 random(rd());
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
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


struct edge
{
	int to, rev, flow, w;
};

struct dinic
{
	int d[N], done[N], s, t;
	const int INF=2e9;
	vector<edge> g[N];
	/// N equals to node_number

	void addedge(int u, int v, int w)
	{
		edge a={v,(int)g[v].size(),0,w};
		edge b={u,(int)g[u].size(),0,0};

		/// If the graph has bidirectional edges
		/// Capacity for the edge b will equal to w
		/// For directed, it is 0

		g[u].emplace_back(a);
		g[v].emplace_back(b);
	}

	bool bfs()
	{
		mem(d,-1);
		d[s]=0;
		queue<int>q;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto &e: g[u])
			{
				int v=e.to;
				if(d[v]==-1 && e.flow<e.w)
				{
					d[v]=d[u]+1;
					q.push(v);
				}
			}
		}
		return d[t]!=-1;
	}

	int dfs(int u, int flow)
	{
		if(u==t) return flow;
		for(int &i=done[u]; i<(int)g[u].size(); i++)
		{
			edge &e=g[u][i];
			if(e.w<=e.flow) continue;
			int v=e.to;
			if(d[v]==d[u]+1)
			{
				int nw=dfs(v,min(flow,e.w-e.flow));
				if(nw>0)
				{
					e.flow+=nw;
					g[v][e.rev].flow-=nw;
					return nw;
				}
			}
		}
		return 0;
	}

	int max_flow(int _s, int _t)
	{
		s=_s;
		t=_t;
		int flow=0;
		while(bfs())
		{
			mem(done,0);
			while(int nw=dfs(s,INF)) flow+=nw;
		}
		return flow;
	}
};
dinic flow;


int occur[210],a[210];
vector<int>fac[210],primes;

bool ck[N];
void sieve()
{
    for(int i=3;i*i<N;i+=2){
        if(!ck[i]) for(int j=i*i;j<N;j+=2*i) ck[j]=1;
    }
    primes.eb(2);
    for(int i=3;i<N;i+=2) if(!ck[i]) primes.eb(i);
}

int main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    sieve();
    int idx = 1,ans = 0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        occur[i] = idx;
        for(int j = 0;j<primes.size();j++){
            while(a[i] % primes[j] == 0){
                a[i]/=primes[j];
                fac[i].push_back(primes[j]);
                idx++;
            }
        }
        if(a[i] > 1){
            fac[i].push_back(a[i]);
            idx++;
        }
    }
    occur[n + 1] = idx;
    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        for(int j = 0;j<fac[a].size();j++){
            int f = fac[a][j];
            for(int k = 0;k<fac[b].size();k++){
                int num = fac[b][k];
                if(f == num){
                    if(a % 2 == 1){
                        flow.addedge(occur[a] + j,occur[b] + k,1);
                    }
                    else {
                        flow.addedge(occur[b] + k,occur[a] + j,1);
                    }
                }
            }
        }
    }
    for(int i = 1;i<=n;i+=2){
        int st = occur[i];
        int ed = occur[i + 1];
        for(int j = st;j < ed; j++){
            flow.addedge(0,j,1);
        }
    }
    for(int i = 2;i<=n;i+=2){
        int st = occur[i];
        int ed = occur[i + 1];
        for(int j = st;j < ed; j++){
            flow.addedge(j,idx,1);
        }
    }
    ans = flow.max_flow(0,idx);
    cout << ans;
}
