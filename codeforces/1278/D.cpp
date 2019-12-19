#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 1e6 + 9;
const int mod = 1e9 + 7;

struct dsu {
	vector<int> par, rnk, size; int c;
	dsu(int n) : par(n+1), rnk(n+1,0), size(n+1,1), c(n) {
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }///connected components
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1; else --c;
		if (rnk[i] > rnk[j]) swap(i, j);
		par[i] = j; size[j] += size[i];
		if (rnk[i] == rnk[j]) rnk[j]++;
		return j;
	}
};

int l[N], r[N], st[N], en[N];
int32_t main()
{
    int n=in();
    for(int i=1; i<=n; i++){
        l[i]=in(), r[i]=in();
        st[l[i]]=i;
        en[r[i]]=i;
    }
    dsu d(n);
    set<pii> alive;
    int ed=0;
    for(int i=1; i<=2*n; i++){
        if(st[i]){
            int id=st[i];
            for(auto y: alive){
                if(y.first>r[id]) break;
                ed++;
                d.merge(id, y.second);
            }
            if(ed>=n) break;
            alive.insert({r[id], id});
        }
        while((int)alive.size()&&(*(alive.begin())).first<=i) alive.erase(alive.begin());
    }
    if(ed==n-1&&d.count()==1) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
