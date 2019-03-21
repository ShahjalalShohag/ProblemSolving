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
    const int N=2e5+9;
    const ld eps=1e-9;
    const ld PI=acos(-1.0);
    ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
    ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
    ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


    vi g[N];
    int par[N][20],dep[N],sz[N];
    void dfs(int u,int pre)
    {
        par[u][0]=pre;
        dep[u]=dep[pre]+1;
        sz[u]=1;
        for(int i=1;i<=18;i++) par[u][i]=par[par[u][i-1]][i-1];
        for(auto v:g[u]){
            if(v==pre) continue;
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
    int lca(int u,int v)
    {
        if(dep[u]<dep[v]) swap(u,v);
        for(int k=18;k>=0;k--) if(dep[par[u][k]]>=dep[v]) u=par[u][k];
        if(u==v) return u;
        for(int k=18;k>=0;k--) if(par[u][k]!=par[v][k]) u=par[u][k],v=par[v][k];
        return par[u][0];
    }

    int kth(int u,int k)
    {
        for(int i=0;i<=18;i++) if(k&(1<<i)) u=par[u][i];
        return u;
    }

    int isanc(int u, int g) {
        int k = dep[u] - dep[g];
        return k>=0 && kth(u, k) == g;
    }

    ///merging two paths
    pii merge(pii x, pii y) {
        if (x.first == 0)                 return y;///where {0,0} is a null path
        if (y.first == 0)                 return x;
        if (x.first==-1 || y.first==-1)   return {-1, -1};

        vector<int> can = {x.first, x.second, y.first, y.second};
        int a = can[0];

        for (int u: can)
            if (dep[u] > dep[a])
                a = u;

        int b = -1;
        for (int u: can)
            if (!isanc(a, u)) {
                if (b==-1)  b = u;
                if (dep[b] < dep[u])    b = u;
            }

        if (b == -1) {
            b = can[0];
            for (int u: can)
                if (dep[u] < dep[b])
                    b = u;
            return {a, b};
        }

        int g = lca(a, b);
        for (int u: can) {
            if (u==a || u==b)   continue;
            if (dep[u] < dep[g] || (!isanc(a, u) && !isanc(b, u)))    return {-1, -1};
        }
        return {a, b};
    }
    int pos[N];
    struct segtree
    {
        pii t[4*N];
        void build(int n,int b,int e)
        {
            if(b==e){
                t[n]=MP(pos[b],pos[b]);
                return;
            }
            int stree;
            build(l,b,mid);
            build(r,mid+1,e);
            t[n]=merge(t[l],t[r]);
        }
        void upd(int n,int b,int e,int i,int x)
        {
            if(b>i||e<i) return;
            if(b==e&&b==i){
                t[n]=MP(pos[x],pos[x]);
                return;
            }
            int stree;
            upd(l,b,mid,i,x);
            upd(r,mid+1,e,i,x);
            t[n]=merge(t[l],t[r]);
        }
        int query(int n,int b,int e,pii p)
        {
            if(b==e) return (merge(p,t[n]).F==-1?b-1:b);
            int stree;
            pii nw=merge(p,t[l]);
            if(nw.F==-1) return query(l,b,mid,p);
            else return query(r,mid+1,e,nw);
        }
    }t;
    int a[N];
    int32_t main()
    {
        BeatMeScanf;
        cin.tie(0);
        int i,j,k,n,m,q;
        cin>>n;
        for(i=1;i<=n;i++) cin>>k,pos[k+1]=i,a[i]=k+1;
        for(i=2;i<=n;i++) cin>>k,g[i].eb(k),g[k].eb(i);
        dfs(1,0);
        t.build(1,1,n);
        cin>>q;
        while(q--){
            int ty;
            cin>>ty;
            if(ty==1){
                cin>>j>>k;
                t.upd(1,1,n,a[j],a[k]);
                t.upd(1,1,n,a[k],a[j]);
                swap(a[j],a[k]);
                swap(pos[a[j]],pos[a[k]]);
            }
            else cout<<t.query(1,1,n,MP(0,0))<<nl;
        }
        return 0;
    }
    ///Before submit=>
    ///    *check for integer overflow,array bounds
    ///    *check for n=1

