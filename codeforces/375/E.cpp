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
const int N=510;
const ld eps=1e-9;
const ld PI=acos(-1.0);
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

ll n,k,a[N],dis[N][N];
vector <ll> g[N],cost[N];
bool ok[N][N];

void dfs(ll u,ll p,ll d,ll cur)
{
	dis[cur][u] = d;
	ll len = sz(g[u]), i;
	for(int i=0;i<len;i++)
	{
		ll v = g[u][i];
		if(v == p )continue;
		dfs(v,u,d+cost[u][i],cur);
	}
}

#define MAXC 1010
#define MAXV 1010
#define EPS 1e-13

#define MINIMIZE -1
#define MAXIMIZE +1
#define LESSEQ -1
#define EQUAL 0
#define GREATEQ 1
#define INFEASIBLE -1
#define UNBOUNDED 666

/***
1.  Simplex Algorithm for Linear Programming
2.  Maximize or minimize f0*x0 + f1*x1 + f2*x2 + ... + fn-1*xn-1 subject to some constraints
3.  Constraints are of the form, c0x0 + c1x1 + c2x2 + ... + cn-1xn-1 (<= or >= or =) lim
4.  m is the number of constraints indexed from 1 to m, and n is the number of variables indexed from 0 to n-1
5.  ar[0] contains the objective function f, and ar[1] to ar[m] contains the constraints, ar[i][n] = lim_i
6.  It is assumed that all variables satisfies non-negativity constraint, i.e, xi >= 0
7.  If non-negativity constraint is not desired for a variable x, replace each occurrence
    by difference of two new variables r1 and r2 (where r1 >= 0 and r2 >= 0, handled automatically by simplex).
    That is, replace every x by r1 - r2 (Number of variables increases by one, -x, +r1, +r2)
8.  solution_flag = INFEASIBLE if no solution is possible and UNBOUNDED if no finite solution is possible
9.  Returns the maximum/minimum value of the linear equation satisfying all constraints otherwise
10. After successful completion, val[] contains the values of x0, x1 .... xn for the optimal value returned

*** If ABS(X) <= M in constraints, Replace with X <= M and -X <= M

*** Fractional LP:
    max/min
        3x1 + 2x2 + 4x3 + 6
        -------------------
        3x1 + 3x2 + 2x3 + 5

        constraint:
        2x1 + 3x2 + 5x3 ≥ 23
        3x2 + 5x2 + 4x3 <= 30
        x1, x2, x3 ≥ 0

    Replace with:
    max/min
        3y1 + 2y2 + 4y3 + 6t

        constraint:
        3y1 + 3y2 + 2y3 + 5t = 1
        2y1 + 3y2 + 53 - 23t ≥ 0
        3y1 + 5y2 + 4y3- 30t <= 0
        y1, y2, y3, t ≥ 0
***/

///Complexity: O(n^3) or faster
namespace lp
{
    long double val[MAXV], ar[MAXC][MAXV];
    int m, n, solution_flag, minmax_flag, basis[MAXC], index[MAXV];

    /// nvars = number of variables, f = objective function, flag = MINIMIZE or MAXIMIZE
    inline void init(int nvars, long double f[], int flag){
        solution_flag = 0;
        ar[0][nvars] = 0.0;
        m = 0, n = nvars, minmax_flag = flag;
        for (int i = 0; i < n; i++){
            ar[0][i] = f[i] * minmax_flag; /// Negating sign of objective function when minimizing
        }
    }

    /// C[] = co-efficients of the constraints (LHS), lim = limit in RHS
    /// cmp = EQUAL for C[] = lim, LESSEQ for C[] <= lim, GREATEQ for C[] >= lim
    inline void add_constraint(long double C[], long double lim, int cmp){
        m++, cmp *= -1;
        if (cmp == 0){
            for (int i = 0; i < n; i++) ar[m][i] = C[i];
            ar[m++][n] = lim;
            for (int i = 0; i < n; i++) ar[m][i] = -C[i];
            ar[m][n] = -lim;
        }
        else{
            for (int i = 0; i < n; i++) ar[m][i] = C[i] * cmp;
            ar[m][n] = lim * cmp;
        }
    }

