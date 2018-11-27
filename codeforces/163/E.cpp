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
inline void nopenot(){cout<<"YES\n";exit(0);}
inline void nope(){cout<<"NO\n";exit(0);}
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
const int N=1e6+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


///beware! if k distinct patterns are given having sum of length m then size of ending array and oc array will
///be at most m.sqrt(m) ,But for similar patterns one must act with  them differently
struct aho_corasick
{
	bool  is_end[N];
	int link[N];            ///A suffix link for a vertex p is a edge that points to
                            ///the longest proper suffix of
                            ///the string corresponding to the vertex p.
    int psz;                ///tracks node numbers of the trie
	map<char, int> to[N];   ///tracks the next node
	///vi ending[N];           ///ending[i] stores the indexes of patterns which ends
                            ///at node  i(from the trie)
	///vi oc[N];               ///oc[i] stores ending index of all occurrences of pattern[i]
                            ///so real oc[i][j]=oc[i][j]-pattern[i].size()+1,0-indexed
    int cnt[N],path[N],ind[N],len;///for number of occurrences
	void clear()
	{
		for(int i = 0; i < psz; i++)
			is_end[i] = 0,cnt[i]=0,path[i]=0, ind[i]=0,link[i] = 0, to[i].clear();

		psz = 1;
		is_end[0] = 1;
		len=0;
	}

	aho_corasick() { psz = N - 2; clear(); }

	void add_word(string s,int idx)
	{
		int u = 0;
		for(char c: s)
		{
			if(!to[u].count(c)) to[u][c] = psz++;
			u = to[u][c];
		}

		is_end[u] = 1;
		///ending[u].eb(idx);
		ind[idx]=u;
	}

//    void populate(int cur)
//    {
//        /// merging the occurrences of patterns ending  at cur node in  the trie
//        for(auto occ: ending[link[cur]])
//            ending[cur].eb(occ);
//    }

	void push_links()
	{
		queue<int> q;
		int u, v, j;
		char c;

		q.push(0);
		link[0] = -1;

		while(!q.empty())
		{
			u = q.front();
			q.pop();

			for(auto it: to[u])
			{
				v = it.second;
				c = it.first;
				j = link[u];

				while(j != -1 && !to[j].count(c)) j = link[j];
				if(j != -1) link[v] = to[j][c];
				else link[v] = 0;

				q.push(v);
				///populate(v);
				///path[len++]=v;
			}
		}
	}
//    void populate(vi &en, int cur)
//    {
//        /// occurrences of patterns in the given string
//        for(auto idx: en)
//        {
//            oc[idx].eb(cur);
//        }
//    }
	void traverse(string s)
    {
        int n=s.size();
        int cur=0;///root

        for(int i=0;i<n;i++){
            char c=s[i];
            while(cur!=-1 && !to[cur].count(c)) cur=link[cur];
            if(cur!=-1) cur=to[cur][c];
            else cur=0;
            ///populate(ending[cur],i);
            cnt[cur]++;
        }
        for(int i=len-1;i>=0;i--) cnt[link[path[i]]]+=cnt[path[i]];
    }
};

aho_corasick aho;

template <class T>
struct BIT
{
    ///1-indexed
	int sz;
	vector<T> t;

	void init(int n) ///max size of array
	{
		sz = n;
		t.assign(sz,0);
	}

	T query(int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx)) ans += t[idx];
		return ans;
	}

	void upd(int idx, T val)
	{
		if(idx <= 0) return;
		for(; idx <sz; idx += (idx & -idx)) t[idx] += val;
	}

	void upd(int l, int r, T val)
	{
	    upd(l,val);
	    upd(r+1,-val);
	}

	T query(int l, int r) { return query(r) - query(l - 1); }
};


vi g[N];
int st[N],en[N],T=0;
void dfs(int u)
{
    st[u]=++T;
    for(auto v:g[u]) dfs(v);
    en[u]=T;
}
bool has[N];
int main()
{
	BeatMeScanf;
	int i,j,k,n,m,q;
	string s;
	cin>>q>>n;
	for(i=1;i<=n;i++){
        cin>>s;
        aho.add_word(s,i);
	}
    aho.push_links();
    for(i=1;i<aho.psz;i++) g[aho.link[i]].eb(i);
    dfs(0);
    BIT<int>t;
    t.init(N);
    for(i=1;i<=n;i++){
        int p=aho.ind[i];
        t.upd(st[p],en[p],1);
        has[i]=1;
    }
    while(q--){
        cin>>s;
        if(s[0]=='?'){
            ll ans=0;
            int cur=0;
            for(i=1;i<s.size();i++){
                char c=s[i];
                while(cur!=-1 && !aho.to[cur].count(c)) cur=aho.link[cur];
                if(cur!=-1) cur=aho.to[cur][c];
                else cur=0;
                ans+=1LL*t.query(st[cur]);
            }
            cout<<ans<<nl;
        }
        else{
            int x=0;
            for(i=1;i<s.size();i++) x=x*10+(s[i]-'0');
            if(s[0]=='+'){
                if(has[x]) continue;
                has[x]=1;
                int p=aho.ind[x];
                t.upd(st[p],en[p],1);
            }
            else{
                if(!has[x]) continue;
                has[x]=0;
                int p=aho.ind[x];
                t.upd(st[p],en[p],-1);
            }
        }
    }
	return 0;
}
