#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N=3e5+9;
const int mod=1e9+7;

int ans[N],a[N],R[N];
gp_hash_table<int,vector<int>> pos;
vector<pii> Q[N];
int32_t main()
{
    int n=in();
    for(int i=1;i<=n;i++){
        a[i]=in();
        pos[a[i]].eb(i);
        R[i]=a[i];
    }
    for(auto &x:pos) reverse(x.second.begin(),x.second.end());
    sort(a+1,a+n+1,greater<int>());
    int q=in();
    for(int i=1;i<=q;i++){
        int k=in(),id=in();
        Q[k].eb(id,i);
    }
    o_set<int>se;
    for(int i=1;i<=n;i++){
        se.insert(pos[a[i]].back());
        pos[a[i]].pop_back();
        for(auto x:Q[i]){
            ans[x.second]=R[*se.find_by_order(x.first-1)];
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}