    inline void init(){ /// Initialization
        for (int i = 0; i <= m; i++) basis[i] = -i;
        for (int j = 0; j <= n; j++){
            ar[0][j] = -ar[0][j], index[j] = j, val[j] = 0;
        }
    }

    inline void pivot(int m, int n, int a, int b){ /// Pivoting and exchanging a non-basic variable with a basic variable
        for (int i = 0; i <= m; i++){
            if (i != a){
                for (int j = 0; j <= n; j++){
                    if (j != b){
                        ar[i][j] -= (ar[i][b] * ar[a][j]) / ar[a][b];
                    }
                }
            }
        }
        for (int j = 0; j <= n; j++){
            if (j != b) ar[a][j] /= ar[a][b];
        }
        for (int i = 0; i <= m; i++){
            if (i != a) ar[i][b] = -ar[i][b] / ar[a][b];
        }
        ar[a][b] = 1.0 / ar[a][b];
        swap(basis[a], index[b]);
    }
    inline long double solve(){ /// simplex core
        init();
        int i, j, k, l;
        for (; ;){
            for (i = 1, k = 1; i <= m; i++){
                if ((ar[i][n] < ar[k][n]) || (ar[i][n] == ar[k][n] && basis[i] < basis[k] && (rand() & 1))) k = i;
            }
            if (ar[k][n] >= -EPS) break;

            for (j = 0, l = 0; j < n; j++){
                if ((ar[k][j] < (ar[k][l] - EPS)) || (ar[k][j] < (ar[k][l] - EPS) && index[i] < index[j] && (rand() & 1))){
                    l = j;
                }
            }
            if (ar[k][l] >= -EPS){
                solution_flag = INFEASIBLE; /// No solution is possible
                return -1.0;
            }
            pivot(m, n, k, l);
        }
        for (; ;){
            for (j = 0, l = 0; j < n; j++){
                if ((ar[0][j] < ar[0][l]) || (ar[0][j] == ar[0][l] && index[j] < index[l] && (rand() & 1))) l = j;
            }
            if (ar[0][l] > -EPS) break;
            for (i = 1, k = 0; i <= m; i++){
                if (ar[i][l] > EPS && (!k || ar[i][n] / ar[i][l] < ar[k][n] / ar[k][l] - EPS || (ar[i][n] / ar[i][l] < ar[k][n] / ar[k][l] + EPS && basis[i] < basis[k]))){
                    k = i;
                }
            }
            if (ar[k][l] <= EPS){
                solution_flag = UNBOUNDED; /// Solution is infinity, no finite solution exists
                return -666.0;
            }
            pivot(m, n, k, l);
        }
        for (i = 1; i <= m; i++){
            if (basis[i] >= 0) val[basis[i]] = ar[i][n];
        }
        solution_flag = 1; /// Successful completion
        return (ar[0][n] * minmax_flag); /// Negate the output for MINIMIZE since the objective function was negated
    }
}
long double obj[N],cons[N];

int32_t main()
{
    BeatMeScanf;
	ll i,x,y,w,j,black = 0;
    cin>>n>>k;
    for(i=0;i<n;i++) cin>>a[i], black += a[i];
	for(i=1;i<n;i++)
	{
		cin>>x>>y>>w;
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
		cost[x].pb(w);
		cost[y].pb(w);
	}
	for(i=0;i<n;i++) dfs(i,-1,0,i);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if( dis[i][j] <= k )ok[i][j] = 1;
		}
	}
	for(i=0;i<n;i++) obj[i] = (long double)1 - a[i];
	lp::init(n,obj,MINIMIZE);
	for(i=0;i<n;i++)cons[i] = 1.0;
	lp::add_constraint(cons,black,EQUAL);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cons[j] = (long double)ok[i][j];
		}
		lp::add_constraint(cons,1.0,GREATEQ);
	}
    long double ret = lp::solve();
    ll ans = round(ret);
    if(ans < 0)ans = -1;
    cout<<ans<<nl;
	return 0;
}
